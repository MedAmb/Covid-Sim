#include "ppmodel.h"
#include "location.h"
#include "simulator.h"
#include "person.h"
#include "stdlib.h"

static Location popularPlaces[NUM_OF_POPULAR_PLACEs];


popularPlacesModel::popularPlacesModel()
{
    speed = -1;
    home = new Location();

    if(tryEvent(DISTANCING_PROBABILITY))
        homeProbability = DISTANCING_HOME_PROBABILITY;

    else 
        homeProbability = NOT_DISTANCING_HOME_PROBABILITY;
}


void popularPlacesModel::move()
{
    if(speed < 0)
    {
        person->location.setX(home->getX());
        person->location.setY(home->getY());
    }
    else if(person->location.isAt(*wayPoint))
    {
        stay--;
        if(stay <= 0)
            pickANewWayPoint();
    }
    else
        person->location.moveTo(*wayPoint, speed);
}

void popularPlacesModel::pickANewWayPoint()
{
    speed = rand() % PP_TOP_SPEED + 1;
    stay = rand() % MAX_STAY;
    if(tryEvent(homeProbability))
    {
        wayPoint = home;
    }
    else
    {
        int place = rand() % NUM_OF_POPULAR_PLACEs;
        wayPoint = &(popularPlaces[place]);
    }
}