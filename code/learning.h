/*
* Generic headers files :
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

/*
* Cusom headers files :
*/
//To use the prototypes in the core
#include "core.h"

//Definition of the step modification
#define STEP_MODIFICATION (0.f)

//Definition of the factor value for the learning
#define FACTOR (.25f)

void updateAllThieves(Automaton aAutomaton, AllThieves *tableOfThieves);

void update(Automaton aAutomaton, Action action, AllThieves *tableOfThieves, unsigned short int index);

Action chooseAction(AllThieves *tableOfThieves, unsigned short int index);

void updateUtility(State nextState, Action action, AllThieves *tableOfThieves, unsigned short int index);

float reward(AllThieves *tableOfThieves, unsigned short int index);

/*
* function :
*           Printf all the value of an enum State
* 
* param :
*           State aStateEnum : The enum State we want to print the value
*
* return :
*           void
*/
void printStateValue(State aStateEnum);

/*
* function :
*           Printf all the value of an enum Action
* 
* param :
*           Action anActionEnum : The enum Action we want to print the value
*
* return :
*           void
*/
void printActionValue(State anActionEnum);