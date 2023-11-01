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
#include <QtWidgets/QLabel>
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
    QLabel *label;

    void setupUi(QDialog *searchDialog)
    {
        if (searchDialog->objectName().isEmpty())
            searchDialog->setObjectName(QString::fromUtf8("searchDialog"));
        searchDialog->resize(954, 471);
        buttonBox = new QDialogButtonBox(searchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(580, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getStart = new QLineEdit(searchDialog);
        getStart->setObjectName(QString::fromUtf8("getStart"));
        getStart->setGeometry(QRect(70, 70, 231, 20));
        getEnd = new QLineEdit(searchDialog);
        getEnd->setObjectName(QString::fromUtf8("getEnd"));
        getEnd->setGeometry(QRect(70, 140, 231, 20));
        sendRoad = new QTextEdit(searchDialog);
        sendRoad->setObjectName(QString::fromUtf8("sendRoad"));
        sendRoad->setGeometry(QRect(340, 30, 581, 321));
        searchButton = new QPushButton(searchDialog);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(130, 250, 111, 41));
        label = new QLabel(searchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 450, 111, 16));

        retranslateUi(searchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), searchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), searchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(searchDialog);
    } // setupUi

    void retranslateUi(QDialog *searchDialog)
    {
        searchDialog->setWindowTitle(QApplication::translate("searchDialog", "\347\272\277\350\267\257\346\237\245\350\257\242", nullptr));
        searchButton->setText(QApplication::translate("searchDialog", "\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("searchDialog", "by Q21010312", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchDialog: public Ui_searchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
