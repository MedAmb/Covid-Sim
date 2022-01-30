#include <iostream>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "simulator.h"
#include "person.h"
#include "location.h"
#include "ui.h"


bool saturated = false;

bool tryEvent(double probability)
{
    assert((probability >= 0.0) && (probability <= 1.0));
    const int resolution = 10000;

    double randomNumber = rand() % resolution;
    randomNumber = randomNumber / (double)(resolution);
    return randomNumber <= probability;
}

int simMain()
{
    Person people[NUM_PEOPLE];
    int inefectionHistory[SIM_HOURS];


    memset(inefectionHistory, 0, sizeof(inefectionHistory));

    for(int i = 0; i < INITIAL_INFECTIONS; i++)
    {
        people[i].status = INFECTED;
    }

    int maxInfectedAtOnce = 0;

    for(int i = 0; i < SIM_HOURS; i++)
    {
        if((i % 2) == 0)
        {
            uiRedraw(people, NUM_PEOPLE, inefectionHistory, SIM_HOURS);
        }

        for(int j = 0; j < NUM_PEOPLE; j++)
        {
            if(people[j].isAlive())
            {
                people[j].mobilityModel->move();
                people[j].progressDiesease();
            }
        }

        for(int j = 0; j < NUM_PEOPLE; j++)
        {
            if(people[j].isAlive())
            {
                for(int k = 0; k < NUM_PEOPLE; k++)
                {
                    if((j != k) && (people[k].isAlive()))
                    {
                        people[j].tryToInfect(people[k]);
                    }
                }
            }
        }

        int numOfInfected = 0, numOfImmune = 0, numOfDead = 0, numOfVUlnerable = 0;

        for(int j = 0; i < NUM_PEOPLE; j++)
        {
            if((!people[j].isAlive()))
                numOfDead++;

            else if(people[j].status == INFECTED)
                numOfInfected++;

            else if(people[j].status == IMMUNE)
                numOfImmune++;

            else if(people[j].status == VULNERABLE)
                numOfVUlnerable++;


        }        

    }
}