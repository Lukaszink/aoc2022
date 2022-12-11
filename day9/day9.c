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
    FILE *fp = fopen("in9.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char c = 0;
    int in = 0;
    int t[500][500];
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            t[i][j] = 0;

    int xh = 250;
    int xt = 250;
    int yh = 250;
    int yt = 250;

    while (fscanf(f, "%c %d\n", &c, &in) > 0)
    {

        for (int it = 0; it < in; it++)
        {
            if (c == 'U')
                yh--;
            if (c == 'D')
                yh++;
            if (c == 'L')
                xh--;
            if (c == 'R')
                xh++;

            if (xt == xh - 2)
            {
                xt++;
                yt = yh;
            }
            if (xt == xh + 2)
            {
                xt--;
                yt = yh;
            }
            if (yt == yh - 2)
            {
                yt++;
                xt = xh;
            }
            if (yt == yh + 2)
            {
                yt--;
                xt = xh;
            }

            // printf("PosH %d %d\n", xh, yh);
            // printf("PosT %d %d\n", xt, yt);

            t[xt][yt] = 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        {
            // printf("%d ", t[j][i]);
            sum += t[i][j];
        }
        // printf("\n");
    }
    printf("SUM: %d", sum);
}

void v2(FILE *f)
{
    {
        char c = 0;
        int in = 0;
        int t[500][500];
        for (int i = 0; i < 500; i++)
            for (int j = 0; j < 500; j++)
                t[i][j] = 0;

        int xs[10];
        int ys[10];

        for (int x = 0; x < 10; x++)
        {
            xs[x] = 250;
            ys[x] = 250;
        }

        while (fscanf(f, "%c %d\n", &c, &in) > 0)
        {

            for (int it = 0; it < in; it++)
            {
                if (c == 'U')
                    ys[0]--;
                if (c == 'D')
                    ys[0]++;
                if (c == 'L')
                    xs[0]--;
                if (c == 'R')
                    xs[0]++;

                for (int k = 0; k < 9; k++)
                {
                    int xt = xs[k + 1];
                    int yt = ys[k + 1];
                    int yh = ys[k];
                    int xh = xs[k];

                    // new
                    if ((xt == xh - 2) && (yt == yh - 2))
                    {
                        xt++;
                        yt++;
                    }

                    if ((xt == xh + 2) && (yt == yh + 2))
                    {
                        xt--;
                        yt--;
                    }

                    if ((xt == xh - 2) && (yt == yh + 2))
                    {
                        xt++;
                        yt--;
                    }

                    if ((xt == xh + 2) && (yt == yh - 2))
                    {
                        xt--;
                        yt++;
                    }

                    // old

                    if (xt == xh - 2)
                    {
                        xt++;
                        yt = yh;
                    }
                    if (xt == xh + 2)
                    {
                        xt--;
                        yt = yh;
                    }
                    if (yt == yh - 2)
                    {
                        yt++;
                        xt = xh;
                    }
                    if (yt == yh + 2)
                    {
                        yt--;
                        xt = xh;
                    }

                    ys[k + 1] = yt;
                    xs[k + 1] = xt;
                }

                // printf("PosH %d %d\n", xh, yh);
                // printf("PosT %d %d\n", xt, yt);

                t[xs[9]][ys[9]] = 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                // printf("%d ", t[j][i]);
                sum += t[i][j];
            }
            // printf("\n");
        }
        printf("SUM: %d", sum);
    }
}