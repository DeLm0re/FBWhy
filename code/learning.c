//To include the functions prototypes
#include "learning.h"

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
void updateAllThieves(Automaton aAutomaton, AllThieves *tableOfThieves, AllLights *tableOfLights, AllMoney *tableOfMoney)
{
    unsigned short int indexThieves;

    Action choosenAction;

    for(indexThieves = 0; indexThieves < tableOfThieves->lenght; indexThieves++)
    {
        choosenAction = chooseAction(tableOfThieves, indexThieves);

        update(aAutomaton, choosenAction, tableOfThieves, indexThieves, tableOfLights, tableOfMoney);
    }
}

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
void update(Automaton aAutomaton, Action action, AllThieves *tableOfThieves, unsigned short int index, AllLights *tableOfLights, AllMoney *tableOfMoney)
{
    State currentState = tableOfThieves->thieves[index].currentState;

	State newState = aAutomaton[currentState][action];

    //Update cord
	switch(newState)
	{
		case GoingUp:
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentY ++;
			break;
        /*
        case GoingUpRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
            tableOfThieves->thieves[index].currentY ++;
			break;
        */
        case GoingRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].currentX ++;
			break;
        /*
		case GoingDownRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
            tableOfThieves->thieves[index].currentY --;
			break;
        */
        case GoingDown:
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentY --;
			break;
        /*
        case GoingDownLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX --;
            tableOfThieves->thieves[index].currentY --;
			break;
        */
        case GoingLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].currentX --;
			break;
        /*
        case GoingUpLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX --;
            tableOfThieves->thieves[index].currentY ++;
			break;
        */
        case Stable:
			break;
	}

    //Update lights distance
    tableOfThieves->thieves[index].previousLightsDistance = tableOfThieves->thieves[index].currentLightsDistance;
    tableOfThieves->thieves[index].currentLightsDistance = calculLightsDistance(tableOfThieves, index, tableOfLights);

    //Update money distance
    tableOfThieves->thieves[index].previousMoneyDistanceX = tableOfThieves->thieves[index].currentMoneyDistanceX;
    tableOfThieves->thieves[index].previousMoneyDistanceY = tableOfThieves->thieves[index].currentMoneyDistanceY;
    tableOfThieves->thieves[index].nearestMoney = indexNearestMoney(tableOfThieves, index, tableOfMoney);
    tableOfThieves->thieves[index].currentMoneyDistanceX = 
        abs(tableOfThieves->thieves[index].currentX - tableOfMoney->money[tableOfThieves->thieves[index].nearestMoney].x);
    tableOfThieves->thieves[index].currentMoneyDistanceY = 
        abs(tableOfThieves->thieves[index].currentY - tableOfMoney->money[tableOfThieves->thieves[index].nearestMoney].y);
    
    
    //Update weights table
	updateUtility(newState, action, tableOfThieves, index);

    //Update current state that become the state we are now
	tableOfThieves->thieves[index].currentState = newState;
}

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
Action chooseAction(AllThieves *tableOfThieves, unsigned short int index)
{
    State actualState = tableOfThieves->thieves[index].currentState;

	Action indexAction;

    Action actionToMake = GoUp;

    //for(indexAction = GoUpRight; indexAction <= NoActivity; indexAction++)
    for(indexAction = GoRight; indexAction <= NoActivity; indexAction++)
    {
        if(tableOfThieves->thieves[index].weights[actualState][indexAction] > tableOfThieves->thieves[index].weights[actualState][actionToMake])
        {
            actionToMake = indexAction;
        }
    }

    return(actionToMake);
}

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
void updateUtility(State nextState, Action action, AllThieves *tableOfThieves, unsigned short int index)
{
    Action indexAction;

    State currentState = tableOfThieves->thieves[index].currentState;

    float maxWeight = tableOfThieves->thieves[index].weights[nextState][GoUp];

    //for(indexAction = GoUpRight; indexAction <= NoActivity; ++indexAction)
    for(indexAction = GoRight; indexAction <= NoActivity; ++indexAction)
    {
        if(tableOfThieves->thieves[index].weights[nextState][indexAction] > maxWeight)
        {
            maxWeight = tableOfThieves->thieves[index].weights[nextState][indexAction];
        }
    }

	tableOfThieves->thieves[index].weights[currentState][action] =
                (1.f - STEP_MODIFICATION) * tableOfThieves->thieves[index].weights[currentState][action]
                + STEP_MODIFICATION * (reward(tableOfThieves, index)+FACTOR*maxWeight);
}

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
float reward(AllThieves *tableOfThieves, unsigned short int index)
{
    float currentDistanceLights = tableOfThieves->thieves[index].currentLightsDistance;
    float previousDistanceLights =  tableOfThieves->thieves[index].previousLightsDistance;

    float currentDistanceMoneyX = tableOfThieves->thieves[index].currentMoneyDistanceX;
    float currentDistanceMoneyY = tableOfThieves->thieves[index].currentMoneyDistanceY;
    
    float previousDistanceMoneyX = tableOfThieves->thieves[index].previousMoneyDistanceX;
    float previousDistanceMoneyY = tableOfThieves->thieves[index].previousMoneyDistanceY;

    if(currentDistanceLights < previousDistanceLights)
    {
        return(-(2.f));
    }
    else if( (currentDistanceMoneyX < previousDistanceMoneyX) || (currentDistanceMoneyY < previousDistanceMoneyY) )
    {
        return(1.f);
    }
    else
    {
        return(-(2.f));
    } 
}

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
void printStateValue(State aStateEnum)
{
    switch (aStateEnum)
    {
        case GoingUp:
			printf("GoingUp\n");
			break;
        /*
        case GoingUpRight:
			printf("GoingUpRight\n");
			break;
        */
        case GoingRight:
			printf("GoingRight\n");
			break;
        /*
		case GoingDownRight:
			printf("GoingDownRight\n");
			break;
        */
        case GoingDown:
			printf("GoingDown\n");
			break;
        /*
        case GoingDownLeft:
			printf("GoingDownLeft\n");
			break;
        */
        case GoingLeft:
			printf("GoingLeft\n");
			break;
        /*
        case GoingUpLeft:
			printf("GoingUpLeft\n");
			break;
        */
        case Stable:
            printf("Stable\n");
			break;
    }
}

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
void printActionValue(State anActionEnum)
{
    switch (anActionEnum)
    {
        case GoUp:
			printf("GoUp\n");
			break;
        /*
        case GoUpRight:
			printf("GoUpRight\n");
			break;
        */
        case GoRight:
			printf("GoRight\n");
			break;
        /*
		case GoDownRight:
			printf("GoDownRight\n");
			break;
        */
        case GoDown:
			printf("GoDown\n");
			break;
        /*
        case GoDownLeft:
			printf("GoDownLeft\n");
			break;
        */
        case GoLeft:
			printf("GoLeft\n");
			break;
        /*
        case GoUpLeft:
			printf("GoUpLeft\n");
			break;
        */
        case NoActivity:
            printf("NoActivity\n");
			break;
    }
}

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
void printWeightsTable(AllThieves *tableOfThieves, unsigned short int index)
{
    State indexState;
    Action indexAction;

    printf("\n");
    for(indexState = GoingUp; indexState <= Stable; indexState++)
    {
        for(indexAction = GoUp; indexAction <= NoActivity; indexAction++)
        {
            printf(" %f", tableOfThieves->thieves[index].weights[indexState][indexAction]);
        }
        printf("\n");
    }
    printf("\n");
}