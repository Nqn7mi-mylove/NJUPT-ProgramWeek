#ifndef SEARCHLINE_H
#define SEARCHLINE_H

#include <QDialog>
#include <bits/stdc++.h>
#include <QFile>
#include <QTextStream>
#include <QCompleter>
#include <QMessageBox>

using namespace std;

namespace Ui {
class searchline;
}

class searchline : public QDialog
{
    Q_OBJECT

public:
    explicit searchline(QWidget *parent = nullptr);
    ~searchline();

private slots:
    void on_search_clicked();

    void on_findLine_selectionChanged();

private:
    Ui::searchline *ui;
};

#endif // SEARCHLINE_H
