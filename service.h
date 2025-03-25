//
// Created by imremali on 3/18/2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "list.h"
#include "repo.h"

typedef struct {
    Repository *repo;
    List *undoStack;
} Service;

Service *createService();

void addAthlete(Service*service,char *name, int height);

void undo(Service*service);

void destroyService(Service *service);

void testAddWithUndo();


#endif //SERVICE_H
