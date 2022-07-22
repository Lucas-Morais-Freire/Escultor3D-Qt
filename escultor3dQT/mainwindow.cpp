#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zrad, SIGNAL(valueChanged(int)), ui->matriz, SLOT(changeZRadius(int)));
    connect(ui->yrad, SIGNAL(valueChanged(int)), ui->matriz, SLOT(changeYRadius(int)));
    connect(ui->xrad, SIGNAL(valueChanged(int)), ui->matriz, SLOT(changeXRadius(int)));

    connect(ui->rad, SIGNAL(valueChanged(int)), ui->matriz, SLOT(changeRadius(int)));

    connect(ui->crad, SIGNAL(valueChanged(double)), ui->matriz, SLOT(changeCRadius(double)));

    connect(ui->camada_z, SIGNAL(valueChanged(int)), ui->label, SLOT(setNum(int)));
    connect(ui->camada_z, SIGNAL(valueChanged(int)), this, SLOT(changeZLayer()));

    connect(ui->toolButton_2, SIGNAL(clicked()), ui->matriz, SLOT(viewDrawing()));
    connect(ui->toolButton, SIGNAL(clicked()), ui->matriz, SLOT(saveDrawing()));

    connect(ui->red, SIGNAL(valueChanged(int)), ui->redLabel, SLOT(setNum(int)));
    connect(ui->red, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->red, SIGNAL(valueChanged(int)), this, SLOT(showColor()));

    connect(ui->green, SIGNAL(valueChanged(int)), ui->greenLabel, SLOT(setNum(int)));
    connect(ui->green, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->green, SIGNAL(valueChanged(int)), this, SLOT(showColor()));

    connect(ui->blue, SIGNAL(valueChanged(int)), ui->blueLabel, SLOT(setNum(int)));
    connect(ui->blue, SIGNAL(valueChanged(int)), this, SLOT(changeColor()));
    connect(ui->blue, SIGNAL(valueChanged(int)), this, SLOT(showColor()));

    connect(ui->putvoxel, SIGNAL(clicked()), this, SLOT(voxelMode()));
    connect(ui->putsphere, SIGNAL(clicked()), this, SLOT(sphereMode()));
    connect(ui->putellipsoid, SIGNAL(clicked()), this, SLOT(ellipsoidMode()));
    connect(ui->putcylinder, SIGNAL(clicked()), this, SLOT(cylinderMode()));
    connect(ui->putbox, SIGNAL(clicked()), this, SLOT(boxMode()));

    connect(ui->nz, SIGNAL(valueChanged(int)), this, SLOT(changeZSize()));
    connect(ui->ny, SIGNAL(valueChanged(int)), this, SLOT(changeYSize()));
    connect(ui->nx, SIGNAL(valueChanged(int)), this, SLOT(changeXSize()));

    connect(ui->matriz, SIGNAL(askCommand(QString)), ui->inst, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeXSize() {
    ui->matriz->setXSize(ui->nx->value());
    ui->matriz->repaint();
}

void MainWindow::changeYSize() {
    ui->matriz->setYSize(ui->ny->value());
    ui->matriz->repaint();
}

void MainWindow::changeZSize() {
    ui->matriz->setZSize(ui->nz->value());
    ui->matriz->repaint();
    ui->camada_z->setMaximum(ui->nz->value() - 1);
}

void MainWindow::changeZLayer() {
    ui->matriz->setZLayer(ui->camada_z->value());
    ui->matriz->repaint();
}

void MainWindow::voxelMode() {
    ui->matriz->changeMode(0);
    ui->putvoxel->setEnabled(false);
    ui->putbox->setEnabled(true);
    ui->putsphere->setEnabled(true);
    ui->putellipsoid->setEnabled(true);
    ui->putcylinder->setEnabled(true);
}

void MainWindow::boxMode() {
    ui->matriz->changeMode(1);
    ui->putvoxel->setEnabled(true);
    ui->putbox->setEnabled(false);
    ui->putsphere->setEnabled(true);
    ui->putellipsoid->setEnabled(true);
    ui->putcylinder->setEnabled(true);
}

void MainWindow::sphereMode() {
    ui->matriz->changeMode(2);
    ui->putvoxel->setEnabled(true);
    ui->putbox->setEnabled(true);
    ui->putsphere->setEnabled(false);
    ui->putellipsoid->setEnabled(true);
    ui->putcylinder->setEnabled(true);
}

void MainWindow::ellipsoidMode() {
    ui->matriz->changeMode(3);
    ui->putvoxel->setEnabled(true);
    ui->putbox->setEnabled(true);
    ui->putsphere->setEnabled(true);
    ui->putellipsoid->setEnabled(false);
    ui->putcylinder->setEnabled(true);
}

void MainWindow::cylinderMode() {
    ui->matriz->changeMode(4);
    ui->putvoxel->setEnabled(true);
    ui->putbox->setEnabled(true);
    ui->putsphere->setEnabled(true);
    ui->putellipsoid->setEnabled(true);
    ui->putcylinder->setEnabled(false);
}

void MainWindow::changeColor() {
    ui->matriz->changeColor((ui->red->value())/255.0,(ui->green->value())/255.0,(ui->blue->value())/255.0);
}

void MainWindow::showColor() {
    int r = ui->red->value();
    int g = ui->green->value();
    int b = ui->blue->value();
    ui->colorDisplay->setStyleSheet(QString("background-color: rgb(") + QString::number(r) + QString(", ") + QString::number(g) + QString(", ") + QString::number(b) + QString(")"));
}

