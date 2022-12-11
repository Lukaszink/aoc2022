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
    FILE *fp = fopen("in4.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    v2(fp);
    // v2(fp);
}

void v1(FILE *f)
{
    int l1;
    int u1;
    int l2;
    int u2;
    int sum = 0;
    while (fscanf(f, "%d-%d,%d-%d", &l1, &u1, &l2, &u2) > 0)
    {
        if ((l1 <= l2 && u1 >= u2) || (l1 >= l2 && u1 <= u2))
            sum++;
    }
    printf("SUM: %d \n", sum);
}

void v2(FILE *f)
{
    int l1;
    int u1;
    int l2;
    int u2;
    int sum = 0;
    while (fscanf(f, "%d-%d,%d-%d", &l1, &u1, &l2, &u2) > 0)
    {
        if ((l1 >= l2 && l1 <= u2) || (l2 >= l1 && l2 <= u1))

            sum++;
    }
    printf("SUM: %d \n", sum);
}