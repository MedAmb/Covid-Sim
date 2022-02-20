#ifndef __PPMODEL_H__
#define __PPMODEL_H__

#include "mobility_model.h"


class Location;


#define NUM_OF_POPULAR_PLACEs 15


#define DISTANCING_PROBABILITY 0.8

#define DISTANCING_HOME_PROBABILITY 0.997
#define NOT_DISTANCING_HOME_PROBABILITY 0.2

#define PP_TOP_SPEED 20

#define MAX_STAY 4


class popularPlacesModel : mobilityModel
{
    private:
        Location * wayPoint, * home;
        int speed, stay;
        double homeProbability;
    public:
        popularPlacesModel();
        void pickANewWayPoint();
        void move();
};


#endif