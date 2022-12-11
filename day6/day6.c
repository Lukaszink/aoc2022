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
    FILE *fp = fopen("in6.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // v1(fp);
    v2(fp);
}

void v1(FILE *f)
{
    char c1;
    char c2;
    char c3;
    char c4;
    char tmp;

    int iter = 0;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        c1 = c2;
        c2 = c3;
        c3 = c4;
        c4 = tmp;
        iter++;

        if (iter > 3)
        {
            if ((c1 != c2) && (c1 != c3) && (c1 != c4) && (c2 != c3) && (c2 != c4) && (c3 != c4))
            {
                printf("Iter: %d", iter);
                break;
            }
        }
    }
}

void v2(FILE *f)
{
    int cnd = 1;
    int iter = 0;
    char tmp;
    char cur[14];

    while (fscanf(f, "%c", &tmp) > 0)
    {
        for (int i = 0; i < 13; i++)
        {
            cur[i] = cur[i + 1];
        }
        cur[13] = tmp;

        iter++;
        cnd = 1;

        if (iter > 13)
        {
            for (int i = 0; i < 14; i++)
            {
                for (int j = i + 1; j < 14; j++)
                {
                    if (cur[i] == cur[j])
                        cnd = 0;
                }
            }
            if (cnd)
                printf("Iter: %d", iter);
        }
    }
}