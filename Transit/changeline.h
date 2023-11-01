#ifndef CHANGELINE_H
#define CHANGELINE_H

#include <QDialog>
#include <bits/stdc++.h>
#include <QFile>
#include <QTextStream>
#include <QCompleter>
#include <QMessageBox>

using namespace std;

namespace Ui {
class changeLine;
}

class changeLine : public QDialog
{
    Q_OBJECT

public:
    explicit changeLine(QWidget *parent = nullptr);
    ~changeLine();

private:
    Ui::changeLine *ui;
};

#endif // CHANGELINE_H
