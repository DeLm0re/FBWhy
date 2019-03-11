//To include the functions prototypes
#include "learning.h"

void updateAllThieves(Automaton aAutomaton, AllThieves *tableOfThieves)
{
    unsigned short int indexThieves;

    Action choosenAction;

    for(indexThieves = 0; indexThieves < tableOfThieves->lenght; indexThieves++)
    {
        choosenAction = chooseAction(tableOfThieves, indexThieves);

        update(aAutomaton, choosenAction, tableOfThieves, indexThieves);
    }
}

void update(Automaton aAutomaton, Action action, AllThieves *tableOfThieves, unsigned short int index)
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

        case GoingUpRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
            tableOfThieves->thieves[index].currentY ++;
			break;

        case GoingRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].currentX ++;
			break;

		case GoingDownRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
            tableOfThieves->thieves[index].currentY --;
			break;

        case GoingDown:
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentY --;
			break;

        case GoingDownLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX --;
            tableOfThieves->thieves[index].currentY --;
			break;
        
        case GoingLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].currentX --;
			break;

        case GoingUpLeft:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX --;
            tableOfThieves->thieves[index].currentY ++;
			break;

        case Stable:
			break;
	}
    
    puts("before");
    printWeightsTable(tableOfThieves, index);

    //Update weights table
	updateUtility(newState, action, tableOfThieves, index);

    puts("after");
    printWeightsTable(tableOfThieves, index);

    //Update current state that become the state we are now
	tableOfThieves->thieves[index].currentState = newState;
}

Action chooseAction(AllThieves *tableOfThieves, unsigned short int index)
{
    /*Ne marche pas comme prévu*/
    State actualState = tableOfThieves->thieves[index].currentState;

	Action indexAction;

    Action actionToMake = GoUp;

    for(indexAction = GoUpRight; indexAction <= NoActivity; ++indexAction)
    {
        printf("Poids : %f ", tableOfThieves->thieves[index].weights[actualState][indexAction]);
        if(tableOfThieves->thieves[index].weights[actualState][indexAction] > tableOfThieves->thieves[index].weights[actualState][actionToMake])
        {
            actionToMake = tableOfThieves->thieves[index].weights[actualState][indexAction];
        }
    }
    printf("\n\n");
    printActionValue(actionToMake);
    return(actionToMake);
}

void updateUtility(State nextState, Action action, AllThieves *tableOfThieves, unsigned short int index)
{
    Action indexAction;

    State currentState = tableOfThieves->thieves[index].currentState;

    float maxWeight = tableOfThieves->thieves[index].weights[nextState][GoUp];

    for(indexAction = GoUpRight; indexAction <= NoActivity; ++indexAction)
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

float reward(AllThieves *tableOfThieves, unsigned short int index)
{
	if( (tableOfThieves->thieves[index].currentY < tableOfThieves->thieves[index].previousY) && (tableOfThieves->thieves[index].currentX < tableOfThieves->thieves[index].previousX) )
    {
        return(2.f);
    }
    else{
        return(.5f);
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

        case GoingUpRight:
			printf("GoingUpRight\n");
			break;

        case GoingRight:
			printf("GoingRight\n");
			break;

		case GoingDownRight:
			printf("GoingDownRight\n");
			break;

        case GoingDown:
			printf("GoingDown\n");
			break;

        case GoingDownLeft:
			printf("GoingDownLeft\n");
			break;
        
        case GoingLeft:
			printf("GoingLeft\n");
			break;

        case GoingUpLeft:
			printf("GoingUpLeft\n");
			break;

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

        case GoUpRight:
			printf("GoUpRight\n");
			break;

        case GoRight:
			printf("GoRight\n");
			break;

		case GoDownRight:
			printf("GoDownRight\n");
			break;

        case GoDown:
			printf("GoDown\n");
			break;

        case GoDownLeft:
			printf("GoDownLeft\n");
			break;
        
        case GoLeft:
			printf("GoLeft\n");
			break;

        case GoUpLeft:
			printf("GoUpLeft\n");
			break;

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