#ifndef __UI_H__
#define __UI_H__

class Person;

typedef int (*sim_func_t)();


int startUI(sim_func_t simFunc);
void redrawUI(Person *, int, int *, int);

#endif