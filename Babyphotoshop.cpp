#include <iostream>
#include "Image_Class.h"

using namespace std;

Image filter1(Image image){
    string image_name;
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
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga:";
    cin >> image_name;
    image.saveImage(image_name);
}
Image filter2(Image image){

}
Image filter3(Image image){

}
Image filter4(Image image){
    string image_name;
    string image_name2;
    cout << "Please Enter Name of the second Image to merge with the first image:";
    cin >> image_name2;
    Image image2(image_name2);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = (image(i, j, k))/2;
                image2(i, j, k) = (image2(i, j, k))/2;
                image(i, j, k) = image(i, j, k) + image2(i, j, k);
            }
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga:";
    cin >> image_name;
    image.saveImage(image_name);
}
Image filter5(Image image){

}
Image filter6(Image image){

}
Image filter7(Image image){
    char choice;
    cout << "A) Darken Image\n";
    cout << "B) Lighten Image\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while(choice != 'A' && choice != 'B'){
        cout << "Enter a valid choice ( A , B , C , D , E )\n";
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(choice == 'A'){
    string image_name;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image(i, j, k) = (image(i, j, k))/2;}
        }
    }
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga:";
    cin >> image_name;
    image.saveImage(image_name);}
    else if (choice == 'B'){
        string image_name;
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = (image(i, j, k))*2;}
            }
        }
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga:";
        cin >> image_name;
        image.saveImage(image_name);}
    }
Image filter8(Image image){

}
Image filter9(Image image){

}
Image filter10(Image image){

}
int main(){
    char choice;
    while (true) {
        cout << "\n|**Welcome Baby Photoshop app**|\n";
        cout << "A) Grey scale filter\n";
        cout << "D) Merge Images\n";
        cout << "G) Darken and Lighten Images\n";
        cout << "H) Detect Image edges\n";
        cout << "Z) End\n";
        cout << "Enter your choice:";
        cin >> choice;
        choice = toupper(choice);
        while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E'){
            cout << "Enter a valid choice ( A , B , C , D , E)\n";
            cin >> choice;
            choice = toupper(choice);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 'Z'){
            cout << "\nGood Bye\n";
            return 0;
        }
        string image_name;
        cout << "Please Enter Name of the Image which you want to apply a filter on:";
        cin >> image_name;
        Image image(image_name);
        switch (choice) {
            case 'A':{
                image = filter1(image);
            }
            case 'D': {
                filter4(image);
            }
            case 'G': {
                filter7(image);
            }
            case 'J': {
                filter10(image);
            }
            default: {
                cout << "Please enter a valid choice ( A , B , C , D , E )\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        }
    }

}
