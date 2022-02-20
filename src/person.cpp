#include "ppmodel.h"
#include "rwpmodel.h"
#include "person.h"


Person::Person()
{
    popularPlacesModel * model = new popularPlacesModel();
    howToMove = (mobilityModel *)model;
    howToMove->setPerson(this);
    status = VULNERABLE;
    diseaseTime = INFECTION_TIME;
}


bool Person::infect()
{
    if(status == VULNERABLE)
    {
        status = INFECTED;
        return true;
    }
    else
        return false;
}

bool Person::tryToInfect(Person otherPerson)
{
    if(otherPerson.status != INFECTED)
        return false;

    else if(location.getDistance(otherPerson.location) > INFECTION_PROXIMITY)
        return false;

    else if(tryEvent(INFECTION_PROBABILITY))
        return infect();

    else
        return false;
}

void Person::progressDisease()
{
    if(status == INFECTED)
    {
        diseaseTime--;

        if(diseaseTime <= 0)
        {
            double fatalityRate = NORMAL_FATALITY_RATE;

            if(saturated)
                fatalityRate = SATURATION_FATALITY_RATE;

            if(tryEvent(fatalityRate))

                status = DEAD;

            else
                status = IMMUNE;
        }
    }   

}


bool Person::isAlive()
{
    return status != DEAD;
}