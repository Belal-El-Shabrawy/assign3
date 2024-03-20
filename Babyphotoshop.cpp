#include <iostream>
#include "Image_Class.h"

using namespace std;

Image filter1(Image image){
    string image_name;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned  int avg = 0; // Initialize average value

            for (int k = 0; k < 3; k++) {
                avg += image(i, j, k); // Accumulate pixel values
            }

            avg /= 3;
            for (int k = 0; k < 3; ++k){
                    image(i, j, k) = avg;
        }
        }
    }
    return image;
}
Image filter2(Image image){

}
Image filter3(Image image){

}
Image filter4(Image image){

}
int main(){
    char choice;
    while (true) {
        cout << "\n|**Welcome Baby Photoshop app**|\n";
        cout << "A) Grey scale filter\n";
        cout << "B) Merge Images\n";
        cout << "C) Darken and Lighten Images\n";
        cout << "D) Detect Image edges\n";
        cout << "E) End\n";
        cout << "Enter your choice:";
        cin >> choice;
        choice = toupper(choice);
        while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E'){
            cout << "Enter a valid choice ( A , B , C , D , E )\n";
            cin >> choice;
            choice = toupper(choice);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 'E'){
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
            case 'B': {
                filter2(image);
            }
            case 'C': {
                filter3(image);
            }
            case 'D': {
                filter4(image);
            }
            default: {
                cout << "Please enter a valid choice ( A , B , C , D , E )\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        }
        cout << "Pls enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga:";
        cin >> image_name;
        image.saveImage(image_name);
    }

}
