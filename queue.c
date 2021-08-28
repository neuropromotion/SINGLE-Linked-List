#include "queue.h"

void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAX_SIZE_QUEUE;
}
int QueueItemCount(const Queue *pq)
{
    return pq->items;
}
bool AddItemQueue(Item item, Queue *pq)
{
    Node *newnode;
    Queue *temp = pq;
    if (QueueIsFull(pq))
        return false;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        fprintf(stderr, "Not Enoght Memory, allocate error!\n");
        return false;
    }
    AddNode(item, newnode);
    newnode->next = NULL;
    if (QueueIsEmpty(pq))
        pq->front = newnode;
    else
        pq->rear->next = newnode; // связывание с концом очереди (не совсем понятно)
    pq->rear = newnode;
    pq->items++;
    return true;
}
bool DeleteItemQueue(Item *pitem, Queue *pq)
{
    Node *pt;
    if (QueueIsEmpty(pq))
        return false;
    *pitem = pq->front->item; // копирование переменной item в ожидающую переменную
    pt = pq->front;
    pq->front = pq->front->next; //если удаляется последний элемент, то pq->front получается значение NULL из pq->front->next
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}
void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
        DeleteItemQueue(&dummy, pq);
}