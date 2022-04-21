#include<stdio.h>
#include<stdlib.h>


//Stack node and the whole stack
typedef struct node
{
    int data;
    struct node* next;
}stackNode;

typedef struct stack
{
    stackNode* top;
}stack;
//stack operations
void createStack(stack* ps)
{
    ps->top = NULL;
}

void push(int data, stack* ps)
{
    stackNode* pn = (stackNode*)malloc(sizeof(stackNode));
    pn->data = data;
    pn->next = ps->top;
    ps->top = pn;
}

int pop(stack* ps)
{
    int value;
    stackNode* temp;

    value = ps->top->data;
    temp = ps->top;

    ps->top = ps->top->next;

    free(temp);

    return value;
}

int stackEmpty(stack* ps)
{
    if (ps->top == NULL)
        return 1;
    else
        return 0;
}
int vert;   //global to use it in main and function
int isBipartite(int graph[vert][vert], int src)
{
    /*
        this function check if the graph nodes satisfies the whole bipartite conditions or not
    */

    int arr[vert];
    for (int a = 0; a < vert; ++a)
        arr[a] = -1;

    arr[src] = 1;

    stack S;
    createStack(&S);
    push(src, &S);

    while (!stackEmpty(&S))
    {
        int u, v;
        u = pop(&S);

        if (graph[u][u] == 1)  //check self loop
            return 0;

        for (v = 0; v < vert; ++v)
        {
            if (graph[u][v] && arr[v] == -1)
            {
                arr[v] = 1 - arr[u];
                push(v, &S);
            }

            else if (graph[u][v] && arr[v] == arr[u])
                return 0;
        }
    }

    return 1;
}


int main()
{
    int a, b, E, R, C;
    scanf("%d  %d", &vert, &E);

    int graph[vert][vert];
    //initialize array with zeros
    for (a = 0; a < vert; a++)
    {
        for (b = 0; b < vert; b++)
            graph[a][b] = 0;
    }

    for (a = 0; a < E; a++)
    {
        scanf("%d  %d", &R, &C);
        graph[R - 1][C - 1] = 1;
    }

    if (isBipartite(graph, 0))
        printf("Yes");

    else
        printf("No");

    return 0;
}
