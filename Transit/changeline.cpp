#include "changeline.h"
#include "ui_changeline.h"

changeLine::changeLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeLine)
{
    ui->setupUi(this);
}

changeLine::~changeLine()
{
    delete ui;
}
