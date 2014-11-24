/********************************************************************************
** Form generated from reading UI file 'resultatenscherm.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTATENSCHERM_H
#define UI_RESULTATENSCHERM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResultatenScherm
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *tekenVeld;
    QHBoxLayout *horizontalLayout;
    QPushButton *Begin;
    QPushButton *Volgende;
    QPushButton *Vorige;
    QPushButton *Einde;
    QPushButton *Upload;
    QPushButton *Stop;

    void setupUi(QDialog *ResultatenScherm)
    {
        if (ResultatenScherm->objectName().isEmpty())
            ResultatenScherm->setObjectName(QStringLiteral("ResultatenScherm"));
        ResultatenScherm->resize(1150, 758);
        ResultatenScherm->setMaximumSize(QSize(2000, 2000));
        ResultatenScherm->setStyleSheet(QStringLiteral("background-color: rgba(202, 164, 227, 194);"));
        gridLayout = new QGridLayout(ResultatenScherm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tekenVeld = new QGraphicsView(ResultatenScherm);
        tekenVeld->setObjectName(QStringLiteral("tekenVeld"));
        tekenVeld->setMinimumSize(QSize(281, 192));
        tekenVeld->setMouseTracking(true);
        tekenVeld->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(tekenVeld, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Begin = new QPushButton(ResultatenScherm);
        Begin->setObjectName(QStringLiteral("Begin"));
        Begin->setMinimumSize(QSize(0, 110));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        Begin->setFont(font);
        Begin->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Begin);

        Volgende = new QPushButton(ResultatenScherm);
        Volgende->setObjectName(QStringLiteral("Volgende"));
        Volgende->setMinimumSize(QSize(0, 110));
        Volgende->setFont(font);
        Volgende->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Volgende);

        Vorige = new QPushButton(ResultatenScherm);
        Vorige->setObjectName(QStringLiteral("Vorige"));
        Vorige->setMinimumSize(QSize(0, 110));
        Vorige->setFont(font);
        Vorige->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Vorige->setAutoDefault(true);

        horizontalLayout->addWidget(Vorige);

        Einde = new QPushButton(ResultatenScherm);
        Einde->setObjectName(QStringLiteral("Einde"));
        Einde->setMinimumSize(QSize(0, 110));
        Einde->setFont(font);
        Einde->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Einde);

        Upload = new QPushButton(ResultatenScherm);
        Upload->setObjectName(QStringLiteral("Upload"));
        Upload->setMinimumSize(QSize(0, 110));
        Upload->setFont(font);
        Upload->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Upload);

        Stop = new QPushButton(ResultatenScherm);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setMinimumSize(QSize(0, 110));
        Stop->setFont(font);
        Stop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Stop);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ResultatenScherm);

        QMetaObject::connectSlotsByName(ResultatenScherm);
    } // setupUi

    void retranslateUi(QDialog *ResultatenScherm)
    {
        ResultatenScherm->setWindowTitle(QApplication::translate("ResultatenScherm", "Dialog", 0));
        Begin->setText(QApplication::translate("ResultatenScherm", "BEGIN", 0));
        Volgende->setText(QApplication::translate("ResultatenScherm", "VOLGENDE", 0));
        Vorige->setText(QApplication::translate("ResultatenScherm", "VORIGE", 0));
        Einde->setText(QApplication::translate("ResultatenScherm", "EINDE", 0));
        Upload->setText(QApplication::translate("ResultatenScherm", "UPLOAD", 0));
        Stop->setText(QApplication::translate("ResultatenScherm", "STOP", 0));
    } // retranslateUi

};

namespace Ui {
    class ResultatenScherm: public Ui_ResultatenScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTATENSCHERM_H
