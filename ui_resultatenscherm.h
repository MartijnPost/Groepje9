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
        ResultatenScherm->resize(1150, 740);
        Begin = new QPushButton(ResultatenScherm);
        Begin->setObjectName(QStringLiteral("Begin"));
        Begin->setGeometry(QRect(0, 680, 141, 61));
        QFont font;
        font.setPointSize(14);
        Begin->setFont(font);
        Vorige = new QPushButton(ResultatenScherm);
        Vorige->setObjectName(QStringLiteral("Vorige"));
        Vorige->setGeometry(QRect(410, 680, 141, 61));
        Vorige->setFont(font);
        Volgende = new QPushButton(ResultatenScherm);
        Volgende->setObjectName(QStringLiteral("Volgende"));
        Volgende->setGeometry(QRect(210, 680, 141, 61));
        Volgende->setFont(font);
        Einde = new QPushButton(ResultatenScherm);
        Einde->setObjectName(QStringLiteral("Einde"));
        Einde->setGeometry(QRect(620, 680, 141, 61));
        Einde->setFont(font);
        Upload = new QPushButton(ResultatenScherm);
        Upload->setObjectName(QStringLiteral("Upload"));
        Upload->setGeometry(QRect(810, 680, 141, 61));
        Upload->setFont(font);
        Stop = new QPushButton(ResultatenScherm);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(1010, 680, 141, 61));
        Stop->setFont(font);
        tekenVeld = new QGraphicsView(ResultatenScherm);
        tekenVeld->setObjectName(QStringLiteral("tekenVeld"));
        tekenVeld->setGeometry(QRect(0, 0, 1151, 681));
        tekenVeld->setMinimumSize(QSize(281, 192));
        tekenVeld->setMouseTracking(true);

        retranslateUi(ResultatenScherm);

        QMetaObject::connectSlotsByName(ResultatenScherm);
    } // setupUi

    void retranslateUi(QDialog *ResultatenScherm)
    {
        ResultatenScherm->setWindowTitle(QApplication::translate("ResultatenScherm", "Dialog", 0));
        Begin->setText(QApplication::translate("ResultatenScherm", "Begin", 0));
        Vorige->setText(QApplication::translate("ResultatenScherm", "Vorige", 0));
        Volgende->setText(QApplication::translate("ResultatenScherm", "Volgende", 0));
        Einde->setText(QApplication::translate("ResultatenScherm", "Einde", 0));
        Upload->setText(QApplication::translate("ResultatenScherm", "Upload", 0));
        Stop->setText(QApplication::translate("ResultatenScherm", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class ResultatenScherm: public Ui_ResultatenScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTATENSCHERM_H
