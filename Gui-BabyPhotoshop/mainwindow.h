#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_8_clicked();

    void on_Rotate_clicked();

    void on_pushButton_25_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_24_clicked();

    void on_save_clicked();

    void on_pushButton_13_clicked();

    QString showColorPickerDialog();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_14_clicked();

    void visibilty();
    void on_pushButton_9_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_26_clicked();

    void onStartPointChanged(const QPoint &point);
    void onEndPointChanged(const QPoint &point);


    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

private:
    Ui::MainWindow *ui;
    CustomWidget *customWidget;
};
#endif // MAINWINDOW_H
