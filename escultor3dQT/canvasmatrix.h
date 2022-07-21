#ifndef CANVASMATRIX_H
#define CANVASMATRIX_H

#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QWidget>
#include "sculptor.h"

class CanvasMatrix : public QWidget {
    Q_OBJECT
private:
    int xsize, ysize, zsize, zlayer, h, w, xstart, ystart;
    bool lPressed, rPressed, firstClick;
    int firstCoords[3];
    int rad, rx, ry, rz;
    float rc;
    Voxel placeHolder;
    Sculptor* s;
    short unsigned int paintMode;
public:
    explicit CanvasMatrix(QWidget *parent = nullptr);
    ~CanvasMatrix();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setXSize(int nx);
    void setYSize(int ny);
    void setZSize(int nz);
    void setZLayer(int z);
    void drawGrid();
    void changeMode(short unsigned int mode);
public slots:
    void saveDrawing();
    void changeColor(float r, float g, float b);
signals:
};

#endif // CANVASMATRIX_H
