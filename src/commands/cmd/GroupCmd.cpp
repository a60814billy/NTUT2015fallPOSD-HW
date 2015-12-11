//
// Created by Raccoon on 2015/12/11.
//

#include "GroupCmd.h"
#include "DescriptionVisitor.h"
#include "MultiRootGraphicFactory.h"

void GroupCmd::execute() {

    if(isExcute){
        MultiRootGraphicFactory gf;
        Graphics *g = gf.buildGraphicsFromString(this->checkpoint2.c_str());
        if (g) {
            this->w->activateGraphics = g;
            this->w->updateScene();
        }
        return;;
    }

    DescriptionVisitor v;
    this->w->activateGraphics->accept(v);
    this->checkpoint = v.getDescription();

    this->w->doGroup();
    isExcute = true;

    DescriptionVisitor v2;
    this->w->activateGraphics->accept(v2);
    this->checkpoint2 = v2.getDescription();

}

void GroupCmd::unexecute() {
    MultiRootGraphicFactory gf;
    Graphics *g = gf.buildGraphicsFromString(this->checkpoint.c_str());
    if (g) {
        this->w->activateGraphics = g;
        this->w->updateScene();
    }
}
