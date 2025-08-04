#include "InputDiceValueAction.h"

#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) :Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pInp = pGrid->GetInput();
	Output* pOutp = pGrid->GetOutput();
	
	
	pOutp->PrintMessage("Enter Dice Number: ");
	InputDiceValue = pInp->GetInteger(pOutp);
	while (InputDiceValue > 6 || InputDiceValue < 1)
	{
		pOutp->PrintMessage("Invalid ,Please Enter a Number Ranging between 1 to 6 !");
		InputDiceValue = pInp->GetInteger(pOutp);
	}

	
}

void InputDiceValueAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	
	if (!(pGrid->GetEndGame()))
	{
		ReadActionParameters();
		Player* currentPlayer = pGrid->GetCurrentPlayer();
		currentPlayer->Move(pGrid, InputDiceValue);
		pGrid->AdvanceCurrentPlayer();
	}
	else
	{
		Input* pInp = pGrid->GetInput();
		Output* pOutp = pGrid->GetOutput();
		pOutp->PrintMessage("Oops ,Game Over !");
		pInp->GetCellClicked();
	}
}

InputDiceValueAction::~InputDiceValueAction()
{
}
