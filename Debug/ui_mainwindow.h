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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDetecta;
    QPushButton *btnRecorta;
    QPushButton *btnCanny;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
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
        capturaCamara->setBaseSize(QSize(600, 400));

        verticalLayout->addWidget(capturaCamara);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnDetecta = new QPushButton(centralWidget);
        btnDetecta->setObjectName(QStringLiteral("btnDetecta"));

        horizontalLayout->addWidget(btnDetecta);

        btnRecorta = new QPushButton(centralWidget);
        btnRecorta->setObjectName(QStringLiteral("btnRecorta"));

        horizontalLayout->addWidget(btnRecorta);

        btnCanny = new QPushButton(centralWidget);
        btnCanny->setObjectName(QStringLiteral("btnCanny"));

        horizontalLayout->addWidget(btnCanny);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnDetecta->setText(QApplication::translate("MainWindow", "Iniciar Deteccion", 0));
        btnRecorta->setText(QApplication::translate("MainWindow", "Recortar Rostro", 0));
        btnCanny->setText(QApplication::translate("MainWindow", "Filtro Canny", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
