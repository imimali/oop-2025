//
// Created by imremali on 3/18/2025.
//
#include "list.h"
#include "domain.h"
#include<stdlib.h>
#define INIT_CAPACITY 2

List *createList() {
    List *list = (List *) malloc(sizeof(List));
    list->elements = (TElem *) malloc(sizeof(TElem) * INIT_CAPACITY);
    list->size = 0;
    list->capacity = INIT_CAPACITY;
    return list;
}

void destroyList(List *list) {
    for (int i = 0; i < list->size; i++) {
        destroyAthlete(list->elements[i]);
    }
    free(list->elements);
    free(list);
}

void resize(List *list) {
    int newCapacity = list->capacity * 2;
    TElem *newElements = (TElem *) malloc(sizeof(TElem) * newCapacity);
    for (int i = 0; i < list->size; i++) {
        newElements[i] = list->elements[i];
    }
    free(list->elements);
    list->elements = newElements;
    list->capacity = newCapacity;
}

void add(List *list, TElem elem) {
    if (list->size == list->capacity) {
        resize(list);
    }
    list->elements[list->size++] = elem;
}

List * copyList(List *list) {
    List *copy = (List *) malloc(sizeof(List));
    copy->elements = (TElem *) malloc(sizeof(TElem) * list->capacity);
    for (int i = 0; i < list->size; i++) {
        copy->elements[i] = copyAthlete(list->elements[i]);
        //copy->elements[i] = list->elements[i];
    }
    copy->size = list->size;
    copy->capacity = list->capacity;
    return copy;
}

void testList() {
    List* list = createList();
    add(list, createAthlete("aaaa",178));
    List* list2 = copyList(list);
    destroyList(list);
    destroyList(list2);
}
