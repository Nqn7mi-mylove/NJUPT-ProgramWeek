/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *randomGen;
    QPushButton *roadChange;
    QPushButton *roadSearch;
    QPushButton *lineSearch;
    QPushButton *help;
    QPushButton *nanjing;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(671, 486);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 721, 151));
        randomGen = new QPushButton(centralwidget);
        randomGen->setObjectName(QString::fromUtf8("randomGen"));
        randomGen->setGeometry(QRect(360, 240, 151, 51));
        roadChange = new QPushButton(centralwidget);
        roadChange->setObjectName(QString::fromUtf8("roadChange"));
        roadChange->setGeometry(QRect(140, 240, 151, 51));
        roadSearch = new QPushButton(centralwidget);
        roadSearch->setObjectName(QString::fromUtf8("roadSearch"));
        roadSearch->setGeometry(QRect(360, 150, 151, 51));
        lineSearch = new QPushButton(centralwidget);
        lineSearch->setObjectName(QString::fromUtf8("lineSearch"));
        lineSearch->setGeometry(QRect(140, 150, 151, 51));
        help = new QPushButton(centralwidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(10, 0, 81, 31));
        nanjing = new QPushButton(centralwidget);
        nanjing->setObjectName(QString::fromUtf8("nanjing"));
        nanjing->setGeometry(QRect(140, 320, 371, 51));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 671, 21));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "\345\205\254\345\205\261\344\272\244\351\200\232\345\257\274\350\210\252\347\263\273\347\273\237(admin)", nullptr));
        label->setText(QApplication::translate("AdminWindow", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:600;\">\345\205\254\345\205\261\344\272\244\351\200\232\345\257\274\350\210\252\347\263\273\347\273\237-\347\256\241\347\220\206\345\221\230\347\253\257</span></p></body></html>", nullptr));
        randomGen->setText(QApplication::translate("AdminWindow", "\351\232\217\346\234\272\347\224\237\346\210\220", nullptr));
        roadChange->setText(QApplication::translate("AdminWindow", "\344\277\256\346\224\271\350\267\257\347\272\277", nullptr));
        roadSearch->setText(QApplication::translate("AdminWindow", "\347\272\277\350\267\257\346\237\245\350\257\242", nullptr));
        lineSearch->setText(QApplication::translate("AdminWindow", "\350\275\246\346\254\241\346\237\245\350\257\242", nullptr));
        help->setText(QApplication::translate("AdminWindow", "\345\270\256\345\212\251", nullptr));
        nanjing->setText(QApplication::translate("AdminWindow", "\345\210\207\346\215\242\345\210\260\345\215\227\344\272\254\345\205\254\344\272\244\347\272\277\350\267\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
