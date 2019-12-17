/********************************************************************************
** Form generated from reading UI file 'ContentForm.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTENTFORM_H
#define UI_CONTENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContentForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelConsole;
    QLineEdit *lineEditSearch;
    QPushButton *btnSearch;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_2;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidgetContent;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelAttributeTitle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelAttributeConsole;
    QLineEdit *lineEdit_2;
    QPushButton *btnAdd;
    QPushButton *btnUpdate;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidgetAttribute;

    void setupUi(QWidget *ContentForm)
    {
        if (ContentForm->objectName().isEmpty())
            ContentForm->setObjectName(QStringLiteral("ContentForm"));
        ContentForm->resize(800, 600);
        ContentForm->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/res/ET.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        ContentForm->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(ContentForm);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTitle = new QLabel(ContentForm);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        verticalLayout->addWidget(labelTitle);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(8);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelConsole = new QLabel(ContentForm);
        labelConsole->setObjectName(QStringLiteral("labelConsole"));

        horizontalLayout_3->addWidget(labelConsole);

        lineEditSearch = new QLineEdit(ContentForm);
        lineEditSearch->setObjectName(QStringLiteral("lineEditSearch"));

        horizontalLayout_3->addWidget(lineEditSearch);

        btnSearch = new QPushButton(ContentForm);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setMaximumSize(QSize(23, 23));
        btnSearch->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/search.bmp);"));

        horizontalLayout_3->addWidget(btnSearch);

        pushButton = new QPushButton(ContentForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(23, 23));
        pushButton->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/next.bmp);"));

        horizontalLayout_3->addWidget(pushButton);

        line = new QFrame(ContentForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        pushButton_3 = new QPushButton(ContentForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(23, 23));
        pushButton_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/unfold.bmp);"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(ContentForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(23, 23));
        pushButton_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/merge.bmp);"));

        horizontalLayout_3->addWidget(pushButton_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        treeWidget = new QTreeWidget(ContentForm);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setColumnCount(0);

        verticalLayout->addWidget(treeWidget);


        horizontalLayout->addLayout(verticalLayout);

        tableWidgetContent = new QTableWidget(ContentForm);
        tableWidgetContent->setObjectName(QStringLiteral("tableWidgetContent"));

        horizontalLayout->addWidget(tableWidgetContent);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelAttributeTitle = new QLabel(ContentForm);
        labelAttributeTitle->setObjectName(QStringLiteral("labelAttributeTitle"));

        verticalLayout_2->addWidget(labelAttributeTitle);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(8);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelAttributeConsole = new QLabel(ContentForm);
        labelAttributeConsole->setObjectName(QStringLiteral("labelAttributeConsole"));
        labelAttributeConsole->setMaximumSize(QSize(23, 23));
        labelAttributeConsole->setAutoFillBackground(false);
        labelAttributeConsole->setStyleSheet(QStringLiteral(""));
        labelAttributeConsole->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/res/hardware.bmp")));
        labelAttributeConsole->setScaledContents(false);

        horizontalLayout_4->addWidget(labelAttributeConsole);

        lineEdit_2 = new QLineEdit(ContentForm);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);

        btnAdd = new QPushButton(ContentForm);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMaximumSize(QSize(23, 23));
        btnAdd->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/add.png);"));

        horizontalLayout_4->addWidget(btnAdd);

        btnUpdate = new QPushButton(ContentForm);
        btnUpdate->setObjectName(QStringLiteral("btnUpdate"));
        btnUpdate->setMaximumSize(QSize(23, 23));
        btnUpdate->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/res/modify.png);"));

        horizontalLayout_4->addWidget(btnUpdate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tableWidgetAttribute = new QTableWidget(ContentForm);
        tableWidgetAttribute->setObjectName(QStringLiteral("tableWidgetAttribute"));

        verticalLayout_2->addWidget(tableWidgetAttribute);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ContentForm);

        QMetaObject::connectSlotsByName(ContentForm);
    } // setupUi

    void retranslateUi(QWidget *ContentForm)
    {
        ContentForm->setWindowTitle(QApplication::translate("ContentForm", "Form", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("ContentForm", "\350\256\276\345\244\207\347\261\273\345\210\253\345\210\227\350\241\250", Q_NULLPTR));
        labelConsole->setText(QApplication::translate("ContentForm", "\345\205\263\351\224\256\345\255\227\357\274\232", Q_NULLPTR));
        btnSearch->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        labelAttributeTitle->setText(QApplication::translate("ContentForm", "\345\261\236\346\200\247", Q_NULLPTR));
        labelAttributeConsole->setText(QString());
        btnAdd->setText(QString());
        btnUpdate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ContentForm: public Ui_ContentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTENTFORM_H
