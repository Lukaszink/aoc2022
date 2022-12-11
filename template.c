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

    v1(fp);
    // v2(fp);
}

// List in C
struct node
{
    int key;
    int data;
    struct node *next;
};

void insert(int ke, int dat, struct node *start)
{
    struct node *oldstart = start->next;
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->key = ke;
    ne->data = dat;
    ne->next = oldstart;
    start->next = ne;
}

int isempty(struct node *start)
{
    return (start->next == NULL);
}

struct node *getfirst(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
    return tmp;
}

int getfirstdata(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
    return tmp->data;
}

void removefirtst(struct node *start)
{
    struct node *tmp = start->next;
    start->next = tmp->next;
}

void printlist(struct node *start)
{
    printf("Print out list: \n");
    struct node *cur = start;
    if ((cur->next) != NULL)
    {
        cur = cur->next;
    }
    while ((cur->next) != NULL)
    {
        printf("%d %d\n", cur->key, cur->data);
        cur = cur->next;
    }
    printf("%d %d\n", cur->key, cur->data);
}





void v1(FILE *f)
{
    char tmp = 0;
    while (fscanf(f, "%c", &tmp) > 0)
    {
    }
}

void v2(FILE *f)
{
}