#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);

int ctoint(char a)
{
    return (a - '0');
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

int main()
{
    FILE *fp = fopen("test.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char tmp = 0;

    int counter[8];

    for (int x = 0; x < 8; x++)
    {
        counter[x] = 0;
    }

    int divb[8];
    int isop[8];
    int add[8];
    int ope[8];
    int ift[8];
    int iff[8];

    struct node *arr[10];
    int N = 4;

    for (int i = 0; i < 8; i++)
    {
        arr[i] = (struct node *)malloc(sizeof(struct node));
    }

    for (int i = 0; i < N; i++)
    {
        // line 1
        fscanf(f, "Monkey %*d:\n");

        // line 2
        fscanf(f, "  Starting items:");
        char c = ',';
        while (c == ',')
        {
            fscanf(f, "%*c");
            // printf("%c", c);
            int tmp = 0;
            fscanf(f, "%d%c", &tmp, &c);
            insert(0, tmp, arr[i]);
        }

        // line 3
        char op;
        char fst;
        fscanf(f, "  Operation: new = old %c %c", &op, &fst);
        if (fst == 'o')
        {
            isop[i] = 1;
            fscanf(f, "ld\n");
            ope[i] = 0;
        }
        else
        {
            int oper = 0;
            isop[i] = 0;
            fscanf(f, "%d\n", &oper);
            ope[i] = ctoint(fst); // ! only works for val < 10
        }

        if (op == '+')
        {
            add[i] = 1;
        }
        else
        {
            add[i] = 0;
        }

        // line 4
        divb[i] = 0;
        fscanf(f, "  Test: divisible by %d\n", &divb[i]);

        // line 5
        ift[i] = 0;
        fscanf(f, "    If true: throw to monkey %d\n", &ift[i]);

        // line 6
        iff[i] = 0;
        fscanf(f, "    If false: throw to monkey %d\n", &iff[i]);

        // line 7
        fscanf(f, "\n");
        printf("Add?%d Isold?%d Op:%d div:%d t:%d f:%d\n", add[i], isop[i], ope[i], divb[i], ift[i], iff[i]);
        printlist(arr[i]);
    }
    printf("\n\n\n");
    ope[0] = 19;

    int scm = 1;
    for (int x = 0; x < N; x++)
    {
        scm = scm * divb[x];
    }

    for (int iter = 0; iter < 10000; iter++)
    {
        for (int curmonkey = 0; curmonkey < N; curmonkey++)
        {
            while (!isempty(arr[curmonkey]))
            {
                counter[curmonkey]++;

                int opwith;
                int t = getfirstdata(arr[curmonkey]);
                // printf("getdata: %d  -> ", t);
                if (isop[curmonkey]) // op old * old or int
                {
                    opwith = t;
                }
                else
                {
                    opwith = ope[curmonkey];
                }

                int val = 0;
                // mult or add
                if (add[curmonkey])
                {
                    val = t + opwith;
                }
                else
                {
                    val = t * opwith;
                }

                val = val % scm;
                // val = val / 3;

                if (val % divb[curmonkey] == 0)
                {
                    insert(0, val, arr[ift[curmonkey]]);
                    // printf("Monkey %d send item size to %d since divby %d is true\n", curmonkey, val, divb[curmonkey]);
                }
                else
                {
                    insert(0, val, arr[iff[curmonkey]]);
                    // printf("Monkey %d send item size to %d since divby %d is false\n", curmonkey, val, divb[curmonkey]);
                }
            }
        }
        if (iter % 1000 == 999)
        {
            for (int x = 0; x < 8; x++)
            {
                if (x == 0)
                    printf("After Run %d\n", iter);
                printf("%d %d\n", x, counter[x]);
            }
        }
    }
    for (int x = 0; x < N; x++)
    {
        printf("[%d] %d\n", x, counter[x]);
        // printf("%ld \n", counter[3] * counter[4]);
    }
}

void v2(FILE *f)
{
}