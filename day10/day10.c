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
    FILE *fp = fopen("in10.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char tmp = 0;
    int state[1000];
    char crt[1000];

    state[1] = 1;
    int cycle = 1;
    int cur = 0;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp == 'n')
        {
            fscanf(f, "%*c%*c%*c\n");
            cycle++;
            state[cycle] = state[cycle - 1];
        }
        else
        {
            // ADD
            fscanf(f, "%*c%*c%*c%*c%d\n", &cur);
            cycle++;
            state[cycle] = state[cycle - 1];
            cycle++;
            state[cycle] = state[cycle - 1] + cur;
        }
    }
    int outp = 0;
    for (int i = 20; i <= 220; i += 40)
    {
        printf("Loop %d %d \n", i, state[i]);
        outp += state[i] * i;
    }
    printf("Out: %d\n", outp);

    for (int i = 0; i < 40; i++)
    {

        if (state[i + 1] >= i - 1 && state[i + 1] <= i + 1)
        {
            crt[i] = '#';
        }
        else
        {
            crt[i] = '.';
        }

        if (state[i + 41] >= i - 1 && state[i + 41] <= i + 1)
        {
            crt[i + 41] = '#';
        }
        else
        {
            crt[i + 41] = '.';
        }

        if (state[i + 81] >= i - 1 && state[i + 81] <= i + 1)
        {
            crt[i + 81] = '#';
        }
        else
        {
            crt[i + 81] = '.';
        }

        if (state[i + 121] >= i - 1 && state[i + 121] <= i + 1)
        {
            crt[i + 121] = '#';
        }
        else
        {
            crt[i + 121] = '.';
        }

        if (state[i + 161] >= i - 1 && state[i + 161] <= i + 1)
        {
            crt[i + 161] = '#';
        }
        else
        {
            crt[i + 161] = '.';
        }

        if (state[i + 201] >= i - 1 && state[i + 201] <= i + 1)
        {
            crt[i + 201] = '#';
        }
        else
        {
            crt[i + 201] = '.';
        }
    }

    for (int x = 0; x < 241; x++)
    {
        if (x % 40 == 1 && x != 1)
            printf("\n");
        printf("%c", crt[x]);
    }
    printf("\n");
}
