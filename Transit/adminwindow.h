#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <bits/stdc++.h>



#include "searchdialog.h"

using namespace std;

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_roadSearch_clicked();

    void on_randomGen_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
