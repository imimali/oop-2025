//
// Created by imremali on 3/18/2025.
//
#include "domain.h"
#include <string.h>
#include <stdlib.h>
#include<assert.h>

Athlete *createAthlete(char *name, int height) {
    Athlete *athlete = (Athlete *) malloc(sizeof(Athlete));
    if (athlete == NULL) {
        return NULL;
    }
    athlete->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(athlete->name, name);
    athlete->height = height;
    return athlete;
}

void destroyAthlete(Athlete *athlete) {
    free(athlete->name);
    free(athlete);
}

Athlete *copyAthlete(Athlete *athlete) {
    Athlete *copy = (Athlete *) malloc(sizeof(Athlete));
    if (copy == NULL) {
        return NULL;
    }
    copy->name = (char *) malloc(sizeof(char) * (strlen(athlete->name) + 1));
    strcpy(copy->name, athlete->name);
    copy->height = athlete->height;
    return copy;
}

void testAthlete() {
    Athlete *athlete = createAthlete("aaa", 178);
    assert(strcmp(athlete->name,"aaa")==0);
    assert(athlete->height==178);
    Athlete* athleteCopy = copyAthlete(athlete);
    assert(strcmp(athleteCopy->name,"aaa")==0);
    assert(athleteCopy->height==178);
    // todo test all
    destroyAthlete(athlete);
    destroyAthlete(athleteCopy);
}
