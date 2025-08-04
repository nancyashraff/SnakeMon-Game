#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid* pGrid) //No parameters are Needed
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->Move(pGrid, pPlayer->GetjustRolledDiceNum());
}

CardFive::~CardFive()
{
}

void CardFive::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
}

bool CardFive::IsOfType(int type)
{
	return false;
}

bool CardFive::IsOverlapping(GameObject* newObj) const
{
	return false;
}
