#pragma once

#include "Card.h"


class CardEight : public Card
{
public:
	CardEight(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();
	void Draw(Output* pOut) const;
	virtual bool IsOfType(int type);
	virtual bool IsOverlapping(GameObject* newObj) const;
	
};


