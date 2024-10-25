# BMP Image Filter

This project is a command-line tool that applies various image filters to BMP (Bitmap) images. It supports four different filters: grayscale, sepia, reflection, and blur. The tool reads an uncompressed 24-bit BMP file, applies the selected filter, and saves the result as a new BMP file.

## Features

- **Grayscale**: Converts the image to shades of gray by averaging the red, green, and blue components of each pixel.
- **Sepia**: Applies a sepia tone to the image, mimicking an old photograph style.
- **Reflection**: Reflects the image horizontally (mirrors the image along the vertical axis).
- **Blur**: Applies a simple blur effect to the image by averaging neighboring pixels.

## File Structure

- **`filter.c`**: The main program that processes command-line arguments, reads the input BMP file, applies the selected filter, and writes the output file.
- **`helpers.c`**: Contains the implementation of the four image filters (grayscale, sepia, reflection, blur).
- **`bmp.h`**: Defines data structures used to represent BMP headers and pixels.
- **`helpers.h`**: Header file that declares the filter functions used in `helpers.c`.
- **`Makefile`**: Script for compiling the program.

## Usage

To compile the program, run the following command:

```bash
make filter
