#include "mobility_model.h"
#include "person.h"

mobilityModel::mobilityModel()
{
    person = nullptr;
}

void mobilityModel::setPerson(Person * _person)
{
    if(_person != nullptr)
        person = _person;
}