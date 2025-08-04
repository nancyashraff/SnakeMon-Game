#include "EditCardAction.h"

#include "Input.h"
#include "Output.h"
#include "Card.h"

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void EditCardAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Click on the source to edit");
    targetCell = pIn->GetCellClicked();

    if (!targetCell.IsValidCell())
    {
        pOut->PrintMessage("Invalid cell clicked. Action cancelled.");
        return;
    }
    pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    Card* pCard = dynamic_cast<Card*>(pGrid->GetGameObjectFromCell(targetCell));

    if (pCard)
    {
        pCard->EditParameters(pGrid);
        pGrid->GetOutput()->PrintMessage("Card parameters updated successfully.");
    }
    else
    {
        pGrid->GetOutput()->PrintMessage("Action failed. No card found in the cell.operation cancelled");
    }
}

EditCardAction::~EditCardAction() {}
