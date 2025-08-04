#include "Snake.h"


Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	///TODO: Do the needed validation (DONE)
	if (!startCellPos.IsValidCell() || !endCellPos.IsValidCell())
	{
		this->endCellPos = CellPosition(0, 0);
		return;
	}
	this->endCellPos = endCellPos;
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below (DONE)


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	if (endCellPos.HCell() == 0 && endCellPos.VCell() == 0)
	{
		pGrid->PrintErrorMessage("You have reached a snake. Click to continue...");
		pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	}
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
void Snake::Save(ofstream& OutFile, int type)	// Saves the GameObject parameters to the file
{
	//TODO (DONE)
	if (type == 2)
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << std::endl;
}
void Snake::Load(ifstream& Infile)	// Loads and Reads the GameObject parameters from the file
{
	//TODO (DONE)
		int startCellNum, endCellNum;
		Infile >> startCellNum >> endCellNum;
		position = CellPosition::GetCellPositionFromNum(startCellNum);
		endCellPos = CellPosition::GetCellPositionFromNum(endCellNum);
}

bool Snake::IsOfType(int type) const
{
	return type == 2;
}

bool Snake::IsOverlapping(GameObject* newObj) const
{
	Snake* pSnake = dynamic_cast<Snake*>(newObj);
	if (pSnake)
	{
		if ((position.VCell() <= pSnake->endCellPos.VCell()) && (endCellPos.VCell() >= pSnake->position.VCell()) &&
			(position.HCell() == pSnake->position.HCell()))
		{
			return true;
		}
	}
	return false;
}