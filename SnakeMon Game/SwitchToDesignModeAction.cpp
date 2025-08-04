#include "SwitchToDesignModeAction.h"
#include "Grid.h"
#include "Output.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDesignModeAction::ReadActionParameters()
{
    // No parameters are required for switching to design mode.
}

void SwitchToDesignModeAction::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    // Reset the grid or clean up any play mode state
    //pGrid->ResetPlayers(); // Reset players to the initial state
    //pGrid->ResetGameObjects(); // Optionally reset objects if necessary

    // Switch the UI to design mode
    pOut->CreateDesignModeToolBar();

    // Clear the status bar
    pOut->PrintMessage("Switched to Design Mode. The current grid is now editable.");
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}

