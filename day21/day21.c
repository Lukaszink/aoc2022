#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);

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

int ctoint(char a)
{
    return (a - '0');
}

int chartonr(char a)
{
    return (a - 'a');
}

int fourchartonr(char a, char b, char c, char d, struct node *ma)
{
    // return (21.952 * chartonr(a) + 784 * chartonr(b) + 28 * chartonr(c) + chartonr(d));
    int tmp = (27000 * chartonr(a) + 900 * chartonr(b) + 30 * chartonr(c) + chartonr(d));
    return mapint(ma, tmp);
}

int main()
{
    FILE *fp = fopen("in21.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

long long getval(int loc, long long dp[10000][3], struct node *map)
{
    int oper = dp[loc][0];

    switch (oper)
    {
    case 1:
        return (getval(dp[loc][1], dp, map) + getval(dp[loc][2], dp, map));

    case 2:
        return (getval(dp[loc][1], dp, map) - getval(dp[loc][2], dp, map));

    case 3:
        return (getval(dp[loc][1], dp, map) * getval(dp[loc][2], dp, map));

    case 4:
        return (getval(dp[loc][1], dp, map) / getval(dp[loc][2], dp, map));

    case 0:
        return (dp[loc][1]); // int

    default:
        printf("error\n");
        return (dp[loc][1]); // int
    }
}

long long getvalandcheck(int loc, long long dp[10000][3], struct node *map)
{

    int oper = dp[loc][0];
    long long tmp1;
    long long tmp2;
    if (loc == fourchartonr('h', 'u', 'm', 'n', map))
        return -1;

    switch (oper)
    {
    case 1:
        tmp1 = getvalandcheck(dp[loc][1], dp, map);
        tmp2 = getvalandcheck(dp[loc][2], dp, map);
        return ((tmp1 != -1 && tmp2 != -1) ? tmp1 + tmp2 : -1);

    case 2:
        tmp1 = getvalandcheck(dp[loc][1], dp, map);
        tmp2 = getvalandcheck(dp[loc][2], dp, map);
        return ((tmp1 != -1 && tmp2 != -1) ? tmp1 - tmp2 : -1);
    case 3:
        tmp1 = getvalandcheck(dp[loc][1], dp, map);
        tmp2 = getvalandcheck(dp[loc][2], dp, map);
        return ((tmp1 != -1 && tmp2 != -1) ? tmp1 * tmp2 : -1);
    case 4:
        tmp1 = getvalandcheck(dp[loc][1], dp, map);
        tmp2 = getvalandcheck(dp[loc][2], dp, map);
        return ((tmp1 != -1 && tmp2 != -1) ? tmp1 / tmp2 : -1);
    case 0:
        return (dp[loc][1]); // int

    default:
        printf("error\n");
        return (dp[loc][1]); // int
    }
}

long long selectval(int loc, long long dp[10000][3], struct node *map, long long val)
{
    int oper = dp[loc][0];
    long long val_left = getvalandcheck(dp[loc][1], dp, map);
    long long val_right = getvalandcheck(dp[loc][2], dp, map);
    printf("Sv with %lld %lld\n", val_left, val_right);
    if (val_right == -1)
        oper += 10;

    switch (oper)
    {
    case 1:
        return selectval(dp[loc][1], dp, map, (val - val_right));
    case 2:
        return selectval(dp[loc][1], dp, map, (val + val_right));
    case 3:
        return selectval(dp[loc][1], dp, map, (val / val_right));
    case 4:
        return selectval(dp[loc][1], dp, map, (val * val_right));
    case 11:
        return selectval(dp[loc][2], dp, map, (val - val_left));
    case 12:
        return selectval(dp[loc][2], dp, map, (val_left - val));
    case 13:
        return selectval(dp[loc][2], dp, map, (val / val_left));
    case 14:
        return selectval(dp[loc][2], dp, map, (val_left / val));
    default:
        if (loc == fourchartonr('h', 'u', 'm', 'n', map))
        {
            return val;
        }
        return dp[loc][1];
    }
}

void v1(FILE *f)
{
    long long dp[10000][3];

    struct node *map = (struct node *)malloc(sizeof(struct node));

    char name[5];
    while (fscanf(f, "%c%c%c%c: ", &name[0], &name[1], &name[2], &name[3]) > 0)
    {
        char tmp = ' ';
        fscanf(f, "%c", &tmp);

        int index = fourchartonr(name[0], name[1], name[2], name[3], map);
        int nr = ctoint(tmp);

        if (nr >= 0 && nr <= 9)
        {
            nr = 0;
            while (tmp != '\n')
            {
                nr = 10 * nr + ctoint(tmp);
                fscanf(f, "%c", &tmp);
            }
            dp[index][0] = 0; // 0 means int
            dp[index][1] = (long long)nr;
            // printf("Read int :%d\n", nr);
        }
        else
        {
            fscanf(f, "%c%c%c", &name[1], &name[2], &name[3]);
            int fst = fourchartonr(tmp, name[1], name[2], name[3], map);
            fscanf(f, " %c ", &tmp);
            int oper;
            if (tmp == '+')
                oper = 1;
            if (tmp == '-')
                oper = 2;
            if (tmp == '*')
                oper = 3;
            if (tmp == '/')
                oper = 4;

            fscanf(f, "%c%c%c%c\n", &name[0], &name[1], &name[2], &name[3]);
            int snd = fourchartonr(name[0], name[1], name[2], name[3], map);
            dp[index][0] = (long long)oper;
            dp[index][1] = (long long)fst;
            dp[index][2] = (long long)snd;

            // printf("Read op :%c\n", tmp);
        }
    }
    int root = fourchartonr('r', 'o', 'o', 't', map);

    long long out = getval(root, dp, map);
    printf("Out: %lld\n", out);
}

void v2(FILE *f)
{
    long long dp[10000][3];

    struct node *map = (struct node *)malloc(sizeof(struct node));

    char name[5];
    while (fscanf(f, "%c%c%c%c: ", &name[0], &name[1], &name[2], &name[3]) > 0)
    {
        char tmp = ' ';
        fscanf(f, "%c", &tmp);

        int index = fourchartonr(name[0], name[1], name[2], name[3], map);
        int nr = ctoint(tmp);

        if (nr >= 0 && nr <= 9)
        {
            nr = 0;
            while (tmp != '\n')
            {
                nr = 10 * nr + ctoint(tmp);
                fscanf(f, "%c", &tmp);
            }
            dp[index][0] = 0; // 0 means int
            dp[index][1] = (long long)nr;
            // printf("Read int :%d\n", nr);
        }
        else
        {
            fscanf(f, "%c%c%c", &name[1], &name[2], &name[3]);
            int fst = fourchartonr(tmp, name[1], name[2], name[3], map);
            fscanf(f, " %c ", &tmp);
            int oper;
            if (tmp == '+')
                oper = 1;
            if (tmp == '-')
                oper = 2;
            if (tmp == '*')
                oper = 3;
            if (tmp == '/')
                oper = 4;

            fscanf(f, "%c%c%c%c\n", &name[0], &name[1], &name[2], &name[3]);
            int snd = fourchartonr(name[0], name[1], name[2], name[3], map);
            dp[index][0] = (long long)oper;
            dp[index][1] = (long long)fst;
            dp[index][2] = (long long)snd;

            // printf("Read op :%c\n", tmp);
        }
    }
    int root = fourchartonr('r', 'o', 'o', 't', map);
    long long out = 0;

    long long fst = getvalandcheck(dp[root][1], dp, map);
    if (fst == -1)
    {
        long long tmp = getvalandcheck(dp[root][2], dp, map);
        out = selectval(dp[root][1], dp, map, tmp);
    }
    else
    {
        out = selectval(dp[root][1], dp, map, fst);
    }

    printf("Out: %lld\n", out);
}