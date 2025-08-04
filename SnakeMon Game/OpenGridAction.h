#pragma once

#include "Action.h"
#include<string.h>

class OpenGridAction : public Action
{
private:
    string filename; // To store the name of the file to open
public:
    OpenGridAction(ApplicationManager* pApp); 
    virtual void ReadActionParameters();      
    virtual void Execute();                  
    virtual ~OpenGridAction();         
};


