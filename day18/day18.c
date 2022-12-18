#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);

int main()
{
    FILE *fp = fopen("in18.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    int dp[25][25][25];

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    int x;
    int y;
    int z;

    while (fscanf(f, "%d,%d,%d\n", &x, &y, &z) > 0)
    {
        dp[x][y][z] = 1;
        printf("Add Cube %d %d %d\n", x, y, z);
    }
    int sum = 0;

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                if (dp[i][j][k])
                {
                    sum += 6;
                    if (i > 0 && (dp[i - 1][j][k]))
                        sum--;

                    if (j > 0 && (dp[i][j - 1][k]))
                        sum--;
                    if (k > 0 && (dp[i][j][k - 1]))
                        sum--;
                    if (i < 24 && (dp[i + 1][j][k]))
                        sum--;
                    if (j < 24 && (dp[i][j + 1][k]))
                        sum--;
                    if (k < 24 && (dp[i][j][k + 1]))
                        sum--;
                }
            }
        }
    }
    printf("Out: %d", sum);
}

void v2(FILE *f)
{
    int dp[25][25][25];

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }

    int x;
    int y;
    int z;

    while (fscanf(f, "%d,%d,%d\n", &x, &y, &z) > 0)
    {
        dp[x][y][z] = 1;
        printf("Add Cube %d %d %d\n", x, y, z);
    }
    int sum = 0;

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                if (dp[i][j][k])
                {
                    sum += 6;                       // surface area of cube
                    if (i > 0 && (dp[i - 1][j][k])) // subtract if no surface
                        sum--;

                    if (j > 0 && (dp[i][j - 1][k]))
                        sum--;
                    if (k > 0 && (dp[i][j][k - 1]))
                        sum--;
                    if (i < 24 && (dp[i + 1][j][k]))
                        sum--;
                    if (j < 24 && (dp[i][j + 1][k]))
                        sum--;
                    if (k < 24 && (dp[i][j][k + 1]))
                        sum--;
                }
            }
        }
    }

    // all ==2 are are reachable from outside
    dp[23][23][23] = 2;
    for (int it = 0; it < 25 * 24 * 25; it++)
    {
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                for (int k = 0; k < 25; k++)
                {
                    if (dp[i][j][k] == 0)
                    {
                        if (i > 0 && (dp[i - 1][j][k] == 2))
                            dp[i][j][k] = 2;
                        if (j > 0 && (dp[i][j - 1][k] == 2))
                            dp[i][j][k] = 2;
                        if (k > 0 && (dp[i][j][k - 1] == 2))
                            dp[i][j][k] = 2;
                        if (i < 24 && (dp[i + 1][j][k] == 2))
                            dp[i][j][k] = 2;
                        if (j < 24 && (dp[i][j + 1][k] == 2))
                            dp[i][j][k] = 2;
                        if (k < 24 && (dp[i][j][k + 1]) == 2)
                            dp[i][j][k] = 2;
                    }
                }
            }
        }
    }

    // subtract inside area (same as task one but for air pockets)
    int subtract = 0;
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                if (dp[i][j][k] == 0)
                {
                    subtract += 6;
                    if (i > 0 && (dp[i - 1][j][k] == 0))
                        subtract--;

                    if (j > 0 && (dp[i][j - 1][k] == 0))
                        subtract--;
                    if (k > 0 && (dp[i][j][k - 1] == 0))
                        subtract--;
                    if (i < 24 && (dp[i + 1][j][k] == 0))
                        subtract--;
                    if (j < 24 && (dp[i][j + 1][k] == 0))
                        subtract--;
                    if (k < 24 && (dp[i][j][k + 1] == 0))
                        subtract--;
                }
            }
        }
    }
}