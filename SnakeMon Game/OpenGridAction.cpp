#include "OpenGridAction.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include <fstream>

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Open Grid: Enter the filename to open...");
    filename = pIn->GetSrting(pOut);

    pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
    ReadActionParameters();

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        Grid* pGrid = pManager->GetGrid();
        pGrid->GetOutput()->PrintMessage("Error: Unable to open file!");
        return;
    }

    Grid* pGrid = pManager->GetGrid();

    pGrid->ClearGrid();

    int numLadders, numSnakes, numCards;

    inputFile >> numLadders;

    for (int i = 0; i < numLadders; i++)
    {
        Ladder* pLadder = new Ladder(0,0);
        pLadder->Load(inputFile);
        bool added = pGrid->AddObjectToCell(pLadder);
        if (!added)
            delete pLadder;               
    }

    inputFile >> numSnakes;

    for (int i = 0; i < numSnakes; i++)
    {
        Snake* pSnake = new Snake(0,0);
        pSnake->Load(inputFile);          
        bool added = pGrid->AddObjectToCell(pSnake);
        if (!added)
            delete pSnake;           
    }

    inputFile >> numCards;
/*
    for (int i = 0; i < numCards; i++)
    {
        int cardType;
        inputFile >> cardType;

        Card* pCard = Card::CreateCard(cardType);
        if (pCard)
        {
            pCard->Load(inputFile);        
            bool added = pGrid->AddObjectToCell(pCard);
            if (!added)
                delete pCard;       
        }
    }
    */
    inputFile.close();

    pGrid->UpdateInterface();
}

OpenGridAction::~OpenGridAction()
{
}

