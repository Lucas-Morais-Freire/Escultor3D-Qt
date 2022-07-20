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
    int xsize, ysize, zsize, zlayer;
    Sculptor* s;
public:
    explicit CanvasMatrix(QWidget *parent = nullptr);
    ~CanvasMatrix();
    void paintEvent(QPaintEvent *event);
    void setXSize(int nx);
    void setYSize(int ny);
    void setZSize(int nz);
    void setZLayer(int z);
    void drawGrid();
signals:
};

#endif // CANVASMATRIX_H
