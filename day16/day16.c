#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);
int recu(int, int, int[1000][1000]);

int ctoint(char a)
{
    return (a - 'A');
}

// List in C
struct node
{
    int key;
    int data;
    struct node *next;
};

void insert(int ke, int dat, struct node *start)
{
    struct node *oldstart = start->next;
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->key = ke;
    ne->data = dat;
    ne->next = oldstart;
    start->next = ne;
}

int isempty(struct node *start)
{
    return (start->next == NULL);
}

struct node *getfirst(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
    return tmp;
}

int getfirstdata(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
    return tmp->data;
}

void removefirtst(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
}

void printlist(struct node *start)
{
    printf("Print out list: \n");
    struct node *cur = start;
    if ((cur->next) != NULL)
    {
        cur = cur->next;
    }
    while ((cur->next) != NULL)
    {
        printf("%d %d\n", cur->key, cur->data);
        cur = cur->next;
    }
    printf("%d %d\n", cur->key, cur->data);
}

int mapint(struct node *start, int i)
{
    struct node *cur = start;
    while (cur->next != NULL)
    {
        if (cur->data == i)
        {
            return cur->key;
        }
        cur = cur->next;
    }
    if (cur->data == i)
    {
        return cur->key;
    }

    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->key = cur->key + 1;
    ne->data = i;
    ne->next = NULL;
    cur->next = ne;
    return ne->key;
}
int main()
{
    FILE *fp = fopen("test.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{

    struct node *map = (struct node *)malloc(sizeof(struct node));
    map->next = NULL;
    map->key = -1;
    map->data = -100;

    char tmp = 's';
    int flowr = 0;
    int valves[100][100];
    int flows[100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            valves[i][j] = 0;

    char fst;
    char snd;
    char cu = '.';

    int pos;
    int tmppos;

    while (fscanf(f, "Valve %c%c has flow rate=%d; tunnel", &fst, &snd, &flowr) > 0)
    {
        fscanf(f, "%c", &cu);
        if (cu == 's')
        {
            fscanf(f, " lead to valves");
        }
        else
        {
            fscanf(f, "leads to valve");
        }

        pos = mapint(map, (ctoint(fst) * 30 + ctoint(snd)));
        printf("\n");
        printf("From %c%c\n", fst, snd);
        flows[pos] = flowr;
        tmp = '.';

        while (tmp != '\n')
        {

            fscanf(f, " %c%c%c", &fst, &snd, &tmp);

            tmppos = mapint(map, (ctoint(fst) * 30 + ctoint(snd)));
            printf("Add connect %d to %c%c: %d\n", pos, fst, snd, tmppos);

            valves[pos][tmppos] = 1;
        }
    }

    int usedvalves[100][100][31]; // pos valveto iteration
    int score[100][31];

    score[mapint(map, 0)][0] = 1000000; //start at valve AA

    int globalmax=0;

    for (int it = 1; it < 31; it++)
    {
        for (int po = 0; po < 100; po++) // find max val of all pos in round it
        {
            int tmpmax = 0;

            if (usedvalves[po][po][it - 1] == 0)
            { // open valve
                score[po][it] = score[po][it - 1] + (30 - it) * flows[po];
            }
            else
            {
                score[po][it] = score[po][it - 1];
            }

            for (int c = 0; c < 100; c++)
                usedvalves[po][c][it] = usedvalves[po][c][it - 1];
            usedvalves[po][po][it] = 1;

            for (int i = 0; i < 100; i++)
            {
                tmpmax = 0;

                if (valves[i][po] == 1) // if edge from valve i to this po
                {

                    tmpmax = score[i][it - 1];
                }

                if (tmpmax > score[po][it]) // check if other valve score is better
                {
                    for (int c = 0; c < 100; c++)
                        usedvalves[po][c][it] = usedvalves[i][c][it - 1]; // copy used valves
                    score[po][it] = tmpmax;
                }
            }
            if (globalmax < score[po][it])
                globalmax = score[po][it];
        }
    }

    printf("Out %d\n", globalmax - 1000000);
}

void v2(FILE *f)
{
}