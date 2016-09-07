/********************************************************************************
** Form generated from reading UI file 'scwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCWIDGET_H
#define UI_SCWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_3;
    QSpinBox *frenquencySpinBox;
    QLabel *label_2;
    QTextEdit *noteTextEdit;

    void setupUi(QWidget *ScWidget)
    {
        if (ScWidget->objectName().isEmpty())
            ScWidget->setObjectName(QStringLiteral("ScWidget"));
        ScWidget->resize(768, 457);
        gridLayout = new QGridLayout(ScWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ScWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(ScWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 1, 0, 1, 1);

        label_3 = new QLabel(ScWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        frenquencySpinBox = new QSpinBox(ScWidget);
        frenquencySpinBox->setObjectName(QStringLiteral("frenquencySpinBox"));
        frenquencySpinBox->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(frenquencySpinBox, 3, 0, 1, 1);

        label_2 = new QLabel(ScWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        noteTextEdit = new QTextEdit(ScWidget);
        noteTextEdit->setObjectName(QStringLiteral("noteTextEdit"));

        gridLayout->addWidget(noteTextEdit, 5, 0, 1, 1);


        retranslateUi(ScWidget);

        QMetaObject::connectSlotsByName(ScWidget);
    } // setupUi

    void retranslateUi(QWidget *ScWidget)
    {
        ScWidget->setWindowTitle(QApplication::translate("ScWidget", "ScWidget", 0));
        label->setText(QApplication::translate("ScWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("ScWidget", "\346\216\247\345\210\266\346\234\272\351\242\221\347\216\207\357\274\232", 0));
        label_2->setText(QApplication::translate("ScWidget", "\345\244\207\346\263\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class ScWidget: public Ui_ScWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCWIDGET_H
