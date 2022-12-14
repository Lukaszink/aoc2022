#include <stdio.h>
#include <stdlib.h>

struct ArrayStr
{
    int arr[100];
};

void v1(FILE *);
void v2(FILE *);
int recu(int, int, int, int[100][100], struct ArrayStr);

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
    printf("map %d to %d\n", i, ne->key);
    return ne->key;
}
int main()
{
    FILE *fp = fopen("in16.txt", "r");
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
        flows[pos] = flowr;
        tmp = '.';

        while (tmp != '\n')
        {

            fscanf(f, " %c%c%c", &fst, &snd, &tmp);

            tmppos = mapint(map, (ctoint(fst) * 30 + ctoint(snd)));
            // printf("Add connect %d to %c%c: %d\n", pos, fst, snd, tmppos);

            valves[pos][tmppos] = 1;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%d ", valves[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // // skip valves with flow = 0
    // for (int curv = 0; curv < 100; curv++)
    // {
    //     if (flows[curv] == 0 && curv != mapint(map, 0))
    //     { // for all valves check if flow = 0
    //         for (int i = 0; i < 100; i++)
    //         {
    //             for (int j = 0; j < 100; j++)
    //             {
    //                 if (valves[i][curv] > 0 && valves[curv][j] > 0)
    //                 {
    //                     valves[i][j] = valves[curv][j] + 1; // add neighbours to predecessor
    //                 }
    //                 if (j == 99)
    //                 {
    //                     valves[i][curv] = 0; // set all paths of this valve to 0
    //                 }
    //                 if (i == 99)
    //                     valves[curv][j] = 0; // set all paths from this valve to 0 (not necessary)
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i < 100; i++)
    {
        valves[i][i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", valves[i][j]);
        }
        printf("\n");
    }
    int nrunopened;
    struct ArrayStr used;
    for (int i = 0; i < 100; i++)
    {
        used.arr[i] = flows[i];
        if (flows[i] > 0)
            nrunopened++;
    }
    printf("Start it at node %d with nr unopened = %d\n", mapint(map, 0), nrunopened);

    int out = recu(1, mapint(map, 0), nrunopened, valves, used);
    printf("Out: %d \n", out);
}

int recu(int iter, int cur, int nruop, int valv[100][100], struct ArrayStr avialflowr)
{
    int max = 0;

    if (iter == 30)
        return 0;

    if (nruop == 0)
        return 0;

    struct ArrayStr newfr;
    for (int i = 0; i < 100; i++)
    {
        newfr.arr[i] = avialflowr.arr[i];
    }

    if (avialflowr.arr[cur] != 0)
    {
        int curflow = avialflowr.arr[cur];
        newfr.arr[cur] = 0;

        max = avialflowr.arr[cur] * (30 - iter) + recu(iter + 1, cur, nruop - 1, valv, newfr);

        newfr.arr[cur] = curflow;
    }
    for (int next = 0; next < 100; next++)
    {
        if (valv[cur][next] > 0 && valv[cur][next] + iter <= 30)
        {
            int tmp = recu(iter + valv[cur][next], next, nruop, valv, newfr);
            if (tmp > max)
                max = tmp;
        }
    }
    return max;
}

void v2(FILE *f)
{
}