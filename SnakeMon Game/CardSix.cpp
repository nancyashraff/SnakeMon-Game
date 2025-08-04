#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)//No parameters are Needed
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->Move(pGrid, -(pPlayer->GetjustRolledDiceNum()));
}

CardSix::~CardSix()
{
}

void CardSix::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
}

bool CardSix::IsOfType(int type)
{
	return false;
}

bool CardSix::IsOverlapping(GameObject* newObj) const
{
	return false;
}
