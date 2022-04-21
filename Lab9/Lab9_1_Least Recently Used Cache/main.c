#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Creating the double linked list
struct doublelinkedlist
{
    int val;
    int key;
    struct doublelinkedlist *next;
    struct doublelinkedlist *prev;
};

// Creating three lists and make them global to save use them in any function and save memory in case of temp(because I use it in many functions)
struct doublelinkedlist *head;
struct doublelinkedlist *tail;
struct doublelinkedlist *temp;

// Function to add a new node
int AddNode(int key, int value)
{

    if (head == NULL)
    {
        head = (struct doublelinkedlist *)malloc(sizeof(struct doublelinkedlist));

        if (head == NULL)
        {
            printf("Error\n");
        }

        head->val = value;
        head->key = key;
        tail = head;
        head->prev = NULL;
    }
    else
    {

        temp = tail;
        tail->next = (struct doublelinkedlist *)malloc(sizeof(struct doublelinkedlist));

        if (tail->next == NULL)
        {
            printf("Error\n");
        }

        tail->next->val = value;
        tail->next->key = key;
        tail = tail->next;
        tail->prev = temp;
    }
    tail->next = NULL;

    return 0;
}

void insertAtHead(int key, int value)
{
    struct doublelinkedlist *newNode = (struct doublelinkedlist *)malloc(sizeof(struct doublelinkedlist));
    newNode->val = value;
    newNode->key = key;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    // delete last node
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}
void put(int key, int value)
{
    /*
        This function search the elements to show the new element present in the list or not, and if not present put the element at the head and shift other
        values to the right
    */
    if (head == NULL)
    {
        printf("Error\n");
    }

    temp = head;

    // Traverse Double Linked List.
    while (temp != NULL)
    {
        // If value in list matches with given value.
        if (temp->key == key)
        {
            // Shift all values to the right before found the value .
            while (temp != head)
            {
                temp->key = temp->prev->key;
                temp->val = temp->prev->val;
                temp = temp->prev;
            }

            // Place the found value at the head.
            head->key = key;
            head->val = value;
            return;
        }

        // Keep iterating the loop.
        temp = temp->next;
    }

    // For new elements that are not in the list
    // create new node and put it in front of head
    insertAtHead(key, value);

    return;
}

void createCache(int number)
{
    /*
        This function initialize all the elements in the cache capacity with zeros (their values and keys)
    */
    static int i = 0;
    for (i = 0; i < number; i += 1)
    {
        AddNode(0, 0);
    }
}

void get(int key)
{
    /*
        this function get the element that its key equal to the key that search for and print the its corresponding value
    */
    if (head == NULL)
    {
        printf("Not Found\n");
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("%d\n", temp->val);
            return;
        }

        // Keep iterating
        temp = temp->next;
    }
    printf("Not Found\n");
}

int main(void)
{

    int p, c, operation;
    scanf("%d%d", &p, &c);

    createCache(c);
    int a;
    int key, value;
    for (a = 0; a < p; a++)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case (1):
            scanf("%d%d", &key, &value);
            if (c == 0)
            {
                printf("Error\n");
                break;
            }
            put(key, value);
            break;
        case (2):
            scanf("%d", &key);
            if (c == 0)
            {
                printf("Not Found\n");
                break;
            }
            get(key);
            break;
        default:
            printf("Error\n");
            break;
        }
    }

    return 0;
}
