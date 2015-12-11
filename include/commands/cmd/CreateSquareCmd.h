//
// Created by Raccoon on 2015/12/11.
//

#ifndef POSD_104598003_HW5_CREATESQUARECMD_H
#define POSD_104598003_HW5_CREATESQUARECMD_H

#include "Command.h"
#include "DrawingWindow.h";

class CreateSquareCmd : public Command{

public:
    CreateSquareCmd(DrawingWindow *d) : Command(d) { }

public:
    virtual void execute();
    virtual void unexecute();
};


#endif //POSD_104598003_HW5_CREATESQUARECMD_H
