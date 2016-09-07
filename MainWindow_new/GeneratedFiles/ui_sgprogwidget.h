/********************************************************************************
** Form generated from reading UI file 'sgprogwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SGPROGWIDGET_H
#define UI_SGPROGWIDGET_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SgProgWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_6;
    QLineEdit *countPhaseLineEdit;
    QLabel *label_8;
    QComboBox *startPhaseComboBox;
    QLabel *label_7;
    QComboBox *ctrlTypeComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_9;
    QComboBox *comboBox_squence;
    QLabel *label_3;
    QSpinBox *cycleSpinBox;
    QLabel *label_4;
    QSpinBox *offSetSpinBox;
    QLabel *label_5;
    QSpinBox *switchPointSpinBox;
    QTableWidget *sgProgTableWidget;

    void setupUi(QWidget *SgProgWidget)
    {
        if (SgProgWidget->objectName().isEmpty())
            SgProgWidget->setObjectName(QStringLiteral("SgProgWidget"));
        SgProgWidget->resize(728, 441);
        gridLayout = new QGridLayout(SgProgWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SgProgWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(SgProgWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        horizontalLayout->addWidget(nameLineEdit);

        label_6 = new QLabel(SgProgWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        countPhaseLineEdit = new QLineEdit(SgProgWidget);
        countPhaseLineEdit->setObjectName(QStringLiteral("countPhaseLineEdit"));

        horizontalLayout->addWidget(countPhaseLineEdit);

        label_8 = new QLabel(SgProgWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        startPhaseComboBox = new QComboBox(SgProgWidget);
        startPhaseComboBox->setObjectName(QStringLiteral("startPhaseComboBox"));
        startPhaseComboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(startPhaseComboBox);

        label_7 = new QLabel(SgProgWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        ctrlTypeComboBox = new QComboBox(SgProgWidget);
        ctrlTypeComboBox->setObjectName(QStringLiteral("ctrlTypeComboBox"));

        horizontalLayout->addWidget(ctrlTypeComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SgProgWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(SgProgWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        label_9 = new QLabel(SgProgWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        comboBox_squence = new QComboBox(SgProgWidget);
        comboBox_squence->setObjectName(QStringLiteral("comboBox_squence"));

        horizontalLayout_2->addWidget(comboBox_squence);

        label_3 = new QLabel(SgProgWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        cycleSpinBox = new QSpinBox(SgProgWidget);
        cycleSpinBox->setObjectName(QStringLiteral("cycleSpinBox"));
        cycleSpinBox->setMaximum(10000);
        cycleSpinBox->setValue(100);

        horizontalLayout_2->addWidget(cycleSpinBox);

        label_4 = new QLabel(SgProgWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        offSetSpinBox = new QSpinBox(SgProgWidget);
        offSetSpinBox->setObjectName(QStringLiteral("offSetSpinBox"));
        offSetSpinBox->setMaximum(10000);
        offSetSpinBox->setValue(0);

        horizontalLayout_2->addWidget(offSetSpinBox);

        label_5 = new QLabel(SgProgWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        switchPointSpinBox = new QSpinBox(SgProgWidget);
        switchPointSpinBox->setObjectName(QStringLiteral("switchPointSpinBox"));
        switchPointSpinBox->setMaximum(10000);
        switchPointSpinBox->setValue(0);

        horizontalLayout_2->addWidget(switchPointSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        sgProgTableWidget = new QTableWidget(SgProgWidget);
        if (sgProgTableWidget->columnCount() < 19)
            sgProgTableWidget->setColumnCount(19);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        sgProgTableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lights/red"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem10->setIcon(icon);
        sgProgTableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lights/flashing_red"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setIcon(icon1);
        sgProgTableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lights/green"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setIcon(icon2);
        sgProgTableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setIcon(icon);
        sgProgTableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setIcon(icon1);
        sgProgTableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setIcon(icon2);
        sgProgTableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lights/red_amber"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setIcon(icon3);
        sgProgTableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lights/amber"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setIcon(icon4);
        sgProgTableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setIcon(icon1);
        sgProgTableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        sgProgTableWidget->setObjectName(QStringLiteral("sgProgTableWidget"));
        sgProgTableWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(sgProgTableWidget, 2, 0, 1, 1);


        retranslateUi(SgProgWidget);

        QMetaObject::connectSlotsByName(SgProgWidget);
    } // setupUi

    void retranslateUi(QWidget *SgProgWidget)
    {
        SgProgWidget->setWindowTitle(QApplication::translate("SgProgWidget", "SgProgWidget", 0));
        label->setText(QApplication::translate("SgProgWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_6->setText(QApplication::translate("SgProgWidget", "\346\234\211\346\225\210\347\233\270\344\275\215\346\225\260\357\274\232", 0));
        label_8->setText(QApplication::translate("SgProgWidget", "\345\274\200\345\247\213\347\233\270\344\275\215\357\274\232", 0));
        label_7->setText(QApplication::translate("SgProgWidget", "\346\216\247\345\210\266\346\226\271\345\274\217\357\274\232", 0));
        label_2->setText(QApplication::translate("SgProgWidget", "\347\273\277\347\201\257\351\227\264\351\232\224\357\274\232", 0));
        label_9->setText(QApplication::translate("SgProgWidget", "\347\233\270\345\272\217\357\274\232", 0));
        label_3->setText(QApplication::translate("SgProgWidget", "\345\221\250\346\234\237\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("SgProgWidget", "\345\201\217\347\247\273\357\274\232", 0));
        label_5->setText(QApplication::translate("SgProgWidget", "\345\210\207\346\215\242\347\202\271\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem = sgProgTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SgProgWidget", "\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = sgProgTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SgProgWidget", "\344\277\241\345\217\267\347\201\257\347\273\204", 0));
        QTableWidgetItem *___qtablewidgetitem2 = sgProgTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SgProgWidget", "\347\233\270\344\275\215\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem3 = sgProgTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SgProgWidget", "\345\215\217\350\260\203\347\233\270\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem4 = sgProgTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SgProgWidget", "\346\234\200\345\260\217\347\273\277", 0));
        QTableWidgetItem *___qtablewidgetitem5 = sgProgTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SgProgWidget", "\346\234\200\345\244\247\347\273\2771", 0));
        QTableWidgetItem *___qtablewidgetitem6 = sgProgTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SgProgWidget", "\346\234\200\345\244\247\347\273\2772", 0));
        QTableWidgetItem *___qtablewidgetitem7 = sgProgTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("SgProgWidget", "\345\273\266\351\225\277\347\273\277", 0));
        QTableWidgetItem *___qtablewidgetitem8 = sgProgTableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("SgProgWidget", "\344\277\241\345\217\267\345\272\217\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem9 = sgProgTableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("SgProgWidget", "\345\233\276\345\275\242\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem10 = sgProgTableWidget->horizontalHeaderItem(10);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem10->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242\347\201\2571\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem11 = sgProgTableWidget->horizontalHeaderItem(11);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem11->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242\351\227\2521\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem12 = sgProgTableWidget->horizontalHeaderItem(12);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem12->setToolTip(QApplication::translate("SgProgWidget", "\347\273\277\347\201\2571\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem13 = sgProgTableWidget->horizontalHeaderItem(13);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem13->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242\347\201\2572\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem14 = sgProgTableWidget->horizontalHeaderItem(14);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem14->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242\351\227\2522\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem15 = sgProgTableWidget->horizontalHeaderItem(15);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem15->setToolTip(QApplication::translate("SgProgWidget", "\347\273\277\347\201\2572\347\273\223\346\235\237", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem16 = sgProgTableWidget->horizontalHeaderItem(16);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem16->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242/\351\273\204", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem17 = sgProgTableWidget->horizontalHeaderItem(17);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem17->setToolTip(QApplication::translate("SgProgWidget", "\351\273\204\347\201\257", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem18 = sgProgTableWidget->horizontalHeaderItem(18);
#endif
#ifndef QT_NO_TOOLTIP
        ___qtablewidgetitem18->setToolTip(QApplication::translate("SgProgWidget", "\347\272\242\351\227\252", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class SgProgWidget: public Ui_SgProgWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SGPROGWIDGET_H
