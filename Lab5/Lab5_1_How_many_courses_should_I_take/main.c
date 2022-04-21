#include <stdio.h>
#include <stdlib.h>
typedef struct queuenode
{
    unsigned int days;
    unsigned int last_day;
    struct queuenode *next;
}queueNode;

typedef struct fifo
{
    queueNode *front;
}queue;

void insert_with_priority(queue *pq, unsigned  d, unsigned  i);
void initializeQueue(queue *pq);
unsigned count_courses(queue *pq);



int main()
{
    queue q;
    initializeQueue(&q);
    unsigned  n, days, last_day,a;
    scanf("%u", &n);
    for (a = 0; a<n; a++)
    {
        scanf("%u %u", &days, &last_day);
        insert_with_priority(&q, days, last_day);
    }
    printf("%u", count_courses(&q));

    return 0;
}

void initializeQueue(queue *pq)
{
    pq->front = NULL;
}
void insert_with_priority(queue *pq, unsigned  d, unsigned  i)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    //I prepare my new node
    newNode ->next = NULL;
    newNode ->days = d;
    newNode ->last_day = i;

    queueNode *temp;
    temp = pq->front;
    if(!pq->front)
    {
        pq->front=newNode;

    }

    else
    {
        if(temp->last_day > i)
        {   //check if the days of the new node greater than the first node put the new node in front of first node
            newNode->next = pq->front;
            pq->front = newNode;

        }
       else
        {  //put the new node after the node that has priority greater than it

            while (temp->next != NULL && temp->last_day<i)
            {
                temp = temp->next;
            }
            if(temp->next == NULL)
                temp -> next = newNode;
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

}

unsigned count_courses(queue *pq)
{
    //This function count the maximum courses that I will take
    unsigned count = 0, total_days =0;//I initialize count with 0 to count number of courses
    //I initialize total days with number of days of the first course
    queueNode *temp;
    temp = pq->front;

    while(temp!=NULL)//while the total days <= last day of first course
    {
        //dequeue(pq);  //I remove each course I will take from the queue to move to the other courses
        if((total_days +temp->days) <= temp->last_day && temp->days <= temp->last_day)
        {
            total_days += temp->days;  /*I add the number of days of next course to the total_days to check
            it gain in while loop*/
            count ++;  //increment count each time the condition satisfies
        }
        temp = temp ->next;

    }
    return count;  //return the total number of courses that I will take
}
