#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include "Image_Class.h"
#include <QPushButton>
#include <QStringList>
#include <QComboBox>
#include <QColorDialog>
#include <QColor>
#include <algorithm>
#include <random>
#include <QWidget>
#include <QLabel>
#include <QFrame>
#include<QPainter>
#include <QPoint>
#include <QCursor>
#include <QMouseEvent>
#include <QStyleFactory>

using namespace std;
std::string stringname,stringname2,stringname3;
bool condition = true;
bool condition2=false;
bool condition3=true;
Image image;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1125, 760);
    ui->label_importedpic_3->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_19->setVisible(false);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::on_horizontalSlider_valueChanged);
    ui->horizontalSlider->setValue(50);
    ui->bright->parentWidget()->setVisible(false);
    ui->label_6->setVisible(false);
    QBitmap mask(ui->label_importedpic->size());
    mask.fill(Qt::color0);
    QPainter painter(&mask);
    painter.setBrush(Qt::color1);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(mask.rect(), 10, 10);
    ui->label_importedpic->setMask(mask);
    ui->label_importedpic_2->setMask(mask);

    if(stringname2.empty()){
        condition=true;
    }
    else{
        condition=false;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
        // Open a file dialog
        QString fileName = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg);;All Files (*.*)");
        stringname = fileName.toStdString();
        // Check if a file was selected
        if (!fileName.isEmpty()) {
            stringname2 = stringname;
            // Load the image
            QPixmap image(fileName);
            if (image.isNull()) {
                // Handle error (e.g., invalid image format)
                QMessageBox::warning(this, "Error", "Failed to load image!");
                return;
            }
            ui->label_importedpic->setScaledContents(true);
            ui->label_importedpic->setPixmap(image);
            image.save("Rotated.png");
            ui->label_importedpic_2->setPixmap(QPixmap());
        }
        else{
            QMessageBox::warning(this, "Error", "Failed to load image!");
            stringname=stringname2;
            return;

        }
        if(stringname2.empty()){
            condition=true;
        }
        else{
            condition=false;
        }

    }
void MainWindow::on_pushButton_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned  int average = 0;
            for (int k = 0; k < 3; k++) {
                average += image(i, j, k);
            }
            average /= 3;
            for (int k = 0; k < 3; k++){
                image(i, j, k) = average;
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}

