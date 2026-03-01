//
// Created by Nicolas on 2/23/2026.
//

#ifndef LL_H
#define LL_H

#include <stdbool.h>


typedef struct LLNode {
    void* obj;
    struct LLNode* next;
    struct LLNode* prev;
} LLNode;

typedef struct LL
{
    LLNode* head;
    //int length; // other attributes
    // ... idk for now
} LL;


// ALL METHODS RETURN TRUE ON SUCCESS

LL* LL_init();
bool LL_destroy(LL*);
bool LL_destroyFreeObj(LL*);
bool LL_append(LL*, void*);

LLNode* LL_getLastNode(LL*);

#endif //LL_H
