/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cvimagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    CVImageWidget *capturaCamara;
    QGridLayout *gridLayout;
    QPushButton *btnDetecta;
    QPushButton *btnRecortar;
    QLabel *label;
    QLineEdit *leNombre;
    QLineEdit *leEtiqueta;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        capturaCamara = new CVImageWidget(centralWidget);
        capturaCamara->setObjectName(QStringLiteral("capturaCamara"));
        sizePolicy.setHeightForWidth(capturaCamara->sizePolicy().hasHeightForWidth());
        capturaCamara->setSizePolicy(sizePolicy);
        capturaCamara->setMinimumSize(QSize(600, 500));
        capturaCamara->setBaseSize(QSize(600, 400));

        verticalLayout->addWidget(capturaCamara);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnDetecta = new QPushButton(centralWidget);
        btnDetecta->setObjectName(QStringLiteral("btnDetecta"));

        gridLayout->addWidget(btnDetecta, 0, 0, 1, 1);

        btnRecortar = new QPushButton(centralWidget);
        btnRecortar->setObjectName(QStringLiteral("btnRecortar"));

        gridLayout->addWidget(btnRecortar, 0, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leNombre = new QLineEdit(centralWidget);
        leNombre->setObjectName(QStringLiteral("leNombre"));

        gridLayout->addWidget(leNombre, 1, 1, 1, 1);

        leEtiqueta = new QLineEdit(centralWidget);
        leEtiqueta->setObjectName(QStringLiteral("leEtiqueta"));

        gridLayout->addWidget(leEtiqueta, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 19));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnDetecta->setText(QApplication::translate("MainWindow", "Iniciar Deteccion", 0));
        btnRecortar->setText(QApplication::translate("MainWindow", "Guardar Rostro", 0));
        label->setText(QApplication::translate("MainWindow", "Ingrese su nombre:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
