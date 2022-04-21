#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}stackNode;
typedef struct Stack
{
    //while working I found that I need variable to indicate the current size of the stack, so I make this as stuct of the node I make previous
    stackNode *top;
    int size;
}stack;

void initializeStack(stack *ps);
void push(stack *ps, int );
int pop(stack *ps);
int isempty(stack *ps);
int isNumber(char c );
int operation(char c, int operator1, int operator2);
int postfix(char str[], stack s);
int main()
{
    stack s;
    char str[10000];
    initializeStack(&s);
    scanf("%[^\n]s",str);
    int result = postfix(str, s);
    if(s.size !=0)
        printf("Not Valid");
    else
        printf("%d", result);
    return 0;
}
void initializeStack(stack *ps)
{
    //this function initialize the stack
    ps->top = NULL;
    ps->size = 0;
}
void push(stack *ps, int e)
{
    //this function push a new node to the stack
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->value = e;
    newNode->next = ps->top;
    ps->top = newNode;
    ps->size++;
}

int pop(stack *ps)
{
    //This function remove an element from the stack (from the top) and return the poped value to use it as I want
    int pop_num=0 ;
    stackNode *temp;
    if (ps->size != 0)
    {
        pop_num = ps->top->value;
        temp = ps->top;
        ps->top = ps->top->next;
        free(temp);
        ps->size--;
    }
    return pop_num;
}

int isNumber(char c )
{
    //This function check if the string I insert is a number from 0 to 9 or not
    //to make another action if not
    if (c >='0' && c<= '9')
        return 1;
    else
        return 0;
}

int operation(char c, int operator1, int operator2)
{
    //This function check the type of operation and make the operation according to that
    switch(c)
    {
    case '+':
        return(operator1 + operator2);
    case '-':
        return(operator1 - operator2);
    case '*':
        return(operator1 * operator2);
    case '/':
        return(operator1 / operator2);
    case '%':
        return(operator1 % operator2);
    default:
        printf("Not Valid");
        exit(0);
    }
}
int postfix(char str[], stack s)
{
    int a;
    char c;
    int operator1, operator2, result;
    for (a = 0 ; (c=str[a]) != '\0' ; a++)
    {

        if(isNumber(c))
            push(&s, (int)(c - '0'));//convert char to int
        else
        {
            if(s.size <2)
            {
                printf("Not Valid");
                exit(0);
            }
            operator2 = pop(&s);
            operator1 = pop(&s);
            result = operation(c, operator1, operator2);
            push(&s, result);
        }
    }
    return pop(&s);

}
