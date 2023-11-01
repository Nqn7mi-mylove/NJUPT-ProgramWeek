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
    QLineEdit *lineEdit;
    QPushButton *pushButton;

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
        listWidget->setGeometry(QRect(50, 90, 761, 401));
        lineEdit = new QLineEdit(changeLine);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 40, 241, 20));
        pushButton = new QPushButton(changeLine);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 30, 151, 41));

        retranslateUi(changeLine);
        QObject::connect(buttonBox, SIGNAL(accepted()), changeLine, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), changeLine, SLOT(reject()));

        QMetaObject::connectSlotsByName(changeLine);
    } // setupUi

    void retranslateUi(QDialog *changeLine)
    {
        changeLine->setWindowTitle(QApplication::translate("changeLine", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("changeLine", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeLine: public Ui_changeLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGELINE_H
