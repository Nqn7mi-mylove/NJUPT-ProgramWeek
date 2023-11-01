#ifndef CHANGELINE_H
#define CHANGELINE_H

#include <QDialog>
#include <bits/stdc++.h>
#include <QFile>
#include <QTextStream>
#include <QCompleter>
#include <QMessageBox>
#include <QListWidget>
#include <QInputDialog>

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
    void addItem();

private slots:
    void on_pushButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

private:
    Ui::changeLine *ui;
};

#endif // CHANGELINE_H
