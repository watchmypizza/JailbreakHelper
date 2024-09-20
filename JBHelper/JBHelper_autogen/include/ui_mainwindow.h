/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *Title;
    QPushButton *Confirm;
    QCheckBox *Disclaimer;
    QLineEdit *iPhoneOS;
    QTextEdit *outputConsole;
    QLineEdit *iPhoneModel;
    QPushButton *Check;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuJAILBREAK_HELPER;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Title = new QLineEdit(centralwidget);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(320, 0, 141, 31));
        Title->setReadOnly(true);
        Confirm = new QPushButton(centralwidget);
        Confirm->setObjectName("Confirm");
        Confirm->setGeometry(QRect(350, 520, 96, 34));
        Disclaimer = new QCheckBox(centralwidget);
        Disclaimer->setObjectName("Disclaimer");
        Disclaimer->setGeometry(QRect(0, 480, 801, 21));
        iPhoneOS = new QLineEdit(centralwidget);
        iPhoneOS->setObjectName("iPhoneOS");
        iPhoneOS->setGeometry(QRect(290, 60, 201, 31));
        outputConsole = new QTextEdit(centralwidget);
        outputConsole->setObjectName("outputConsole");
        outputConsole->setGeometry(QRect(143, 200, 491, 201));
        outputConsole->setReadOnly(true);
        iPhoneModel = new QLineEdit(centralwidget);
        iPhoneModel->setObjectName("iPhoneModel");
        iPhoneModel->setGeometry(QRect(292, 110, 201, 31));
        Check = new QPushButton(centralwidget);
        Check->setObjectName("Check");
        Check->setGeometry(QRect(350, 430, 96, 34));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuJAILBREAK_HELPER = new QMenu(menubar);
        menuJAILBREAK_HELPER->setObjectName("menuJAILBREAK_HELPER");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuJAILBREAK_HELPER->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Title->setText(QCoreApplication::translate("MainWindow", "Jailbreak Helper", nullptr));
        Confirm->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        Disclaimer->setText(QCoreApplication::translate("MainWindow", "I understand that jailbreaking my iOS device voids my warranty and might possibly break the iPhone.", nullptr));
        iPhoneOS->setText(QCoreApplication::translate("MainWindow", "iOS Version (ex. 20H350)", nullptr));
        outputConsole->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans Mono'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-- JAILBREAK OUTPUT CONSOLE --</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">iPhoneOS: </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">iPhone Model:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-- IF EMPTY THERE IS NO JAILBREAK FOUND FOR YOUR PHONE --</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Jailbreak: </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-- TH"
                        "IS WILL DELETE AND DISPLAY OUTPUT ONCE STARTED --</p></body></html>", nullptr));
        iPhoneModel->setText(QCoreApplication::translate("MainWindow", "iOS Model (ex. iPhone 12)", nullptr));
        Check->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        menuJAILBREAK_HELPER->setTitle(QCoreApplication::translate("MainWindow", "JAILBREAK &HELPER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
