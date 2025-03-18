//
// Created by imremali on 3/18/2025.
//

#ifndef LIST_H
#define LIST_H
#include "domain.h"
typedef Athlete* TElem;

typedef struct {
    TElem* elements;
    int size, capacity;
} List;

///
/// @return
List* createList();

void destroyList(List*list);

void add(List* list, TElem elem);

List* copyList(List* list);

void testList();

#endif //LIST_H
