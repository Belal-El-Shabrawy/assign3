// File:  CS112_A3_Part3_S6_20230096_20230300_20230274.cpp.
// Purpose: This Program can be used to apply 20 Different filters for any image
// Author: Belal Alaa El-Shabrawy ID: 20230096 Section:S6
//         Amr Salah ID: 20230274 Section:S6
//         Mark Amir ID: 20230300 Section:S6
// Belal Alaa : Did (GrayScale, Merge, Lighten and Darken, Edge Detect, Sunshine, Skew, BrokenTvFilter)
// Amr Salah : Did (Black and White, Flip, Crop, Resize, Oil, Infrared)
// Mark Amin : Did (Invert colors, Rotate, Frame, Blur, TvEffect, PurpleEffect, GlitchEffect)
// Emails: Belal ALaa, madbusiness05@gmail.com
//         Amr Salah,  20230274@stud.fci-cu.edu.eg
//         Mark Amir,  markamir415@gamil.com
// Link to GitHub Repo: https://github.com/Belal-El-Shabrawy/assign3.git

#include <bits/stdc++.h>
#include "Image_Class.h"
#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <random>
#include <regex>
#include <cmath>
using namespace std;
// Function to check if the input string contains only digits
int digit_checker(string value)
{
    // Loop until a valid number is entered
    while (true)
    {
        // Iterate through each character in the string
        for (char i : value)
        {
            // Check if the character is not a digit
            if (!isdigit(i))
            {
                cout << "Enter number only ";
                cin >> value;
                // Recursively call digit_checker with the new input
                return digit_checker(value);
            }
        }
        // Convert the string to an integer and return
        return stoi(value);
    }
}

// Function to quickly resize an image
Image quickresize(Image image, int wPixel, int hPixel)
{
    double wScale, hScale;
    // Create a new image with the specified width and height
    Image nwImg(wPixel, hPixel);
    wScale = (double)(image.width) / wPixel;
    hScale = (double)(image.height) / hPixel;
    // Loop through each pixel in the new image
    for (int i = 0; i < wPixel; i++)
    {
        for (int j = 0; j < hPixel; j++)
        {
            int w, h;
            // Calculate the corresponding pixel in the original image
            w = round(wScale * i);
            h = round(hScale * j);
            // Copy the pixel values from the original image to the new image
            for (int k = 0; k < 3; k++)
                nwImg(i, j, k) = image(w, h, k);
        }
    }
    // Return the new image
    return nwImg;
}

// Function to convert the image to grayscale
void grayscale(Image &image)
{
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int average = 0;
            // Calculate the average value of the RGB channels
            for (int k = 0; k < 3; k++)
            {
                average += image(i, j, k);
            }
            average /= 3;
            // Set all RGB channels to the average value
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) = average;
            }
        }
    }
}

// Function to convert the image to black and white
void blackAndWhite(Image &image)
{
    // Convert the image to grayscale
    grayscale(image);
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Check if the grayscale value is less than or equal to 127
            if (image(i, j, 0) <= 127)
            {
                // Set all RGB channels to 0 (black)
                for (int k = 0; k < 3; k++)
                {
                    image(i, j, k) = 0;
                }
            }
            else
            {
                // Set all RGB channels to 255 (white)
                for (int k = 0; k < 3; k++)
                {
                    image(i, j, k) = 255;
                }
            }
        }
    }
}

// Function to invert the colors of the image
void invert(Image &image)
{
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Invert each RGB channel By removing the value of pixel from 255
            image(i, j, 0) = 255 - image(i, j, 0);
            image(i, j, 1) = 255 - image(i, j, 1);
            image(i, j, 2) = 255 - image(i, j, 2);
        }
    }
}

