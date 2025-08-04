#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	///TODO: Do the needed validation (DONE)
	if (!startCellPos.IsValidCell() || !endCellPos.IsValidCell())
	{
		this->endCellPos = CellPosition(0,0);
		return;
	}
	this->endCellPos = endCellPos;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below (DONE)


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	if (endCellPos.HCell()==0 && endCellPos.VCell()==0) 
	{
		pGrid->PrintErrorMessage("You have reached a ladder. Click to continue...");
		pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	}
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
void Ladder::Save(ofstream& OutFile, int type)	// Saves the GameObject parameters to the file
{
	//TODO (DONE)
	if(type==1)
	OutFile << position.GetCellNum() << " "<< endCellPos.GetCellNum() << std::endl;
}
void Ladder::Load(ifstream& Infile)	// Loads and Reads the GameObject parameters from the file
{
	//TODO (DONE)
		int startCellNum, endCellNum;
		Infile >> startCellNum >> endCellNum;
		position = CellPosition::GetCellPositionFromNum(startCellNum);
		endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
}
bool Ladder::IsOfType(int type) const
{
	return type == 1;
}

bool Ladder::IsOverlapping(GameObject* newObj) const
{
	Ladder* pLadder = dynamic_cast<Ladder*>(newObj);
	if (pLadder) 
	{
		if ((position.VCell() >= pLadder->endCellPos.VCell()) && (endCellPos.VCell() <= pLadder->position.VCell()) &&
			(position.HCell() == pLadder->position.HCell())) 
		{
			return true; // Overlap
		}
	}
	return false; // No overlap
}