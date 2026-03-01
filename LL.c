#include <stdlib.h>
#include "LL.h"
#include <stdbool.h>


LL* LL_init()
{
    LL* list = malloc(1 * sizeof (LL*));
    list->head = NULL;

    // list may be null but the caller function should check
    return list;
}


bool LL_destroy(LL* list)
{
    if(list == NULL || list->head == NULL)
    {
        return false;
    }

    LLNode* tmp = list->head;
    LLNode* current = tmp->next;

    free(tmp);
    while(current != NULL)
    {
        tmp = current;
        free(tmp);
        current = current->next;
    }

    free(list);
    return true;
}

bool LL_destroyFreeObj(LL* list)
{
    if(list == NULL || list->head == NULL)
    {
        return false;
    }

    LLNode* tmp = list->head;
    LLNode* current = tmp->next;

    free(tmp);
    while(current != NULL)
    {
        tmp = current;
        free(tmp->obj);
        free(tmp);
        current = current->next;
    }

    free(list);
    return true;
}

bool LL_append(LL* list, void* obj)
{
    if(list == NULL)
    {
        return false;
    }

    LLNode* node = malloc(sizeof(LLNode));
    if(node == NULL)
    {
        return false;
    }

    node->next = NULL;
    // make sure this is overwritten accordingly
    node->prev = NULL;
    node->obj = obj;

    if(list->head == NULL)
    {
        list->head = node;
        return true;
    }

    LLNode* lastNode = LL_getLastNode(list);
    if(lastNode == NULL)
    {
        return false;
    }

    lastNode->next = node;
    node->prev = lastNode;
    return true;
}

LLNode* LL_getLastNode(LL* list)
{
    if(list == NULL || list->head == NULL)
        return NULL;

    LLNode* prev = list->head;
    LLNode* current = prev->next;
    while(current != NULL)
    {
        prev = current;
        current = current->next;
    }
    return prev;
}
