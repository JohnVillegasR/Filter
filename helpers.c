#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;

            float Green = image[i][j].rgbtGreen;

            float Blue = image[i][j].rgbtBlue;
            //calculate avarege
            int avag = round((Red + Green + Blue) / 3);

            image[i][j].rgbtRed = avag;
            image[i][j].rgbtGreen = avag;
            image[i][j].rgbtBlue = avag;


        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;

            float Green = image[i][j].rgbtGreen;

            float Blue = image[i][j].rgbtBlue;
            //use the algorithim given
            int SepiaRed = round(.393 * Red + .769 * Green + .189 * Blue);
            int SepiaGreen = round(.349 * Red + .686 * Green + .168 * Blue);
            int SepiaBlue = round(.272 * Red + .534 * Green + .131 * Blue);
            //check andd cap if its more then 255
            if (SepiaRed > 255)
            {
                SepiaRed = 255;
            }
            if (SepiaGreen > 255)
            {
                SepiaGreen = 255;
            }
            if (SepiaBlue > 255)
            {
                SepiaBlue = 255;
            }
            //copy the pixels
            image[i][j].rgbtRed = SepiaRed;
            image[i][j].rgbtGreen = SepiaGreen;
            image[i][j].rgbtBlue = SepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //use temp to put the pixel somewehre sel temporarily 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //put the pixel in the temp and then use then later
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int TotalRed;
            int TotalBlue;
            int TotalGreen;

            TotalRed = TotalBlue = TotalGreen = 0;

            float counter = 0.00;

            // neighbor pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currenX =  i + x;
                    int currenY = j + y;

                    // invalid pixels
                    if (currenX < 0 || currenX > (height - 1) || currenY < 0 || currenY > (width - 1))
                    {
                        continue;
                    }

                    TotalRed = TotalRed + image[currenX][currenY].rgbtRed;
                    TotalGreen = TotalGreen + image[currenX][currenY].rgbtGreen;
                    TotalBlue = TotalBlue + image[currenX][currenY].rgbtBlue;

                    counter++;
                }
                //calculate
                temp[i][j].rgbtRed = round(TotalRed / counter);
                temp[i][j].rgbtGreen = round(TotalGreen / counter);
                temp[i][j].rgbtBlue = round(TotalBlue / counter);
            }
        }
    }
    //put the pixel back from the temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
