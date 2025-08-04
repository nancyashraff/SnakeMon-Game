#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"


}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
}

void Card::EditParameters(Grid* pGrid)
{
	// Default implementation (for cards that do not take parameters)
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("This card does not have editable parameters.");
}

void Card::Save(ofstream& OutFile, int type)
{
	if (type == 3)
	{
		//TODO
	}
	
}
void Card::Load(ifstream& Infile)
{
		//TODO




}

bool Card::IsOfType(int type) 
{
	return type == 3;
}
