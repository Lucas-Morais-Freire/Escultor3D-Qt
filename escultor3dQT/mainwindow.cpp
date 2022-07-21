#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->camada_z->setMaximum(9);
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
}

void MainWindow::boxMode() {
    ui->matriz->changeMode(1);
}

void MainWindow::sphereMode() {
    ui->matriz->changeMode(2);
}

void MainWindow::ellipsoidMode() {
    ui->matriz->changeMode(3);
}

void MainWindow::cylinderMode() {
    ui->matriz->changeMode(4);
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

