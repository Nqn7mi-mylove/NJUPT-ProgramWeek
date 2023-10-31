#include "searchdialog.h"
#include "ui_searchdialog.h"

searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    ui->setupUi(this);

    ui->getStart->setPlaceholderText("请输入起点");
    ui->getEnd->setPlaceholderText("请输入终点");

    QStringList list;
    list.append("aaa1");
    list.append("aaa2");
    list.append("aaa3");
    list.append("bbb1");
    QCompleter *completer = new QCompleter(list, ui->getStart);
    ui->getStart->setCompleter(completer);
}

searchDialog::~searchDialog()
{
    delete ui;
}


void searchDialog::on_getStart_selectionChanged()
{
    ui->getStart->clear();
}

void searchDialog::on_getEnd_selectionChanged()
{
    ui->getEnd->clear();
}
