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
    FILE *fp = fopen("in8.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{

    char tmp = 0;

    int table[100][100];
    int out[100][100];

    int n = 0;
    int m = 0;
    int gln = 0;

    // read into table
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {
            table[m][n] = tmp;
            out[m][n] = 0;
            n++;
        }
        else
        {
            gln = n;
            table[m][n] = tmp;
            out[m][n] = 0;
            n = 0;
            m++;
        }
    }
    n = gln;
    int cmaxup = 0;
    int cmaxdown = 0;
    int cmaxl = 0;
    int cmaxr = 0;

    for (int i = 0; i < m; i++)
    {
        cmaxl = 0;
        cmaxr = 0;
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] > cmaxl)
            {
                out[i][j] = 1;
                cmaxl = table[i][j];
            }
            if (table[i][n - 1 - j] > cmaxr)
            {
                out[i][n - j - 1] = 1;
                cmaxr = table[i][n - j - 1];
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        cmaxup = 0;
        cmaxdown = 0;
        for (int i = 0; i < m; i++)
        {
            if (table[i][j] > cmaxup)
            {
                out[i][j] = 1;
                cmaxup = table[i][j];
            }
            if (table[m - i - 1][j] > cmaxdown)
            {
                out[m - i - 1][j] = 1;
                cmaxdown = table[m - i - 1][j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("%d ", out[i][j]);
            sum += out[i][j];
        }
        // printf("\n");
    }
    printf("Out: %d", sum);
}

void v2(FILE *f)
{
    char tmp = 0;

    int table[100][100];

    int n = 0;
    int m = 0;
    int gln = 0;

    // read into table
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {
            table[m][n] = tmp;
            n++;
        }
        else
        {
            gln = n;
            table[m][n] = tmp;
            n = 0;
            m++;
        }
    }
    n = gln;
    int res = 0;

    for (int i = 1; i < m - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int val = table[i][j];
            int curres = 0;
            int k = 1;
            int cnd = 1;

            // up
            while (i - k >= 0 && cnd)
            {
                if (table[i - k][j] < val)
                {
                    k++;
                }
                else
                {
                    cnd = 0;
                    k++;
                }
            }
            curres = k - 1;

            cnd = 1;
            k = 1;
            // down
            while (i + k < m && cnd)
            {
                if (table[i + k][j] < val)
                {
                    k++;
                }
                else
                {
                    cnd = 0;
                    k++;
                }
            }
            k--;
            curres *= k;

            cnd = 1;
            k = 1;
            // left
            while (j - k >= 0 && cnd)
            {
                if (table[i][j - k] < val)
                {
                    k++;
                }
                else
                {
                    cnd = 0;
                    k++;
                }
            }
            k--;
            curres *= k;

            cnd = 1;
            k = 1;

            while (j + k < n && cnd)
            {
                if (table[i][j + k] < val)
                {
                    k++;
                }
                else
                {
                    cnd = 0;
                    k++;
                }
            }
            k--;
            curres *= k;

            if (curres > res)
            {
                res = curres;
                printf("I and J: %d %d", i, j);
            }
        }
    }
    printf("Res: %d", res);
}