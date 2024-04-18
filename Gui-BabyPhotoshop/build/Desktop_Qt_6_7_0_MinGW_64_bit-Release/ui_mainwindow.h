/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Apply;
    QPushButton *pushButton_2;
    QPushButton *Saveimage;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *Filters;
    QPushButton *rotate;
    QWidget *layoutWidget1;
    QHBoxLayout *bright;
    QSlider *horizontalSlider;
    QLabel *slidervalue;
    QLabel *label_importedpic_2;
    QLabel *label_importedpic;
    QLabel *label_background;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1125, 706);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe Script\";"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Apply = new QPushButton(centralwidget);
        Apply->setObjectName("Apply");
        Apply->setGeometry(QRect(10, 600, 151, 51));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Apply->sizePolicy().hasHeightForWidth());
        Apply->setSizePolicy(sizePolicy);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 440, 151, 71));
        Saveimage = new QPushButton(centralwidget);
        Saveimage->setObjectName("Saveimage");
        Saveimage->setGeometry(QRect(10, 520, 151, 71));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 450, 221, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        Filters = new QComboBox(layoutWidget);
        Filters->setObjectName("Filters");
        Filters->setMaxVisibleItems(6);

        verticalLayout->addWidget(Filters);

        rotate = new QPushButton(centralwidget);
        rotate->setObjectName("rotate");
        rotate->setGeometry(QRect(570, 570, 71, 51));
        rotate->setIconSize(QSize(30, 40));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(760, 450, 251, 61));
        bright = new QHBoxLayout(layoutWidget1);
        bright->setObjectName("bright");
        bright->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(layoutWidget1);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);

        bright->addWidget(horizontalSlider);

        slidervalue = new QLabel(layoutWidget1);
        slidervalue->setObjectName("slidervalue");
        slidervalue->setTextFormat(Qt::AutoText);
        slidervalue->setIndent(1);

        bright->addWidget(slidervalue);

        label_importedpic_2 = new QLabel(centralwidget);
        label_importedpic_2->setObjectName("label_importedpic_2");
        label_importedpic_2->setGeometry(QRect(564, 0, 556, 439));
        label_importedpic_2->setMidLineWidth(1);
        label_importedpic = new QLabel(centralwidget);
        label_importedpic->setObjectName("label_importedpic");
        label_importedpic->setGeometry(QRect(5, 0, 556, 439));
        label_background = new QLabel(centralwidget);
        label_background->setObjectName("label_background");
        label_background->setGeometry(QRect(0, 0, 1211, 681));
        MainWindow->setCentralWidget(centralwidget);
        label_background->raise();
        Apply->raise();
        pushButton_2->raise();
        Saveimage->raise();
        layoutWidget->raise();
        rotate->raise();
        layoutWidget->raise();
        label_importedpic_2->raise();
        label_importedpic->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1125, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Import Image", nullptr));
        Saveimage->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose Filter", nullptr));
        Filters->setCurrentText(QString());
        rotate->setText(QString());
        slidervalue->setText(QString());
        label_importedpic_2->setText(QString());
        label_importedpic->setText(QString());
        label_background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
