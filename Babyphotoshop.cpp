#include <bits/stdc++.h>
#include "Image_Class.h"
#include <iostream>
#include<limits>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
#include <regex>



using namespace std;
int digit_checker(string value) {//to check if the input is digit
    while (true) {

        for (char i : value) {
            if (!isdigit(i)) {
                cout << "Enter number only ";
                cin >> value;
                return digit_checker(value);
            }


        }
        return stoi(value);


    }
}
void grayscale(Image &image){
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
void blackAndWhite(Image &image){
    grayscale(image);
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


void invert(Image &image){
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Set all channels to the average value
            image(i, j, 0) = 255-image(i, j, 0);
            image(i, j, 1) = 255-image(i, j, 1);
            image(i, j, 2) = 255-image(i, j, 2);
        }
    }

}


void merge(Image &image){
    string image_name;
    string image_name2;
    cout << "Please Enter Name of the second Image to merge with the first image: ";
    cin >> image_name2;
    Image image2;
    while(true) {
        try {
            if (image2.loadNewImage(image_name2)) {
                image2.loadNewImage(image_name2);
                break;
            }

        } catch (invalid_argument) {
            cout << "Please enter a valid extension \n" << endl;
            cin >> image_name2;
        }
    }
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
void flip(Image &image){
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
                    image(i,j,k) = image(i,image.height-j-1,k);
                    image(i,image.height-j-1,k)=temporary;
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
                    image(i,j,k) = image(image.width-i-1,j,k);
                    image(image.width-i-1,j,k)=temporary;
                }
            }
        }
    }
}
void rotate(Image &image) {
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
        image = image2;
        image2 = temp;

    }
}
void darkenAndLighten(Image &image){
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
void crop(Image &image)
{
    int x,y,w,h;
    cout<<"Please enter upper left corner pixel coordinate(first pixel is zero), width and height respectively: ";
    cin>>x>>y>>w>>h;
    while((x<0||x>image.width)||(y<0||y>image.height)||(w<=0||w>(image.width-w))||(h<=0||h>(image.height-h)))
    {
        cout<<"Please enter valid number"<<endl;
        cout<<"Please enter upper left corner pixel coordinate(first pixel is zero), width and height respectively: ";
        cin>>x>>y>>w>>h;
    }
    Image nwImg = image;
    nwImg=Image(w,h);
    for(int i=0,ii=x;i<w;i++,ii++)
    {
        for(int j=0,jj=y;j<h;j++,jj++)
        {
            for(int k=0;k<3;k++)
            {
                nwImg(i,j,k)=image(ii,jj,k);
            }
        }
    }
    image=nwImg;
}


void frame(Image &image){
    char choice;

    cout << "A) Default Frame\n";
    cout << "B) Fancy  frame\n";
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
    if(choice=='A'){
    int thickness=20;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < thickness; ++j) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
        for (int i = 0; i < thickness; ++i) {
        for (int j = 0; j < image.height; ++j) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
    for (int i = image.width; i >image.width-thickness ; i--) {
        for (int j = 0; j < image.height; j++) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }
    for (int j = image.height-1; j > image.height-thickness; j--) {
        for (int i = 0; i <image.width ; i++) {
             // Initialize average value
            image(i, j, 0) = 2;
            image(i, j, 1) = 2;
            image(i, j, 2) = 232;

        }
    }

    }
    else{
    int red;
    int green;
    int blue;
    string test;

    cout << "A) Default color\n";
    cout << "B) Custom color\n";
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
    if(choice=='A'){
        red=2;
        blue=2;
        green=232;
    }
    else{
        cout<<"Enter red value ";
        cin>>test;
        red=digit_checker(test);
        cout<<"Enter green value ";
        cin>>test;
        green=digit_checker(test);
        cout<<"Enter blue value ";
        cin>>test;
        blue=digit_checker(test);
        while(true){
        bool condition1=false;
        bool condition2=false;
        bool condition3=false;

            if(red>255 || red<0){
                cout<<"Enter red only from 0 to 255 ";
                cin>>red;
            }
            else{
                condition1=true;
            }

            if(green>255 || green<0){
                cout<<"Enter green only from 0 to 255 ";
                cin>>green;
            }
            else{
                condition2=true;
            }

            if(blue>255 || blue<0){
                cout<<"Enter blue only from 0 to 255 ";
                cin>>blue;
            }
            else{
                condition3=true;
            }
            if(!condition1||!condition2||!condition3){
                continue;
            }
            else{
                break;
            }



        }
    }
         int thickness=20;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < thickness; ++j) {
             // Initialize average value
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;

        }
    }
    for (int i = thickness+10; i < image.width-(thickness+10); ++i) {
        for (int j = (thickness+5); j <(thickness+5)+5 ; ++j) {
             // Initialize average value
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;

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
    for (int i = thickness+10; i < thickness+15; ++i) {
        for (int j = thickness+10; j <image.height-(thickness+10) ; ++j) {
             // Initialize average value
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;

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
    for (int i = thickness+10; i < image.width-(thickness+10); ++i) {
        for (int j = image.height-(thickness+10); j >(image.height-(thickness+10))-5 ; j--) {
             // Initialize average value
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;

        }
    }
    for (int i = image.width-thickness-11; i > (image.width-thickness-10)-5; i--) {
        for (int j = thickness+10; j <image.height-(thickness+10) ; ++j) {
             // Initialize average value
            image(i, j, 0) = 255;
            image(i, j, 1) = 255;
            image(i, j, 2) = 255;

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
    }

}


void imageEdges(Image &image ,string &image_name){
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
Image resize(Image image){
    double wScale,hScale;
    int wPixel=image.width,hPixel=image.height;
    string choice;
    cout<<"Do you want to scale using:\nA) Pixels\nB) Percentage\n";
    cin>>choice;
    choice[0]=toupper(choice[0]);
    while(choice!="A"&&choice!="B")
    {
        cout<<"Please enter valid choice"<<endl;
        cin>>choice;
        choice[0]=toupper(choice[0]);
    }
    if(choice=="A")
    {
        cout<<"Enter width, height respectively: ";
        cin>>wPixel>>hPixel;
        wScale=image.width/wPixel;
        hScale=image.height/hPixel;
    }
    else if(choice=="B")
    {
        cout<<"Enter percentage: ";
        int percentage;
        cin>>percentage;
        wScale=percentage/100;
        hScale=percentage/100;
        wPixel=round(image.width*wScale);
        hPixel=round(image.height*hScale);
    }
    Image nwImg=Image(wPixel,hPixel);
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
    return nwImg;
}

void blur(Image &image,double sigma) {

    int width = image.width;
    int height = image.height;
    string rr;
    int number;
    cout<<"Enter the blur radius ";
    cin>>rr;
    number=digit_checker(rr);
    while(number>8 || number<1){
        cout<<"The number must be from 1 to 8 "<<endl;
        cin>>number;
    }








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


}
void sunlight(Image &image) {
    double sunshine = 0.25;
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            image(x, y, 0) = floor(image(x, y, 0) + sunshine * (255 - image(x, y, 0)));
            image(x, y, 1) = floor(image(x, y, 1) + sunshine * (255 - image(x, y, 1)) * 0.5);
            image(x, y, 2) = floor(image(x, y, 2) - sunshine * image(x, y, 2));
        }
    }
}

void oilPainting(Image &image)
{
    for(int i=0;i<image.width;i+=5)
    {
        for(int j=0;j<image.height;j+=5)
        {
            
        }
    }
}

void infrared(Image &image)
{
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
}

void television(Image &image){
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

}
void purple(Image &image){
    for(int i =0 ; i<image.width;i++){
        for(int j=0;j<image.height;j++){
            image(i,j,1)=.7 *image(i,j,1) ;
        }
    }
}
void glitch(Image &image){
    const int lineSpacing = 5; // Spacing between horizontal lines
    const int lineThickness = 2; // Thickness of the lines

// Loop to generate horizontal lines
for (int i = 0; i < image.height; i += lineSpacing) {
    // Draw horizontal lines
    for (int k = 0; k < lineThickness; k++) {
        if (i + k < image.height) {
            for (int j = 0; j < image.width; j++) {
                // Distort pixel values by shifting horizontally
                int shift = rand() % 20 - 9; // Random shift between -3 and 3
                int newPos = j + shift;
                if (newPos >= 0 && newPos < image.width) {
                    image(j, i + k, 0) = image(newPos, i + k, 0); // Red channel
                    image(j, i + k, 1) = image(newPos, i + k, 1); // Green channel
                    image(j, i + k, 2) = image(newPos, i + k, 2); // Blue channel
                }
            }
        }
    }
}

}
Image skew(Image image){
    double degree;
    cout << "Enter a degree: ";
    cin >> degree;
    degree = (22 * degree) / (7 * 180);
    while(true){
        bool valid = true;
        if (degree == 90 || degree == 270){
            valid = false;
        }
        if(valid) break;
        cout << "Invalid input\n";
        cout << "Enter an angle: ";
        cin >> degree;
    }
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
    return image1;
}

void filter20(Image &image)
{
    
}

int main(){
    string choice;
    string image_name;
    int x;
    Image image;
    cout << "Please Enter Name of the Image which you want to apply a filter on with (.png, .jpeg, .jpg, .bmp):";
    cin>>image_name;
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
    }    while (true) {
        cout << "\n|**Welcome Baby Photoshop app**|\n";
        cout << "Filter 1: Grayscale Conversion\n";
        cout << "Filter 2: Black and White\n";
        cout << "Filter 3: Invert Image\n";
        cout << "Filter 4: Merge Images\n";
        cout << "Filter 5: Flip Image\n";
        cout << "Filter 6: Rotate image\n";
        cout << "Filter 7: Darken and Lighten Image\n";
        cout << "Filter 8: Crop Image\n";
        cout << "Filter 9: Add frame\n";
        cout << "Filter 10: Detect Image edges\n";
        cout << "Filter 11: Resizing Image\n";
        cout << "Filter 12: Blur Image\n";
        cout << "Filter 13: Sunlight Effect\n";
        cout << "Filter 14: Oil Painting Effect\n";
        cout << "Filter 15: Television Effect\n";
        cout << "Filter 16: Purple Effect\n";
        cout << "Filter 17: Infrared Effect\n";
        cout << "Filter 18: Skewing Filter\n";
        cout << "Filter 19: Glitch effect\n";
        cout << "Filter 20: \n";

        cout << "21: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while(true){
            if(regex_match(choice,regex("[\\d]+")))
            {
                x=stoi(choice);
                if(x>=1&&x<=21)
                    break;
            }
            cout << "Enter a valid choice \n";
            cin >> choice;
        }
        if (x == 21){
            break;
        }

        switch (x) {
            case 1:
                grayscale(image);
                break;
            case 2:
                blackAndWhite(image);
                break;
            case 3:
                invert(image);
                break;
            case 4:
                merge(image);
                break;
            case 5:
                flip(image);
                break;
            case 6:
                rotate(image);
                break;
            case 7:
                darkenAndLighten(image);
                break;
            case 8:
                crop(image);
                break;
            case 9:
                frame(image);
                break;
            case 10:
                imageEdges(image, image_name);
                break;
            case 11:
                image=resize(image);
                break;
            case 12:
                blur(image,2);
                break;
            case 13:
                sunlight(image);
                break;
            case 14:
                oilPainting(image);
                break;
            case 15:
                television(image);
                break;
            case 16:
                purple(image);
                break;
            case 17:
                infrared(image);
                break;
            case 18:
                image = skew(image);
                break;
            case 19:
                glitch(image);
                break;
            case 20:
                filter20(image);
                break;
        }
    }
    cout << "Please enter the image name to store the new image with (.png, .jpeg, .jpg, .bmp): ";
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
