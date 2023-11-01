/********************************************************************************
** Form generated from reading UI file 'searchline.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHLINE_H
#define UI_SEARCHLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_searchline
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *findLine;
    QTextEdit *outLine;
    QPushButton *search;

    void setupUi(QDialog *searchline)
    {
        if (searchline->objectName().isEmpty())
            searchline->setObjectName(QString::fromUtf8("searchline"));
        searchline->resize(664, 393);
        buttonBox = new QDialogButtonBox(searchline);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        findLine = new QLineEdit(searchline);
        findLine->setObjectName(QString::fromUtf8("findLine"));
        findLine->setGeometry(QRect(80, 40, 131, 20));
        outLine = new QTextEdit(searchline);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setGeometry(QRect(80, 90, 501, 201));
        search = new QPushButton(searchline);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(450, 30, 121, 41));

        retranslateUi(searchline);
        QObject::connect(buttonBox, SIGNAL(accepted()), searchline, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), searchline, SLOT(reject()));

        QMetaObject::connectSlotsByName(searchline);
    } // setupUi

    void retranslateUi(QDialog *searchline)
    {
        searchline->setWindowTitle(QApplication::translate("searchline", "\346\237\245\350\257\242", nullptr));
        search->setText(QApplication::translate("searchline", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchline: public Ui_searchline {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHLINE_H
