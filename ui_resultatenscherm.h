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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ResultatenScherm
{
public:
    QPushButton *Begin;
    QPushButton *Vorige;
    QPushButton *Volgende;
    QPushButton *Einde;
    QPushButton *Upload;
    QPushButton *Stop;
    QGraphicsView *tekenVeld;

    void setupUi(QDialog *ResultatenScherm)
    {
        if (ResultatenScherm->objectName().isEmpty())
            ResultatenScherm->setObjectName(QStringLiteral("ResultatenScherm"));
        ResultatenScherm->resize(1150, 758);
        ResultatenScherm->setStyleSheet(QStringLiteral("background-color: rgba(202, 164, 227, 194);"));
        Begin = new QPushButton(ResultatenScherm);
        Begin->setObjectName(QStringLiteral("Begin"));
        Begin->setGeometry(QRect(0, 680, 201, 81));
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
        Vorige = new QPushButton(ResultatenScherm);
        Vorige->setObjectName(QStringLiteral("Vorige"));
        Vorige->setGeometry(QRect(390, 680, 191, 81));
        Vorige->setFont(font);
        Vorige->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Volgende = new QPushButton(ResultatenScherm);
        Volgende->setObjectName(QStringLiteral("Volgende"));
        Volgende->setGeometry(QRect(200, 680, 191, 81));
        Volgende->setFont(font);
        Volgende->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Einde = new QPushButton(ResultatenScherm);
        Einde->setObjectName(QStringLiteral("Einde"));
        Einde->setGeometry(QRect(580, 680, 191, 81));
        Einde->setFont(font);
        Einde->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Upload = new QPushButton(ResultatenScherm);
        Upload->setObjectName(QStringLiteral("Upload"));
        Upload->setGeometry(QRect(770, 680, 181, 81));
        Upload->setFont(font);
        Upload->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Stop = new QPushButton(ResultatenScherm);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(950, 680, 201, 81));
        Stop->setFont(font);
        Stop->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        tekenVeld = new QGraphicsView(ResultatenScherm);
        tekenVeld->setObjectName(QStringLiteral("tekenVeld"));
        tekenVeld->setGeometry(QRect(0, 0, 1151, 681));
        tekenVeld->setMinimumSize(QSize(281, 192));
        tekenVeld->setMouseTracking(true);
        tekenVeld->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        retranslateUi(ResultatenScherm);

        QMetaObject::connectSlotsByName(ResultatenScherm);
    } // setupUi

    void retranslateUi(QDialog *ResultatenScherm)
    {
        ResultatenScherm->setWindowTitle(QApplication::translate("ResultatenScherm", "Dialog", 0));
        Begin->setText(QApplication::translate("ResultatenScherm", "BEGIN", 0));
        Vorige->setText(QApplication::translate("ResultatenScherm", "VORIGE", 0));
        Volgende->setText(QApplication::translate("ResultatenScherm", "VOLGENDE", 0));
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
