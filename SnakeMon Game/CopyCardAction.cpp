#include "CopyCardAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyCardAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // Prompt user for the source cell
    pOut->PrintMessage("Copy Card: Click on the source cell ...");
    sourceCell = pIn->GetCellClicked();

    // Validate the selected cell
    if (!sourceCell.IsValidCell())
    {
        pOut->PrintMessage("Invalid cell! Operation cancelled.");
        sourceCell.SetVCell(-1); // Mark as invalid
    }

    pOut->ClearStatusBar();
}

void CopyCardAction::Execute()
{
    ReadActionParameters();

    if (!sourceCell.IsValidCell()) 
        return;

    Grid* pGrid = pManager->GetGrid();

    GameObject* pGameObject = pGrid->GetGameObjectFromCell(sourceCell);

    Card* cardToCopy = dynamic_cast<Card*>(pGameObject);
    if (!cardToCopy)
    {
        pGrid->GetOutput()->PrintMessage("The selected cell does not contain a card. Operation cancelled.");
        return;
    }
    pGrid->SetClipboard(cardToCopy);

    pGrid->GetOutput()->PrintMessage("Card copied successfully to clipboard.");
}


CopyCardAction::~CopyCardAction()
{
}


