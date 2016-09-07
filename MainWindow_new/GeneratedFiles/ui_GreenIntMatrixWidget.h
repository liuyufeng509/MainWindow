/********************************************************************************
** Form generated from reading UI file 'GreenIntMatrixWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREENINTMATRIXWIDGET_H
#define UI_GREENINTMATRIXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_greenIntMatrixWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QTableWidget *matrixTableWidget;

    void setupUi(QWidget *greenIntMatrixWidget)
    {
        if (greenIntMatrixWidget->objectName().isEmpty())
            greenIntMatrixWidget->setObjectName(QStringLiteral("greenIntMatrixWidget"));
        greenIntMatrixWidget->resize(841, 476);
        verticalLayout = new QVBoxLayout(greenIntMatrixWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(greenIntMatrixWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(greenIntMatrixWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        matrixTableWidget = new QTableWidget(greenIntMatrixWidget);
        matrixTableWidget->setObjectName(QStringLiteral("matrixTableWidget"));

        verticalLayout->addWidget(matrixTableWidget);


        retranslateUi(greenIntMatrixWidget);

        QMetaObject::connectSlotsByName(greenIntMatrixWidget);
    } // setupUi

    void retranslateUi(QWidget *greenIntMatrixWidget)
    {
        greenIntMatrixWidget->setWindowTitle(QApplication::translate("greenIntMatrixWidget", "GreenIntMatrixWidget", 0));
        label->setText(QApplication::translate("greenIntMatrixWidget", "\345\220\215\347\247\260", 0));
    } // retranslateUi

};

namespace Ui {
    class greenIntMatrixWidget: public Ui_greenIntMatrixWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREENINTMATRIXWIDGET_H
