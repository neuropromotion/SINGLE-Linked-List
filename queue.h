#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE_QUEUE 10
typedef int Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;
typedef struct queue
{
    Node *front;
    Node *rear;
    int items;
} Queue;
static void AddNode(Item item, Node *pnode);
void InitializeQueue(Queue *pq);
bool QueueIsEmpty(const Queue *pq);
bool QueueIsFull(const Queue *pq);
int QueueItemCount(const Queue *pq);
bool AddItemQueue(Item item, Queue *pq);
bool DeleteItemQueue(Item *pitem, Queue *pq);
void EmptyTheQueue(Queue *pq);

void AddNode(Item item, Node *pnode)
{
    pnode->item = item;
}
#endif