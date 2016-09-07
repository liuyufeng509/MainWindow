/********************************************************************************
** Form generated from reading UI file 'detectorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORWIDGET_H
#define UI_DETECTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorWidget
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *vehGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *presenceCheckBox;
    QCheckBox *frontEndsCheckBox;
    QCheckBox *rearEndsCheckBox;
    QCheckBox *frontEndTimeCheckBox;
    QCheckBox *rearEndTimeCheckBox;
    QCheckBox *occupancyRateCheckBox;
    QCheckBox *occupancyRateSmoothedCheckBox;
    QCheckBox *gapTimeCheckBox;
    QCheckBox *vehSpeedCheckBox;
    QCheckBox *vehLengthCheckBox;
    QCheckBox *occupancyTimeCheckBox;
    QGroupBox *BusGroupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *telegramsCheckBox;
    QCheckBox *tele_CPCheckBox;
    QCheckBox *tele_CourseCheckBox;
    QCheckBox *tele_RouteCheckBox;
    QCheckBox *tele_LengthCheckBox;
    QCheckBox *tele_ManualDCCheckBox;
    QCheckBox *tele_DelayCheckBox;
    QCheckBox *tele_PassengersCheckBox;
    QCheckBox *tele_PrioCheckBox;
    QCheckBox *tele_LineCheckBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QComboBox *phaseComboBox;
    QLabel *label_3;
    QComboBox *phaseTypeComboBox;
    QLabel *label_4;
    QCheckBox *isUsedCheckBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DetectorWidget)
    {
        if (DetectorWidget->objectName().isEmpty())
            DetectorWidget->setObjectName(QStringLiteral("DetectorWidget"));
        DetectorWidget->resize(615, 489);
        gridLayout_3 = new QGridLayout(DetectorWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        vehGroupBox = new QGroupBox(DetectorWidget);
        vehGroupBox->setObjectName(QStringLiteral("vehGroupBox"));
        gridLayout = new QGridLayout(vehGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        presenceCheckBox = new QCheckBox(vehGroupBox);
        presenceCheckBox->setObjectName(QStringLiteral("presenceCheckBox"));

        gridLayout->addWidget(presenceCheckBox, 0, 0, 1, 1);

        frontEndsCheckBox = new QCheckBox(vehGroupBox);
        frontEndsCheckBox->setObjectName(QStringLiteral("frontEndsCheckBox"));

        gridLayout->addWidget(frontEndsCheckBox, 0, 1, 1, 1);

        rearEndsCheckBox = new QCheckBox(vehGroupBox);
        rearEndsCheckBox->setObjectName(QStringLiteral("rearEndsCheckBox"));

        gridLayout->addWidget(rearEndsCheckBox, 0, 2, 1, 1);

        frontEndTimeCheckBox = new QCheckBox(vehGroupBox);
        frontEndTimeCheckBox->setObjectName(QStringLiteral("frontEndTimeCheckBox"));

        gridLayout->addWidget(frontEndTimeCheckBox, 0, 3, 1, 1);

        rearEndTimeCheckBox = new QCheckBox(vehGroupBox);
        rearEndTimeCheckBox->setObjectName(QStringLiteral("rearEndTimeCheckBox"));

        gridLayout->addWidget(rearEndTimeCheckBox, 1, 0, 1, 1);

        occupancyRateCheckBox = new QCheckBox(vehGroupBox);
        occupancyRateCheckBox->setObjectName(QStringLiteral("occupancyRateCheckBox"));

        gridLayout->addWidget(occupancyRateCheckBox, 1, 2, 1, 1);

        occupancyRateSmoothedCheckBox = new QCheckBox(vehGroupBox);
        occupancyRateSmoothedCheckBox->setObjectName(QStringLiteral("occupancyRateSmoothedCheckBox"));

        gridLayout->addWidget(occupancyRateSmoothedCheckBox, 1, 3, 1, 1);

        gapTimeCheckBox = new QCheckBox(vehGroupBox);
        gapTimeCheckBox->setObjectName(QStringLiteral("gapTimeCheckBox"));

        gridLayout->addWidget(gapTimeCheckBox, 2, 0, 1, 1);

        vehSpeedCheckBox = new QCheckBox(vehGroupBox);
        vehSpeedCheckBox->setObjectName(QStringLiteral("vehSpeedCheckBox"));

        gridLayout->addWidget(vehSpeedCheckBox, 2, 1, 1, 1);

        vehLengthCheckBox = new QCheckBox(vehGroupBox);
        vehLengthCheckBox->setObjectName(QStringLiteral("vehLengthCheckBox"));

        gridLayout->addWidget(vehLengthCheckBox, 2, 2, 1, 1);

        occupancyTimeCheckBox = new QCheckBox(vehGroupBox);
        occupancyTimeCheckBox->setObjectName(QStringLiteral("occupancyTimeCheckBox"));

        gridLayout->addWidget(occupancyTimeCheckBox, 1, 1, 1, 1);


        gridLayout_3->addWidget(vehGroupBox, 2, 0, 1, 1);

        BusGroupBox = new QGroupBox(DetectorWidget);
        BusGroupBox->setObjectName(QStringLiteral("BusGroupBox"));
        gridLayout_2 = new QGridLayout(BusGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        telegramsCheckBox = new QCheckBox(BusGroupBox);
        telegramsCheckBox->setObjectName(QStringLiteral("telegramsCheckBox"));

        gridLayout_2->addWidget(telegramsCheckBox, 0, 0, 1, 1);

        tele_CPCheckBox = new QCheckBox(BusGroupBox);
        tele_CPCheckBox->setObjectName(QStringLiteral("tele_CPCheckBox"));

        gridLayout_2->addWidget(tele_CPCheckBox, 0, 1, 1, 1);

        tele_CourseCheckBox = new QCheckBox(BusGroupBox);
        tele_CourseCheckBox->setObjectName(QStringLiteral("tele_CourseCheckBox"));

        gridLayout_2->addWidget(tele_CourseCheckBox, 0, 3, 1, 1);

        tele_RouteCheckBox = new QCheckBox(BusGroupBox);
        tele_RouteCheckBox->setObjectName(QStringLiteral("tele_RouteCheckBox"));

        gridLayout_2->addWidget(tele_RouteCheckBox, 1, 0, 1, 1);

        tele_LengthCheckBox = new QCheckBox(BusGroupBox);
        tele_LengthCheckBox->setObjectName(QStringLiteral("tele_LengthCheckBox"));

        gridLayout_2->addWidget(tele_LengthCheckBox, 1, 2, 1, 1);

        tele_ManualDCCheckBox = new QCheckBox(BusGroupBox);
        tele_ManualDCCheckBox->setObjectName(QStringLiteral("tele_ManualDCCheckBox"));

        gridLayout_2->addWidget(tele_ManualDCCheckBox, 1, 3, 1, 1);

        tele_DelayCheckBox = new QCheckBox(BusGroupBox);
        tele_DelayCheckBox->setObjectName(QStringLiteral("tele_DelayCheckBox"));

        gridLayout_2->addWidget(tele_DelayCheckBox, 2, 0, 1, 1);

        tele_PassengersCheckBox = new QCheckBox(BusGroupBox);
        tele_PassengersCheckBox->setObjectName(QStringLiteral("tele_PassengersCheckBox"));

        gridLayout_2->addWidget(tele_PassengersCheckBox, 2, 1, 1, 1);

        tele_PrioCheckBox = new QCheckBox(BusGroupBox);
        tele_PrioCheckBox->setObjectName(QStringLiteral("tele_PrioCheckBox"));

        gridLayout_2->addWidget(tele_PrioCheckBox, 1, 1, 1, 1);

        tele_LineCheckBox = new QCheckBox(BusGroupBox);
        tele_LineCheckBox->setObjectName(QStringLiteral("tele_LineCheckBox"));

        gridLayout_2->addWidget(tele_LineCheckBox, 0, 2, 1, 1);


        gridLayout_3->addWidget(BusGroupBox, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DetectorWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(DetectorWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        nameLineEdit->setEnabled(false);

        horizontalLayout->addWidget(nameLineEdit);

        label_2 = new QLabel(DetectorWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        phaseComboBox = new QComboBox(DetectorWidget);
        phaseComboBox->setObjectName(QStringLiteral("phaseComboBox"));
        phaseComboBox->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(phaseComboBox);

        label_3 = new QLabel(DetectorWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        phaseTypeComboBox = new QComboBox(DetectorWidget);
        phaseTypeComboBox->setObjectName(QStringLiteral("phaseTypeComboBox"));
        phaseTypeComboBox->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(phaseTypeComboBox);

        label_4 = new QLabel(DetectorWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        isUsedCheckBox = new QCheckBox(DetectorWidget);
        isUsedCheckBox->setObjectName(QStringLiteral("isUsedCheckBox"));

        horizontalLayout->addWidget(isUsedCheckBox);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);


        retranslateUi(DetectorWidget);

        QMetaObject::connectSlotsByName(DetectorWidget);
    } // setupUi

    void retranslateUi(QWidget *DetectorWidget)
    {
        DetectorWidget->setWindowTitle(QApplication::translate("DetectorWidget", "DetectorWidget", 0));
        vehGroupBox->setTitle(QApplication::translate("DetectorWidget", "\345\217\202\346\225\260\346\240\207\345\277\227", 0));
        presenceCheckBox->setText(QApplication::translate("DetectorWidget", "Det_Presence", 0));
        frontEndsCheckBox->setText(QApplication::translate("DetectorWidget", "Det_FrontEnds", 0));
        rearEndsCheckBox->setText(QApplication::translate("DetectorWidget", "Det_RearEnds", 0));
        frontEndTimeCheckBox->setText(QApplication::translate("DetectorWidget", "Det_FrontEndTime", 0));
        rearEndTimeCheckBox->setText(QApplication::translate("DetectorWidget", "Det_RearEndTime", 0));
        occupancyRateCheckBox->setText(QApplication::translate("DetectorWidget", "Det_OccupancyRate", 0));
        occupancyRateSmoothedCheckBox->setText(QApplication::translate("DetectorWidget", "Det_OccupancyRateSmoothed", 0));
        gapTimeCheckBox->setText(QApplication::translate("DetectorWidget", "Det_GapTime", 0));
        vehSpeedCheckBox->setText(QApplication::translate("DetectorWidget", "Det_VehSpeed", 0));
        vehLengthCheckBox->setText(QApplication::translate("DetectorWidget", "Det_VehLength", 0));
        occupancyTimeCheckBox->setText(QApplication::translate("DetectorWidget", "Det_OccupancyTime", 0));
        BusGroupBox->setTitle(QApplication::translate("DetectorWidget", "\345\217\202\346\225\260\346\240\207\345\277\227", 0));
        telegramsCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Telegrams", 0));
        tele_CPCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_CP", 0));
        tele_CourseCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Course", 0));
        tele_RouteCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Route", 0));
        tele_LengthCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Length", 0));
        tele_ManualDCCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_ManualDC", 0));
        tele_DelayCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Delay", 0));
        tele_PassengersCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Passengers", 0));
        tele_PrioCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Prio", 0));
        tele_LineCheckBox->setText(QApplication::translate("DetectorWidget", "CP_Tele_Line", 0));
        label->setText(QApplication::translate("DetectorWidget", "\345\220\215\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("DetectorWidget", "\350\257\267\346\261\202\347\233\270\344\275\215\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("DetectorWidget", "\350\257\267\346\261\202\347\233\270\344\275\215\347\261\273\345\236\213\357\274\232", 0));
        label_4->setText(QApplication::translate("DetectorWidget", "\345\220\257\347\224\250\357\274\232", 0));
        isUsedCheckBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DetectorWidget: public Ui_DetectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORWIDGET_H
