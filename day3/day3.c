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
    FILE *fp = fopen("in3.txt", "r");
    FILE *fp2 = fopen("test.txt", "r");

    // v1(fp);
    // v1(fp2);
    v2(fp);
}

void v1(FILE *f)
{
    char tmp = 0;
    int l = 0;
    char arr[10000];
    int sum = 0;
    int br = 1;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {

            arr[l] = tmp;
            l++;
        }
        else
        {
            for (int i = 0; i < (l / 2); i++)
            {
                for (int j = 0; j < (l / 2); j++)
                {
                    if (arr[i] == arr[j + (l / 2)])
                    {
                        if (br && arr[i] >= 'A' && arr[i] <= 'Z')
                            sum += (arr[i] - 'A' + 27);

                        if (br && arr[i] >= 'a' && arr[i] <= 'z')
                            sum += (arr[i] - 'a' + 1);

                        printf("Common char : %c \n", arr[i]);
                        br = 0;
                    }
                }
            }
            l = 0;
            br = 1;
        }
    }
    printf("SUM %d \n", sum);
}

void v2(FILE *f)
{
    char tmp = 0;
    int iter = 0;
    int l1;
    int l2;
    int l3;
    char arr1[10000];
    char arr2[10000];
    char arr3[10000];
    int sum = 0;
    int br = 1;

    while (fscanf(f, "%c", &tmp) > 0)
    {
        if (tmp != '\n')
        {

            if (iter == 0)
            {
                arr1[l1] = tmp;
                l1++;
            }
            if (iter == 1)
            {
                arr2[l2] = tmp;
                l2++;
            }
            if (iter == 2)
            {
                arr3[l3] = tmp;
                l3++;
            }
        }
        else
        {
            if (iter != 2)
            {
                iter++;
            }
            else
            {
                for (int i = 0; i < l1; i++)
                {
                    for (int j = 0; j < l2; j++)
                    {
                        for (int k = 0; k < l3; k++)
                        {

                            if (arr1[i] == arr2[j] && arr1[i] == arr3[k])
                            {
                                if (br && arr1[i] >= 'A' && arr1[i] <= 'Z')
                                    sum += (arr1[i] - 'A' + 27);

                                if (br && arr1[i] >= 'a' && arr1[i] <= 'z')
                                    sum += (arr1[i] - 'a' + 1);

                                printf("Common char : %c \n", arr1[i]);
                                br = 0;
                            }
                        }
                    }
                }
                br = 1;
                l1 = 0;
                l2 = 0;
                l3 = 0;
                iter = 0;
            }
        }
    }
    printf("SUM %d \n", sum);
}