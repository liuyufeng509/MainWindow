/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionAdd;
    QAction *actionCopy;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *upLoadAction;
    QAction *downLoadAction;
    QAction *netFrontAction;
    QAction *aboutAction;
    QAction *saveDefAction;
    QAction *loadDefAction;
    QAction *localFileSaveAction;
    QAction *localFileSaveAsAction;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menu;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(979, 679);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ToolBar/window"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        MainWindowClass->setStyleSheet(QStringLiteral(""));
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ToolBar/fileopen"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ToolBar/filesave"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindowClass);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionSave_As->setIcon(icon2);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ToolBar/exit"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionAdd = new QAction(MainWindowClass);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/ToolBar/add"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon4);
        actionCopy = new QAction(MainWindowClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/ToolBar/copy"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionEdit = new QAction(MainWindowClass);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/ToolBar/edit"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon6);
        actionDelete = new QAction(MainWindowClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/ToolBar/delete"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon7);
        upLoadAction = new QAction(MainWindowClass);
        upLoadAction->setObjectName(QStringLiteral("upLoadAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/ToolBar/upload"), QSize(), QIcon::Normal, QIcon::Off);
        upLoadAction->setIcon(icon8);
        downLoadAction = new QAction(MainWindowClass);
        downLoadAction->setObjectName(QStringLiteral("downLoadAction"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/ToolBar/down"), QSize(), QIcon::Normal, QIcon::Off);
        downLoadAction->setIcon(icon9);
        netFrontAction = new QAction(MainWindowClass);
        netFrontAction->setObjectName(QStringLiteral("netFrontAction"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/ToolBar/signal"), QSize(), QIcon::Normal, QIcon::Off);
        netFrontAction->setIcon(icon10);
        aboutAction = new QAction(MainWindowClass);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        saveDefAction = new QAction(MainWindowClass);
        saveDefAction->setObjectName(QStringLiteral("saveDefAction"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/ToolBar/savedefault"), QSize(), QIcon::Normal, QIcon::Off);
        saveDefAction->setIcon(icon11);
        loadDefAction = new QAction(MainWindowClass);
        loadDefAction->setObjectName(QStringLiteral("loadDefAction"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/ToolBar/loaddefault"), QSize(), QIcon::Normal, QIcon::Off);
        loadDefAction->setIcon(icon12);
        localFileSaveAction = new QAction(MainWindowClass);
        localFileSaveAction->setObjectName(QStringLiteral("localFileSaveAction"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/ToolBar/localSave"), QSize(), QIcon::Normal, QIcon::Off);
        localFileSaveAction->setIcon(icon13);
        localFileSaveAsAction = new QAction(MainWindowClass);
        localFileSaveAsAction->setObjectName(QStringLiteral("localFileSaveAsAction"));
        localFileSaveAsAction->setIcon(icon13);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 979, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(localFileSaveAction);
        menuFile->addAction(localFileSaveAsAction);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(saveDefAction);
        menuFile->addAction(loadDefAction);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(netFrontAction);
        menuEdit->addAction(upLoadAction);
        menuEdit->addAction(downLoadAction);
        menu->addAction(aboutAction);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(localFileSaveAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionEdit);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addAction(netFrontAction);
        mainToolBar->addAction(upLoadAction);
        mainToolBar->addAction(downLoadAction);
        mainToolBar->addAction(saveDefAction);
        mainToolBar->addAction(loadDefAction);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindowClass", "\346\211\223\345\274\200...", 0));
        actionSave->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230VISSIM", 0));
        actionSave_As->setText(QApplication::translate("MainWindowClass", "\345\217\246\345\255\230\344\270\272VISSIM...", 0));
        actionExit->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272", 0));
        actionAdd->setText(QApplication::translate("MainWindowClass", "\346\267\273\345\212\240", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindowClass", "\346\267\273\345\212\240", 0));
#endif // QT_NO_TOOLTIP
        actionCopy->setText(QApplication::translate("MainWindowClass", "\345\244\215\345\210\266", 0));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("MainWindowClass", "\345\244\215\345\210\266\345\271\266\346\267\273\345\212\240\344\270\200\350\241\214", 0));
#endif // QT_NO_TOOLTIP
        actionEdit->setText(QApplication::translate("MainWindowClass", "\347\274\226\350\276\221", 0));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindowClass", "\347\274\226\350\276\221\351\200\211\351\241\271", 0));
#endif // QT_NO_TOOLTIP
        actionDelete->setText(QApplication::translate("MainWindowClass", "\345\210\240\351\231\244", 0));
#ifndef QT_NO_TOOLTIP
        actionDelete->setToolTip(QApplication::translate("MainWindowClass", "\345\210\240\351\231\244\344\270\200\350\241\214", 0));
#endif // QT_NO_TOOLTIP
        upLoadAction->setText(QApplication::translate("MainWindowClass", "\344\270\212\350\275\275\344\277\241\345\217\267\346\234\272\346\225\260\346\215\256", 0));
        downLoadAction->setText(QApplication::translate("MainWindowClass", "\344\270\213\350\275\275\344\277\241\345\217\267\346\234\272\346\225\260\346\215\256", 0));
        netFrontAction->setText(QApplication::translate("MainWindowClass", "\347\216\260\345\234\272\351\205\215\347\275\256\350\256\276\345\244\207", 0));
        aboutAction->setText(QApplication::translate("MainWindowClass", "\345\205\263\344\272\216", 0));
        saveDefAction->setText(QApplication::translate("MainWindowClass", "\350\256\276\344\270\272\351\273\230\350\256\244\346\226\271\346\241\210", 0));
        loadDefAction->setText(QApplication::translate("MainWindowClass", "\345\212\240\350\275\275\351\273\230\350\256\244\346\226\271\346\241\210", 0));
        localFileSaveAction->setText(QApplication::translate("MainWindowClass", "\344\277\235\345\255\230", 0));
        localFileSaveAction->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0));
        localFileSaveAsAction->setText(QApplication::translate("MainWindowClass", "\345\217\246\345\255\230\344\270\272....", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "\346\226\207\344\273\266", 0));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "\344\277\241\345\217\267\346\234\272", 0));
        menu->setTitle(QApplication::translate("MainWindowClass", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
