#include "canvasmatrix.h"
#include <cmath>

#include <iostream>

CanvasMatrix::CanvasMatrix(QWidget *parent) : QWidget{parent} {
    xsize = 10; ysize = 10; zsize = 10; zlayer = 0;
    s = new Sculptor(10,10,10);
    s->setColor(1, 0, 0, 1);
    s->putEllipsoid(0, 0, 0, xsize - 1, ysize - 1, zsize - 1);
}

CanvasMatrix::~CanvasMatrix() {
    s->writeOFF("teste.off");
    delete s;
}

void CanvasMatrix::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(brush);

    painter.drawRect(0, 0, width(), height());

    drawGrid();
}

void CanvasMatrix::setXSize(int nx) {
    xsize = nx;
    delete s;
    s = new Sculptor(xsize, ysize, zsize);
    s->setColor(1, 0, 0, 1);
    s->putEllipsoid(0, 0, 0, xsize - 1, ysize - 1, zsize - 1);
}

void CanvasMatrix::setYSize(int ny) {
    ysize = ny;
    delete s;
    s = new Sculptor(xsize, ysize, zsize);
    s->setColor(1, 0, 0, 1);
    s->putEllipsoid(0, 0, 0, xsize - 1, ysize - 1, zsize - 1);
}

void CanvasMatrix::setZSize(int nz) {
    zsize = nz;
    delete s;
    s = new Sculptor(xsize, ysize, zsize);
    s->setColor(1, 0, 0, 1);
    s->putEllipsoid(0, 0, 0, xsize - 1, ysize - 1, zsize - 1);
}

void CanvasMatrix::setZLayer(int z) {
    zlayer = z;
}

void CanvasMatrix::drawGrid() {
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(1);

    painter.setPen(pen);
    painter.setBrush(brush);

    int sizeY, sizeX, startX, startY;
    if (height()*xsize < width()*ysize) {
        startY = 0;
        sizeY = height();
        sizeX = (xsize*sizeY)/ysize;
        startX = (width() - sizeX)/2;
    } else {
        startX = 0;
        sizeX = width();
        sizeY = (ysize*sizeX)/xsize;
        startY = (height() - sizeY)/2;
    }
    for (int i = 0; i < xsize; i++) {
        for (int j = 0; j < ysize; j++) {
            if (s->vox(i, j, zlayer)->isOn) {
                brush.setColor(QColor((s->vox(i, j, zlayer)->r)*255,(s->vox(i, j, zlayer)->g)*255,(s->vox(i, j, zlayer)->b)*255));
                painter.setBrush(brush);
                painter.drawRect(startX + (sizeX*i)/xsize, startY + (sizeY*j)/ysize, sizeX/xsize, sizeY/ysize);
            } else {
                brush.setColor(QColor(255,255,255));
                painter.setBrush(brush);
                painter.drawRect(startX + (sizeX*i)/xsize, startY + (sizeY*j)/ysize, sizeX/xsize, sizeY/ysize);
            }
        }
    }
}


