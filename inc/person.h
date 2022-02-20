#ifndef __PERSON_H__
#define __PERSON_H__

#include "simulator.h"
#include "mobility_model.h"
#include "location.h"

class mobilityModel;


class Person 
{
    public:
        Person();
        bool infect();
        bool tryToInfect(Person otherPerson);
        void progressDisease();
        bool isAlive();

        Location location;
        mobilityModel * howToMove;
        diseaseStatus status;
        int diseaseTime;
};


#endif 