#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "D:\Bibs\InputManager\InputManager\InputManager.h"

#pragma pack(push, 1)

typedef struct 
{
	unsigned short signatur;
	unsigned int size;
	unsigned int reserved;
	unsigned int offset;
}BMPHEADER;

typedef struct 
{
	unsigned int size;
	unsigned int width;
	unsigned int height;
	unsigned short planes;
	unsigned short bits_per_pixels;
	unsigned int compression;
	unsigned int imageSize;
	unsigned int XpixelsPerMeter;
	unsigned int YpixelsPerMeter;
	unsigned int colorsUsed;
	unsigned int colorsImportant;

}BMPINFOHEADER;

typedef struct
{
	unsigned char Red;
	unsigned char Green;
	unsigned char Blue;
}PIXELS;

#pragma pack(pop)

typedef struct
{
	BMPHEADER BMPHead;
	BMPINFOHEADER BMPinfo;
	PIXELS* pixels;
}BMPfile;

int main();

void menu(BMPfile BMP, FILE* outputBMP);

BMPfile initBMPstruct(FILE* file);

void outputBMPfile(FILE* file, BMPfile BMP);

void convertToNegative(BMPfile BMP);

void convertToBlackAndWhite(BMPfile BMP);

void medianFiltering(BMPfile BMP, int count);

void gammaCorrection();