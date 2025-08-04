#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Player* currentPlayer = pGrid->GetCurrentPlayer();
	// == Here are some guideline steps (numbered below) to implement this function ==
	/*int Card8Validation = currentPlayer->GetjustRolledDiceNum();
	if (Card8Validation == 0)
	{
		currentPlayer->SetjustRolledDiceNum(1);
		currentPlayer->IncrementTurnCount();
		return;
	}*/

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (!(pGrid->GetEndGame()))
		// -- If not ended, do the following --:
	{

		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 3- Get the "current" player from pGrid
		currentPlayer->Move(pGrid, diceNumber);
		// 4- Move the currentPlayer using function Move of class player
		/*int Turns = currentPlayer->GetTurnCount();
		if (Turns < 3)
			currentPlayer->Move(pGrid, diceNumber);
		else
		{
			int Currency = currentPlayer->GetWallet();
			int Commission = 10 * currentPlayer->GetjustRolledDiceNum();

			currentPlayer->SetWallet(Currency + Commission);
			currentPlayer->Move(pGrid, 0);
		}*/

		/*currentPlayer->IncrementTurnCount();*/
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	else
	{
		pGrid->PrintErrorMessage("GameOver !");
	}
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
