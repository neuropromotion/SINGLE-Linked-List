#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
typedef struct film {
    char title[MAX_SIZE];
    int rating;
} Item;
typedef struct node {
    Item item;
    struct node* next;
} Node;
typedef Node* List;

void initialiazeList(List* pList);
bool ListIsEmpty(const List* plist);
bool ListIsFull(void);
unsigned int ListItemCount(const List* plist);
bool AddItem(Item item, List* plist);
void Traverse(const List* plist, void (*pfun)(Item item));
void EmptyList(List* plist);

#endif