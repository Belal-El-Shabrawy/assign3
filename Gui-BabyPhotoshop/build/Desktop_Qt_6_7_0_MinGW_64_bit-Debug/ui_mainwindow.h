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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_importedpic;
    QLabel *label_importedpic_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *Rotate;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_20;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QLabel *label_background;
    QWidget *widget;
    QHBoxLayout *bright;
    QSlider *horizontalSlider;
    QLabel *slidervalue;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_7;
    QPushButton *save;
    QLabel *label_importedpic_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_19;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1131, 791);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("BabyPhotshop");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(255);
        sizePolicy.setVerticalStretch(255);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(1131, 791));
        centralwidget->setAutoFillBackground(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 150, 151, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Oswald")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 450, 141, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Oswald")});
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 700 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;\n"
"border-radius:25px;}\n"
"QPushButton:hover:!pressed{\n"
"font: 700 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"background-color: #FDF6F6;\n"
"border: 3px solid #C5001A}"));
        label_importedpic = new QLabel(centralwidget);
        label_importedpic->setObjectName("label_importedpic");
        label_importedpic->setGeometry(QRect(400, 160, 301, 281));
        label_importedpic->setStyleSheet(QString::fromUtf8("background-color: #2A3132;\n"
"border-radius: 10px;"));
        label_importedpic->setWordWrap(false);
        label_importedpic->setOpenExternalLinks(false);
        label_importedpic_2 = new QLabel(centralwidget);
        label_importedpic_2->setObjectName("label_importedpic_2");
        label_importedpic_2->setGeometry(QRect(780, 160, 301, 281));
        label_importedpic_2->setAutoFillBackground(false);
        label_importedpic_2->setStyleSheet(QString::fromUtf8("background-color: #2A3132; border-radius: 10px;\n"
"\n"
"font: 12pt \"Oswald\";\n"
"color: #FDF6F6;"));
        label_importedpic_2->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(190, 150, 151, 41));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 210, 151, 41));
        pushButton_4->setFont(font);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 570, 151, 41));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(190, 570, 151, 41));
        pushButton_6->setFont(font);
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        Rotate = new QPushButton(centralwidget);
        Rotate->setObjectName("Rotate");
        Rotate->setGeometry(QRect(190, 210, 151, 41));
        Rotate->setFont(font);
        Rotate->setCursor(QCursor(Qt::PointingHandCursor));
        Rotate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(190, 330, 151, 41));
        pushButton_10->setFont(font);
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(30, 270, 151, 41));
        pushButton_11->setFont(font);
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(190, 390, 151, 41));
        pushButton_12->setFont(font);
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(190, 510, 151, 41));
        pushButton_13->setFont(font);
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(30, 510, 151, 41));
        pushButton_14->setFont(font);
        pushButton_14->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(30, 450, 151, 41));
        pushButton_15->setFont(font);
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(30, 330, 151, 41));
        pushButton_16->setFont(font);
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(190, 450, 151, 41));
        pushButton_17->setFont(font);
        pushButton_17->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(190, 270, 151, 41));
        pushButton_18->setFont(font);
        pushButton_18->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(30, 390, 151, 41));
        pushButton_20->setFont(font);
        pushButton_20->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setEnabled(true);
        pushButton_22->setGeometry(QRect(30, 630, 81, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Oswald")});
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        pushButton_22->setFont(font2);
        pushButton_22->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 9pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 9pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(110, 630, 71, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Oswald")});
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        pushButton_23->setFont(font3);
        pushButton_23->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 9pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 9pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        label_background = new QLabel(centralwidget);
        label_background->setObjectName("label_background");
        label_background->setGeometry(QRect(-4, 10, 1131, 791));
        label_background->setCursor(QCursor(Qt::ArrowCursor));
        label_background->setStyleSheet(QString::fromUtf8("background-color: #FDF6F6;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(795, 442, 281, 71));
        widget->setStyleSheet(QString::fromUtf8(""));
        bright = new QHBoxLayout(widget);
        bright->setObjectName("bright");
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::handle{\n"
"background-color:#002C54;\n"
"border-radius: 7;}"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);

        bright->addWidget(horizontalSlider);

        slidervalue = new QLabel(widget);
        slidervalue->setObjectName("slidervalue");
        slidervalue->setTextFormat(Qt::AutoText);
        slidervalue->setIndent(1);

        bright->addWidget(slidervalue);

        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(270, 630, 71, 41));
        pushButton_24->setFont(font);
        pushButton_24->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_25 = new QPushButton(centralwidget);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setEnabled(true);
        pushButton_25->setGeometry(QRect(190, 630, 81, 41));
        sizePolicy1.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy1);
        pushButton_25->setFont(font);
        pushButton_25->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(918, 26, 81, 41));
        pushButton_7->setFont(font);
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"border: 3px solid #C5001A;\n"
"background-color: #FDF6F6;}\n"
"QPushButton:hover:!pressed{\n"
"font: 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;}"));
        save = new QPushButton(centralwidget);
        save->setObjectName("save");
        save->setGeometry(QRect(1020, 20, 81, 51));
        save->setFont(font1);
        save->setCursor(QCursor(Qt::PointingHandCursor));
        save->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 700 14pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;\n"
