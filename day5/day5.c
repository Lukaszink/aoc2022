#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);

int ctoint(char a)
{
    return (a - '0');
}

int main()
{
    FILE *fp = fopen("in5.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // v1(fp);
    v2(fp);
}

void v1(FILE *f)
{
    int end;
    int m = 0;
    int n = 0;
    int tmpn = 0;

    char openbr;
    char c = ' ';
    char closebr;
    char space;

    char **table = malloc(200 * sizeof(char *));
    for (int i = 0; i < 200; i++)
        table[i] = malloc(20 * sizeof(char));

    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 20; j++)
            table[i][j] = ' ';

    while (c != '1')
    {
        end = fscanf(f, "%c%c%c%c", &openbr, &c, &closebr, &space);
        if (openbr == '[' && (c != '1'))
        {
            printf("%c%c%c ", openbr, c, closebr);
            for (int i = m; i > 0; i--)
            {
                table[i][tmpn] = table[i - 1][tmpn];
            }
            table[0][tmpn] = c;
        }
        tmpn++;

        if (space == '\n')
        {
            printf("\n");
            n = tmpn;
            m++;
            tmpn = 0;
        }
    }

    // 1 2 3.. line and following line get ignored
    for (int i = 0; i < n - 1; i++)
    {
        end = fscanf(f, "%c%c%c%c", &openbr, &c, &closebr, &space);
    }
    end = fscanf(f, "%c", &openbr);

    // move instr
    int nr = 0;
    int src = 0;
    int dest = 0;

    int a;
    int b;
    while (fscanf(f, "move %d from %d to %d\n", &nr, &src, &dest) > 0)
    {
        printf("Move %d %d %d\n", nr, src, dest);
        src--;
        dest--;
        for (int x = 0; x < nr; x++)
        {
            a = 199;
            b = 199;

            while (table[a][src] == ' ')
                a--;
            while (table[b][dest] == ' ' && b > 0)
                b--;
            table[b + 1][dest] = table[a][src];
            table[a][src] = ' ';
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("[%c] ", table[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%c] ", table[i][j]);
        }
        printf("\n");
    }
}

void v2(FILE *f)
{
    int end;
    int m = 0;
    int n = 0;
    int tmpn = 0;

    char openbr;
    char c = ' ';
    char closebr;
    char space;

    char **table = malloc(200 * sizeof(char *));
    for (int i = 0; i < 200; i++)
        table[i] = malloc(20 * sizeof(char));

    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 20; j++)
            table[i][j] = ' ';

    while (c != '1')
    {
        end = fscanf(f, "%c%c%c%c", &openbr, &c, &closebr, &space);
        if (openbr == '[' && (c != '1'))
        {
            printf("%c%c%c ", openbr, c, closebr);
            for (int i = m; i > 0; i--)
            {
                table[i][tmpn] = table[i - 1][tmpn];
            }
            table[0][tmpn] = c;
        }
        tmpn++;

        if (space == '\n')
        {
            printf("\n");
            n = tmpn;
            m++;
            tmpn = 0;
        }
    }

    // 1 2 3.. line and following line get ignored
    for (int i = 0; i < n - 1; i++)
    {
        end = fscanf(f, "%c%c%c%c", &openbr, &c, &closebr, &space);
    }
    end = fscanf(f, "%c", &openbr);

    // move instr
    int nr = 0;
    int src = 0;
    int dest = 0;

    int a;
    int b;
    while (fscanf(f, "move %d from %d to %d\n", &nr, &src, &dest) > 0)
    {
        printf("Move %d %d %d\n", nr, src, dest);
        src--;
        dest--;

        a = 199;
        b = 199;

        while (table[a][src] == ' ')
            a--;
        while (table[b][dest] == ' ' && b > 0)
            b--;
        for (int x = 0; x < nr; x++)
        {
            table[b + nr - x][dest] = table[a - x][src];
            table[a - x][src] = ' ';
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("[%c] ", table[i][j]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%c] ", table[i][j]);
        }
        printf("\n");
    }
}