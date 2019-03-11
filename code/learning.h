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
#define STEP_MODIFICATION (.2f)

//Definition of the factor value for the learning
#define FACTOR (.25f)

/*
* function :
*           Update the position of all thieves based on a reinforment algorythm
* 
* param :
*           Automaton aAutomaton : A table on which we based our State and Action
*           AllTHieves *tableOfThieves : A pointer on a table of "Thief"
*           AllLights *tableOfLights : A pointer on a table of "Light"
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*
* return :
*           void
*/
void updateAllThieves(Automaton aAutomaton, AllThieves *tableOfThieves, AllLights *tableOfLights, AllMoney *tableOfMoney);

/*
* function :
*           Update the position of a specific thief based on a reinforment algorythm and a specific Action choosen
*           == >> Used by updateAllThieves
* 
* param :
*           Automaton aAutomaton : A table on which we based our State and Action
*           Action action : The Action choosen
*           AllThieves *tableOfThieves : A pointer on a table of "Thief"
*           unsigned short int index : A index in the table tableOfThieve to determine which Thief we work with
*           AllLights *tableOfLights : A pointer on a table of "Light"
*           AllMoney *tableOfMoney : A pointer on a table of "Money"
*
* return :
*           void
*/
void update(Automaton aAutomaton, Action action, AllThieves *tableOfThieves, unsigned short int index, AllLights *tableOfLights, AllMoney *tableOfMoney);

/*
* function :
*           Choose the bestest Action for a specific Thief
*           == >> Used by updateAllThieves
* 
* param :
*           AllTHieves *tableOfThieves : A pointer on a table of "Thief"
*           unsigned short int index : A index in the table tableOfThieve to determine which Thief we work with
*
* return :
*           Action : The Action choosen
*/
Action chooseAction(AllThieves *tableOfThieves, unsigned short int index);

/*
* function :
*           Update the weightsTable of a Thief
*           == >> Used by update
* 
* param :
*           State nextState : The newt State the Thief will have
*           Action action : The Action choosen
*           AllTHieves *tableOfThieves : A pointer on a table of "Thief"
*           unsigned short int index : A index in the table tableOfThieve to determine which Thief we work with
*
* return :
*           void
*/
void updateUtility(State nextState, Action action, AllThieves *tableOfThieves, unsigned short int index);

/*
* function :
*           Determine the reward to give to a Thief his last Action
* 
* param :
*           AllTHieves *tableOfThieves : A pointer on a table of "Thief"
*           unsigned short int index : A index in the table tableOfThieve to determine which Thief we work with
*
* return :
*           float
*/
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

/*
* function :
*           Printf all the weights table for a thief in console
* 
* param :
*           AllMoney *tableOfThieves : A pointer on our table of "Thief"
*           unisgned short int : Index on the thief containing the weights table we want to print
*
* return :
*           void
*/
void printWeightsTable(AllThieves *tableOfThieves, unsigned short int index);