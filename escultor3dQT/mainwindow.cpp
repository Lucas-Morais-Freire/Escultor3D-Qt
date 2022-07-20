#include "mainwindow.h"
#include "ui_mainwindow.h"

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
