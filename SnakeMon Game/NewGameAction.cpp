#include "NewGameAction.h"

#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->ResetGame();
	/*CellPosition StartCellPosition(NumVerticalCells - 1, 0);*/
	/*pGrid->ClearPlayers();*/
	/*pGrid->ResetPosition();
	pGrid->ResetWallet();
	pGrid->ResetPlayer();
	pGrid->ResetTurnCount();*/
}

NewGameAction::~NewGameAction()
{
}
