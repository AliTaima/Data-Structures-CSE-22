#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
}*header;


int getFirstDigit(struct node *header);
void CreatelList(int num);
bool isPalindrome(int n);
int main()
{
    double n; //I make n as double integer to check the constrains with right way
    scanf("%lf", &n);

    if(isPalindrome((int) n))  //I covert the type, as isPalindrome take an integer
        printf("YES");
    else
        printf("NO");

    return 0;
}
void CreatelList(int num)
{
    /*
    - Here I create a single linked list from the digits of
       the number I enter
    - The order of digits will be reversed from the original number
    so the header will contain the last digit of the number

    */
    struct node *newNode, *temp = 0;
    int digit;  //digit--> for store each digit of the number
    //A node is created by allocating memory
    newNode = (struct node *) malloc(sizeof(struct node));
    if(newNode !=NULL)
    {
        digit = num % 10;  //get the last digit of the number
        num /= 10;  //delete last digit of the number
        newNode ->data = digit;
        newNode ->next = NULL;
        header = newNode;
        temp = newNode;
    }

    while(num>0)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
            break;
        else
        {
            digit = num % 10;
            num /= 10;
            newNode ->data = digit;
            newNode ->next = NULL;
            temp ->next = newNode;
            temp = temp ->next;
        }

    }
}

int getFirstDigit(struct node *header)
{
    /*
    - In this function I get the last element of the linked list
    that consider my first digit of the input number
    */
    int first_digit = 0;
    struct node *temp;

    if(header !=NULL)
        {
        temp = header;

        while(temp->next != NULL)  //traverse to the last node
            temp = temp ->next;

        first_digit = temp ->data;
    }

    return first_digit;
}

bool isPalindrome(int n)
{
    /*
    This function check the number is Palindrome or not
    */
    if(n<=(pow(2,31)-1) && n>=(-pow(2,31)))  //check the constrains
    {
        CreatelList(n);

        int first_digit = 0, last_digit;

        last_digit = header ->data;

        first_digit = getFirstDigit(header);

        if (first_digit == last_digit)
            return true;
        else
            return false;
    }
    else
        return false;
}

