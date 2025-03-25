//
// Created by imremali on 3/18/2025.
//
#include "repo.h"
#include "domain.h"
#include <stdlib.h>

Repository *createRepo() {
    Repository *repo = (Repository *) malloc(sizeof(Repository));
    repo->elements = createList(destroyAthlete, copyAthlete);
    return repo;
}

void destroyRepo(Repository *repo) {
    destroyList(repo->elements);
    free(repo);
}
