#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);

int ctoint(char a)
{
    return (a - 'a' + 1);
}

int main()
{
    FILE *fp = fopen("in12.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char tmp = ' ';
    int h[50][200];

    int m = 0;
    int tmpn = 0;
    int n = 0;

    int startm = 0;
    int startn = 0;

    int endn = 0;
    int endm = 0;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp == '\n')
        {
            n = tmpn;
            m++;
            tmpn = 0;
        }
        else
        {
            h[m][tmpn] = ctoint(tmp);
            if (tmp == 'E')
            {
                h[m][tmpn] = ctoint('z') + 1;
                endm = m;
                endn = tmpn;
            }
            if (tmp == 'S')
            {
                h[m][tmpn] = 0;
                startm = m;
                startn = tmpn;
            }
            tmpn++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }

    int dp[m][n];
    // set max
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 100000;

    dp[startm][startn] = 0;

    for (int it = 0; it < m * n; it++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i > 0) && ((h[i][j] <= (h[i - 1][j]) + 1)) && dp[i - 1][j] < dp[i][j])
                    dp[i][j] = dp[i - 1][j] + 1;

                if ((i < (m - 1)) && ((h[i][j] <= (h[i + 1][j]) + 1)) && dp[i + 1][j] < dp[i][j])
                    dp[i][j] = dp[i + 1][j] + 1;

                if ((j > 0) && ((h[i][j] <= (h[i][j - 1]) + 1)) && dp[i][j - 1] < dp[i][j])
                    dp[i][j] = dp[i][j - 1] + 1;

                if ((j < (n - 1)) && ((h[i][j] <= (h[i][j + 1]) + 1)) && dp[i][j + 1] < dp[i][j])
                    dp[i][j] = dp[i][j + 1] + 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] < 100000)
            {
                printf("%c", h[i][j] + 'a' - 1);
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("Out %d \n", dp[endm][endn]);
}

void v2(FILE *f)
{
    char tmp = ' ';
    int h[50][200];

    int m = 0;
    int tmpn = 0;
    int n = 0;

    int startm = 0;
    int startn = 0;

    int endn = 0;
    int endm = 0;

    int dp[50][200];

    // set max
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 200; j++)
            dp[i][j] = 100000;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp == '\n')
        {
            n = tmpn;
            m++;
            tmpn = 0;
        }
        else
        {
            h[m][tmpn] = ctoint(tmp);
            if (tmp == 'E')
            {
                h[m][tmpn] = ctoint('z') + 1;
                endm = m;
                endn = tmpn;
            }
            if (tmp == 'a')
            {
                // h[m][tmpn] = 1;
                dp[m][tmpn] = 0;
            }
            tmpn++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", h[i][j]);
        }
        printf("\n");
    }

    for (int it = 0; it < m * n; it++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i > 0) && ((h[i][j] <= (h[i - 1][j]) + 1)) && dp[i - 1][j] < dp[i][j])
                    dp[i][j] = dp[i - 1][j] + 1;

                if ((i < (m - 1)) && ((h[i][j] <= (h[i + 1][j]) + 1)) && dp[i + 1][j] < dp[i][j])
                    dp[i][j] = dp[i + 1][j] + 1;

                if ((j > 0) && ((h[i][j] <= (h[i][j - 1]) + 1)) && dp[i][j - 1] < dp[i][j])
                    dp[i][j] = dp[i][j - 1] + 1;

                if ((j < (n - 1)) && ((h[i][j] <= (h[i][j + 1]) + 1)) && dp[i][j + 1] < dp[i][j])
                    dp[i][j] = dp[i][j + 1] + 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] < 100000)
            {
                printf("%c", h[i][j] + 'a' - 1);
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("Out %d \n", dp[endm][endn]);
}