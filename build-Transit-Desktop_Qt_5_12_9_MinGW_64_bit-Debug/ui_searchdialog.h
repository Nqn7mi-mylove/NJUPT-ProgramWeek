/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_searchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *getStart;
    QLineEdit *getEnd;
    QTextEdit *sendRoad;
    QPushButton *searchButton;

    void setupUi(QDialog *searchDialog)
    {
        if (searchDialog->objectName().isEmpty())
            searchDialog->setObjectName(QString::fromUtf8("searchDialog"));
        searchDialog->resize(391, 424);
        buttonBox = new QDialogButtonBox(searchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 370, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getStart = new QLineEdit(searchDialog);
        getStart->setObjectName(QString::fromUtf8("getStart"));
        getStart->setGeometry(QRect(80, 30, 231, 20));
        getEnd = new QLineEdit(searchDialog);
        getEnd->setObjectName(QString::fromUtf8("getEnd"));
        getEnd->setGeometry(QRect(80, 70, 231, 20));
        sendRoad = new QTextEdit(searchDialog);
        sendRoad->setObjectName(QString::fromUtf8("sendRoad"));
        sendRoad->setGeometry(QRect(60, 170, 271, 171));
        searchButton = new QPushButton(searchDialog);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(140, 110, 111, 41));

        retranslateUi(searchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), searchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), searchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(searchDialog);
    } // setupUi

    void retranslateUi(QDialog *searchDialog)
    {
        searchDialog->setWindowTitle(QApplication::translate("searchDialog", "\347\272\277\350\267\257\346\237\245\350\257\242", nullptr));
        searchButton->setText(QApplication::translate("searchDialog", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchDialog: public Ui_searchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
