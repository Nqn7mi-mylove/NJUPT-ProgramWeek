/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *getUser;
    QLineEdit *getPassword;
    QPushButton *help;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(478, 293);
        buttonBox = new QDialogButtonBox(Login);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 220, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getUser = new QLineEdit(Login);
        getUser->setObjectName(QString::fromUtf8("getUser"));
        getUser->setGeometry(QRect(130, 70, 211, 20));
        getPassword = new QLineEdit(Login);
        getPassword->setObjectName(QString::fromUtf8("getPassword"));
        getPassword->setGeometry(QRect(130, 140, 211, 20));
        help = new QPushButton(Login);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(10, 10, 71, 31));

        retranslateUi(Login);
        QObject::connect(buttonBox, SIGNAL(rejected()), Login, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), Login, SLOT(accept()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225\350\264\246\346\210\267", nullptr));
        help->setText(QApplication::translate("Login", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
