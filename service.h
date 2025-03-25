//
// Created by imremali on 3/18/2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "list.h"
#include "repo.h"
typedef struct {
    Repository*repo;
    List* undoStack;
}Service;

Service* createService();

void destroyService(Service* service);
#endif //SERVICE_H
