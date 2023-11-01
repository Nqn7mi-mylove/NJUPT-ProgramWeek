#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_roadSearch_clicked()
{
    searchDialog *searchD=new searchDialog;
    searchD->show();
}

void MainWindow::on_help_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("帮助");
    msgBox.setText("此处界面为用户端，无法增添、修改路线。\n如需增添修改，请使用管理员账号登陆");
    msgBox.exec();
}

void MainWindow::on_showMap_clicked()
{

}
