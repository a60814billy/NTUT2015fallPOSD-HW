#ifndef QTGRAPHICSVIEWVISITOR_H
#define QTGRAPHICSVIEWVISITOR_H

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "boundingbox.h"
#include "GraphicsVisitor.h"
#include "CompositeQGraphicsItem.h"
#include "DrawingController.h"

#include <QGraphicsScene>
#include <QColor>

#include <stack>
using std::stack;

class QtGraphicsViewVisitor : public GraphicsVisitor {

public:

    QtGraphicsViewVisitor(QGraphicsScene *scene);

    DrawingController *controller;

    virtual void visitSimpleGraphic(SimpleGraphics *graphics) override;
    virtual void visitCompositeGraphic(CompositeGraphics *graphics) override;
    virtual void visitRootGraphic(RootGraphics *graphics) override ;

    virtual void enter() override;
    virtual void leave() override;
    void draw();
private:

    QPen *greenPen;
    QPen *blackPen;

    stack<CompositeQGraphicsItem *> v;
    stack<ShapeQGraphicsItem *> rootItem;

    QGraphicsScene *scene;
    void drawCircle(Circle &shape);
    void drawRectangle(Rectangle &shape);
    void drawSquare(Square &shape);
    void drawBoundingBox(BoundingBox &boundingBox);
};


#endif
