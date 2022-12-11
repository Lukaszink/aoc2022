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
    FILE *fp = fopen("in2.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // v1(fp);
    v2(fp);
}

void v1(FILE *f)
{
    int sum = 0;
    char c1;
    char c2;
    while (fscanf(f, "%c %c\n", &c1, &c2) > 0)
    {
        printf("readin %c %c\n", c1, c2);
        if (c1 == 'A' && c2 == 'X')
            sum += 3;
        if (c1 == 'A' && c2 == 'Y')
            sum += 6;
        if (c1 == 'A' && c2 == 'Z')
            sum += 0;
        if (c1 == 'B' && c2 == 'X')
            sum += 0;
        if (c1 == 'B' && c2 == 'Y')
            sum += 3;
        if (c1 == 'B' && c2 == 'Z')
            sum += 6;
        if (c1 == 'C' && c2 == 'X')
            sum += 6;
        if (c1 == 'C' && c2 == 'Y')
            sum += 0;
        if (c1 == 'C' && c2 == 'Z')
            sum += 3;

        sum += (c2 - 'W');
    }

    printf("SUM: %d\n", sum);
}

void v2(FILE *f)
{
    int sum = 0;
    char c1;
    char c2;
    while (fscanf(f, "%c %c\n", &c1, &c2) > 0)
    {
        printf("readin %c %c\n", c1, c2);
        if (c1 == 'A' && c2 == 'X')
            sum += 3;
        if (c1 == 'A' && c2 == 'Y')
            sum += 4;
        if (c1 == 'A' && c2 == 'Z')
            sum += 8;
        if (c1 == 'B' && c2 == 'X')
            sum += 1;
        if (c1 == 'B' && c2 == 'Y')
            sum += 5;
        if (c1 == 'B' && c2 == 'Z')
            sum += 9;
        if (c1 == 'C' && c2 == 'X')
            sum += 2;
        if (c1 == 'C' && c2 == 'Y')
            sum += 6;
        if (c1 == 'C' && c2 == 'Z')
            sum += 7;
    }

    printf("SUM: %d\n", sum);
}