/********************************************************************************
** Form generated from reading UI file 'transwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSWIDGET_H
#define UI_TRANSWIDGET_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *phaseComboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TransWidget)
    {
        if (TransWidget->objectName().isEmpty())
            TransWidget->setObjectName(QStringLiteral("TransWidget"));
        TransWidget->resize(655, 491);
        gridLayout = new QGridLayout(TransWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TransWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(TransWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setEnabled(false);

        horizontalLayout->addWidget(nameLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(TransWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        phaseComboBox = new QComboBox(TransWidget);
        phaseComboBox->setObjectName(QStringLiteral("phaseComboBox"));
        phaseComboBox->setMinimumSize(QSize(160, 0));

        horizontalLayout->addWidget(phaseComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 442, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(TransWidget);

        QMetaObject::connectSlotsByName(TransWidget);
    } // setupUi

    void retranslateUi(QWidget *TransWidget)
    {
        TransWidget->setWindowTitle(QApplication::translate("TransWidget", "TransWidget", 0));
        label->setText(QApplication::translate("TransWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("TransWidget", "\345\260\206\350\246\201\347\273\223\346\235\237\347\232\204\347\233\270\344\275\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class TransWidget: public Ui_TransWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSWIDGET_H
