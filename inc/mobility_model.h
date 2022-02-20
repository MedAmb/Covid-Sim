#ifndef __MOBILITY_MODEL_H__
#define __MOBILITY_MODEL_H__

class Person;

class mobilityModel
{
    protected:
        Person * person;
    public:
        mobilityModel();
        void setPerson(Person *);
        virtual void move() = 0;
};


#endif