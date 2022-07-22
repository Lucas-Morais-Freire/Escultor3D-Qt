#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvasmatrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
public slots:
    void changeXSize();
    void changeYSize();
    void changeZSize();
    void changeZLayer();
    void voxelMode();
    void boxMode();
    void sphereMode();
    void ellipsoidMode();
    void cylinderMode();
    void changeColor();
    void showColor();
};
#endif // MAINWINDOW_H
