//To include the functions prototypes
#include "learning.h"

void updateAllThieves(Automaton aAutomaton, AllThieves *tableOfThieves)
{
    unsigned short int indexThieves;

    Action choosenAction;

    for(indexThieves = 0; indexThieves < tableOfThieves->lenght; indexThieves++)
    {
        printf("Index du voleur : %u \n", indexThieves);

        printf("current state : %d \n", tableOfThieves->thieves[indexThieves].currentState);

        choosenAction = chooseAction(tableOfThieves, indexThieves);

        puts("ok choseaction");

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
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
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
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
			break;

		case GoingDownRight:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
            tableOfThieves->thieves[index].currentX ++;
            tableOfThieves->thieves[index].currentY --;
			break;

        case GoingDown:
			tableOfThieves->thieves[index].previousX = tableOfThieves->thieves[index].currentX;
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
            tableOfThieves->thieves[index].previousY = tableOfThieves->thieves[index].currentY;
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

    //Update weights table
	updateUtility(newState, action, tableOfThieves, index);

    //Update current state that become the state we are now
	tableOfThieves->thieves[index].currentState = newState;
}

Action chooseAction(AllThieves *tableOfThieves, unsigned short int index)
{
    State actualState = tableOfThieves->thieves[index].currentState;

	Action indexAction;

    Action actionToMake = GoUp;

    for(indexAction = GoUpRight; indexAction <= NoActivity; ++indexAction)
    {
        printf("Indexaction : %d \n", indexAction);

        if(tableOfThieves->thieves[index].weights[actualState][indexAction] > tableOfThieves->thieves[index].weights[actualState][actionToMake])
        {
            puts("ok if");
            actionToMake = tableOfThieves->thieves[index].weights[actualState][indexAction];
        }
    }

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
                (1.f-STEP_MODIFICATION)*tableOfThieves->thieves[index].weights[currentState][action]
                +STEP_MODIFICATION*(reward(tableOfThieves, index)+FACTOR*maxWeight);
}

float reward(AllThieves *tableOfThieves, unsigned short int index)
{
	if(tableOfThieves->thieves[index].currentX > tableOfThieves->thieves[index].previousX)
    {
        return(.5f);
    }
    else{
        return(2.f);
    }
}