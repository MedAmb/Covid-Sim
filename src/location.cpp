#include "location.h"
#include "simulator.h"
#include <stdlib.h>


Location::Location()
{
    x = rand() % X_LIMIT;
    y = rand() % Y_LIMIT;
}

Location::Location(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Location::getX()
{
    return x;
}

double Location::getY()
{
    return y;
}

void Location::setX(double _x)
{
    x = _x;
}

void Location::setY(double _y)
{
    y = _y;
}

double Location::getDistance(Location otherLocation)
{
    double dx = otherLocation.x - x;
    double dy = otherLocation.y - y;

    return sqrt((dx*dx) + (dy*dy));
}

bool Location::moveTo(Location destination, double speed)
{
    double dx = destination.x - x;
    double dy = destination.y - y;
    double theta = atan2(dy, dx);
    double distance = sqrt((dx*dx) + (dy*dy));

    if(distance < speed)
    {
        x = destination.x;
        y = destination.y;

        return true;
    }
    else 
    {
        x = x + (cos(theta) * speed);
        y = y + (sin(theta) * speed);
        return false;
    }
}

bool Location::isAt(Location otherLocation)
{
    return (getDistance(otherLocation) < CLOSE_ENOUGH);
}