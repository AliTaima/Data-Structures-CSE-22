#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct lifo
{
    /*
    In this stack we consider the top at the last element that we make a push for it
    that means, if we want to push a new element we should increment the top by one first
    */
    int top;
    int entry[MAXSIZE];
}stack;

//Declaration of the functions
void initializeStack(stack *ps);
void push(int element, stack *ps);
void pop(stack *ps);
int getMinimum(stack *ps);
int main()
{
    stack s;
    initializeStack(&s);
    int E, Q, a, operation;  //Q --> number of operations , a--> the counter of for loop, E-->element that will push
    // operation --> variable that will store the number of operation

    //Take the number of operations from the user
    scanf("%d", &Q);
    for(a = 0; a<Q; a++)
    {
        scanf("%d", &operation);
        switch(operation)
        {
        case 1:
            scanf("%d", &E);
            push(E, &s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            if(s.top == -1)
            {
                printf("Empty\n");
                break;
            }
            else
            {
                printf("%d\n", getMinimum(&s));
                break;
            }
        }
    }



    return 0;
}

void initializeStack(stack *ps)
{
    /*
    This function initialize my stack
    */
    ps ->top = -1;
}

void push(int element, stack *ps)
{
    /*
    This function push an element to the stack
    */
    if(ps ->top != MAXSIZE - 1)
    {
        ps->top ++;
        ps->entry[ps->top] = element;
    }

}

void pop(stack *ps)
{
    /*
    This function pop an element from the stack
    */
    if(ps ->top != -1)
        ps->top--;
}

int getMinimum(stack *ps)
{
    /*
    This function find the minimum element among the currents elements in the stack
    without change anything in the stack
    */
    int min = ps->entry[ps->top];  //define the min variable with first element in the stack
    int temp = ps->top -1;   //store the top in another element to save the stack as it
    int a;
    for(a = temp; a>-1; a--)
    {
        if (ps->entry[a] < min)
            min = ps->entry[a];
    }
    return min;
}

