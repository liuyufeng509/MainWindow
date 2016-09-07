/********************************************************************************
** Form generated from reading UI file 'sequencewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQUENCEWIDGET_H
#define UI_SEQUENCEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SequenceWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *startPhaseComboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_countStage;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SequenceWidget)
    {
        if (SequenceWidget->objectName().isEmpty())
            SequenceWidget->setObjectName(QStringLiteral("SequenceWidget"));
        SequenceWidget->resize(852, 463);
        gridLayout = new QGridLayout(SequenceWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(SequenceWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nameLineEdit = new QLineEdit(SequenceWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout_2->addWidget(nameLineEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(SequenceWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        startPhaseComboBox = new QComboBox(SequenceWidget);
        startPhaseComboBox->setObjectName(QStringLiteral("startPhaseComboBox"));

        horizontalLayout->addWidget(startPhaseComboBox);

        label_3 = new QLabel(SequenceWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_countStage = new QLineEdit(SequenceWidget);
        lineEdit_countStage->setObjectName(QStringLiteral("lineEdit_countStage"));
        lineEdit_countStage->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(lineEdit_countStage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tableWidget = new QTableWidget(SequenceWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 2, 0, 1, 1);


        retranslateUi(SequenceWidget);

        QMetaObject::connectSlotsByName(SequenceWidget);
    } // setupUi

    void retranslateUi(QWidget *SequenceWidget)
    {
        SequenceWidget->setWindowTitle(QApplication::translate("SequenceWidget", "SequenceSet", 0));
        label->setText(QApplication::translate("SequenceWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("SequenceWidget", "\350\265\267\345\247\213\347\233\270\344\275\215\357\274\232", 0));
        label_3->setText(QApplication::translate("SequenceWidget", "\346\234\211\346\225\210\346\256\265\346\225\260\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SequenceWidget", "\351\230\266\346\256\265", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SequenceWidget", "\347\233\270\345\272\217", 0));
    } // retranslateUi

};

namespace Ui {
    class SequenceWidget: public Ui_SequenceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQUENCEWIDGET_H
