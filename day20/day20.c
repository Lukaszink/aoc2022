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
    FILE *fp = fopen("in20.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    int pos[6000];
    int init[6000];

    int mapvalues[20000];

    int cnt = 0;
    while (fscanf(f, "%d\n", &pos[cnt]) > 0)
    {
        printf("RI %d: %d \n", cnt, pos[cnt]);
        init[cnt] = pos[cnt];
        mapvalues[pos[cnt]] = cnt;
        cnt++;
    }
    int nrothers = cnt - 1;

    for (int x = 0; x < nrothers + 1; x++)
    {
        printf("%d, ", pos[x]);
    }
    printf("\n");

    for (int it = 0; it <= nrothers; it++)
    {
        int cur = init[it];
        int val = cur;
        // find nr
        int i = mapvalues[10000 + pos[i]];

        // prepare number
        while (cur < 0)
            cur += nrothers;

        cur = cur % nrothers;
        // move
        if (i + cur <= nrothers)
        {

            printf("Move %d-th pos: %d right by: %d\n", i, val, cur);
            for (int j = i; j < cur + i; j++)
            {
                pos[j] = pos[j + 1];
                mapvalues[10000 + pos[j + 1]] = j;
            }
            pos[i + cur] = val;
            mapvalues[10000 + val] = i + cur;
        }
        else
        {
            printf("Move %d-th pos: %d left by: %d\n", i, val, cur - nrothers);
            for (int j = i; j >= (i + cur - nrothers + 1); j--)
            {
                pos[j] = pos[j - 1];
                mapvalues[10000 + pos[j - 1]] = j;
            }
            pos[(i + cur - nrothers)] = val;
            mapvalues[10000 + val] = i + cur - nrothers;
        }
        // for (int x = 0; x < nrothers + 1; x++)
        // {
        //     printf("%d, ", pos[x]);
        // }
        // printf("\n");
    }
    int loczero = mapvalues[10000];
    printf("Out: %d %d %d %d\n", loczero, pos[1000 + loczero], pos[2000 + loczero], pos[3000 + loczero]);
    printf("%d\n", pos[1000 + loczero] + pos[2000 + loczero] + pos[3000 + loczero]);
}

void v2(FILE *f)
{
}