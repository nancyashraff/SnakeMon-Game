#include "DeleteAction.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters() 
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->ClearStatusBar();
    pOut->PrintMessage("Delete Object: Click on the START CELL of the object to delete it...");

    targetCell = pIn->GetCellClicked();

    if (!targetCell.IsValidCell())
    {
        pOut->PrintMessage("Invalid cell! Operation cancelled.");
        targetCell.SetVCell(-1);

    }
    GameObject* pGameObject = pGrid->GetGameObjectFromCell(targetCell);
    if (!pGameObject)
    {
        pOut->PrintMessage("The selected cell does not contain an object. Operation cancelled.");
        targetCell.SetVCell(-1);
        return;
    }
    pOut->ClearStatusBar();
}

void DeleteAction::Execute() 
{
    ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    pGrid->RemoveObjectFromCell(targetCell);
    pGrid->UpdateInterface();

    Output* pOut = pGrid->GetOutput();
    if(pGrid->GetGameObjectFromCell(targetCell))
    pOut->PrintMessage("Object deleted from the selected cell.");
}

DeleteAction::~DeleteAction() 
{
}

