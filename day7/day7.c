#include <stdio.h>
#include <stdlib.h>
void v1(FILE *);
void v2(FILE *);
int rec(char[2000][40], int);
int rec2(char[2000][40], int);

int globalsum2 = 500000000;
int globalsum = 0;

int ctoint(char a)
{
    return (a - '0');
}

int main()
{
    FILE *fp = fopen("in7.txt", "r");
    // FILE *fp2 = fopen("input2.txt", "r");

    // v1(fp);
    v2(fp);
}

void v1(FILE *f)
{

    char tmp = 0;

    char table[2000][40];

    int n = 0;
    int m = 0;

    // read into table
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {
            table[m][n] = tmp;
            n++;
        }
        else
        {
            table[m][n] = tmp;
            n = 0;
            m++;
        }
    }
    printf("\n");

    rec(table, 0);
    printf("Globalsum: %d", globalsum);
}

int rec(char table[2000][40], int inpos)
{
    int pos = inpos;
    int sum = 0; /// sum of

    int lvl = 0; // fixes same subdirectory name issue

    while (1)
    {
        if ((table[pos][2] == 'c') && (table[pos][5] != '.'))
        {
            // printf("cd into directory: %c\n", table[pos][5]);
            lvl++;
            int cnd = (lvl == 1); // is funct dir == cur dir name
            int offs = 4;
            while (((table[inpos][offs] != '\n') || (table[pos][offs + 1] != '\n')) && cnd)
            {
                cnd = table[inpos][offs] == table[pos][offs + 1];
                offs++;
            }
            if (cnd) // cd into dir that this funct was called on
            {
                printf("matched directory\n");
                pos = pos + 2;               // Jump over ls
                while (table[pos][0] != '$') // until the end of ls (listed items dont start with $)
                {
                    if (table[pos][0] >= '0' && table[pos][0] <= '9') // check if file or subdirectory
                    {
                        int i = 0;
                        int s = 0;
                        while (table[pos][i] >= '0' && table[pos][i] <= '9')
                        {
                            s = s * 10 + ctoint(table[pos][i]);
                            i++;
                        }
                        sum += s;
                        // printf("added size %d\n", s);
                        pos++;
                    }
                    else // subdirectory -> recursive call (add size of subdir to this dir)
                    {
                        // printf("rec call\n");
                        sum += rec(table, pos); // call function recursively on dir ...
                        pos++;
                    }
                }
                printf("total size of dir: %d\n", sum);
                if (sum <= 100000)
                {
                    globalsum += sum;
                }
                return sum;
            }
        }
        else
        {
            if ((table[pos][2] == 'c') && (table[pos][5] == '.'))
                lvl--;
        }
        pos++;

        // printf("next line\n");
    }
}

void v2(FILE *f)
{

    char tmp = 0;

    char table[2000][40];

    int n = 0;
    int m = 0;

    // read into table
    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {
            table[m][n] = tmp;
            n++;
        }
        else
        {
            table[m][n] = tmp;
            n = 0;
            m++;
        }
    }
    printf("\n");

    rec2(table, 0);
    printf("Globalsum2: %d", globalsum2);
}

int rec2(char table[2000][40], int inpos)
{
    int pos = inpos;
    int sum = 0; /// sum of
    int neededsize = -1 * ((70000000 - 48008081) - 30000000);

    int lvl = 0; // fixes same subdirectory name issue

    while (1)
    {
        if ((table[pos][2] == 'c') && (table[pos][5] != '.'))
        {
            // printf("cd into directory: %c\n", table[pos][5]);
            lvl++;
            int cnd = (lvl == 1); // is funct dir == cur dir name
            int offs = 4;
            while (((table[inpos][offs] != '\n') || (table[pos][offs + 1] != '\n')) && cnd)
            {
                cnd = table[inpos][offs] == table[pos][offs + 1];
                offs++;
            }
            if (cnd) // cd into dir that this funct was called on
            {
                printf("matched directory\n");
                pos = pos + 2;               // Jump over ls
                while (table[pos][0] != '$') // until the end of ls (listed items dont start with $)
                {
                    if (table[pos][0] >= '0' && table[pos][0] <= '9') // check if file or subdirectory
                    {
                        int i = 0;
                        int s = 0;
                        while (table[pos][i] >= '0' && table[pos][i] <= '9')
                        {
                            s = s * 10 + ctoint(table[pos][i]);
                            i++;
                        }
                        sum += s;
                        // printf("added size %d\n", s);
                        pos++;
                    }
                    else // subdirectory -> recursive call (add size of subdir to this dir)
                    {
                        // printf("rec call\n");
                        sum += rec2(table, pos); // call function recursively on dir ...
                        pos++;
                    }
                }
                printf("total size of dir: %d\n", sum);
                if (sum > neededsize && sum < globalsum2)
                {
                    globalsum2 = sum;
                }
                return sum;
            }
        }
        else
        {
            if ((table[pos][2] == 'c') && (table[pos][5] == '.'))
                lvl--;
        }
        pos++;

        // printf("next line\n");
    }
}
