#include "SwitchToPlayModeAction.h"
#include "Input.h"
#include "Output.h"
#include"GameObject.h"
#include "Player.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{

    // Constructor: Passes the ApplicationManager pointer to the base class
}

void SwitchToPlayModeAction::ReadActionParameters()
{
    // No parameters to read for this action
}

void SwitchToPlayModeAction::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    // Reset all players to the initial state
    for (int i = 0; i < MaxPlayerCount; i++)
    {
        Player* player = pGrid->GetCurrentPlayer(); // Get each player
        player->SetWallet(100);                     // Reset wallet to full (you can adjust this initial value)
        //player->SetTurnCount(0);                    // Reset turn count
        //player->MoveToCell(CellPosition::GetCellPositionFromNum(1)); // Move player to step 0
    }

    // Switch the UI to play mode
    pOut->CreatePlayModeToolBar();

    // Clear the status bar
    pOut->PrintMessage("Switched to Play Mode! All players have been reset to step 0 with full wallets.");
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
    // Destructor: Nothing specific to delete
}
