#pragma once

#include "Card.h"


class CardFive : public Card
{
public:
	CardFive(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFive();
	void Draw(Output* pOut) const;
	virtual bool IsOfType(int type);
	virtual bool IsOverlapping(GameObject* newObj) const;
};

