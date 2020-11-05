#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int r = image[h][w].rgbtBlue;
            int g = image[h][w].rgbtGreen;
            int b = image[h][w].rgbtRed;
            float avg = (r + g + b) / (float)3;
            image[h][w].rgbtBlue = round(avg);
            image[h][w].rgbtGreen = round(avg);
            image[h][w].rgbtRed = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0 ; h < height ; h++)
    {
        for (int w = 0 ; w < width ; w++)
        {
            int originalRed = image[h][w].rgbtRed;
            int originalBlue = image[h][w].rgbtBlue;
            int originalGreen = image[h][w].rgbtGreen;

            int SepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int SepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            int SepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);

            if (SepiaRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = SepiaRed;
            }

            if (SepiaBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = SepiaBlue;
            }

            if (SepiaGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = SepiaGreen;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int h = 0; h < height; h++) //Copy image to temp
    {
        for (int w = 0; w < width; w++)
        {
            temp[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++) //Reverse row elemens in temp
    {
        for (int  w = 0; w < width; w++)
        {
            temp[h][w] =  image[h][width - w - 1];
        }
    }

    for (int h = 0; h < height; h++) //Copy temp to image
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp[h][w];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int h = 0; h < height; h++) //Copy image to temp
    {
        for (int w = 0; w < width; w++)
        {
            temp[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (h == 0 && w == 0) //Top corner left edge case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w + 1].rgbtRed +
                                            image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed) / 4.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen +
                                              image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) / 4.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue +
                                             image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) / 4.0);
            }
            else if (h == 0 && w == width - 1) //Top corner right edge case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w - 1].rgbtRed +
                                            image[h + 1][w].rgbtRed + image[h + 1][w - 1].rgbtRed) / 4.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w - 1].rgbtGreen +
                                              image[h + 1][w].rgbtGreen + image[h + 1][w - 1].rgbtGreen) / 4.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w - 1].rgbtBlue +
                                             image[h + 1][w].rgbtBlue + image[h + 1][w - 1].rgbtBlue) / 4.0);
            }
            else if (h == height - 1 && w == width - 1) //Bottom corner right edge case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w - 1].rgbtRed +
                                            image[h - 1][w].rgbtRed + image[h - 1][w - 1].rgbtRed) / 4.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w - 1].rgbtGreen +
                                              image[h - 1][w].rgbtGreen + image[h - 1][w - 1].rgbtGreen) / 4.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w - 1].rgbtBlue +
                                             image[h - 1][w].rgbtBlue + image[h - 1][w - 1].rgbtBlue) / 4.0);
            }
            else if (h == height - 1 && w == 0) //Bottom corner left edge case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w + 1].rgbtRed +
                                            image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed) / 4.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w + 1].rgbtGreen +
                                              image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen) / 4.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w + 1].rgbtBlue +
                                             image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue) / 4.0);
            }
            //Middle cases
            else if ((h != 0 && h != height - 1) && w == 0) //Left side middle case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed +
                                            image[h][w + 1].rgbtRed + image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed) / 6.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen +
                                              image[h][w + 1].rgbtGreen + image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen) / 6.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue +
                                             image[h][w + 1].rgbtBlue + image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue) / 6.0);
            }
            else if ((h != 0 && h != height - 1) && w == width - 1) //Right side middle case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h - 1][w].rgbtRed + image[h - 1][w - 1].rgbtRed +
                                            image[h][w - 1].rgbtRed + image[h + 1][w].rgbtRed + image[h + 1][w - 1].rgbtRed) / 6.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h - 1][w].rgbtGreen + image[h - 1][w - 1].rgbtGreen +
                                              image[h][w - 1].rgbtGreen + image[h + 1][w].rgbtGreen + image[h + 1][w - 1].rgbtGreen) / 6.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h - 1][w].rgbtBlue + image[h - 1][w - 1].rgbtBlue +
                                             image[h][w - 1].rgbtBlue + image[h + 1][w].rgbtBlue + image[h + 1][w - 1].rgbtBlue) / 6.0);
            }
            else if (h == 0 && (w != 0 && w != width - 1)) //Top side middle case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w - 1].rgbtRed + image[h + 1][w - 1].rgbtRed +
                                            image[h + 1][w].rgbtRed + image[h + 1][w + 1].rgbtRed + image[h][w + 1].rgbtRed) / 6.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w - 1].rgbtGreen + image[h + 1][w - 1].rgbtGreen +
                                              image[h + 1][w].rgbtGreen + image[h + 1][w + 1].rgbtGreen + image[h][w + 1].rgbtGreen) / 6.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w - 1].rgbtBlue + image[h + 1][w - 1].rgbtBlue +
                                             image[h + 1][w].rgbtBlue + image[h + 1][w + 1].rgbtBlue + image[h][w + 1].rgbtBlue) / 6.0);
            }
            else if (h == height - 1 && (w != 0 && w != width - 1))  //Bottom side middle case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w - 1].rgbtRed + image[h - 1][w - 1].rgbtRed +
                                            image[h - 1][w].rgbtRed + image[h - 1][w + 1].rgbtRed + image[h][w + 1].rgbtRed) / 6.0);
                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w - 1].rgbtGreen + image[h - 1][w - 1].rgbtGreen +
                                              image[h - 1][w].rgbtGreen + image[h - 1][w + 1].rgbtGreen + image[h][w + 1].rgbtGreen) / 6.0);
                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w - 1].rgbtBlue + image[h - 1][w - 1].rgbtBlue +
                                             image[h - 1][w].rgbtBlue + image[h - 1][w + 1].rgbtBlue + image[h][w + 1].rgbtBlue) / 6.0);
            }
            else //Normal case
            {
                temp[h][w].rgbtRed = round((image[h][w].rgbtRed + image[h][w - 1].rgbtRed + image[h][w + 1].rgbtRed +
                                            image[h - 1][w].rgbtRed + image[h - 1][w - 1].rgbtRed + image[h - 1][w + 1].rgbtRed +
                                            image[h + 1][w].rgbtRed + image[h + 1][w - 1].rgbtRed + image[h + 1][w + 1].rgbtRed) / 9.0);

                temp[h][w].rgbtGreen = round((image[h][w].rgbtGreen + image[h][w - 1].rgbtGreen + image[h][w + 1].rgbtGreen +
                                              image[h - 1][w].rgbtGreen + image[h - 1][w - 1].rgbtGreen + image[h - 1][w + 1].rgbtGreen +
                                              image[h + 1][w].rgbtGreen + image[h + 1][w - 1].rgbtGreen + image[h + 1][w + 1].rgbtGreen) / 9.0);

                temp[h][w].rgbtBlue = round((image[h][w].rgbtBlue + image[h][w - 1].rgbtBlue + image[h][w + 1].rgbtBlue +
                                             image[h - 1][w].rgbtBlue + image[h - 1][w - 1].rgbtBlue + image[h - 1][w + 1].rgbtBlue +
                                             image[h + 1][w].rgbtBlue + image[h + 1][w - 1].rgbtBlue + image[h + 1][w + 1].rgbtBlue) / 9.0);
            }
        }
    }

    for (int h = 0; h < height; h++) // copy temp to image
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = temp[h][w];
        }
    }

    return;
}
