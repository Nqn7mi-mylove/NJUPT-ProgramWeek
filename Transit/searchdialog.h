#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QApplication>
#include <QLineEdit>
#include <QCompleter>
#include <bits/stdc++.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

using namespace std;

namespace Ui {
class searchDialog;
}

class searchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchDialog(QWidget *parent = nullptr);
    ~searchDialog();

private slots:

    void on_getStart_selectionChanged();

    void on_getEnd_selectionChanged();

    void on_searchButton_clicked();

private:
    Ui::searchDialog *ui;
};

#endif // SEARCHDIALOG_H