void MainWindow::on_pushButton_3_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned  int average = 0;
            for (int k = 0; k < 3; k++) {
                average += image(i, j, k);
            }
            average /= 3;
            for (int k = 0; k < 3; k++){
                image(i, j, k) = average;
            }
        }
    }
    for(int i = 0;i<image.width;i++)
    {
        for(int j = 0;j<image.height;j++)
        {
            if(image(i,j,0)<= 100)
            {
                for(int k = 0; k < 3; k++)
                {
                    image(i,j,k)=0;
                }
            }
            else
            {
                for(int k = 0; k < 3; k++)
                {
                    image(i,j,k)=255;
                }
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}


void MainWindow::on_pushButton_12_clicked()
{if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Set all channels to the average value
            image(i, j, 0) = 255-image(i, j, 0);
            image(i, j, 1) = 255-image(i, j, 1);
            image(i, j, 2) = 255-image(i, j, 2);
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}

void MainWindow::on_pushButton_22_clicked()
{if(!condition){
    ui->pushButton_8->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->bright->parentWidget()->setVisible(false);
    ui->label_6->setVisible(false);
    condition3=false;
    image.loadNewImage(stringname);
    int temporary;
    for(int i = 0;i<image.width;i++)
    {
        for(int j = 0;j<image.height/2;j++)
        {
            for(int k = 0; k < 3; k++)
            {
                temporary=image(i,j,k);
                image(i,j,k) = image(i,image.height-j-1,k);
                image(i,image.height-j-1,k)=temporary;
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}


void MainWindow::on_pushButton_23_clicked()
{if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    int temporary;
    for(int i = 0;i<image.width/2;i++)
    {
        for(int j = 0;j<image.height;j++)
        {
            for(int k = 0; k < 3; k++)
            {
                temporary=image(i,j,k);
                image(i,j,k) = image(image.width-i,j,k);
                image(image.width-i,j,k)=temporary;
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}



void MainWindow::on_Rotate_clicked()
{
    if(!condition){
        ui->pushButton_8->setVisible(false);
        ui->pushButton_19->setVisible(false);
        ui->label_importedpic_3->setVisible(false);
        ui->label_importedpic->setVisible(true);
        ui->bright->parentWidget()->setVisible(false);
        ui->label_6->setVisible(false);
        if(condition3){
        image.loadNewImage("Rotated.png");
        }
        else {
            QString imagePath = ui->label_importedpic->text();


             image.loadNewImage(stringname);
        }
        int m = image.width;
        int n = image.height;
        Image image2(n, m); // Width and height are swapped for the rotated image
        // Iterate through each pixel of the original image
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Assign the pixel at (i, j) of the original image to the rotated position in the result image
                // The formula for the rotated position is (n - j - 1, i)
                for (int k = 0; k < 3; k++) {
                    image2(n - j - 1, i, k) = image(i, j, k);

                }
            }
        }
        Image temp;
        image=image2;
        image2=temp;
        image.saveImage("Rotated.png");
        QPixmap editedImage("Rotated.png");
        ui->label_importedpic_2->setScaledContents(true);
        ui->label_importedpic_2->setPixmap(editedImage);
        condition2 =true;
        condition3=true;

    }
}


void MainWindow::on_pushButton_25_clicked()
{if(!condition){
    ui->pushButton_8->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->label_importedpic_3->setVisible(false);
    ui->label_importedpic->setVisible(true);
    ui->label_6->setVisible(true);
    condition3=false;
    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setMaximum(100);
    ui->bright->parentWidget()->setVisible(true);
    image.loadNewImage(stringname);
    double num=ui->horizontalSlider->value();
    num=1+num/100;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                int newValue = static_cast<int>(image.getPixel(i, j, k) * num);
                newValue = std::max(0, std::min(255, newValue));
                image.setPixel(i, j, k, newValue);
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
        ui->slidervalue->setText(QString::number(value));
}


void MainWindow::on_pushButton_24_clicked()
{if(!condition){
    ui->pushButton_8->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->label_importedpic_3->setVisible(false);
    ui->label_importedpic->setVisible(true);
    condition3=false;
    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setMaximum(100);;
    ui->bright->parentWidget()->setVisible(true);
    ui->label_6->setVisible(true);
    image.loadNewImage(stringname);
    double num=ui->horizontalSlider->value();
    num=1-num/100;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                int newValue = static_cast<int>(image.getPixel(i, j, k) * num);
                newValue = std::max(0, std::min(255, newValue));
                image.setPixel(i, j, k, newValue);
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}

void MainWindow::on_save_clicked()
{
    if(!condition){
        QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("PNG Files (*.png);;JPEG Files (*.jpg)"));
        if (!saveFilePath.isEmpty()) {
            image.saveImage(saveFilePath.toStdString());
            ui->label_importedpic_2->setPixmap(QPixmap());
            QFile::remove("Rotated.png");
            QPixmap image3("Filtered.png");
            image3.save("Rotated.png");
        }
        else{
            QMessageBox::warning(this, "Error", "Failed to Save image!");
            return;
        }
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    QColor color(showColorPickerDialog());
    int red = color.red();
    int green = color.green();
    int blue = color.blue();
    image.loadNewImage(stringname);
    int thickness=(image.height)/25;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < thickness; ++j) {
            // Initialize average value
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;

        }
    }
    for (int i = 0; i < thickness; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Initialize average value
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;

        }
    }
    for (int i = image.width; i >image.width-thickness ; i--) {
        for (int j = 0; j < image.height; j++) {
            // Initialize average value
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;

        }
    }
    for (int j = image.height-1; j > image.height-thickness; j--) {
        for (int i = 0; i <image.width ; i++) {
            // Initialize average value
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;

        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}

QString MainWindow::showColorPickerDialog() {
    QColor color = QColorDialog::getColor(Qt::white, this, tr("Frame Color"));
    return color.name();
}

void MainWindow::on_pushButton_5_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    Image image1(stringname);
    int kernelX[3][3] = { {-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1} };
    int kernelY[3][3] = { {-1, -1, -1}, {0, 0, 0}, {1, 1, 1} };
    for (int i = 1; i < image.width-1; i++) {
        for (int j = 1; j < image.height-1; j++) {
            int gx = 0, gy = 0;
            for (int ky = 0; ky < 3; ky++) {
                for (int kx = 0; kx < 3; kx++) {
                    gx += kernelX[ky][kx] * (image1(i + kx - 1, j + ky - 1, 0) + image1(i + kx - 1, j + ky - 1, 1) + image1(i + kx - 1, j + ky - 1, 2));
                    gy += kernelY[ky][kx] * (image1(i + kx - 1, j + ky - 1, 0) + image1(i + kx - 1, j + ky - 1, 1) + image1(i + kx - 1, j + ky - 1, 2));
                }
                int magnitude = std::sqrt(gx * gx + gy * gy);
                if (magnitude > 200) {
                    for (int k = 0; k < 3; k++){
                        image(i, j, k) = 0;
                    }
                }
                else {
                    for (int k = 0; k < 3; k++) {
                        image(i, j, k) = 255;
                    }
                }
            }
        }}
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }}


void MainWindow::on_pushButton_4_clicked()
{
 if(!condition){
    ui->bright->parentWidget()->setVisible(true);
     ui->label_6->setVisible(true);
     ui->pushButton_8->setVisible(false);
     ui->pushButton_19->setVisible(false);
     ui->label_importedpic_3->setVisible(false);
     ui->label_importedpic->setVisible(true);
     condition3=false;
    image.loadNewImage(stringname);
    ui->horizontalSlider->setMinimum(1);
    ui->horizontalSlider->setMaximum(8);
    int width = image.width;
    int height = image.height;
    double number = ui->horizontalSlider->value();
    for(int o=0; o<number;o++){
        for(int i = 1; i < width - 1; ++i) {
            for(int j = 1; j < height - 1; ++j) {
                unsigned int total_red = 0, total_green = 0, total_blue = 0;
                for(int k = -1; k <= 1; ++k) {
                    for(int l = -1; l <= 1; ++l) {
                        total_red += image(i + k, j + l, 0);
                        total_green += image(i + k, j + l, 1);
                        total_blue += image(i + k, j + l, 2);
                    }
                }
                // Compute the average color
                total_red = round((float)total_red / 9.0);
                total_green = round((float)total_green / 9.0);
                total_blue = round((float)total_blue / 9.0);
                // Assign the averaged values back to the image
                for(int k = -1; k <= 1; ++k) {
                    for(int l = -1; l <= 1; ++l) {
                        image(i + k, j + l, 0) = total_red;
                        image(i + k, j + l, 1) = total_green;
                        image(i + k, j + l, 2) = total_blue;
                    }
                }
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }
}


 void MainWindow::on_pushButton_18_clicked()
 {
     if(!condition){
        MainWindow::visibilty();

    image.loadNewImage(stringname);
    double sunshine = 0.25;
    for (int y = 0; y < image.height; ++y) {
         for (int x = 0; x < image.width; ++x) {
             image(x, y, 0) = floor(image(x, y, 0) + sunshine * (255 - image(x, y, 0)));
             image(x, y, 1) = floor(image(x, y, 1) + sunshine * (255 - image(x, y, 1)) * 0.5);
             image(x, y, 2) = floor(image(x, y, 2) - sunshine * image(x, y, 2));
         }
     }
     image.saveImage("Filtered.png");
     QPixmap editedImage("Filtered.png");
     ui->label_importedpic_2->setScaledContents(true);
     ui->label_importedpic_2->setPixmap(editedImage);
    }
}

 void MainWindow::on_pushButton_10_clicked()
 {
     if(!condition){
        MainWindow::visibilty();

     image.loadNewImage(stringname);
     for(int i=0;i<image.width;i++)
     {
         for(int j=0;j<image.height;j++)
         {
             int avg = (image(i,j,1)+image(i,j,2))/2;
             avg = abs(255-avg);
             image(i,j,0)=255;
             image(i,j,1)=avg;
             image(i,j,2)=avg;
         }
     }
     image.saveImage("Filtered.png");
     QPixmap editedImage("Filtered.png");
     ui->label_importedpic_2->setScaledContents(true);
     ui->label_importedpic_2->setPixmap(editedImage);
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    for(int i =0 ; i<image.width;i++){
        for(int j=0;j<image.height;j++){
            image(i,j,1)=.7 *image(i,j,1) ;
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}
void MainWindow::on_pushButton_17_clicked()
{
    if(!condition){
    MainWindow::visibilty();

    image.loadNewImage(stringname);
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int average = 0;
            for (int k = 0; k < 3; k++)
            {
                average += image(i, j, k);
            }

            average /= 3;
            unsigned int red=0.393 * average + 0.769 * average + 0.189 * average;
            unsigned int green= 0.349 * average + 0.686 * average + 0.168 * average;
            unsigned int blue = 0.272 * average + 0.534 * average + 0.131 * average;
            image(i,j,0)=min(255,(int)red);
            image(i,j,1)=min(255,(int)green);
            image(i,j,2)=min(255,(int)blue);


        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}


void MainWindow::on_pushButton_7_clicked()
{
    if(!condition){
        if (ui->label_importedpic_2->pixmap().isNull()) {
        }
        else {
            image.saveImage("Filteredimage.png");
            image.saveImage("Rotated.png");
            stringname="Filteredimage.png";
            stringname2 = "Filteredimage.png";
            if(!condition2){
                image.loadNewImage("Filtered.png");

                QPixmap editedImage("Filteredimage.png");
                ui->label_importedpic->setScaledContents(true);
                ui->label_importedpic->setPixmap(editedImage);
            }
            else{
                QPixmap editedImage("Rotated.png");
                ui->label_importedpic->setScaledContents(true);
                ui->label_importedpic->setPixmap(editedImage);
                condition2=false;
            }
        }
    }
}


void MainWindow::on_pushButton_20_clicked()
{
    if(!condition){
        image.loadNewImage(stringname);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_19->setVisible(false);
        ui->label_importedpic_3->setVisible(false);
        ui->label_importedpic->setVisible(true);
        ui->bright->parentWidget()->setVisible(true);
        ui->label_6->setVisible(true);
        condition3=false;
        ui->horizontalSlider->setMinimum(0);
        ui->horizontalSlider->setMaximum(89);
        double degree = ui->horizontalSlider->value();
        degree = (22 * degree) / (7 * 180);
        int width = image.width;
        int height = image.height;
        double l = height * tan(degree); // Calculate the skewing length based on height
        int newWidth = width + int(l);    // New width after skewing
        int x_shift = (newWidth - width) / 2; // Calculate the shift for the new width to maintain centering
        Image image1(newWidth, height); // Create new image with adjusted width
        for (int i = 0; i < newWidth; i++) {
            for (int j = 0; j < height; j++) {
                for(int k = 0; k < 3; k++){
                    image1(i, j, k) = 255; // Initialize the new image with white pixels
                }
            }
        }
        for (int i = 0; i < newWidth; i++) {
            for (int j = 0; j < height; j++) {
                for(int k = 0; k < 3; k++){
                    int originalX = i - x_shift - int(l) / 2 + int(l) * j / height; // Calculate original x-coordinate
                    if (originalX >= 0 && originalX < width) { // Check if original x-coordinate is within bounds
                        image1(i, j, k) = image(originalX, j, k); // Copy pixel values from original image to temporary image
                    }
                }
            }
        }
        image1.saveImage("Filtered.png");
        QPixmap editedImage("Filtered.png");
        ui->label_importedpic_2->setScaledContents(true);
        ui->label_importedpic_2->setPixmap(editedImage);
    }
}

Image quickresize(Image image,int wPixel , int hPixel){
    double wScale,hScale;
    Image nwImg(wPixel,hPixel);
    wScale=(double)(image.width)/wPixel;
    hScale=(double)(image.height)/hPixel;
    for(int i = 0;i<wPixel;i++)
    {
        for(int j=0;j<hPixel;j++)
        {
            int w,h;
            w=round(wScale*i);
            h=round(hScale*j);
            for(int k=0;k<3;k++)
                nwImg(i,j,k)=image(w,h,k);
        }
    }
    return nwImg;;
}

void MainWindow::on_pushButton_11_clicked()
{
    if(!condition){
    image.loadNewImage(stringname);
    ui->bright->parentWidget()->setVisible(false);
    ui->label_6->setVisible(false);
    QString fileName2 = QFileDialog::getOpenFileName(this, "Select Image to merge with", "", "Image Files (*.png *.jpg);;All Files (*.*)");
    stringname3 = fileName2.toStdString();
    // Check if a file was selected
    if (!fileName2.isEmpty()) {
        QPixmap image(fileName2);
        if (image.isNull()) {
            // Handle error (e.g., invalid image format)
            QMessageBox::warning(this, "Error", "Failed to load image!");
            return;
        }
        ui->label_importedpic_3->setScaledContents(true);
        ui->label_importedpic_3->setPixmap(image);
        ui->label_importedpic_3->setVisible(true);
        ui->label_importedpic->setVisible(false);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_19->setVisible(true);
    }
    else{
        QMessageBox::warning(this, "Error", "Failed to load image!");
        stringname=stringname2;
        return;
    }

    Image image2;
    image2.loadNewImage(stringname3);
    image2 = quickresize(image2, image.width,image.height);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = (image(i, j, k))/2;
                image2(i, j, k) = (image2(i, j, k))/2;
                image(i, j, k) = image(i, j, k) + image2(i, j, k);
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->label_importedpic_3->setVisible(false);
    ui->label_importedpic->setVisible(true);
    condition3=false;
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->label_importedpic_3->setVisible(true);
    ui->label_importedpic->setVisible(false);
    condition3=false;
}


void MainWindow::on_pushButton_16_clicked()
{
    if(!condition){
    image.loadNewImage(stringname);
    MainWindow::visibilty();
    // Define a random number generator engine
    mt19937 rng(random_device{}());
    // Define a normal distribution with mean 0 and standard deviation 20 (for example)
    normal_distribution<double> dist(0.0, 20.0); // Adjust the standard deviation as needed
    // Loop through each pixel in the image
    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            // Generate a random number from the Gaussian distribution
            double noiseRed = dist(rng);
            double noiseGreen = dist(rng);
            double noiseBlue = dist(rng);

            // Add Gaussian noise to the pixel values
            int newRed = min(255, max(0, static_cast<int>(image(j, i, 0) + noiseRed)));
            int newGreen = min(255, max(0, static_cast<int>(image(j, i, 1) + noiseGreen)));
            int newBlue = min(255, max(0, static_cast<int>(image(j, i, 2) + noiseBlue)));

            // Assign the new pixel values to the image
            image(j, i, 0) = newRed;
            image(j, i, 1) = newGreen;
            image(j, i, 2) = newBlue;
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
    }
}



void MainWindow::on_pushButton_14_clicked()
{
    if(!condition){
    image.loadNewImage(stringname);
    MainWindow::visibilty();
    for(int i=0;i<image.width;i++)
    {
        for(int j=0;j<image.height;j++)
        {
            for(int k=0;k<3;k++)
            {
                image(i,j,k)/=30;
                image(i,j,k)*=30;
            }
        }
    }
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}

}

void MainWindow::visibilty()
{
    ui->pushButton_8->setVisible(false);
    ui->pushButton_19->setVisible(false);
    ui->label_importedpic_3->setVisible(false);
    ui->label_importedpic->setVisible(true);
    ui->bright->parentWidget()->setVisible(false);
    ui->label_6->setVisible(false);
    condition3=false;
}

void MainWindow::on_pushButton_15_clicked()
{
    if(!condition){
    image.loadNewImage(stringname);
    MainWindow::visibilty();
    Image image1(image.width, image.height);
    for (int x = 0; x < image.width; x++) {
        for (int y = 0; y < image.height; y++) {
            int index = (y * image.width + x) * 3;
            int dist = sqrt(pow(x - (image.width/2), 2) + pow(y - (image.height/2), 2));
            // Increase the contrast based on the distance
            int contrast = 1 + dist / 80;
            // set contrast value to a reasonable range
            contrast = min(max(contrast, 1), 5);
            for (int c = 0; c < 3; c++) {
                image1.imageData[index + c] = image.imageData[index + c] * contrast;
            }
        }
    }
    image = image1;
    image.saveImage("Filtered.png");
    QPixmap editedImage("Filtered.png");
    ui->label_importedpic_2->setScaledContents(true);
    ui->label_importedpic_2->setPixmap(editedImage);
}
}


