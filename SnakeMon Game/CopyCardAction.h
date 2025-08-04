#pragma once
#include "Action.h"

class CopyCardAction : public Action
{
private:
    CellPosition sourceCell;
public:
    CopyCardAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CopyCardAction();
};

