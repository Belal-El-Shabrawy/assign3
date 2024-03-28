#include <iostream>
#include <limits>
#include <string>
#include "Image_Class.h"
using namespace std;

void filter11(Image &image)
{
    
}

void filter13(Image &image) {
    double sunshine = 0.25;
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            // Increase warmth towards yellow based on sunshine factor
            image(x, y, 0) = floor(image(x, y, 0) + sunshine * (255 - image(x, y, 0)));
            image(x, y, 1) = floor(image(x, y, 1) + sunshine * (255 - image(x, y, 1)) * 0.5);
            image(x, y, 2) = floor(image(x, y, 2) - sunshine * image(x, y, 2));
        }
    }
}
void tvEffect(Image &image) {
    int blockSize = 50;
    // Calculate new image dimensions based on block size
    int newWidth = (image.width + blockSize - 1) / blockSize;
    int newHeight = (image.height + blockSize - 1) / blockSize;

    // Create a temporary image to store downscaled pixel averages
    Image tempImage(newWidth, newHeight);

    // Downscale image and calculate average color for each block
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            for (int dy = 0; dy < blockSize; ++dy) {
                for (int dx = 0; dx < blockSize; ++dx) {
                    int originalX = x * blockSize + dx;
                    int originalY = y * blockSize + dy;

                    // Check for valid coordinates within original image boundaries
                    if (originalX < image.width && originalY < image.height) {
                        unsigned char red = image.getPixel(originalX, originalY, 0);
                        unsigned char green = image.getPixel(originalX, originalY, 1);
                        unsigned char blue = image.getPixel(originalX, originalY, 2);

                        sumRed += red;
                        sumGreen += green;
                        sumBlue += blue;
                    }
                }
            }

            // Calculate average color for the block
            int avgRed = sumRed / (blockSize * blockSize);
            int avgGreen = sumGreen / (blockSize * blockSize);
            int avgBlue = sumBlue / (blockSize * blockSize);

            // Set average color as the pixel value in the temporary image
            tempImage.setPixel(x, y, 0, avgRed);
            tempImage.setPixel(x, y, 1, avgGreen);
            tempImage.setPixel(x, y, 2, avgBlue);
        }
    }

    // Resize the temporary image back to original dimensions using nearest neighbor interpolation (optional)
    // ... (implementation for resizing using nearest neighbor interpolation)

    // Optionally, copy the downscaled and averaged image data back to the original image
    image = tempImage; // Replace with your resizing function if desired
}
int main() {
    char choice;
    bool endProgram = false;
    while (!endProgram) {
        cout << "\n|**Welcome Baby Photoshop app**|\n";
        cout << "A) purple\n";
        cout << "B) Black and White\n";
        cout << "D) Merge Images\n";
        cout << "E) Flip Image\n";
        cout << "G) Darken and Lighten Images\n";
        cout << "H) Detect Image edges\n";
        cout << "Z) End\n";
        cout << "Enter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        while (choice != 'A' && choice != 'B' && choice != 'D' && choice != 'E' && choice != 'G' && choice != 'H' && choice != 'Z') {
            cout << "Enter a valid choice ( A , B, D, E , G , H , Z)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            choice = toupper(choice);
        }
        if (choice == 'Z') {
            cout << "\nGood Bye\n";
            // Set endProgram to true to break out of the loop
            endProgram = true;
        } else {
            string image_name;
            cout << "Please Enter Name of the Image which you want to apply a filter on:";
            cin.ignore();
            getline(cin, image_name);
            Image image(image_name);
            switch (choice) {
                case 'A':
                    filter13(image);
                    // Call filter function
                    break;
                case 'B':
                    tvEffect(image);
                    // Call filter function
                    break;
                case 'D':
                    // Call filter function
                    filter11(image);
                    break;
                case 'E':
                    // Call filter function
                    break;
                case 'G':
                    // Call filter function
                    break;
                case 'H':{
                    Image image1(image_name);
                    break;}
                default:
                    cout << "Please enter a valid choice ( A , B , D , G , H , Z )\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
            }
            cout << "Please enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";
            getline(cin,image_name);
            image.saveImage(image_name);
        }
    }
    return 0;
}