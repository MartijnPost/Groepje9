/********************************************************************************
** Form generated from reading UI file 'invoegscherm.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOEGSCHERM_H
#define UI_INVOEGSCHERM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InvoegScherm
{
public:
    QPushButton *Toevoegen;
    QPushButton *Terug;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *addAlgBox;

    void setupUi(QDialog *InvoegScherm)
    {
        if (InvoegScherm->objectName().isEmpty())
            InvoegScherm->setObjectName(QStringLiteral("InvoegScherm"));
        InvoegScherm->resize(570, 740);
        InvoegScherm->setStyleSheet(QStringLiteral("background-color: rgba(202, 164, 227, 194);"));
        Toevoegen = new QPushButton(InvoegScherm);
        Toevoegen->setObjectName(QStringLiteral("Toevoegen"));
        Toevoegen->setGeometry(QRect(0, 610, 281, 131));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        Toevoegen->setFont(font);
        Toevoegen->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        Terug = new QPushButton(InvoegScherm);
        Terug->setObjectName(QStringLiteral("Terug"));
        Terug->setGeometry(QRect(280, 610, 291, 131));
        Terug->setFont(font);
        Terug->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));
        plainTextEdit = new QPlainTextEdit(InvoegScherm);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 60, 571, 551));
        QFont font1;
        font1.setPointSize(14);
        plainTextEdit->setFont(font1);
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        addAlgBox = new QLineEdit(InvoegScherm);
        addAlgBox->setObjectName(QStringLiteral("addAlgBox"));
        addAlgBox->setGeometry(QRect(0, 0, 571, 61));
        addAlgBox->setFont(font1);

        retranslateUi(InvoegScherm);

        QMetaObject::connectSlotsByName(InvoegScherm);
    } // setupUi

    void retranslateUi(QDialog *InvoegScherm)
    {
        InvoegScherm->setWindowTitle(QApplication::translate("InvoegScherm", "Dialog", 0));
        Toevoegen->setText(QApplication::translate("InvoegScherm", "TOEVOEGEN", 0));
        Terug->setText(QApplication::translate("InvoegScherm", "TERUG", 0));
        plainTextEdit->setPlaceholderText(QApplication::translate("InvoegScherm", "Algoritme geschreven in C++", 0));
        addAlgBox->setPlaceholderText(QApplication::translate("InvoegScherm", "Naam van algoritme", 0));
    } // retranslateUi

};

namespace Ui {
    class InvoegScherm: public Ui_InvoegScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOEGSCHERM_H
