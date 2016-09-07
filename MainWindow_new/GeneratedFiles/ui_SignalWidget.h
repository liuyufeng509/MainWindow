/********************************************************************************
** Form generated from reading UI file 'SignalWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALWIDGET_H
#define UI_SIGNALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignalWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QComboBox *typeComboBox;
    QLabel *label_3;
    QTableWidget *typeTableWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QTextEdit *bakTextEdit;

    void setupUi(QWidget *SignalWidget)
    {
        if (SignalWidget->objectName().isEmpty())
            SignalWidget->setObjectName(QStringLiteral("SignalWidget"));
        SignalWidget->resize(835, 725);
        gridLayout = new QGridLayout(SignalWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SignalWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(SignalWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        verticalLayout->addWidget(nameLineEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(SignalWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(label_2);

        typeComboBox = new QComboBox(SignalWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lights/red"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lights/green"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/type/red_redamber_green_amber"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/type/red_green"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/type/red_redamber_green_flashgreen_amber"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon4, QString());
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/type/red_green_flashgreen"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon5, QString());
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/type/red_green_amber"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon6, QString());
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lights/flash_amber"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon7, QString());
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lights/off"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/type/red_off"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/type/red_off_amber"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/type/off_green"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon11, QString());
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/type/flashamber_off"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon12, QString());
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/type/red_green_flashred"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon13, QString());
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/type/flashred_off"), QSize(), QIcon::Normal, QIcon::Off);
        typeComboBox->addItem(icon14, QString());
        typeComboBox->setObjectName(QStringLiteral("typeComboBox"));
        typeComboBox->setMaximumSize(QSize(16777215, 16777215));
        typeComboBox->setIconSize(QSize(90, 16));

        verticalLayout_2->addWidget(typeComboBox);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        label_3 = new QLabel(SignalWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        typeTableWidget = new QTableWidget(SignalWidget);
        if (typeTableWidget->columnCount() < 8)
            typeTableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setIcon(icon);
        typeTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/lights/red_amber"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon15);
        typeTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setIcon(icon1);
        typeTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/lights/amber"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setIcon(icon16);
        typeTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/lights/flashing_green"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setIcon(icon17);
        typeTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setIcon(icon7);
        typeTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setIcon(icon8);
        typeTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/lights/flashing_red"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setIcon(icon18);
        typeTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (typeTableWidget->rowCount() < 1)
            typeTableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        typeTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        typeTableWidget->setItem(0, 7, __qtablewidgetitem16);
        typeTableWidget->setObjectName(QStringLiteral("typeTableWidget"));
        typeTableWidget->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(typeTableWidget, 3, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(SignalWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        bakTextEdit = new QTextEdit(SignalWidget);
        bakTextEdit->setObjectName(QStringLiteral("bakTextEdit"));

        verticalLayout_5->addWidget(bakTextEdit);


        gridLayout->addLayout(verticalLayout_5, 4, 0, 1, 1);


        retranslateUi(SignalWidget);

        QMetaObject::connectSlotsByName(SignalWidget);
    } // setupUi

    void retranslateUi(QWidget *SignalWidget)
    {
        SignalWidget->setWindowTitle(QApplication::translate("SignalWidget", "SignalWidget", 0));
        label->setText(QApplication::translate("SignalWidget", "\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("SignalWidget", "\351\273\230\350\256\244\347\232\204\345\272\217\345\210\227", 0));
        typeComboBox->setItemText(0, QApplication::translate("SignalWidget", "\345\205\250\347\272\242", 0));
        typeComboBox->setItemText(1, QApplication::translate("SignalWidget", "\345\205\250\347\273\277", 0));
        typeComboBox->setItemText(2, QApplication::translate("SignalWidget", "\347\272\242-\347\272\242\351\273\204-\347\273\277-\351\273\204", 0));
        typeComboBox->setItemText(3, QApplication::translate("SignalWidget", "\347\272\242-\347\273\277", 0));
        typeComboBox->setItemText(4, QApplication::translate("SignalWidget", "\347\272\242-\347\272\242\351\273\204-\347\273\277-\347\273\277\351\227\252-\351\273\204", 0));
        typeComboBox->setItemText(5, QApplication::translate("SignalWidget", "\347\272\242-\347\273\277-\347\273\277\351\227\252", 0));
        typeComboBox->setItemText(6, QApplication::translate("SignalWidget", "\347\272\242-\347\273\277-\351\273\204", 0));
        typeComboBox->setItemText(7, QApplication::translate("SignalWidget", "\351\273\204\351\227\252", 0));
        typeComboBox->setItemText(8, QApplication::translate("SignalWidget", "\345\205\263\347\201\257", 0));
        typeComboBox->setItemText(9, QApplication::translate("SignalWidget", "\347\272\242\347\201\257-\345\205\263\347\201\257", 0));
        typeComboBox->setItemText(10, QApplication::translate("SignalWidget", "\347\272\242\347\201\257-\345\205\263\347\201\257-\351\273\204", 0));
        typeComboBox->setItemText(11, QApplication::translate("SignalWidget", "\345\205\263\347\201\257-\347\273\277", 0));
        typeComboBox->setItemText(12, QApplication::translate("SignalWidget", "\351\273\204\351\227\252-\345\205\263\347\201\257", 0));
        typeComboBox->setItemText(13, QApplication::translate("SignalWidget", "\347\272\242-\347\273\277-\347\272\242\351\227\252", 0));
        typeComboBox->setItemText(14, QApplication::translate("SignalWidget", "\347\272\242\351\227\252-\345\205\263\347\201\257", 0));

        label_3->setText(QApplication::translate("SignalWidget", "\351\273\230\350\256\244\347\232\204\346\234\200\345\260\217\346\227\266\351\225\277", 0));
        QTableWidgetItem *___qtablewidgetitem = typeTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SignalWidget", "\347\272\242", 0));
        QTableWidgetItem *___qtablewidgetitem1 = typeTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SignalWidget", "\347\272\242\351\273\204", 0));
        QTableWidgetItem *___qtablewidgetitem2 = typeTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SignalWidget", "\347\273\277", 0));
        QTableWidgetItem *___qtablewidgetitem3 = typeTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SignalWidget", "\351\273\204", 0));
        QTableWidgetItem *___qtablewidgetitem4 = typeTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SignalWidget", "\347\273\277\351\227\252", 0));
        QTableWidgetItem *___qtablewidgetitem5 = typeTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SignalWidget", "\351\273\204\351\227\252", 0));
        QTableWidgetItem *___qtablewidgetitem6 = typeTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SignalWidget", "\345\205\263\351\227\255", 0));
        QTableWidgetItem *___qtablewidgetitem7 = typeTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("SignalWidget", "\347\272\242\351\227\252", 0));

        const bool __sortingEnabled = typeTableWidget->isSortingEnabled();
        typeTableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = typeTableWidget->item(0, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem9 = typeTableWidget->item(0, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem10 = typeTableWidget->item(0, 2);
        ___qtablewidgetitem10->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem11 = typeTableWidget->item(0, 3);
        ___qtablewidgetitem11->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem12 = typeTableWidget->item(0, 4);
        ___qtablewidgetitem12->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem13 = typeTableWidget->item(0, 5);
        ___qtablewidgetitem13->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem14 = typeTableWidget->item(0, 6);
        ___qtablewidgetitem14->setText(QApplication::translate("SignalWidget", "0", 0));
        QTableWidgetItem *___qtablewidgetitem15 = typeTableWidget->item(0, 7);
        ___qtablewidgetitem15->setText(QApplication::translate("SignalWidget", "0", 0));
        typeTableWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QApplication::translate("SignalWidget", "\345\244\207\346\263\250", 0));
    } // retranslateUi

};

namespace Ui {
    class SignalWidget: public Ui_SignalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALWIDGET_H
