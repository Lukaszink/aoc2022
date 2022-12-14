#include <stdio.h>
#include <stdlib.h>
void v1(FILE *, FILE *);
void v2(FILE *);
int rec(FILE *, FILE *, int, char, int);
int isone(FILE *);
int getfirst(FILE *);

int ctoint(char a)
{
    return (a - '0');
}

int main()
{
    FILE *fp = fopen("in13.txt", "r");
    FILE *fp2 = fopen("in13.txt", "r");

    v1(fp, fp2);
    // v2(fp);
}

void v1(FILE *f1, FILE *f2)
{
    int sum = 0;
    char tmp = ' ';
    while (tmp != '\n')
    {
        fscanf(f2, "%c", &tmp);
    }
    for (int i = 0; i < 150; i++)
    {

        fscanf(f1, "%c", &tmp); // jump over first [
        fscanf(f2, "%c", &tmp);

        int res = rec(f1, f2, 0, ' ', 0);
        printf("result: %d\n\n\n", res);
        sum += (i + 1) * res;

        tmp = ' ';
        while (tmp != '\n')
            fscanf(f1, "%c", &tmp);

        tmp = ' ';
        while (tmp != '\n')
            fscanf(f2, "%c", &tmp);
        tmp = ' ';

        // advance two lines
        while (tmp != '\n')
        {
            fscanf(f1, "%c", &tmp);
        }
        tmp = ' ';
        while (tmp != '\n')
        {
            fscanf(f2, "%c", &tmp);
        }

        tmp = ' ';

        // advance two lines
        while (tmp != '\n')
        {
            fscanf(f1, "%c", &tmp);
        }
        tmp = ' ';
        while (tmp != '\n')
        {
            fscanf(f2, "%c", &tmp);
        }
    }
    printf("Sum: %d\n", sum);
}

int rec(FILE *f1, FILE *f2, int of, char in, int reuse)
{
    char curl;
    char curr;

    while (1)
    {
        if (reuse == 1)
        {
            curl = in;
        }
        else
            fscanf(f1, "%c", &curl);

        if (reuse == 2)
        {
            curr = in;
        }
        else
            fscanf(f2, "%c", &curr);

        // both int
        int lnr = 0;
        int rnr = 0;
        if ((curl >= '0' && curl <= '9') && (curr >= '0' && curr <= '9'))
        {
            printf("Int Int");
            while (curl >= '0' && curl <= '9')
            {
                lnr = lnr * 10 + ctoint(curl);
                fscanf(f1, "%c", &curl);
            }
            while (curr >= '0' && curr <= '9')
            {
                rnr = rnr * 10 + ctoint(curr);
                fscanf(f2, "%c", &curr);
            }
            printf(" -> cmp %d %d\n", lnr, rnr);
            // printf("---%c\n", curl);
            if (lnr > rnr)
                return 0;
            if (lnr < rnr)
                return 1;
            lnr = 0;
            rnr = 0;
        }
        int ret = 100;

        if (curl == '[' && curr == '[')
        {

            printf("list list\n");
            ret = rec(f1, f2, 0, ' ', 0);
        }

        // left is int right is list
        if ((curl >= '0' && curl <= '9') && (curr == '['))
        {
            printf("Int List\n");

            // advance right

            ret = rec(f1, f2, 10, curl, 1);
        }

        // left is list, right is int
        if ((curl == '[') && (curr >= '0' && curr <= '9'))
        {
            printf("list Int\n");

            // advance left
            // fscanf(f1, "%c", &curl);

            ret = rec(f1, f2, -10, curr, 2);
        }

        // check ret
        if (ret != 100)
        {
            if (ret == 12)
            {
                ret -= 10;
                fscanf(f1, "%c", &curl);
            }
            if (ret == -8)
            {
                ret += 10;
                fscanf(f2, "%c", &curr);
            }
            if (ret == 0)
                return 0;
            if (ret == 1)
                return 1;
        }

        if (reuse == 1 && (curl == ',' || curl == ']'))
        {
            printf("end of left bracket in int list\n");
            return 1;
        }

        if (reuse == 2 && (curr == ',' || curr == ']'))
        {
            printf("end of right side in List Int\n");
            return 0;
        }

        if (curl == ']' && curr == ']')
        {
            printf("no decision made here\n");
            return 2 + of;
        }

        if (curl == ']')
        {
            printf("Correct\n");
            return 1;
        }

        if (curr == ']')
        {
            printf("Incorrect: right side ended\n");
            return 0;
        }
    }
}
