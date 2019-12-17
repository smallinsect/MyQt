/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_file_exit;
    QAction *action_operation_connect;
    QAction *action_operation_discon;
    QAction *action_operation_resetService;
    QAction *action_operation_resetEquip;
    QAction *action_editor_add;
    QAction *action_editor_modify;
    QAction *action_editor_cut;
    QAction *action_editor_copy;
    QAction *action_editor_paste;
    QAction *menu_view_statusBar;
    QAction *action_help_about;
    QAction *menu_view_tool_standard;
    QAction *menu_view_tool_equipCatList;
    QAction *menu_view_tool_attribute;
    QAction *menu_view_tool_custom;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_operation;
    QMenu *menu_editor;
    QMenu *menu_view;
    QMenu *menu_view_tool;
    QMenu *menu_help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1345, 611);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/res/ET.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_file_exit = new QAction(MainWindow);
        action_file_exit->setObjectName(QStringLiteral("action_file_exit"));
        action_operation_connect = new QAction(MainWindow);
        action_operation_connect->setObjectName(QStringLiteral("action_operation_connect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/res/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_operation_connect->setIcon(icon1);
        action_operation_discon = new QAction(MainWindow);
        action_operation_discon->setObjectName(QStringLiteral("action_operation_discon"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/res/discon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_operation_discon->setIcon(icon2);
        action_operation_resetService = new QAction(MainWindow);
        action_operation_resetService->setObjectName(QStringLiteral("action_operation_resetService"));
        action_operation_resetEquip = new QAction(MainWindow);
        action_operation_resetEquip->setObjectName(QStringLiteral("action_operation_resetEquip"));
        action_editor_add = new QAction(MainWindow);
        action_editor_add->setObjectName(QStringLiteral("action_editor_add"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/res/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_add->setIcon(icon3);
        action_editor_modify = new QAction(MainWindow);
        action_editor_modify->setObjectName(QStringLiteral("action_editor_modify"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/res/modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_modify->setIcon(icon4);
        action_editor_cut = new QAction(MainWindow);
        action_editor_cut->setObjectName(QStringLiteral("action_editor_cut"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/res/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_cut->setIcon(icon5);
        action_editor_copy = new QAction(MainWindow);
        action_editor_copy->setObjectName(QStringLiteral("action_editor_copy"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/res/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_copy->setIcon(icon6);
        action_editor_paste = new QAction(MainWindow);
        action_editor_paste->setObjectName(QStringLiteral("action_editor_paste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/res/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editor_paste->setIcon(icon7);
        menu_view_statusBar = new QAction(MainWindow);
        menu_view_statusBar->setObjectName(QStringLiteral("menu_view_statusBar"));
        action_help_about = new QAction(MainWindow);
        action_help_about->setObjectName(QStringLiteral("action_help_about"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/res/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_help_about->setIcon(icon8);
        menu_view_tool_standard = new QAction(MainWindow);
        menu_view_tool_standard->setObjectName(QStringLiteral("menu_view_tool_standard"));
        menu_view_tool_equipCatList = new QAction(MainWindow);
        menu_view_tool_equipCatList->setObjectName(QStringLiteral("menu_view_tool_equipCatList"));
        menu_view_tool_attribute = new QAction(MainWindow);
        menu_view_tool_attribute->setObjectName(QStringLiteral("menu_view_tool_attribute"));
        menu_view_tool_custom = new QAction(MainWindow);
        menu_view_tool_custom->setObjectName(QStringLiteral("menu_view_tool_custom"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1345, 22));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        menu_operation = new QMenu(menuBar);
        menu_operation->setObjectName(QStringLiteral("menu_operation"));
        menu_editor = new QMenu(menuBar);
        menu_editor->setObjectName(QStringLiteral("menu_editor"));
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QStringLiteral("menu_view"));
        menu_view_tool = new QMenu(menu_view);
        menu_view_tool->setObjectName(QStringLiteral("menu_view_tool"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_operation->menuAction());
        menuBar->addAction(menu_editor->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_file->addAction(action_file_exit);
        menu_operation->addAction(action_operation_connect);
        menu_operation->addAction(action_operation_discon);
        menu_operation->addAction(action_operation_resetService);
        menu_operation->addAction(action_operation_resetEquip);
        menu_editor->addAction(action_editor_add);
        menu_editor->addAction(action_editor_modify);
        menu_editor->addSeparator();
        menu_editor->addAction(action_editor_cut);
        menu_editor->addAction(action_editor_copy);
        menu_editor->addAction(action_editor_paste);
        menu_view->addAction(menu_view_tool->menuAction());
        menu_view->addAction(menu_view_statusBar);
        menu_view_tool->addAction(menu_view_tool_standard);
        menu_view_tool->addSeparator();
        menu_view_tool->addAction(menu_view_tool_equipCatList);
        menu_view_tool->addAction(menu_view_tool_attribute);
        menu_view_tool->addSeparator();
        menu_view_tool->addAction(menu_view_tool_custom);
        menu_help->addAction(action_help_about);
        mainToolBar->addAction(action_operation_connect);
        mainToolBar->addAction(action_operation_discon);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_editor_add);
        mainToolBar->addAction(action_editor_modify);
        mainToolBar->addAction(action_editor_cut);
        mainToolBar->addAction(action_editor_copy);
        mainToolBar->addAction(action_editor_paste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_help_about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_file_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", Q_NULLPTR));
        action_operation_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245(&C)", Q_NULLPTR));
        action_operation_discon->setText(QApplication::translate("MainWindow", "\346\226\255\345\274\200(&D)", Q_NULLPTR));
        action_operation_resetService->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215\346\234\215\345\212\241", Q_NULLPTR));
        action_operation_resetEquip->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215\350\256\276\345\244\207", Q_NULLPTR));
        action_editor_add->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240(&A)", Q_NULLPTR));
        action_editor_modify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271(&M)", Q_NULLPTR));
        action_editor_cut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", Q_NULLPTR));
        action_editor_copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", Q_NULLPTR));
        action_editor_paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", Q_NULLPTR));
        menu_view_statusBar->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217(&S)", Q_NULLPTR));
        action_help_about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216XEditor(&A)", Q_NULLPTR));
        menu_view_tool_standard->setText(QApplication::translate("MainWindow", "\346\240\207\345\207\206", Q_NULLPTR));
        menu_view_tool_equipCatList->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\210\253\345\210\227\350\241\250", Q_NULLPTR));
        menu_view_tool_attribute->setText(QApplication::translate("MainWindow", "\345\261\236\346\200\247", Q_NULLPTR));
        menu_view_tool_custom->setText(QApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211...", Q_NULLPTR));
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu_operation->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&O)", Q_NULLPTR));
        menu_editor->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", Q_NULLPTR));
        menu_view->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276(&V)", Q_NULLPTR));
        menu_view_tool->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217\345\222\214\345\201\234\351\235\240\347\252\227\345\217\243(&T)", Q_NULLPTR));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
