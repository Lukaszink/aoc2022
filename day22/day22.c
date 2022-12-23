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
    FILE *fp = fopen("in22.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v1(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    char tmp = 0;
    int lines = 200;
    int right = 500;

    char dp[250][500];
    for (int i = 0; i < 250; i++)
        for (int j = 0; j < 500; j++)
            dp[i][j] = ' ';

    int i = 0;
    int j = 0;

    for (int line = 0; line < lines; line++)
    {
        fscanf(f, "%c", &tmp);
        while (tmp != '\n')
        {
            dp[i][j] = tmp;
            j++;
            fscanf(f, "%c", &tmp);
        }
        j = 0;
        i++;
    }
    fscanf(f, "\n");

    int curx = 0;
    int cury = 0;
    int rot = 0;
    while (dp[cury][curx] == ' ')
        curx++;

    fscanf(f, "%c", &tmp);
    int dist = 0;
    while (tmp != 'E')
    {
        if (tmp >= '0' && tmp <= '9')
        {
            dist = dist * 10 + ctoint(tmp);
            printf("Cur dist: %d\n", dist);
        }
        else
        {
            switch (rot)
            {
            case 0:
                while (dist > 0)
                {
                    int tmpx = curx + 1;
                    if (dp[cury][tmpx] == ' ')
                    {
                        tmpx = 0;
                        while (dp[cury][tmpx] == ' ')
                        {
                            tmpx++;
                            // printf("Upto :%d %d\n", cury, tmpx);
                        }
                    }
                    if (dp[cury][tmpx] == '#')
                    {
                        printf("hit a wall\n");
                        dist = 0;
                        break;
                    }
                    dist--;
                    curx = tmpx;
                    printf("Move right to %d %d\n", cury, curx);
                    dp[cury][curx] = '>';
                }
                break;

            case 1:

                while (dist > 0)
                {
                    int tmpy = cury + 1;
                    if (dp[tmpy][curx] == ' ')
                    {
                        tmpy = 0;
                        while (dp[tmpy][curx] == ' ')
                            tmpy++;
                    }
                    if (dp[tmpy][curx] == '#')
                    {
                        printf("hit a wall\n");
                        dist = 0;
                        break;
                    }
                    dist--;
                    cury = tmpy;
                    printf("Move down to %d %d\n", cury, curx);
                    dp[cury][curx] = '|';
                }
                break;

            case 2:
                while (dist > 0)
                {
                    int tmpx = curx - 1;
                    if (tmpx == -1 || dp[cury][tmpx] == ' ')
                    {
                        tmpx = right - 1;
                        while (dp[cury][tmpx] == ' ')
                            tmpx--;
                    }
                    if (dp[cury][tmpx] == '#')
                    {
                        printf("hit a wall\n");
                        dist = 0;
                        break;
                    }
                    dist--;
                    curx = tmpx;
                    dp[cury][curx] = '<';
                    printf("Move left to %d %d\n", cury, curx);
                }
                break;

            case 3:

                while (dist > 0)
                {
                    int tmpy = cury - 1;
                    if (tmpy == -1 || dp[tmpy][curx] == ' ')
                    {
                        tmpy = lines - 1;
                        while (dp[tmpy][curx] == ' ')
                            tmpy--;
                    }
                    if (dp[tmpy][curx] == '#')
                    {
                        printf("hit a wall\n");
                        dist = 0;
                        break;
                    }
                    dist--;
                    cury = tmpy;
                    printf("Move up to %d %d\n", cury, curx);
                    dp[cury][curx] = '^';
                }
                break;
            default:
                break;
            }

            if (tmp == 'R')
            {
                rot++;
                rot = rot % 4;
                printf("rotate right, new dir %d \n", rot);
            }
            if (tmp == 'L')
            {
                printf("try left\n");
                rot--;
                rot = (rot < 0) ? rot + 4 : rot;
                printf("rotate left, new dir %d \n", rot);
            }
            if (tmp == '\n')
            {
                tmp = 'E';
            }
        }
        fscanf(f, "%c", &tmp);
    }
    for (int x = 0; x < 210; x++)
    {
        for (int y = 0; y < 500; y++)
        {
            printf("%c", dp[x][y]);
        }
        printf("\n");
    }
    printf("Out: X:%d Y:%d R:%d Res:%d", curx, cury, rot, 1000 * (cury + 1) + 4 * (curx + 1) + rot);
}

void v2(FILE *f)
{
}