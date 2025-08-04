#include "PasteCardAction.h"
#include "Grid.h"
#include "Card.h"
#include "Input.h"
#include "Output.h"
#include"Ladder.h"
#include"Snake.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteCardAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Paste Card: Click on the destination cell ...");

    destinationCell = pIn->GetCellClicked();

    if (!destinationCell.IsValidCell())
    {
        pOut->PrintMessage("Invalid cell! Operation cancelled.");
        destinationCell.SetVCell(-1);
    }
    else
    {
        pOut->ClearStatusBar();
    }
}

void PasteCardAction::Execute()
{
    ReadActionParameters();

    if (!destinationCell.IsValidCell())
        return;

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    GameObject* pGameObject = pGrid->GetGameObjectFromCell(destinationCell);

    if (pGameObject) 
    {
        if (dynamic_cast<Card*>(pGameObject) || dynamic_cast<Ladder*>(pGameObject) || dynamic_cast<Snake*>(pGameObject))
        {
            pOut->PrintMessage("The destination cell contains a card, ladder, or snake. Operation cancelled.");
            return;
        }
    }

    Card* pCardToPaste = pGrid->GetClipboard();
    if (!pCardToPaste)
    {
        pOut->PrintMessage("Clipboard is empty. No card to paste.");
        return;
    }

    if (!pGrid->SetGameObjectInCell(destinationCell, pCardToPaste))
    {
        pOut->PrintMessage("Failed to paste card to the destination cell.");
        return;
    }
    pGrid->SetClipboard(NULL);

    pGrid->UpdateInterface();
    pOut->PrintMessage("Card pasted successfully.");
}

PasteCardAction::~PasteCardAction()
{
}

