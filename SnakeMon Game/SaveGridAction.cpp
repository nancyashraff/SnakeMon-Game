#include "SaveGridAction.h"
#include "Grid.h"
#include <iostream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp) 
{
}

void SaveGridAction::ReadActionParameters() 
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("Enter the filename to save the grid ");
    fileName = pIn->GetSrting(pOut);

    pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
    ReadActionParameters();

    ofstream OutFile(fileName);

    if (!OutFile.is_open()) 
    {
        Grid* pGrid = pManager->GetGrid();
        pGrid->PrintErrorMessage("Error opening file for writing!");
        return;
    }

    Grid* pGrid = pManager->GetGrid();

    // Save Ladders
    OutFile << pGrid->CountGameObjects(1) << std::endl; // Number of ladders
    pGrid->SaveAll(OutFile, 1);

    // Save Snakes
    OutFile << pGrid->CountGameObjects(2) << std::endl; // Number of snakes
    pGrid->SaveAll(OutFile, 2);

    // Save Cards
    OutFile << pGrid->CountGameObjects(3) << std::endl; // Number of cards
    pGrid->SaveAll(OutFile, 3);

    OutFile.close();

    pGrid->PrintErrorMessage("Grid saved successfully to file!");
}
SaveGridAction::~SaveGridAction()
{
}