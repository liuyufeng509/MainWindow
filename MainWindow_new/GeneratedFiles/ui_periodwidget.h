/********************************************************************************
** Form generated from reading UI file 'periodwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERIODWIDGET_H
#define UI_PERIODWIDGET_H

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
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PeriodWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QTimeEdit *startTimeEdit;
    QLabel *startTimeLabel;
    QLabel *label_3;
    QTimeEdit *endTimeEdit;
    QLabel *endTimeLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *planComboBox;
    QLabel *label_5;
    QComboBox *transPlanComboBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *PeriodWidget)
    {
        if (PeriodWidget->objectName().isEmpty())
            PeriodWidget->setObjectName(QStringLiteral("PeriodWidget"));
        PeriodWidget->resize(608, 492);
        gridLayout = new QGridLayout(PeriodWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PeriodWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(PeriodWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setEnabled(false);

        horizontalLayout->addWidget(nameLineEdit);

        label_2 = new QLabel(PeriodWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        startTimeEdit = new QTimeEdit(PeriodWidget);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));
        startTimeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        startTimeEdit->setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        startTimeEdit->setMinimumTime(QTime(0, 0, 0));

        horizontalLayout->addWidget(startTimeEdit);

        startTimeLabel = new QLabel(PeriodWidget);
        startTimeLabel->setObjectName(QStringLiteral("startTimeLabel"));
        startTimeLabel->setMinimumSize(QSize(54, 0));

        horizontalLayout->addWidget(startTimeLabel);

        label_3 = new QLabel(PeriodWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        endTimeEdit = new QTimeEdit(PeriodWidget);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));
        endTimeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        endTimeEdit->setMinimumDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        endTimeEdit->setMinimumTime(QTime(0, 0, 0));

        horizontalLayout->addWidget(endTimeEdit);

        endTimeLabel = new QLabel(PeriodWidget);
        endTimeLabel->setObjectName(QStringLiteral("endTimeLabel"));
        endTimeLabel->setMinimumSize(QSize(54, 0));

        horizontalLayout->addWidget(endTimeLabel);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(PeriodWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        planComboBox = new QComboBox(PeriodWidget);
        planComboBox->setObjectName(QStringLiteral("planComboBox"));

        horizontalLayout_2->addWidget(planComboBox);

        label_5 = new QLabel(PeriodWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        transPlanComboBox = new QComboBox(PeriodWidget);
        transPlanComboBox->setObjectName(QStringLiteral("transPlanComboBox"));

        horizontalLayout_2->addWidget(transPlanComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        retranslateUi(PeriodWidget);

        QMetaObject::connectSlotsByName(PeriodWidget);
    } // setupUi

    void retranslateUi(QWidget *PeriodWidget)
    {
        PeriodWidget->setWindowTitle(QApplication::translate("PeriodWidget", "PeriodWidget", 0));
        label->setText(QApplication::translate("PeriodWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("PeriodWidget", "\350\265\267\345\247\213\346\227\266\351\227\264\357\274\232", 0));
        startTimeEdit->setDisplayFormat(QApplication::translate("PeriodWidget", "HH:mm:ss", 0));
        startTimeLabel->setText(QString());
        label_3->setText(QApplication::translate("PeriodWidget", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", 0));
        endTimeEdit->setDisplayFormat(QApplication::translate("PeriodWidget", "HH:mm:ss", 0));
        endTimeLabel->setText(QString());
        label_4->setText(QApplication::translate("PeriodWidget", "\345\257\271\345\272\224\346\226\271\346\241\210\345\217\267\357\274\232", 0));
        label_5->setText(QApplication::translate("PeriodWidget", "\345\257\271\345\272\224\350\277\207\346\270\241\346\226\271\346\241\210\345\217\267\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class PeriodWidget: public Ui_PeriodWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERIODWIDGET_H
