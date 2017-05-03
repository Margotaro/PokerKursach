#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QLabel"
#include <QPixmap>

MainWindow* MainWindow::instance = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    instance = this;
}

MainWindow* MainWindow::getInstance() {
    return instance;
}

MainWindow::~MainWindow()
{
    delete ui;
}
