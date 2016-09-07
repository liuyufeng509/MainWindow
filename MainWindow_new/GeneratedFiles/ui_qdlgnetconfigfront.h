/********************************************************************************
** Form generated from reading UI file 'qdlgnetconfigfront.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDLGNETCONFIGFRONT_H
#define UI_QDLGNETCONFIGFRONT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QDlgNetConfigFront
{
public:
    QPushButton *searchButton;
    QListWidget *devListWidget;
    QLabel *label;
    QFrame *line;
    QPushButton *applyButton;
    QPushButton *connButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *addrLineEdit;
    QLabel *label_3;
    QLineEdit *ipLineEdit;
    QLabel *label_4;
    QLineEdit *macLineEdit;
    QLabel *label_5;
    QLineEdit *maskLineEdit;
    QLabel *label_6;
    QLineEdit *routeLineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *sim_ipLineEdit;
    QLineEdit *sim_port1LineEdit;
    QLineEdit *sim_port2LineEdit;

    void setupUi(QDialog *QDlgNetConfigFront)
    {
        if (QDlgNetConfigFront->objectName().isEmpty())
            QDlgNetConfigFront->setObjectName(QStringLiteral("QDlgNetConfigFront"));
        QDlgNetConfigFront->resize(723, 588);
        searchButton = new QPushButton(QDlgNetConfigFront);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(20, 30, 121, 41));
        devListWidget = new QListWidget(QDlgNetConfigFront);
        devListWidget->setObjectName(QStringLiteral("devListWidget"));
        devListWidget->setGeometry(QRect(10, 130, 221, 401));
        label = new QLabel(QDlgNetConfigFront);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 71, 31));
        line = new QFrame(QDlgNetConfigFront);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(342, 10, 21, 531));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        applyButton = new QPushButton(QDlgNetConfigFront);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(570, 500, 121, 41));
        connButton = new QPushButton(QDlgNetConfigFront);
        connButton->setObjectName(QStringLiteral("connButton"));
        connButton->setGeometry(QRect(380, 500, 121, 41));
        groupBox = new QGroupBox(QDlgNetConfigFront);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(390, 40, 301, 231));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        addrLineEdit = new QLineEdit(groupBox);
        addrLineEdit->setObjectName(QStringLiteral("addrLineEdit"));

        gridLayout->addWidget(addrLineEdit, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        ipLineEdit = new QLineEdit(groupBox);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));

        gridLayout->addWidget(ipLineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        macLineEdit = new QLineEdit(groupBox);
        macLineEdit->setObjectName(QStringLiteral("macLineEdit"));

        gridLayout->addWidget(macLineEdit, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        maskLineEdit = new QLineEdit(groupBox);
        maskLineEdit->setObjectName(QStringLiteral("maskLineEdit"));

        gridLayout->addWidget(maskLineEdit, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        routeLineEdit = new QLineEdit(groupBox);
        routeLineEdit->setObjectName(QStringLiteral("routeLineEdit"));

        gridLayout->addWidget(routeLineEdit, 4, 1, 1, 1);

        groupBox_2 = new QGroupBox(QDlgNetConfigFront);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(390, 310, 291, 151));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        sim_ipLineEdit = new QLineEdit(groupBox_2);
        sim_ipLineEdit->setObjectName(QStringLiteral("sim_ipLineEdit"));

        gridLayout_2->addWidget(sim_ipLineEdit, 0, 2, 1, 1);

        sim_port1LineEdit = new QLineEdit(groupBox_2);
        sim_port1LineEdit->setObjectName(QStringLiteral("sim_port1LineEdit"));

        gridLayout_2->addWidget(sim_port1LineEdit, 1, 2, 1, 1);

        sim_port2LineEdit = new QLineEdit(groupBox_2);
        sim_port2LineEdit->setObjectName(QStringLiteral("sim_port2LineEdit"));

        gridLayout_2->addWidget(sim_port2LineEdit, 2, 2, 1, 1);


        retranslateUi(QDlgNetConfigFront);

        QMetaObject::connectSlotsByName(QDlgNetConfigFront);
    } // setupUi

    void retranslateUi(QDialog *QDlgNetConfigFront)
    {
        QDlgNetConfigFront->setWindowTitle(QApplication::translate("QDlgNetConfigFront", "QDlgNetConfigFront", 0));
        searchButton->setText(QApplication::translate("QDlgNetConfigFront", "\346\220\234\347\264\242\350\256\276\345\244\207", 0));
        label->setText(QApplication::translate("QDlgNetConfigFront", "\350\256\276\345\244\207\345\210\227\350\241\250\357\274\232", 0));
        applyButton->setText(QApplication::translate("QDlgNetConfigFront", "\345\272\224\347\224\250", 0));
        connButton->setText(QApplication::translate("QDlgNetConfigFront", "\350\277\236\346\216\245", 0));
        groupBox->setTitle(QApplication::translate("QDlgNetConfigFront", "\344\277\241\345\217\267\346\234\272", 0));
        label_2->setText(QApplication::translate("QDlgNetConfigFront", "\344\277\241\345\217\267\346\234\272\345\234\260\345\235\200\357\274\232", 0));
        label_3->setText(QApplication::translate("QDlgNetConfigFront", "\344\277\241\345\217\267\346\234\272IP\345\234\260\345\235\200\357\274\232", 0));
        label_4->setText(QApplication::translate("QDlgNetConfigFront", "\344\277\241\345\217\267\346\234\272MAC\345\234\260\345\235\200\357\274\232", 0));
        label_5->setText(QApplication::translate("QDlgNetConfigFront", "\345\255\220\347\275\221\346\216\251\347\240\201\357\274\232", 0));
        label_6->setText(QApplication::translate("QDlgNetConfigFront", "\347\275\221\345\205\263\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("QDlgNetConfigFront", "\346\250\241\346\213\237\350\275\257\344\273\266", 0));
        label_8->setText(QApplication::translate("QDlgNetConfigFront", "\347\253\257\345\217\243\345\217\2671\357\274\232", 0));
        label_9->setText(QApplication::translate("QDlgNetConfigFront", "\347\253\257\345\217\243\345\217\2672\357\274\232", 0));
        label_7->setText(QApplication::translate("QDlgNetConfigFront", "IP\345\234\260\345\235\200\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class QDlgNetConfigFront: public Ui_QDlgNetConfigFront {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDLGNETCONFIGFRONT_H
