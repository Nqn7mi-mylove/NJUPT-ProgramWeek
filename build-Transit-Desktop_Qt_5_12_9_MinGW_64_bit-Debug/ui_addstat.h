/********************************************************************************
** Form generated from reading UI file 'addstat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTAT_H
#define UI_ADDSTAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_addStat
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *statName;
    QLineEdit *toLast;
    QLineEdit *toNext;

    void setupUi(QDialog *addStat)
    {
        if (addStat->objectName().isEmpty())
            addStat->setObjectName(QString::fromUtf8("addStat"));
        addStat->resize(393, 225);
        buttonBox = new QDialogButtonBox(addStat);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        statName = new QLineEdit(addStat);
        statName->setObjectName(QString::fromUtf8("statName"));
        statName->setGeometry(QRect(60, 50, 271, 20));
        toLast = new QLineEdit(addStat);
        toLast->setObjectName(QString::fromUtf8("toLast"));
        toLast->setGeometry(QRect(60, 90, 271, 20));
        toNext = new QLineEdit(addStat);
        toNext->setObjectName(QString::fromUtf8("toNext"));
        toNext->setGeometry(QRect(60, 130, 271, 20));

        retranslateUi(addStat);
        QObject::connect(buttonBox, SIGNAL(accepted()), addStat, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addStat, SLOT(reject()));

        QMetaObject::connectSlotsByName(addStat);
    } // setupUi

    void retranslateUi(QDialog *addStat)
    {
        addStat->setWindowTitle(QApplication::translate("addStat", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addStat: public Ui_addStat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTAT_H
