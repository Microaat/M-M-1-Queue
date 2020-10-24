#include "multiqueuewindow.h"
#include "ui_multiqueuewindow.h"

MultiQueueWindow::MultiQueueWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiQueueWindow)
{
    ui->setupUi(this);
}

MultiQueueWindow::~MultiQueueWindow()
{
    delete ui;
}
