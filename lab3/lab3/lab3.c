// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "lab3.h"

BMPfile initBMPstruct(FILE* file)
{
	BMPfile BMP;

	fread(&BMP.BMPHead, sizeof(BMP.BMPHead), 1, file);
	fread(&BMP.BMPinfo, sizeof(BMP.BMPinfo), 1, file);

	BMP.pixels = (PIXELS*)malloc(BMP.BMPinfo.width * BMP.BMPinfo.height * sizeof(PIXELS*));

	for (int i = 0; !feof(file); i++)
	{
		PIXELS pixel;
		fread(&pixel, sizeof(PIXELS), 1, file);
		BMP.pixels[i] = pixel;
	}

	return BMP;
}

void outputBMPfile(FILE* file, BMPfile BMP)
{
	fwrite(&BMP.BMPHead, sizeof(BMP.BMPHead), 1, file);
	fwrite(&BMP.BMPinfo, sizeof(BMP.BMPinfo), 1, file);

	for (int i = 0; i < BMP.BMPinfo.width * BMP.BMPinfo.height + 1; i++)
	{
		fwrite(&BMP.pixels[i], sizeof(PIXELS), 1, file);
	}
}

void convertToNegative(BMPfile BMP)
{
	for (int i = 0; i < BMP.BMPinfo.width * BMP.BMPinfo.height; i++)
	{
		BMP.pixels[i].Red = 255 - BMP.pixels[i].Red;
		BMP.pixels[i].Green = 255 - BMP.pixels[i].Green;
		BMP.pixels[i].Blue = 255 - BMP.pixels[i].Blue;
	}
}

void convertToBlackAndWhite(BMPfile BMP)
{
	for (int i = 0; i < BMP.BMPinfo.width * BMP.BMPinfo.height; i++)
	{
		int gray = (BMP.pixels[i].Red + BMP.pixels[i].Green + BMP.pixels[i].Blue) / 3;
		BMP.pixels[i].Red = BMP.pixels[i].Green = BMP.pixels[i].Blue = gray;
	}
}

void medianFiltering(BMPfile BMP, int count)
{
	int N = count / 2;
	for (int y = N; y < BMP.BMPinfo.height - N; y++)
	{
		for (int x = N; x < BMP.BMPinfo.width - N; x++)
		{
			PIXELS* window = (PIXELS*)malloc(count * count * sizeof(PIXELS));
			int i = 0;
			for (int w = -N; w <= N; w++)
			{
				for (int h = -N; h <= N; h++)
				{
					window[i++] = BMP.pixels[BMP.BMPinfo.width * (y + w) + (x + h)];
				}
			}
			for (int i = 0; i < count * count; i++)
			{
				for (int j = 0; j < count * count; j++)
				{
					if (window[i].Red + window[i].Green + window[i].Blue < window[j].Red + window[j].Green + window[j].Blue)
					{
						PIXELS buf = window[i];
						window[i] = window[j];
						window[j] = buf;
					}
				}
			}
			BMP.pixels[BMP.BMPinfo.width * y + x] = window[count * count / 2];
		}
	}
}

void gammaCorrection(BMPfile BMP, double count)
{
	for (int i = 0; i < BMP.BMPinfo.width * BMP.BMPinfo.height; i++)
	{
		BMP.pixels[i].Red = pow(BMP.pixels[i].Red / 255.0, count) * 255.0;
		BMP.pixels[i].Green = pow(BMP.pixels[i].Green / 255.0, count) * 255.0;
		BMP.pixels[i].Blue = pow(BMP.pixels[i].Blue / 255.0, count) * 255.0;
	}
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
