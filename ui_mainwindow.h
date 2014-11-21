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
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1350, 771);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgba(204, 176, 212, 210);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StartKnop = new QPushButton(centralWidget);
        StartKnop->setObjectName(QStringLiteral("StartKnop"));
        StartKnop->setGeometry(QRect(190, 640, 251, 101));
        StartKnop->setMinimumSize(QSize(71, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QLinearGradient gradient(1, 0, 1, 0);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(160, 75, 164, 255));
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush1(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QLinearGradient gradient1(1, 0, 1, 0);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(160, 75, 164, 255));
        gradient1.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QLinearGradient gradient2(1, 0, 1, 0);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(160, 75, 164, 255));
        gradient2.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(1, 0, 1, 0);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(160, 75, 164, 255));
        gradient3.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(1, 0, 1, 0);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(160, 75, 164, 255));
        gradient4.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QLinearGradient gradient5(1, 0, 1, 0);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(160, 75, 164, 255));
        gradient5.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        QLinearGradient gradient6(1, 0, 1, 0);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(160, 75, 164, 255));
        gradient6.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        QLinearGradient gradient7(1, 0, 1, 0);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(160, 75, 164, 255));
        gradient7.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QLinearGradient gradient8(1, 0, 1, 0);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(160, 75, 164, 255));
        gradient8.setColorAt(1, QColor(255, 255, 255, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        StartKnop->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        StartKnop->setFont(font);
        StartKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"\n"
""));
        InvoegenKnop = new QPushButton(centralWidget);
        InvoegenKnop->setObjectName(QStringLiteral("InvoegenKnop"));
        InvoegenKnop->setGeometry(QRect(660, 640, 231, 101));
        InvoegenKnop->setMinimumSize(QSize(71, 41));
        InvoegenKnop->setFont(font);
        InvoegenKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        AfsluitenKnop = new QPushButton(centralWidget);
        AfsluitenKnop->setObjectName(QStringLiteral("AfsluitenKnop"));
        AfsluitenKnop->setGeometry(QRect(1100, 640, 241, 101));
        AfsluitenKnop->setMinimumSize(QSize(71, 41));
        AfsluitenKnop->setFont(font);
        AfsluitenKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        KnoopRadio = new QRadioButton(centralWidget);
        KnoopRadio->setObjectName(QStringLiteral("KnoopRadio"));
        KnoopRadio->setGeometry(QRect(20, 30, 141, 41));
        KnoopRadio->setMinimumSize(QSize(82, 17));
        QFont font1;
        font1.setPointSize(12);
        KnoopRadio->setFont(font1);
        StartKnoopRadio = new QRadioButton(centralWidget);
        StartKnoopRadio->setObjectName(QStringLiteral("StartKnoopRadio"));
        StartKnoopRadio->setGeometry(QRect(20, 100, 141, 41));
        StartKnoopRadio->setMinimumSize(QSize(82, 17));
        StartKnoopRadio->setFont(font1);
        OngerichteTakRadio = new QRadioButton(centralWidget);
        OngerichteTakRadio->setObjectName(QStringLiteral("OngerichteTakRadio"));
        OngerichteTakRadio->setGeometry(QRect(20, 240, 161, 41));
        OngerichteTakRadio->setMinimumSize(QSize(91, 17));
        OngerichteTakRadio->setFont(font1);
        GerichteTakRadio = new QRadioButton(centralWidget);
        GerichteTakRadio->setObjectName(QStringLiteral("GerichteTakRadio"));
        GerichteTakRadio->setGeometry(QRect(20, 310, 151, 41));
        GerichteTakRadio->setMinimumSize(QSize(82, 17));
        GerichteTakRadio->setFont(font1);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(190, 0, 1151, 641));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        algChoice = new QComboBox(centralWidget);
        algChoice->setObjectName(QStringLiteral("algChoice"));
        algChoice->setGeometry(QRect(440, 640, 221, 101));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(algChoice->sizePolicy().hasHeightForWidth());
        algChoice->setSizePolicy(sizePolicy);
        algChoice->setMinimumSize(QSize(0, 0));
        algChoice->setFont(font);
        algChoice->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
""));
        algChoice->setEditable(false);
        EindKnoopRadio = new QRadioButton(centralWidget);
        EindKnoopRadio->setObjectName(QStringLiteral("EindKnoopRadio"));
        EindKnoopRadio->setGeometry(QRect(20, 170, 141, 41));
        EindKnoopRadio->setMinimumSize(QSize(82, 17));
        EindKnoopRadio->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 61, 61));
        label->setPixmap(QPixmap(QString::fromUtf8("knoop.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 90, 61, 61));
        label_2->setPixmap(QPixmap(QString::fromUtf8("startknoop.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 160, 61, 61));
        label_3->setPixmap(QPixmap(QString::fromUtf8("eindknoop.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 230, 61, 61));
        label_4->setPixmap(QPixmap(QString::fromUtf8("gerichtepijll.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 300, 61, 61));
        label_5->setPixmap(QPixmap(QString::fromUtf8("gerichtpijl.png")));
        label_5->setScaledContents(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(890, 640, 211, 101));
        pushButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1350, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        StartKnop->setText(QApplication::translate("MainWindow", "START", 0));
        InvoegenKnop->setText(QApplication::translate("MainWindow", "INVOEGEN", 0));
        AfsluitenKnop->setText(QApplication::translate("MainWindow", "AFSLUITEN", 0));
        KnoopRadio->setText(QString());
        StartKnoopRadio->setText(QString());
        OngerichteTakRadio->setText(QString());
        GerichteTakRadio->setText(QString());
        algChoice->clear();
        algChoice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DIJKSTRA", 0)
        );
        algChoice->setCurrentText(QApplication::translate("MainWindow", "DIJKSTRA", 0));
        EindKnoopRadio->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "CLEAR", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
