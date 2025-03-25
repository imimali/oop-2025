//
// Created by imremali on 3/18/2025.
//

#ifndef REPO_H
#define REPO_H
#include "list.h"
#include "domain.h"
typedef struct {
    List* elements;
}Repository;

Repository* createRepo();

void addAthleteRepo(Repository* repo,Athlete*athlete);

void destroyRepo(Repository* repo);
#endif //REPO_H
