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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *KnoopRadio;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *StartKnoopRadio;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *EindKnoopRadio;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *OngerichteTakRadio;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *GerichteTakRadio;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *StartKnop;
    QComboBox *algChoice;
    QPushButton *InvoegenKnop;
    QPushButton *ClearKnop;
    QPushButton *AfsluitenKnop;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1349, 693);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgba(204, 176, 212, 210);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        KnoopRadio = new QRadioButton(centralWidget);
        KnoopRadio->setObjectName(QStringLiteral("KnoopRadio"));
        KnoopRadio->setMinimumSize(QSize(20, 17));
        QFont font;
        font.setPointSize(12);
        KnoopRadio->setFont(font);

        horizontalLayout_2->addWidget(KnoopRadio);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 60));
        label->setBaseSize(QSize(0, 0));
        label->setMouseTracking(false);
        label->setPixmap(QPixmap(QString::fromUtf8("knoop.png")));
        label->setScaledContents(true);

        horizontalLayout_2->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        StartKnoopRadio = new QRadioButton(centralWidget);
        StartKnoopRadio->setObjectName(QStringLiteral("StartKnoopRadio"));
        StartKnoopRadio->setMinimumSize(QSize(20, 17));
        StartKnoopRadio->setFont(font);

        horizontalLayout_3->addWidget(StartKnoopRadio);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 60));
        label_2->setMaximumSize(QSize(60, 60));
        label_2->setPixmap(QPixmap(QString::fromUtf8("startknoop.png")));
        label_2->setScaledContents(true);

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        EindKnoopRadio = new QRadioButton(centralWidget);
        EindKnoopRadio->setObjectName(QStringLiteral("EindKnoopRadio"));
        EindKnoopRadio->setMinimumSize(QSize(20, 17));
        EindKnoopRadio->setFont(font);

        horizontalLayout_4->addWidget(EindKnoopRadio);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(60, 60));
        label_3->setMaximumSize(QSize(60, 60));
        label_3->setPixmap(QPixmap(QString::fromUtf8("eindknoop.png")));
        label_3->setScaledContents(true);

        horizontalLayout_4->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        OngerichteTakRadio = new QRadioButton(centralWidget);
        OngerichteTakRadio->setObjectName(QStringLiteral("OngerichteTakRadio"));
        OngerichteTakRadio->setMinimumSize(QSize(20, 17));
        OngerichteTakRadio->setFont(font);

        horizontalLayout_5->addWidget(OngerichteTakRadio);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(60, 60));
        label_4->setMaximumSize(QSize(60, 60));
        label_4->setPixmap(QPixmap(QString::fromUtf8("gerichtepijll.png")));
        label_4->setScaledContents(true);

        horizontalLayout_5->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        GerichteTakRadio = new QRadioButton(centralWidget);
        GerichteTakRadio->setObjectName(QStringLiteral("GerichteTakRadio"));
        GerichteTakRadio->setMinimumSize(QSize(20, 17));
        GerichteTakRadio->setFont(font);

        horizontalLayout_6->addWidget(GerichteTakRadio);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(60, 60));
        label_5->setMaximumSize(QSize(60, 60));
        label_5->setPixmap(QPixmap(QString::fromUtf8("gerichtpijl.png")));
        label_5->setScaledContents(true);

        horizontalLayout_6->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMaximumSize(QSize(16777215, 16777215));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        StartKnop = new QPushButton(centralWidget);
        StartKnop->setObjectName(QStringLiteral("StartKnop"));
        StartKnop->setMinimumSize(QSize(0, 110));
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
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        StartKnop->setFont(font1);
        StartKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"\n"
""));

        horizontalLayout->addWidget(StartKnop);

        algChoice = new QComboBox(centralWidget);
        algChoice->setObjectName(QStringLiteral("algChoice"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(algChoice->sizePolicy().hasHeightForWidth());
        algChoice->setSizePolicy(sizePolicy2);
        algChoice->setMinimumSize(QSize(200, 110));
        algChoice->setFont(font1);
        algChoice->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"padding: 1px 0px 1px 3px; /*This makes text colour work*/\n"
""));
        algChoice->setEditable(false);

        horizontalLayout->addWidget(algChoice);

        InvoegenKnop = new QPushButton(centralWidget);
        InvoegenKnop->setObjectName(QStringLiteral("InvoegenKnop"));
        InvoegenKnop->setMinimumSize(QSize(0, 110));
        InvoegenKnop->setFont(font1);
        InvoegenKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(InvoegenKnop);

        ClearKnop = new QPushButton(centralWidget);
        ClearKnop->setObjectName(QStringLiteral("ClearKnop"));
        ClearKnop->setMinimumSize(QSize(0, 110));
        ClearKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";\n"
"\n"
""));

        horizontalLayout->addWidget(ClearKnop);

        AfsluitenKnop = new QPushButton(centralWidget);
        AfsluitenKnop->setObjectName(QStringLiteral("AfsluitenKnop"));
        AfsluitenKnop->setMinimumSize(QSize(0, 110));
        AfsluitenKnop->setFont(font1);
        AfsluitenKnop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(AfsluitenKnop);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1349, 25));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        KnoopRadio->setText(QString());
        label->setText(QString());
        StartKnoopRadio->setText(QString());
        label_2->setText(QString());
        EindKnoopRadio->setText(QString());
        label_3->setText(QString());
        OngerichteTakRadio->setText(QString());
        label_4->setText(QString());
        GerichteTakRadio->setText(QString());
        label_5->setText(QString());
        StartKnop->setText(QApplication::translate("MainWindow", "START", 0));
        algChoice->clear();
        algChoice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DIJKSTRA", 0)
         << QApplication::translate("MainWindow", "BELLMAN-FORD", 0)
        );
        algChoice->setCurrentText(QApplication::translate("MainWindow", "DIJKSTRA", 0));
        InvoegenKnop->setText(QApplication::translate("MainWindow", "INVOEGEN", 0));
        ClearKnop->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        AfsluitenKnop->setText(QApplication::translate("MainWindow", "AFSLUITEN", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
