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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InvoegScherm
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *addAlgBox;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Terug;
    QPushButton *Toevoegen;

    void setupUi(QDialog *InvoegScherm)
    {
        if (InvoegScherm->objectName().isEmpty())
            InvoegScherm->setObjectName(QStringLiteral("InvoegScherm"));
        InvoegScherm->resize(570, 740);
        InvoegScherm->setStyleSheet(QStringLiteral("background-color: rgba(202, 164, 227, 194);"));
        gridLayout = new QGridLayout(InvoegScherm);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addAlgBox = new QLineEdit(InvoegScherm);
        addAlgBox->setObjectName(QStringLiteral("addAlgBox"));
        QFont font;
        font.setPointSize(14);
        addAlgBox->setFont(font);
        addAlgBox->setStyleSheet(QStringLiteral("background-color: rgba(202, 164, 227, 194);"));

        verticalLayout->addWidget(addAlgBox);

        plainTextEdit = new QPlainTextEdit(InvoegScherm);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Terug = new QPushButton(InvoegScherm);
        Terug->setObjectName(QStringLiteral("Terug"));
        Terug->setMinimumSize(QSize(0, 130));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Black"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        Terug->setFont(font1);
        Terug->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Terug);

        Toevoegen = new QPushButton(InvoegScherm);
        Toevoegen->setObjectName(QStringLiteral("Toevoegen"));
        Toevoegen->setMinimumSize(QSize(0, 130));
        Toevoegen->setFont(font1);
        Toevoegen->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:0, stop:0 rgba(160, 75, 164, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"font: 75 16pt \"Arial Black\";"));

        horizontalLayout->addWidget(Toevoegen);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(InvoegScherm);

        QMetaObject::connectSlotsByName(InvoegScherm);
    } // setupUi

    void retranslateUi(QDialog *InvoegScherm)
    {
        InvoegScherm->setWindowTitle(QApplication::translate("InvoegScherm", "Dialog", 0));
        addAlgBox->setPlaceholderText(QApplication::translate("InvoegScherm", "Naam van algoritme", 0));
        plainTextEdit->setPlaceholderText(QApplication::translate("InvoegScherm", "Algoritme geschreven in C++", 0));
        Terug->setText(QApplication::translate("InvoegScherm", "TERUG", 0));
        Toevoegen->setText(QApplication::translate("InvoegScherm", "TOEVOEGEN", 0));
    } // retranslateUi

};

namespace Ui {
    class InvoegScherm: public Ui_InvoegScherm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOEGSCHERM_H
