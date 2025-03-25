//
// Created by imremali on 3/18/2025.
//

#include <stdlib.h>
#include <assert.h>
#include"service.h";
#include "list.h"
#include "repo.h"
#include "domain.h"


Service *createService() {
    Service *service = (Service *) malloc(sizeof(Service));
    service->repo = createRepo();
    service->undoStack = createList(destroyList, copyList);
    return service;
}

void addAthlete(Service *service, char *name, int height) {
    List* copy = copyList(service->repo->elements);
    add(service->undoStack, copy);
    Athlete *athlete = createAthlete(name, height);
    addAthleteRepo(service->repo, athlete);
}

void undo(Service *service) {
    if (service->undoStack->size == 0) {
        return;
    }
    List *lastList = service->undoStack->elements[service->undoStack->size - 1];
    service->undoStack->size--;
    destroyList(service->repo->elements);
    service->repo->elements = lastList;
}

void destroyService(Service *service) {
    destroyRepo(service->repo);
    destroyList(service->undoStack);
    free(service);
}

void testAddWithUndo() {
    Service* service=createService();
    addAthlete(service, "name",178);
    assert(service->repo->elements->size==1);
    undo(service);
    assert(service->repo->elements->size==0);
    destroyService(service);
}