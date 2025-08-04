#pragma once

#include "Card.h"


class CardSix : public Card
{
public:
	CardSix(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSix();
	void Draw(Output* pOut) const;
	virtual bool IsOfType(int type);
	virtual bool IsOverlapping(GameObject* newObj) const;
};

