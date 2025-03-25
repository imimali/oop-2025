//
// Created by imremali on 3/18/2025.
//
#include "repo.h"
#include "domain.h"
#include "list.h"
#include <stdlib.h>

Repository *createRepo() {
    Repository *repo = (Repository *) malloc(sizeof(Repository));
    repo->elements = createList(destroyAthlete, copyAthlete);
    return repo;
}

void addAthleteRepo(Repository *repo, Athlete *athlete) {
    add(repo->elements, athlete);
}


void destroyRepo(Repository *repo) {
    destroyList(repo->elements);
    free(repo);
}
