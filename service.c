//
// Created by imremali on 3/18/2025.
//
#include"service.h";
#include <stdlib.h>

#include "list.h"
#include "repo.h"

Service *createService() {
    Service *service = (Service *) malloc(sizeof(Service));
    service->repo = createRepo();
    service->undoStack = createList(destroyList, copyList);
}

void destroyService(Service *service) {
    destroyRepo(service->repo);
    destroyList(service->undoStack);
    free(service);
}
