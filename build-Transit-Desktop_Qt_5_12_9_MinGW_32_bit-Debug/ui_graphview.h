/********************************************************************************
** Form generated from reading UI file 'graphview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEW_H
#define UI_GRAPHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphView
{
public:

    void setupUi(QWidget *GraphView)
    {
        if (GraphView->objectName().isEmpty())
            GraphView->setObjectName(QString::fromUtf8("GraphView"));
        GraphView->resize(400, 300);

        retranslateUi(GraphView);

        QMetaObject::connectSlotsByName(GraphView);
    } // setupUi

    void retranslateUi(QWidget *GraphView)
    {
        GraphView->setWindowTitle(QApplication::translate("GraphView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphView: public Ui_GraphView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEW_H
