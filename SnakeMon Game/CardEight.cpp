#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)//No parameters are Needed
{
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetjustRolledDiceNum(0);
}

CardEight::~CardEight()
{
}

void CardEight::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
}

bool CardEight::IsOfType(int type)
{
	return false;
}

bool CardEight::IsOverlapping(GameObject* newObj) const
{
	return false;
}