"border-radius:25px}\n"
"QPushButton:hover:!pressed{\n"
"font: 700 14pt \"Oswald\";\n"
"color: #C5001A;\n"
"background-color: #FDF6F6;}"));
        label_importedpic_3 = new QLabel(centralwidget);
        label_importedpic_3->setObjectName("label_importedpic_3");
        label_importedpic_3->setGeometry(QRect(400, 160, 301, 281));
        label_importedpic_3->setAutoFillBackground(false);
        label_importedpic_3->setStyleSheet(QString::fromUtf8("background-color: #2A3132; border-radius: 10px;"));
        label_importedpic_3->setWordWrap(false);
        label_importedpic_3->setOpenExternalLinks(false);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(707, 160, 51, 31));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 10pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(707, 200, 51, 31));
        pushButton_19->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font: 10pt \"Oswald\";\n"
"color: #002C54;\n"
"border: 3px solid #002C54;}\n"
"QPushButton:hover:!pressed{\n"
"font: 10pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #002C54;}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1131, 101));
        label->setStyleSheet(QString::fromUtf8("background-color: #002C54"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(16, 19, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(63, 55, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Oswald\";\n"
"color: #FDF6F6;\n"
"background-color: #C5001A;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(49, 20, 71, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Oswald\";\n"
"color: #FDF6F6;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(96, 57, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Oswald\";\n"
"color: #FDF6F6;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(780, 450, 301, 51));
        label_6->setStyleSheet(QString::fromUtf8("background-color: #C5001A;\n"
"border-radius: 25px;"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 120, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        label_background->raise();
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_importedpic->raise();
        label_importedpic_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        Rotate->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        pushButton_15->raise();
        pushButton_16->raise();
        pushButton_17->raise();
        pushButton_18->raise();
        pushButton_20->raise();
        pushButton_22->raise();
        pushButton_23->raise();
        pushButton_24->raise();
        pushButton_25->raise();
        pushButton_7->raise();
        save->raise();
        label_importedpic_3->raise();
        pushButton_8->raise();
        pushButton_19->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        widget->raise();
        label_7->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Baby Photoshop", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Import Image", nullptr));
        label_importedpic->setText(QString());
        label_importedpic_2->setText(QCoreApplication::translate("MainWindow", "Choose filter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", " Black and White", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Edge detect", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Purple effect", nullptr));
        Rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Infrared", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Merge", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Invert colors", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Add frame", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Oil painting", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Broken TV", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Tv effect", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Classic", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Sunshine", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Skew", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Flip\n"
"Vertically", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Flip\n"
"Horizontally", nullptr));
        label_background->setText(QString());
        slidervalue->setText(QString());
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Darken", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Lighten", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_importedpic_3->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Image 1", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Image 2", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "aby", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "hotoshop", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
