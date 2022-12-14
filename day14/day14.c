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
    FILE *fp = fopen("in14.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char dp[900][200];
    for (int i = 0; i < 900; i++)
        for (int j = 0; j < 200; j++)
            dp[i][j] = '.';
    char tmp = ' ';
    int x1;
    int y1;
    int x2;
    int y2;
    fscanf(f, "%d,%d", &x1, &y1);
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp == '\n')
        {
            fscanf(f, "%d,%d ", &x1, &y1);
        }
        fscanf(f, "-> ");
        fscanf(f, "%d,%d", &x2, &y2);

        printf("-> %d %d  %d %d\n", x1, y1, x2, y2);

        if (x1 == x2 && y1 < y2)
        {
            int ytmp = y1;
            while (ytmp <= y2)
            {
                dp[x1][ytmp] = '#';
                ytmp++;
            }
        }
        if (x1 == x2 && y1 > y2)
        {
            int ytmp = y2;
            while (ytmp <= y1)
            {
                dp[x1][ytmp] = '#';
                ytmp++;
            }
        }
        if (y1 == y2 && x1 < x2)
        {
            int xtmp = x1;
            while (xtmp <= x2)
            {
                dp[xtmp][y1] = '#';
                xtmp++;
            }
        }
        if (y1 == y2 && x1 > x2)
        {
            int xtmp = x2;
            while (xtmp <= x1)
            {
                dp[xtmp][y1] = '#';
                xtmp++;
            }
        }
        x1 = x2;
        y1 = y2;
    }

    int cnd = 1;
    int count = 0;

    char dptmp[900][200];

    while (1)
    {
        for (int i = 0; i < 900; i++)
            for (int j = 0; j < 200; j++)
                dptmp[i][j] = dp[i][j];

        int x = 500;
        int y = 0;

        while (((dp[x - 1][y + 1] == '.') || (dp[x][y + 1] == '.') || (dp[x + 1][y + 1] == '.')) && y < 190)
        {
            if (dp[x][y + 1] == '.')
            {
                y++;
            }
            else
            {
                if (dp[x - 1][y + 1] == '.')
                {
                    x--;
                    y++;
                }
                else
                {
                    if (dp[x + 1][y + 1] == '.')
                    {
                        x++;
                        y++;
                    }
                }
            }
        }
        if (y < 190)
            dp[x][y] = 'o';
        cnd = 1;

        for (int i = 0; i < 900; i++)
            for (int j = 0; j < 200; j++)
                if (dptmp[i][j] != dp[i][j])
                {
                    cnd = 0;
                }
        if (cnd)
        {
            for (int j = 0; j < 200; j++)
            {
                for (int i = 300; i < 600; i++)
                    printf("%c ", dp[i][j]);

                printf("\n");
            }
            printf("\n");

            printf("Out %d\n", count);

            break;
        }

        count++;
    }
}

void v2(FILE *f)
{
    char dp[900][200];
    for (int i = 0; i < 900; i++)
        for (int j = 0; j < 200; j++)
            dp[i][j] = '.';
    char tmp = ' ';
    int x1;
    int y1;
    int x2;
    int y2;

    int h = 0;
    fscanf(f, "%d,%d", &x1, &y1);
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp == '\n')
        {
            fscanf(f, "%d,%d ", &x1, &y1);
        }
        fscanf(f, "-> ");
        fscanf(f, "%d,%d", &x2, &y2);

        printf("-> %d %d  %d %d\n", x1, y1, x2, y2);

        if (x1 == x2 && y1 < y2)
        {
            int ytmp = y1;
            while (ytmp <= y2)
            {
                dp[x1][ytmp] = '#';
                ytmp++;
            }
        }
        if (x1 == x2 && y1 > y2)
        {
            int ytmp = y2;
            while (ytmp <= y1)
            {
                dp[x1][ytmp] = '#';
                ytmp++;
            }
        }
        if (y1 == y2 && x1 < x2)
        {
            int xtmp = x1;
            while (xtmp <= x2)
            {
                dp[xtmp][y1] = '#';
                xtmp++;
            }
        }
        if (y1 == y2 && x1 > x2)
        {
            int xtmp = x2;
            while (xtmp <= x1)
            {
                dp[xtmp][y1] = '#';
                xtmp++;
            }
        }
        if (h < y1)
            h = y1;
        if (h < y2)
            h = y2;
        x1 = x2;
        y1 = y2;
    }

    int cnd = 1;
    int count = 0;

    for (int j = 0; j < 900; j++)
    {
        dp[j][h + 2] = '#';
    }

    char dptmp[900][200];

    while (1)
    {
        for (int i = 0; i < 900; i++)
            for (int j = 0; j < 200; j++)
                dptmp[i][j] = dp[i][j];

        int x = 500;
        int y = 0;

        while (((dp[x - 1][y + 1] == '.') || (dp[x][y + 1] == '.') || (dp[x + 1][y + 1] == '.')) && y < 190)
        {
            if (dp[x][y + 1] == '.')
            {
                y++;
            }
            else
            {
                if (dp[x - 1][y + 1] == '.')
                {
                    x--;
                    y++;
                }
                else
                {
                    if (dp[x + 1][y + 1] == '.')
                    {
                        x++;
                        y++;
                    }
                }
            }
        }
        if (y < 190)
            dp[x][y] = '#';

        cnd = 1;

        for (int i = 0; i < 900; i++)
            for (int j = 0; j < 200; j++)
                if (dptmp[i][j] != dp[i][j])
                {
                    cnd = 0;
                }
        if (cnd)
        {
            for (int j = 0; j < 200; j++)
            {
                for (int i = 300; i < 700; i++)
                    printf("%c ", dp[i][j]);

                printf("\n");
            }
            printf("\n");

            printf("Out %d\n", count);

            break;
        }

        count++;
    }
}
