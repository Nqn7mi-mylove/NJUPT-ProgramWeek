/********************************************************************************
** Form generated from reading UI file 'changeline.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGELINE_H
#define UI_CHANGELINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changeLine
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLineEdit *findLine;
    QPushButton *pushButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *changeButton;

    void setupUi(QDialog *changeLine)
    {
        if (changeLine->objectName().isEmpty())
            changeLine->setObjectName(QString::fromUtf8("changeLine"));
        changeLine->resize(839, 578);
        buttonBox = new QDialogButtonBox(changeLine);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(470, 520, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(changeLine);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 90, 751, 401));
        findLine = new QLineEdit(changeLine);
        findLine->setObjectName(QString::fromUtf8("findLine"));
        findLine->setGeometry(QRect(50, 40, 241, 20));
        pushButton = new QPushButton(changeLine);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 30, 151, 41));
        addButton = new QPushButton(changeLine);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(50, 510, 91, 31));
        addButton->setFocusPolicy(Qt::NoFocus);
        deleteButton = new QPushButton(changeLine);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(160, 510, 91, 31));
        changeButton = new QPushButton(changeLine);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));
        changeButton->setGeometry(QRect(270, 510, 91, 31));

        retranslateUi(changeLine);
        QObject::connect(buttonBox, SIGNAL(accepted()), changeLine, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changeLine, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeLine);
    } // setupUi

    void retranslateUi(QDialog *changeLine)
    {
        changeLine->setWindowTitle(QApplication::translate("changeLine", "\344\277\256\346\224\271", nullptr));
        pushButton->setText(QApplication::translate("changeLine", "\346\237\245\350\257\242", nullptr));
        addButton->setText(QApplication::translate("changeLine", "\346\267\273\345\212\240", nullptr));
        deleteButton->setText(QApplication::translate("changeLine", "\345\210\240\351\231\244", nullptr));
        changeButton->setText(QApplication::translate("changeLine", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeLine: public Ui_changeLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGELINE_H
