/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAction;
    QAction *newAction;
    QAction *exitAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *fontAction;
    QAction *bldAction;
    QAction *itlAction;
    QAction *underAction;
    QAction *colorAction;
    QAction *clearAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(983, 593);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QStringLiteral("newAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon1);
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/img/exit_8.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAction->setIcon(icon2);
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QStringLiteral("cutAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/img/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutAction->setIcon(icon3);
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/img/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAction->setIcon(icon4);
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/img/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAction->setIcon(icon5);
        fontAction = new QAction(MainWindow);
        fontAction->setObjectName(QStringLiteral("fontAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/img/20.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fontAction->setIcon(icon6);
        bldAction = new QAction(MainWindow);
        bldAction->setObjectName(QStringLiteral("bldAction"));
        bldAction->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/img/BLD.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        bldAction->setIcon(icon7);
        itlAction = new QAction(MainWindow);
        itlAction->setObjectName(QStringLiteral("itlAction"));
        itlAction->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/img/ITL.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        itlAction->setIcon(icon8);
        underAction = new QAction(MainWindow);
        underAction->setObjectName(QStringLiteral("underAction"));
        underAction->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/img/UNDRLN.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        underAction->setIcon(icon9);
        colorAction = new QAction(MainWindow);
        colorAction->setObjectName(QStringLiteral("colorAction"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/img/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorAction->setIcon(icon10);
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QStringLiteral("clearAction"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icon/img/103.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        clearAction->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(20);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 983, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(openAction);
        menu->addAction(newAction);
        menu->addSeparator();
        menu->addAction(exitAction);
        menu_2->addAction(cutAction);
        menu_2->addAction(copyAction);
        menu_2->addAction(pasteAction);
        menu_2->addSeparator();
        menu_2->addAction(clearAction);
        menu_3->addAction(fontAction);
        menu_3->addAction(bldAction);
        menu_3->addAction(itlAction);
        menu_3->addAction(underAction);
        menu_3->addAction(colorAction);
        mainToolBar->addAction(openAction);
        mainToolBar->addAction(newAction);
        mainToolBar->addAction(exitAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(cutAction);
        mainToolBar->addAction(copyAction);
        mainToolBar->addAction(pasteAction);
        mainToolBar->addAction(clearAction);
        mainToolBar->addSeparator();
        mainToolBar->addAction(fontAction);
        mainToolBar->addAction(bldAction);
        mainToolBar->addAction(itlAction);
        mainToolBar->addAction(underAction);
        mainToolBar->addAction(colorAction);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(exitAction, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(clearAction, SIGNAL(triggered()), textEdit, SLOT(clear()));
        QObject::connect(copyAction, SIGNAL(triggered()), textEdit, SLOT(copy()));
        QObject::connect(cutAction, SIGNAL(triggered()), textEdit, SLOT(cut()));
        QObject::connect(pasteAction, SIGNAL(triggered()), textEdit, SLOT(paste()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0));
#ifndef QT_NO_TOOLTIP
        openAction->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        newAction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", 0));
#ifndef QT_NO_TOOLTIP
        newAction->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", 0));
#endif // QT_NO_TOOLTIP
        newAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        exitAction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        exitAction->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        cutAction->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", 0));
        cutAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        copyAction->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", 0));
        copyAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        pasteAction->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", 0));
        pasteAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        fontAction->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223", 0));
        bldAction->setText(QApplication::translate("MainWindow", "\347\262\227\344\275\223", 0));
        itlAction->setText(QApplication::translate("MainWindow", "\346\226\234\344\275\223", 0));
        underAction->setText(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", 0));
        colorAction->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262", 0));
        clearAction->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\345\274\200\345\247\213(&F)", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\241\265\351\235\242\345\270\203\345\261\200(&T)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
