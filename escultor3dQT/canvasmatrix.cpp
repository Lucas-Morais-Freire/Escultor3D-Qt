#include "canvasmatrix.h"
#include <cmath>
#include <QMouseEvent>

#include <iostream>

CanvasMatrix::CanvasMatrix(QWidget *parent) : QWidget{parent} {
    xsize = 10; ysize = 10; zsize = 10; zlayer = 0;
    s = new Sculptor(10,10,10);
    s->setColor(0,0,0,1);
    lPressed = false;
    rPressed = false;
    firstClick = true;
    paintMode = 0;
    rad = rx = ry = rz = 5;
    rc = 5;
    placeHolder.isOn = false;
    setMouseTracking(true);
}

CanvasMatrix::~CanvasMatrix() {
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

void CanvasMatrix::mousePressEvent(QMouseEvent *event) {
    if (event->button() == 1) {
        lPressed = true;
    }
    if (event->button() == 2) {
        rPressed = true;
    }
}

void CanvasMatrix::mouseReleaseEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
    if (xstart <= x && x <= xstart + w && ystart <= y && y <= ystart + h) {
        switch(paintMode) {
        case 0:
            if (lPressed) {
                s->putVoxel((xsize*(x - xstart))/w, (ysize*(y - ystart))/h, zlayer);
            } else if (rPressed) {
                s->cutVoxel((xsize*(x - xstart))/w, (ysize*(y - ystart))/h, zlayer);
            }
            this->repaint();
            break;
        case 1:
            if (firstClick) {
                firstCoords[0] = (xsize*(x - xstart))/w;
                firstCoords[1] = (ysize*(y - ystart))/h;
                firstCoords[2] = zlayer;
                placeHolder = *(s->vox(firstCoords[0], firstCoords[1], firstCoords[2]));
                s->putVoxel(firstCoords[0], firstCoords[1], firstCoords[2]);
                this->repaint();
                firstClick = false;
            } else {
                if (lPressed) {
                    s->putBox(firstCoords[0], (xsize*(x - xstart))/w, firstCoords[1], (ysize*(y - ystart))/h, firstCoords[2], zlayer);
                } else if (rPressed) {
                    s->cutBox(firstCoords[0], (xsize*(x - xstart))/w, firstCoords[1], (ysize*(y - ystart))/h, firstCoords[2], zlayer);
                }
                this->repaint();
                firstClick = true;
            }
            break;
        }
    }
    lPressed = rPressed = false;
}

void CanvasMatrix::mouseMoveEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
    if (xstart <= x && x <= xstart + w && ystart <= y && y <= ystart + h) {
        switch(paintMode) {
        case 0:
            if (lPressed) {
                s->putVoxel((xsize*(x - xstart))/w, (ysize*(y - ystart))/h, zlayer);
                this->repaint();
            } else if (rPressed) {
                s->cutVoxel((xsize*(x - xstart))/w, (ysize*(y - ystart))/h, zlayer);
                this->repaint();
            }
            break;
        }
    }
}

void CanvasMatrix::setXSize(int nx) {
    xsize = nx;
    Sculptor* temp = new Sculptor(xsize, ysize, zsize);
    temp->setColor(s->getR(), s->getG(), s->getB(), s->getA());
    delete s;
    s = temp;
}

void CanvasMatrix::setYSize(int ny) {
    ysize = ny;
    Sculptor* temp = new Sculptor(xsize, ysize, zsize);
    temp->setColor(s->getR(), s->getG(), s->getB(), s->getA());
    delete s;
    s = temp;
}

void CanvasMatrix::setZSize(int nz) {
    zsize = nz;
    Sculptor* temp = new Sculptor(xsize, ysize, zsize);
    temp->setColor(s->getR(), s->getG(), s->getB(), s->getA());
    delete s;
    s = temp;
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

    if (height()*xsize < width()*ysize) {
        ystart = 0;
        h = height();
        w = (xsize*h)/ysize;
        xstart = (width() - w)/2;
    } else {
        xstart = 0;
        w = width();
        h = (ysize*w)/xsize;
        ystart = (height() - h)/2;
    }
    for (int i = 0; i < xsize; i++) {
        for (int j = 0; j < ysize; j++) {
            if (s->vox(i, j, zlayer)->isOn) {
                brush.setColor(QColor((s->vox(i, j, zlayer)->r)*255,(s->vox(i, j, zlayer)->g)*255,(s->vox(i, j, zlayer)->b)*255));
                painter.setBrush(brush);
                painter.drawRect(xstart + (w*i)/xsize, ystart + (h*j)/ysize, w/xsize, h/ysize);
            } else {
                brush.setColor(QColor(255,255,255));
                painter.setBrush(brush);
                painter.drawRect(xstart + (w*i)/xsize, ystart + (h*j)/ysize, w/xsize, h/ysize);
            }
        }
    }
}

void CanvasMatrix::changeMode(short unsigned int mode) {
    if (paintMode == 1 && !firstClick && mode != 1) {
        firstClick = true;
        if (placeHolder.isOn) {
            float r, g, b, a;
            r = s->getR(); g = s->getG(); b = s->getB(); a = s->getA();
            s->setColor(placeHolder.r, placeHolder.g, placeHolder.b, placeHolder.a);
            s->putVoxel(firstCoords[0], firstCoords[1], firstCoords[2]);
            s->setColor(r, g, b, a);
        } else {
            s->cutVoxel(firstCoords[0], firstCoords[1], firstCoords[2]);
        }
        this->repaint();
    }
    paintMode = mode;
}

void CanvasMatrix::saveDrawing() {
    s->writeOFF("poggers.off");
}

void CanvasMatrix::changeColor(float r, float g, float b) {
    s->setColor(r, g, b, 1);
}


