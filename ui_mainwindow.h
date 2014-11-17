/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *StartKnop;
    QPushButton *InvoegenKnop;
    QPushButton *AfsluitenKnop;
    QRadioButton *KnoopRadio;
    QRadioButton *StartKnoopRadio;
    QRadioButton *OngerichteTakRadio;
    QRadioButton *GerichteTakRadio;
    QGraphicsView *graphicsView;
    QComboBox *algChoice;
    QRadioButton *EindKnoopRadio;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 740);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StartKnop = new QPushButton(centralWidget);
        StartKnop->setObjectName(QStringLiteral("StartKnop"));
        StartKnop->setGeometry(QRect(190, 640, 161, 71));
        StartKnop->setMinimumSize(QSize(71, 0));
        QFont font;
        font.setPointSize(14);
        StartKnop->setFont(font);
        InvoegenKnop = new QPushButton(centralWidget);
        InvoegenKnop->setObjectName(QStringLiteral("InvoegenKnop"));
        InvoegenKnop->setGeometry(QRect(840, 640, 152, 71));
        InvoegenKnop->setMinimumSize(QSize(71, 41));
        InvoegenKnop->setFont(font);
        AfsluitenKnop = new QPushButton(centralWidget);
        AfsluitenKnop->setObjectName(QStringLiteral("AfsluitenKnop"));
        AfsluitenKnop->setGeometry(QRect(1181, 640, 161, 71));
        AfsluitenKnop->setMinimumSize(QSize(71, 41));
        AfsluitenKnop->setFont(font);
        KnoopRadio = new QRadioButton(centralWidget);
        KnoopRadio->setObjectName(QStringLiteral("KnoopRadio"));
        KnoopRadio->setGeometry(QRect(10, 50, 141, 41));
        KnoopRadio->setMinimumSize(QSize(82, 17));
        QFont font1;
        font1.setPointSize(12);
        KnoopRadio->setFont(font1);
        StartKnoopRadio = new QRadioButton(centralWidget);
        StartKnoopRadio->setObjectName(QStringLiteral("StartKnoopRadio"));
        StartKnoopRadio->setGeometry(QRect(10, 90, 141, 41));
        StartKnoopRadio->setMinimumSize(QSize(82, 17));
        StartKnoopRadio->setFont(font1);
        OngerichteTakRadio = new QRadioButton(centralWidget);
        OngerichteTakRadio->setObjectName(QStringLiteral("OngerichteTakRadio"));
        OngerichteTakRadio->setGeometry(QRect(10, 170, 161, 41));
        OngerichteTakRadio->setMinimumSize(QSize(91, 17));
        OngerichteTakRadio->setFont(font1);
        GerichteTakRadio = new QRadioButton(centralWidget);
        GerichteTakRadio->setObjectName(QStringLiteral("GerichteTakRadio"));
        GerichteTakRadio->setGeometry(QRect(10, 210, 151, 41));
        GerichteTakRadio->setMinimumSize(QSize(82, 17));
        GerichteTakRadio->setFont(font1);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(190, 0, 1151, 641));
        algChoice = new QComboBox(centralWidget);
        algChoice->setObjectName(QStringLiteral("algChoice"));
        algChoice->setGeometry(QRect(520, 640, 152, 71));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(algChoice->sizePolicy().hasHeightForWidth());
        algChoice->setSizePolicy(sizePolicy);
        algChoice->setMinimumSize(QSize(0, 0));
        algChoice->setFont(font);
        algChoice->setStyleSheet(QStringLiteral(""));
        EindKnoopRadio = new QRadioButton(centralWidget);
        EindKnoopRadio->setObjectName(QStringLiteral("EindKnoopRadio"));
        EindKnoopRadio->setGeometry(QRect(10, 130, 141, 41));
        EindKnoopRadio->setMinimumSize(QSize(82, 17));
        EindKnoopRadio->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 26));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        StartKnop->setText(QApplication::translate("MainWindow", "Start", 0));
        InvoegenKnop->setText(QApplication::translate("MainWindow", "Invoegen", 0));
        AfsluitenKnop->setText(QApplication::translate("MainWindow", "Afsluiten", 0));
        KnoopRadio->setText(QApplication::translate("MainWindow", "Knoop", 0));
        StartKnoopRadio->setText(QApplication::translate("MainWindow", "Start knoop", 0));
        OngerichteTakRadio->setText(QApplication::translate("MainWindow", "Ongerichte tak", 0));
        GerichteTakRadio->setText(QApplication::translate("MainWindow", "Gerichte tak", 0));
        algChoice->clear();
        algChoice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Dijkstra", 0)
        );
        EindKnoopRadio->setText(QApplication::translate("MainWindow", "Eind knoop", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
