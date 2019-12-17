/********************************************************************************
** Form generated from reading UI file 'DialogConnect.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNECT_H
#define UI_DIALOGCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogConnect
{
public:
    QLineEdit *leditIP;
    QPushButton *btnConnect;
    QPushButton *btnCancel;
    QLabel *label;
    QLineEdit *leditPort;
    QLabel *label_2;

    void setupUi(QDialog *DialogConnect)
    {
        if (DialogConnect->objectName().isEmpty())
            DialogConnect->setObjectName(QStringLiteral("DialogConnect"));
        DialogConnect->resize(296, 187);
        leditIP = new QLineEdit(DialogConnect);
        leditIP->setObjectName(QStringLiteral("leditIP"));
        leditIP->setGeometry(QRect(100, 60, 160, 25));
        btnConnect = new QPushButton(DialogConnect);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(70, 140, 75, 23));
        btnCancel = new QPushButton(DialogConnect);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(180, 140, 75, 23));
        label = new QLabel(DialogConnect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 54, 25));
        leditPort = new QLineEdit(DialogConnect);
        leditPort->setObjectName(QStringLiteral("leditPort"));
        leditPort->setGeometry(QRect(100, 100, 160, 25));
        label_2 = new QLabel(DialogConnect);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 100, 54, 25));

        retranslateUi(DialogConnect);

        QMetaObject::connectSlotsByName(DialogConnect);
    } // setupUi

    void retranslateUi(QDialog *DialogConnect)
    {
        DialogConnect->setWindowTitle(QApplication::translate("DialogConnect", "Dialog", Q_NULLPTR));
        leditIP->setText(QApplication::translate("DialogConnect", "127.0.0.1", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("DialogConnect", "\350\277\236\346\216\245", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("DialogConnect", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("DialogConnect", "IP\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        leditPort->setText(QApplication::translate("DialogConnect", "10001", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogConnect", "\347\253\257\345\217\243\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogConnect: public Ui_DialogConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNECT_H
