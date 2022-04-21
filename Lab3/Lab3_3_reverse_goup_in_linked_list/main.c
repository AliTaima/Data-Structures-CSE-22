#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*header, *last;
struct single_node
{
    int data;
    struct node *next;
}*head;
void CreatelList(int n);
void traverseList(struct node *header);
void traverseListSingle(struct single_node *header);
//void reverseList(int l_group);
int main()
{
    int Q, k;
    scanf("%d", &Q);
    CreatelList(Q);
    //traverseList(header);
    printf("Please enter the length of the group: ");
    scanf("%d", &k);
    reverseList(k);
    //traverseList(head);
    traverseListSingle(head);
    return 0;
}

void CreatelList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {

        header = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        header->data = data;
        header->prev = NULL;
        header->next = NULL;

        last = header;


        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void traverseList(struct node *header)
{

    struct node *temp;
    printf("\nData in the list \n");
     if (header == NULL)
        printf("List is empty.");
    else
    {
        temp = header;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp ->data);
            temp = temp ->next;
        }
    }
}
void reverseList(int l_group)
{
    struct node  *temp, *temp2, *origin_temp;
    struct single_node *newNode, *tempNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp = header;
        for(int a = 1; a<=l_group;a++)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        temp2 = temp;
        temp2 = temp2->prev;
        printf("#################\n");
        //create new node from new elements
        newNode = (struct single_node *)malloc(sizeof(struct single_node));
        if(newNode != NULL)
        {
            newNode->data = temp2->data;
            newNode ->next = NULL;
            head = newNode;
            tempNode = newNode;
        }

        temp2 = temp2->prev;
        for(int a = 2; a<=l_group;a++)
        {
            newNode = (struct single_node *)malloc(sizeof(struct single_node));
            printf("%d\n", temp2->data);
            if(newNode == NULL)
                break;
            else
            {
                newNode->data = temp2->data;
                newNode ->next = NULL;
                tempNode->next = newNode;
                tempNode = tempNode->next;
            }
            temp2 = temp2->prev;
        }
        int end = 0;
        if(temp != NULL)
        {

            origin_temp = temp;
            for(int a = 1; a<=l_group;a++)
        {
            printf("%d\n", temp->data);
            if(temp ->next ==NULL)
            {
                end = 1;
                temp = origin_temp;
                break;
            }
            else
                temp = temp->next;
        }
        }
        if(end == 1)
        {
            temp2 = temp;
        while(temp2 != NULL)
        {
            newNode = (struct single_node *)malloc(sizeof(struct single_node));
            printf("%d\n", temp2->data);
            if(newNode == NULL)
                break;
            else
            {
                newNode->data = temp2->data;
                newNode ->next = NULL;
                tempNode->next = newNode;
                tempNode = tempNode->next;
            }
            temp2 = temp2->next;
        }
        }
        else
        {
            temp2 = temp2->prev;
        for(int a = 1; a<=l_group;a++)
        {
            newNode = (struct single_node *)malloc(sizeof(struct single_node));
            printf("%d\n", temp2->data);
            if(newNode == NULL)
                break;
            else
            {
                newNode->data = temp2->data;
                newNode ->next = NULL;
                tempNode->next = newNode;
                tempNode = tempNode->next;
            }
            temp2 = temp2->prev;
        }
        }





    }
}
void traverseListSingle(struct single_node *header)
{

    struct single_node *temp;
    printf("\nData in the list \n");
     if (header == NULL)
        printf("List is empty.");
    else
    {
        temp = header;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp ->data);
            temp = temp ->next;
        }
    }
}
