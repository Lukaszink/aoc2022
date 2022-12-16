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
    FILE *fp = fopen("in15.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // min test = -2
    // max test = 25
    // min in = -452614
    // max in = 3983829
    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    int y = 2000000;
    char dp[8000000];
    for (int i = 0; i < 8000000; i++)
    {
        dp[i] = '.';
    }
    int sx;
    int sy;
    int bx;
    int by;

    while (fscanf(f, "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &sx, &sy, &bx, &by) > 0)
    {
        int tmpx;
        int tmpy;
        if (by == y)
            dp[bx + 2000000] = 'B';
        if (sy == y)
            dp[sx + 2000000] = 'S';

        int dist = abs(sx - bx) + abs(sy - by);
        for (int i = 0; i < 8000000; i++)
        {
            tmpx = i - 2000000;

            if (((abs(tmpx - sx) + (abs(y - sy))) <= dist) && dp[i] == '.')
                dp[i] = '#';
        }
    }
    int cnt = 0;
    for (int i = 0; i < 8000000; i++)
    {
        // printf("%c ", dp[i]);
        if (dp[i] == '#')
            cnt++;
    }

    printf("Cnt: %d\n", cnt);
}

void v2(FILE *f)
{

    char dp[8000000];
    for (int i = 0; i < 8000000; i++)
    {
        dp[i] = '.';
    }
    int sx[40];
    int sy[40];
    int bx[40];
    int by[40];
    int it = 0;
    int size = 4000000;
    int dist;
    char cur;

    while (fscanf(f, "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d\n", &sx[it], &sy[it], &bx[it], &by[it]) > 0)
    {
        it++;
    }
    for (int s = 0; s < it; s++)
    {
        int di = abs(sx[s] - bx[s]) + abs(sy[s] - by[s]) + 1;

        for (int alld = 0; alld < di; alld++)
        {
            int i = sx[s] - di + alld;
            int j = sy[s] + alld;

            cur = '.';
            for (int k = 0; k < it; k++)
            {
                if ((i == bx[k]) && (j == by[k]))
                    cur = 'B';
                if ((i == sx[k]) && (j == sy[k]))
                    cur = 'S';

                dist = abs(sx[k] - bx[k]) + abs(sy[k] - by[k]);
                if (((abs(i - sx[k]) + abs(j - sy[k])) <= dist) && cur == '.')
                {
                    cur = '#';
                }
            }
            if (cur == '.' && i > 0 && j > 0 && i < size && j < size)
                printf("Out: %d %d \n", i, j);
        }

        for (int alld = 0; alld < di; alld++)
        {
            int i = sx[s] + alld;
            int j = sy[s] - di + alld;

            cur = '.';
            for (int k = 0; k < it; k++)
            {
                if ((i == bx[k]) && (j == by[k]))
                    cur = 'B';
                if ((i == sx[k]) && (j == sy[k]))
                    cur = 'S';

                dist = abs(sx[k] - bx[k]) + abs(sy[k] - by[k]);
                if (((abs(i - sx[k]) + abs(j - sy[k])) <= dist) && cur == '.')
                {
                    cur = '#';
                }
            }
            if (cur == '.' && i > 0 && j > 0 && i < size && j < size)
                printf("Out: %d %d \n", i, j);
        }

        for (int alld = 0; alld < di; alld++)
        {
            int i = sx[s] + di - alld;
            int j = sy[s] + alld;

            cur = '.';
            for (int k = 0; k < it; k++)
            {
                if ((i == bx[k]) && (j == by[k]))
                    cur = 'B';
                if ((i == sx[k]) && (j == sy[k]))
                    cur = 'S';

                dist = abs(sx[k] - bx[k]) + abs(sy[k] - by[k]);
                if (((abs(i - sx[k]) + abs(j - sy[k])) <= dist) && cur == '.')
                {
                    cur = '#';
                }
            }
            if (cur == '.' && i > 0 && j > 0 && i < size && j < size)
                printf("Out: %d %d \n", i, j);
        }

        for (int alld = 0; alld < di; alld++)
        {
            int i = sx[s] - alld;
            int j = sy[s] + di - alld;

            cur = '.';
            for (int k = 0; k < it; k++)
            {
                if ((i == bx[k]) && (j == by[k]))
                    cur = 'B';
                if ((i == sx[k]) && (j == sy[k]))
                    cur = 'S';

                dist = abs(sx[k] - bx[k]) + abs(sy[k] - by[k]);
                if (((abs(i - sx[k]) + abs(j - sy[k])) <= dist) && cur == '.')
                {
                    cur = '#';
                }
            }
            if (cur == '.' && i > 0 && j > 0 && i < size && j < size)
                printf("Out: %d %d \n", i, j);
        }
        printf("%ld \n", (long)3120101 * (long)4000000 + (long)2634249);
    }
}