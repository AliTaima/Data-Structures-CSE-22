#include <stdio.h>
#include <stdlib.h>
typedef struct queuenode
{
    int value;
    struct queuenode *next;
} queueNode;

typedef struct fifo
{
    queueNode *front;
    queueNode *rear;
    int size;
} queue;

void dispQueue(queue *pq);
void dequeue(queue *pq);
void enqueue(queue *pq, int e);
void initializeQueue(queue *pq);
int main()
{
    queue q;
    initializeQueue(&q);
    int Q, E, a, choice;
    scanf("%u", &Q);

    for (a = Q; a > 0; a--)
    {
        scanf("%u", &choice);
        switch (choice)
        {
        case 1:
            scanf("%u", &E);
            enqueue(&q, E);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            if (q.size <= 0)
                printf("Empty\n");
            else
                dispQueue(&q);
            break;
        }
    }

    return 0;
}

void initializeQueue(queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void enqueue(queue *pq, int e)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    // I prepare my new node
    newNode->next = NULL;
    newNode->value = e;
    // I link previous node with new node
    // pq->rear->next = newNode;
    if (!pq->rear)
        pq->front = newNode;
    else
        pq->rear->next = newNode;
    // move rear to the new node
    pq->rear = newNode;
    // increment size, as I add an element
    pq->size++;
}
void dequeue(queue *pq)
{
    // make a temp pointer to save the next node
    queueNode *temp;
    // assign temp to the first node
    temp = pq->front;
    // move front to the next node
    pq->front = pq->front->next;
    // remove temp node that point to the first node
    free(temp);
    // decrement size, as I remove an element
    pq->size--;
}
void dispQueue(queue *pq)
{
    queueNode *temp;
    temp = pq->front;
    while (temp) // I move until temp = NULL
    {

        printf("%d", temp->value);
            if(temp->next != NULL) //to neglect the final comma
                printf(",");
        temp = temp->next;
    }
}
