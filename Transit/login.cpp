#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->getPassword->setEchoMode(QLineEdit::Password);
    ui->getPassword->setPlaceholderText("请输入密码");
    ui->getUser->setPlaceholderText("请输入用户名");
}

Login::~Login()
{
    delete ui;
}

void Login::on_getUser_selectionChanged()
{
    ui->getUser->clear();
}

void Login::on_getPassword_selectionChanged()
{
    ui->getPassword->clear();
}

void Login::on_buttonBox_accepted()
{
    if(ui->getUser->text()=="admin" && ui->getPassword->text()=="admin")
    {
        AdminWindow *w=new AdminWindow;
        w->show();
    }
    else
    {
        MainWindow *w=new MainWindow;
        w->show();
    }
}
