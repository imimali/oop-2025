//
// Created by imremali on 3/18/2025.
//

#ifndef LIST_H
#define LIST_H

typedef void* TElem;
typedef void (*DestroyFunction)(TElem);
typedef TElem (*CopyFunction)(TElem);

typedef struct {
    TElem* elements;
    int size, capacity;
    DestroyFunction destroyElement;
    CopyFunction copyElement;
} List;

///
/// @return
List* createList(DestroyFunction destroyFn, CopyFunction copyFn);

void destroyList(List*list);

void add(List* list, TElem elem);

List* copyList(List* list);

void testList();

#endif //LIST_H
