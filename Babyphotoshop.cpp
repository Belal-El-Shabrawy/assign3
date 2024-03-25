#include <iostream>
#include "Image_Class.h"
#include<limits>
using namespace std;

void filter1(Image &image){
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
}
void filter2(Image &image){
    filter1(image);
    for(int i = 0;i<image.width;i++)
    {
        for(int j = 0;j<image.height;j++)
        {
            if(image(i,j,0)<= 127)
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
}
void filter3(Image &image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Set all channels to the average value
            image(i, j, 0) = 255-image(i, j, 0);
            image(i, j, 1) = 255-image(i, j, 1);
            image(i, j, 2) = 255-image(i, j, 2);
        }
    }

}
void filter4(Image &image){
    string image_name;
    string image_name2;
    cout << "Please Enter Name of the second Image to merge with the first image: ";
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
}
void filter5(Image &image){
    cout<<"A) Flip vertically"<<endl;
    cout<<"B) Flip horizontally"<<endl;
    string choice;
    while(true)
    {
        cin>>choice;
        choice[0]=toupper(choice[0]);
        if(choice == "A" || choice == "B")
            break;
        else
            cout<<"Please enter valid input"<<endl;
    }
    if(choice == "A")
    {
        int temporary;
        for(int i = 0;i<image.width;i++)
        {
            for(int j = 0;j<image.height/2;j++)
            {
                for(int k = 0; k < 3; k++)
                {
                    temporary=image(i,j,k);
                    image(i,j,k) = image(i,image.height-j,k);
                    image(i,image.height-j,k)=temporary;
                }
            }
        }
    }
    else if(choice == "B")
    {
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
    }
}
void filter6(Image &image) {
    int m = image.width; // Number of columns in the original image (width)
    int n = image.height; // Number of rows in the original image (height)


    // Create a new image to store the rotated result
    char choice;
    cout << "A) rotate 90 degrees\n";
    cout << "B) rotate 180 degrees\n";
    cout << "C) rotate 270 degrees\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while (choice != 'A' && choice != 'B' && choice != 'C') {
        cout << "Enter a valid choice ( A , B,C )\n";
        cin >> choice;
        choice = toupper(choice);
    }
    if (choice == 'A') {
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



    } else if (choice == 'B') {
        Image image2(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //            Assign the pixel at (i, j) of the original image to the rotated position in the result image
                //          The formula for the rotated position is (m - i - 1, n - j - 1)
                for (int k = 0; k < 3; k++) {

                    image2(m - i - 1, n - j - 1, k) = image(i, j, k);
                }
            }
        }

        Image temp;
        image=image2;
        image2=temp;
    }
    else if(choice=='C'){
    Image image2(n, m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Assign the pixel at (i, j) of the original image to the rotated position in the result image
            // The formula for the rotated position is (j, m - i - 1)
            for(int k=0;k<3;k++){

                image2(j, m - i - 1, k) = image(i, j, k);
                }
            }
        }
        Image temp;
        image=image2;
        image2=temp;

    }
}
void filter7(Image &image){
    char choice;
    cout << "A) Lighten Image\n";
    cout << "B) Darken Image\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while(choice != 'A' && choice != 'B'){
        cout << "Enter a valid choice ( A , B )\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(choice == 'A'){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int newValue = static_cast<int>(image.getPixel(i, j, k) * 1.5);
                    newValue = std::max(0, std::min(255, newValue));
                    image.setPixel(i, j, k, newValue);
                }
            }
        }
    }
    else if (choice == 'B'){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    int newValue = static_cast<int>(image.getPixel(i, j, k) * 0.5);
                    newValue = std::max(0, std::min(255, newValue));
                    image.setPixel(i, j, k, newValue);
                }
            }
        }
    }
}
Image filter8(Image &image){



}
void filter9(Image &image){
        for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < 30; ++j) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < image.height; ++j) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
    for (int i = image.width; i >image.width-30 ; i--) {
        for (int j = 0; j < image.height; j++) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
    for (int j = image.height-1; j > image.height-30; j--) {
        for (int i = 0; i <image.width ; i++) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }


}
void filter10(Image &image ,string &image_name){
    Image image1(image_name);
    int kernelX[3][3] = { {-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1} };
    int kernelY[3][3] = { {-1, -1, -1}, {0, 0, 0}, {1, 1, 1} };
    for (int i = 1; i < image.width - 1; i++) {
        for (int j = 1; j < image.height - 1; j++) {
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
}
void filter11(){

}

void filter12(Image &image,double sigma) {

    int width = image.width;
    int height = image.height;

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
void filter13(Image &image) {
    double sunshine = 0.25;
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            image(x, y, 0) = floor(image(x, y, 0) + sunshine * (255 - image(x, y, 0)));
            image(x, y, 1) = floor(image(x, y, 1) + sunshine * (255 - image(x, y, 1)) * 0.5);
            image(x, y, 2) = floor(image(x, y, 2) - sunshine * image(x, y, 2));
        }
    }
}
void filter15(Image &image){
    const int lineSpacing = 5; // Spacing between horizontal lines
    const int lineThickness = 2; // Thickness of the lines
    for (int i = 0; i < image.height; i += lineSpacing) {
        // Draw horizontal lines
        for (int k = 0; k < lineThickness; k++) {
            if (i + k < image.height) {
                for (int j = 0; j < image.width; j++) {
                    // Set pixel value to white
                    image(j, i + k, 0) = 0;
                    image(j, i + k, 1) = 0;

                    image(j, i + k, 2) = 0;
                }
            }
        }
    }
}
void filter16(Image &image){
    for(int i =0 ; i<image.width;i++){
        for(int j=0;j<image.height;j++){
            image(i,j,1)=0;
        }
    }
}

int main(){
    char choice;
    while (true) {
        cout << "\n|**Welcome Baby Photoshop app**|\n";
        cout << "A) Grey scale filter\n";
        cout << "B) Black and White\n";
        cout << "C) Invert image\n;";
        cout << "D) Merge Images\n";
        cout << "E) Flip Image\n";
        cout << "F) Rotate image\n";
        cout << "G) Darken and Lighten Images\n";
        cout << "H) Crop image\n";
        cout <<"I) Add frame\n";
        cout << "J) Detect Image edges\n";
        cout << "K) Resizing Image\n";
        cout << "L) Blur image\n";
        cout << "M) Sunlight Effect\n";
        cout << "N)oil Painting effect\n";
        cout << "O)Tv effect\n";
        cout << "P) Purple effect\n";
        cout << "Q) infrared effect\n";
        cout << "R) Skewing Filter\n";
        cout << "Z) End\n";
        cout << "Enter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        while(choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D' && choice != 'E' && choice != 'F' && choice != 'G' && choice != 'H'&&choice!='I'&&choice!='J'&&choice!='K'&&choice!='L'&&choice!='M'&&choice!='N'&&choice!='O'&&choice!='P'&&choice!='Q'&&choice!='R'&&choice!='Z'){
            cout << "Enter a valid choice \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cin>>image_name;
        Image image;
    while(true){
        try {
        if (image.loadNewImage(image_name)) {
            Image image(image_name);
            break;

        }

    } catch( invalid_argument) {
        cout << "Please enter a valid photo \n" << endl;
        cin>>image_name;


        }
    }
        switch (choice) {
            case 'A':
                filter1(image);
                break;
            case 'B':
                filter2(image);
                break;
            case 'C':
                filter3(image);
                break;
            case 'D':
                filter4(image);
                break;
            case 'E':
                filter5(image);
                break;
            case 'F':
                filter6(image);
                break;
            case 'G':
                filter7(image);
                break;
            case 'H':
                filter8(image);
                break;
            case 'I':
                filter9(image);
                break;
            case 'J':
                filter10(image, image_name);
                break;
            case 'L':
                filter12(image,2);

                break;
            case 'M':
                break;
            case 'N':
                filter13(image);
                break;
            case 'O':
                filter15(image);
                break;
            case 'P':
                filter16(image);
                break;


        }

    cout << "Please enter the image name to store the new image: ";
    cin >> image_name;

    while(true){
        try {
            if (image.saveImage(image_name)) {
                image.saveImage(image_name);

                break;

            }

        } catch( invalid_argument) {
            cout << "Please enter a valid extension \n" << endl;
            cin>>image_name;


            }
        }
    }
}
