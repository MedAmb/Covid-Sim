#ifndef __LOCATION_H__
#define __LOCATION_H__

#include <stdlib.h>
#include <math.h>

#define CLOSE_ENOUGH 0.05


class Location
{
    private: 
        double x, y;
    public: 
        Location();
        Location(double x, double y);

        double getX();
        double getY();
        void setX(double x);
        void setY(double y);

        double getDistance(Location otherLocation);
        bool moveTo(Location destination, double speed);
        bool isAt(Location otherLocation);
};

#endif