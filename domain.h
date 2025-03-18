//
// Created by imremali on 3/18/2025.
//

#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct Athlete {
    char *name;
    int height;

} Athlete;

Athlete * createAthlete(char *name, int height);

void destroyAthlete(Athlete* athlete);

Athlete* copyAthlete(Athlete* athlete);

void testAthlete();


#endif //DOMAIN_H
