#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
#include <QMessageBox>

#include "searchdialog.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_roadSearch_clicked();

    void on_help_clicked();

    void on_showMap_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
