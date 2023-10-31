#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMainWindow>
#include "adminwindow.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_getUser_selectionChanged();

    void on_getPassword_selectionChanged();

    void on_buttonBox_accepted();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