// Function to merge two images by averaging their pixel values
void merge(Image &image)
{
    string image_name2;
    cout << "Please Enter Name of the second Image to merge with the first image: ";
    cin >> image_name2;
    Image image2;
    // Load the second image
    while (true)
    {
        try
        {
            if (image2.loadNewImage(image_name2))
            {
                image2.loadNewImage(image_name2);
                break;
            }
        }
        catch (invalid_argument)
        {
            cout << "Please enter a valid extension" << endl;
            cin >> image_name2;
        }
    }
    // Resize the second image to match the dimensions of the first image
    image2 = quickresize(image2, image.width, image.height);
    // Loop through each pixel in the images and average their values
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // Average the pixel values and assign to the first image
                image(i, j, k) = (image(i, j, k)) / 2 + (image2(i, j, k)) / 2;
            }
        }
    }
}
void flip(Image &image)
{
    cout << "A) Flip vertically" << endl;
    cout << "B) Flip horizontally" << endl;
    string choice;
    while (true)
    {
        cin >> choice;
        choice[0] = toupper(choice[0]);
        if (choice == "A" || choice == "B")
            break;
        else
            cout << "Please enter valid input" << endl;
    }
    if (choice == "A")
    {
        int temporary;
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height / 2; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temporary = image(i, j, k);
                    image(i, j, k) = image(i, image.height - j - 1, k);
                    image(i, image.height - j - 1, k) = temporary;
                }
            }
        }
    }
    else if (choice == "B")
    {
        int temporary;
        for (int i = 0; i < image.width / 2; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    temporary = image(i, j, k);
                    image(i, j, k) = image(image.width - i - 1, j, k);
                    image(image.width - i - 1, j, k) = temporary;
                }
            }
        }
    }
}
void rotate(Image &image)
{
    int m = image.width;  // Number of columns in the original image (width)
    int n = image.height; // Number of rows in the original image (height)

    // Create a new image to store the rotated result
    char choice;
    cout << "A) rotate 90 degrees\n";
    cout << "B) rotate 180 degrees\n";
    cout << "C) rotate 270 degrees\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while (choice != 'A' && choice != 'B' && choice != 'C')
    {
        cout << "Enter a valid choice ( A , B,C )\n";
        cin >> choice;
        choice = toupper(choice);
    }
    if (choice == 'A')
    {
        Image image2(n, m); // Width and height are swapped for the rotated image
        // Iterate through each pixel of the original image
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Assign the pixel at (i, j) of the original image to the rotated position in the result image
                // The formula for the rotated position is (n - j - 1, i)
                for (int k = 0; k < 3; k++)
                {
                    image2(n - j - 1, i, k) = image(i, j, k);
                }
            }
        }
        Image temp;
        image = image2;
        image2 = temp;
    }
    else if (choice == 'B')
    {
        Image image2(m, n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //            Assign the pixel at (i, j) of the original image to the rotated position in the result image
                //          The formula for the rotated position is (m - i - 1, n - j - 1)
                for (int k = 0; k < 3; k++)
                {

                    image2(m - i - 1, n - j - 1, k) = image(i, j, k);
                }
            }
        }

        Image temp;
        image = image2;
        image2 = temp;
    }
    else if (choice == 'C')
    {
        Image image2(n, m);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Assign the pixel at (i, j) of the original image to the rotated position in the result image
                // The formula for the rotated position is (j, m - i - 1)
                for (int k = 0; k < 3; k++)
                {

                    image2(j, m - i - 1, k) = image(i, j, k);
                }
            }
        }
        Image temp;
        image = image2;
        image2 = temp;
    }
}
void darkenAndLighten(Image &image)
{
    char choice;
    cout << "A) Lighten Image\n";
    cout << "B) Darken Image\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while (choice != 'A' && choice != 'B')
    {
        cout << "Enter a valid choice ( A , B )\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choice == 'A')
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    int newValue = static_cast<int>(image.getPixel(i, j, k) * 1.5);
                    newValue = std::max(0, std::min(255, newValue));
                    image.setPixel(i, j, k, newValue);
                }
            }
        }
    }
    else if (choice == 'B')
    {
        for (int i = 0; i < image.width; i++)
        {
            for (int j = 0; j < image.height; j++)
            {
                for (int k = 0; k < 3; k++)
                {
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
    int x, y, w, h;
    cout << "Please enter upper left corner pixel coordinate(first pixel is zero), width and height respectively: ";
    cin >> x >> y >> w >> h;
    while ((x < 0 || x > image.width) || (y < 0 || y > image.height) || (w <= 0 || w > (image.width - w)) || (h <= 0 || h > (image.height - h)))
    {
        cout << "Please enter valid number" << endl;
        cout << "Please enter upper left corner pixel coordinate(first pixel is zero), width and height respectively: ";
        cin >> x >> y >> w >> h;
    }
    Image nwImg = image;
    nwImg = Image(w, h);
    for (int i = 0, ii = x; i < w; i++, ii++)
    {
        for (int j = 0, jj = y; j < h; j++, jj++)
        {
            for (int k = 0; k < 3; k++)
            {
                nwImg(i, j, k) = image(ii, jj, k);
            }
        }
    }
    image = nwImg;
}

void frame(Image &image)
{
    char choice;

    cout << "A) Default Frame\n";
    cout << "B) Fancy  frame\n";
    cout << "Enter your choice:";
    cin >> choice;
    choice = toupper(choice);
    while (choice != 'A' && choice != 'B')
    {
        cout << "Enter a valid choice ( A , B )\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choice == 'A')
    {
        int thickness = (image.width)/25;
        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < thickness; ++j)
            {
                // Initialize average value
                image(i, j, 0) = 2;
                image(i, j, 1) = 2;
                image(i, j, 2) = 232;
            }
        }
        for (int i = 0; i < thickness; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                // Initialize average value
                image(i, j, 0) = 2;
                image(i, j, 1) = 2;
                image(i, j, 2) = 232;
            }
        }
        for (int i = image.width; i > image.width - thickness; i--)
        {
            for (int j = 0; j < image.height; j++)
            {
                // Initialize average value
                image(i, j, 0) = 2;
                image(i, j, 1) = 2;
                image(i, j, 2) = 232;
            }
        }
        for (int j = image.height - 1; j > image.height - thickness; j--)
        {
            for (int i = 0; i < image.width; i++)
            {
                // Initialize average value
                image(i, j, 0) = 2;
                image(i, j, 1) = 2;
                image(i, j, 2) = 232;
            }
        }
    }
    else
    {
        int red;
        int green;
        int blue;
        string test;

        cout << "A) Default color\n";
        cout << "B) Custom color\n";
        cout << "Enter your choice:";
        cin >> choice;
        choice = toupper(choice);
        while (choice != 'A' && choice != 'B')
        {
            cout << "Enter a valid choice ( A , B )\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            choice = toupper(choice);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (choice == 'A')
        {
            red = 2;
            blue = 2;
            green = 232;
        }
        else
        {
            cout << "Enter red value ";
            cin >> test;
            red = digit_checker(test);
            cout << "Enter green value ";
            cin >> test;
            green = digit_checker(test);
            cout << "Enter blue value ";
            cin >> test;
            blue = digit_checker(test);
            while (true)
            {
                bool condition1 = false;
                bool condition2 = false;
                bool condition3 = false;

                if (red > 255 || red < 0)
                {
                    cout << "Enter red only from 0 to 255 ";
                    cin >> red;
                }
                else
                {
                    condition1 = true;
                }

                if (green > 255 || green < 0)
                {
                    cout << "Enter green only from 0 to 255 ";
                    cin >> green;
                }
                else
                {
                    condition2 = true;
                }

                if (blue > 255 || blue < 0)
                {
                    cout << "Enter blue only from 0 to 255 ";
                    cin >> blue;
                }
                else
                {
                    condition3 = true;
                }
                if (!condition1 || !condition2 || !condition3)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        int thickness = (image.width)/25;
        for (int i = 0; i < image.width; ++i)
        {
            for (int j = 0; j < thickness; ++j)
            {
                // Initialize average value
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
        for (int i = thickness + 10; i < image.width - (thickness + 10); ++i)
        {
            for (int j = (thickness + 5); j < (thickness + 5) + 5; ++j)
            {
                // Initialize average value
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
        for (int i = 0; i < thickness; ++i)
        {
            for (int j = 0; j < image.height; ++j)
            {
                // Initialize average value
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
        for (int i = thickness + 10; i < thickness + 15; ++i)
        {
            for (int j = thickness + 10; j < image.height - (thickness + 10); ++j)
            {
                // Initialize average value
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
        for (int i = image.width; i > image.width - thickness; i--)
        {
            for (int j = 0; j < image.height; j++)
            {
                // Initialize average value
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
        for (int i = thickness + 10; i < image.width - (thickness + 10); ++i)
        {
            for (int j = image.height - (thickness + 10); j > (image.height - (thickness + 10)) - 5; j--)
            {
                // Initialize average value
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
        for (int i = image.width - thickness - 11; i > (image.width - thickness - 10) - 5; i--)
        {
            for (int j = thickness + 10; j < image.height - (thickness + 10); ++j)
            {
                // Initialize average value
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
        for (int j = image.height - 1; j > image.height - thickness; j--)
        {
            for (int i = 0; i < image.width; i++)
            {
                // Initialize average value
                image(i, j, 0) = red;
                image(i, j, 1) = green;
                image(i, j, 2) = blue;
            }
        }
    }
}

void imageEdges(Image &image, string &image_name)
{
    Image image1(image_name);
    int kernelX[3][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};
    int kernelY[3][3] = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};
    for (int i = 1; i < image.width - 1; i++)
    {
        for (int j = 1; j < image.height - 1; j++)
        {
            int gx = 0, gy = 0;
            for (int ky = 0; ky < 3; ky++)
            {
                for (int kx = 0; kx < 3; kx++)
                {
                    gx += kernelX[ky][kx] * (image1(i + kx - 1, j + ky - 1, 0) + image1(i + kx - 1, j + ky - 1, 1) + image1(i + kx - 1, j + ky - 1, 2));
                    gy += kernelY[ky][kx] * (image1(i + kx - 1, j + ky - 1, 0) + image1(i + kx - 1, j + ky - 1, 1) + image1(i + kx - 1, j + ky - 1, 2));
                }
                int magnitude = std::sqrt(gx * gx + gy * gy);
                if (magnitude > 200)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        image(i, j, k) = 0;
                    }
                }
                else
                {
                    for (int k = 0; k < 3; k++)
                    {
                        image(i, j, k) = 255;
                    }
                }
            }
        }
    }
}
Image resize(Image image)
{
    double wScale, hScale;
    int wPixel = image.width, hPixel = image.height;
    string choice;
    cout << "Do you want to scale using:\nA) Pixels\nB) Percentage\n";
    cin >> choice;
    choice[0] = toupper(choice[0]);
    while (choice != "A" && choice != "B")
    {
        cout << "Please enter valid choice" << endl;
        cin >> choice;
        choice[0] = toupper(choice[0]);
    }
    if (choice == "A")
    {
        cout << "Enter width, height respectively: ";
        cin >> wPixel >> hPixel;
    }
    else if (choice == "B")
    {
        cout << "Enter percentage: ";
        double percentage;
        cin >> percentage;
        wScale = percentage / 100.0;
        hScale = percentage / 100.0;
        wPixel = image.width * wScale;
        hPixel = image.height * hScale;
    }
    Image nwImg(wPixel, hPixel);
    wScale = (double)(image.width) / wPixel;
    hScale = (double)(image.height) / hPixel;
    for (int i = 0; i < wPixel; i++)
    {
        for (int j = 0; j < hPixel; j++)
        {
            int w, h;
            w = round(wScale * i);
            h = round(hScale * j);
            for (int k = 0; k < 3; k++)
                nwImg(i, j, k) = image(w, h, k);
        }
    }
    return nwImg;
}

void blur(Image &image, double sigma)
{

    int width = image.width;
    int height = image.height;
    string rr;
    int number;
    cout << "Enter the blur radius ";
    cin >> rr;
    number = digit_checker(rr);
    while (number > 8 || number < 1)
    {
        cout << "The number must be from 1 to 8 " << endl;
        cin >> number;
    }

    for (int o = 0; o < number; o++)
    {
        for (int i = 1; i < width - 1; ++i)
        {
            for (int j = 1; j < height - 1; ++j)
            {
                unsigned int total_red = 0, total_green = 0, total_blue = 0;
                for (int k = -1; k <= 1; ++k)
                {
                    for (int l = -1; l <= 1; ++l)
                    {
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
                for (int k = -1; k <= 1; ++k)
                {
                    for (int l = -1; l <= 1; ++l)
                    {
                        image(i + k, j + l, 0) = total_red;
                        image(i + k, j + l, 1) = total_green;
                        image(i + k, j + l, 2) = total_blue;
                    }
                }
            }
        }
    }
}
void sunlight(Image &image)
{
    // The amount of sunshine to be added, expressed as a fraction of the difference between the current pixel value and 255.
    double sunshine = 0.25;

    // Loop through each pixel in the image.
    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            // Adjust the red channel of the pixel by increasing it towards 255.
            image(x, y, 0) = floor(image(x, y, 0) + sunshine * (255 - image(x, y, 0)));

            // Adjust the green channel of the pixel by increasing it towards 255 and halving the effect.
            image(x, y, 1) = floor(image(x, y, 1) + sunshine * (255 - image(x, y, 1)) * 0.5);

            // Adjust the blue channel of the pixel by decreasing it towards 0.
            image(x, y, 2) = floor(image(x, y, 2) - sunshine * image(x, y, 2));
        }
    }
}

void oilPainting(Image &image)
{
    // Loop through each pixel in the image.
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Divide each color channel value by 30 and then multiply it back by 30, resulting in a simplification of color values.
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) /= 30;
                image(i, j, k) *= 30;
            }
        }
    }
}

void infrared(Image &image)
{
    // Loop through each pixel in the image.
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Calculate the average of the green and blue channels.
            int avg = (image(i, j, 1) + image(i, j, 2)) / 2;

            // Calculate the absolute difference between 255 and the average value.
            avg = abs(255 - avg);

            // Set the red channel to 255 and the green and blue channels to the calculated average.
            image(i, j, 0) = 255;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}

void television(Image &image)
{
    // Define a random number generator engine
    mt19937 rng(random_device{}());
    // Define a normal distribution with mean 0 and standard deviation 20 (for example)
    normal_distribution<double> dist(0.0, 20.0); // Adjust the standard deviation as needed

    // Loop through each pixel in the image
    for (int i = 0; i < image.height; ++i)
    {
        for (int j = 0; j < image.width; ++j)
        {
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
void purple(Image &image)
{
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            image(i, j, 1) = .7 * image(i, j, 1);
        }
    }
}

Image skew(Image image)
{
    double degree;
    cout << "Enter a degree: ";
    cin >> degree;
    degree = (22 * degree) / (7 * 180);
    while (true)
    {
        bool valid = true;
        if (degree == 90 || degree == 270)
        {
            valid = false;
        }
        if (valid)
            break;
        cout << "Invalid input\n";
        cout << "Enter an angle: ";
        cin >> degree;
    }
    int width = image.width;
    int height = image.height;
    double l = height * tan(degree);      // Calculate the skewing length based on height
    int newWidth = width + int(l);        // New width after skewing
    int x_shift = (newWidth - width) / 2; // Calculate the shift for the new width to maintain centering
    Image image1(newWidth, height);       // Create new image with adjusted width
    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image1(i, j, k) = 255; // Initialize the new image with white pixels
            }
        }
    }
    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int originalX = i - x_shift - int(l) / 2 + int(l) * j / height; // Calculate original x-coordinate
                if (originalX >= 0 && originalX < width)
                {                                             // Check if original x-coordinate is within bounds
                    image1(i, j, k) = image(originalX, j, k); // Copy pixel values from original image to temporary image
                }
            }
        }
    }
    return image1;
}

// Function to simulate a broken TV effect on an image
Image brokenTvEffect(Image image)
{
    // Create a new image with the same dimensions as the input image
    Image image1(image.width, image.height);

    // Loop through each pixel in the image
    for (int x = 0; x < image.width; x++)
    {
        for (int y = 0; y < image.height; y++)
        {
            // Calculate the index of the current pixel in the image data array
            int index = (y * image.width + x) * 3;

            // Calculate the distance of the current pixel from the center of the image
            int dist = sqrt(pow(x - (image.width / 2), 2) + pow(y - (image.height / 2), 2));

            // Increase the contrast based on the distance from the center
            int contrast = 1 + dist / 80;

            // Set contrast value to a reasonable range (between 1 and 5)
            contrast = min(max(contrast, 1), 5);

            // Apply contrast to each color channel of the pixel
            for (int c = 0; c < 3; c++)
            {
                image1.imageData[index + c] = image.imageData[index + c] * contrast;
            }
        }
    }

    // Return the filtered image
    return image1;
}

// Function to apply a classic color transformation to an image
void classic(Image &image)
{
    // Loop through each pixel in the image
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            // Calculate the average intensity of the pixel across all color channels
            unsigned int average = 0;
            for (int k = 0; k < 3; k++)
            {
                average += image(i, j, k);
            }
            average /= 3;

            // Apply a classic color transformation using predefined coefficients
            unsigned int red = 0.393 * average + 0.769 * average + 0.189 * average;
            unsigned int green = 0.349 * average + 0.686 * average + 0.168 * average;
            unsigned int blue = 0.272 * average + 0.534 * average + 0.131 * average;

            // Clamp intensity values to the valid range (0 to 255)
            image(i, j, 0) = min(255, (int)red);
            image(i, j, 1) = min(255, (int)green);
            image(i, j, 2) = min(255, (int)blue);
        }
    }
}
int main()
{
    string choice;
    string image_name;
    int x;
    bool saved = true;
    Image image;
    while (true)
    {
        if (saved)
        {
            cout << "Please Enter Name of the Image which you want to apply a filter on with (.png, .jpeg, .jpg, .bmp):";
            cin >> image_name;
            while (true)
            {
                try
                {
                    if (image.loadNewImage(image_name))
                    {
                        Image image(image_name);
                        break;
                    }
                }
                catch (invalid_argument)
                {
                    cout << "Please enter a valid photo \n"
                         << endl;
                    cin >> image_name;
                }
            }
            saved = false;
        }
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
        cout << "Filter 20: Broken Tv Effect\n";

        cout << "\n21: Load new Image\n";
        cout << "22: Save Image\n";
        cout << "23: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while (true)
        {
            if (regex_match(choice, regex("[\\d]+")))
            {
                x = stoi(choice);
                if (x >= 1 && x <= 23)
                    break;
            }
            cout << "Enter a valid choice \n";
            cin >> choice;
        }
        if (x == 21 || x == 23)
        {
            cout << "Do you want to save image?(Y/N): ";
            string s;
            cin >> s;
            s[0] = toupper(s[0]);
            if (s == "Y")
            {
                cout << "Do you want to:\n";
                cout << "1) Change current image\n";
                cout << "2) Save as new image?\n";
                int c;
                cin >> c;
                if (c == 2)
                {
                    cout << "Please enter the image name to store the new image with (.png, .jpeg, .jpg, .bmp): ";
                    cin >> image_name;
                }
                while (true)
                {
                    try
                    {
                        if (image.saveImage(image_name))
                        {
                            image.saveImage(image_name);
                            break;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Please enter a valid extension" << endl;
                        cin >> image_name;
                    }
                }
                saved = true;
            }
            else if (s != "N")
                cout << "Please enter valid choice" << endl;
            if (x == 23)
                break;
            else
            {
                saved = true;
                continue;
            }
        }

        else if (x == 22)
        {
            cout << "Do you want to:\n";
            cout << "1) Change current image\n";
            cout << "2) Save as new image?\n";
            int c;
            cin >> c;
            if (c == 2)
            {
                cout << "Please enter the image name to store the new image with (.png, .jpeg, .jpg, .bmp): ";
                cin >> image_name;
                while (true)
                {
                    try
                    {
                        if (image.saveImage(image_name))
                        {
                            image.saveImage(image_name);
                            break;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Please enter a valid extension" << endl;
                        cin >> image_name;
                    }
                }
            }
            continue;
        }
        switch (x)
        {
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
            image = resize(image);
            break;
        case 12:
            blur(image, 2);
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
            classic(image);
            break;
        case 20:
            image = brokenTvEffect(image);
            break;
        }
    }
}
