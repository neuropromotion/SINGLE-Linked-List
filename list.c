#include "list.h"
static void CopyToNode(Item item, Node *pnode) { pnode->item = item; }

void initialiazeList(List *pList) {
    *pList = NULL;
    return;
}

bool ListIsEmpty(const List *plist) {
    if (*plist == NULL)
        return true;
    else
        return false;
}
bool ListIsFull(void) {
    bool cond;
    List pt;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        cond = true;
    else
        cond = false;
    free(pt);
    return cond;
}
unsigned int ListItemCount(const List *plist) {
    unsigned int ctr = 0;
    List current;
    current = *plist;
    while (current != NULL) {
        ctr++;
        current = current->next;
    }
    return ctr;
}
bool AddItem(Item item, List *plist) {
    List pnew;
    List scan = *plist;
    pnew      = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Not enogh memory. Allocate error!\n");
        return false;
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
        *plist = pnew;
    else {
        while (scan->next != NULL) scan = scan->next;
        scan->next = pnew;
    }
    return true;
}
void Traverse(const List *plist, void (*pfun)(Item item)) {
    List pnode = *plist;
    while (pnode != NULL) {
        pfun(pnode->item);
        pnode = pnode->next;
    }
    return;
}
void EmptyList(List *plist) {
    List pnode;

    while ((pnode = *plist) != NULL) {
        *plist = pnode->next;
        free(pnode);
    }
    return;
}