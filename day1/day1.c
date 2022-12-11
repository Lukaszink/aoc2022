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
    FILE *fp = fopen("in1.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // v1(fp);
    v2(fp);
}

void v1(FILE *f)
{

    int curmax = 0;
    char tmp = 0;
    int aggregate = 0;
    int cur = 0;
    int isnewline = 1;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        printf("Char: %c \n", tmp);
        if (tmp != '\n')
        {
            isnewline = 0;
            cur = cur * 10 + ctoint(tmp);
        }
        else
        {
            if (isnewline)
            {
                if (aggregate > curmax)
                {
                    curmax = aggregate;
                    aggregate = 0;
                    cur = 0;
                }
                aggregate = 0;
                cur = 0;
            }
            else
            {
                printf("Addded cur: %d \n", cur);
                aggregate += cur;
                cur = 0;
                isnewline = 1;
            }
        }
    }
    printf("MAX:: %d \n", curmax);
}

void v2(FILE *f)
{

    int fst = 0;
    int snd = 0;
    int trd = 0;
    char tmp = 0;
    int aggregate = 0;
    int cur = 0;
    int isnewline = 1;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        printf("Char: %c \n", tmp);
        if (tmp != '\n')
        {
            isnewline = 0;
            cur = cur * 10 + ctoint(tmp);
        }
        else
        {
            if (isnewline)
            {
                if (aggregate > fst)
                {
                    trd = snd;
                    snd = fst;
                    fst = aggregate;
                }
                else if (aggregate > snd)
                {
                    trd = snd;
                    snd = aggregate;
                }
                else if (aggregate > trd)
                {
                    trd = aggregate;
                }
                aggregate = 0;
                cur = 0;
            }
            else
            {
                printf("Addded cur: %d \n", cur);
                aggregate += cur;
                cur = 0;
                isnewline = 1;
            }
        }
    }
    printf("MAX:: %d \n", fst + snd + trd);
}