// menu.cpp : Ýòîò ôàéë ñîäåðæèò ôóíêöèþ "main". Çäåñü íà÷èíàåòñÿ è çàêàí÷èâàåòñÿ âûïîëíåíèå ïðîãðàììû.
//

#include "lab3.h"
#include "InputManager.h"

void menu(BMPfile BMP, FILE* outputBMP)
{
	while (1)
	{
		printf("-----------------------------------------------\n");
		printf("Choose which image you wanna get.\n");
		printf("1.Conversion from image to negative.\n");
		printf("2.Conversion image into black and white.\n");
		printf("3.Median filtration.\n");
		printf("4.Gamma correction.\n");
		printf("5.Save image.\n");
		printf("-----------------------------------------------\n");

		int choose = getIntFromKayboard("");
		double countGamma = 0;
		int countMedian = 0;

		while (choose > 5 && choose < 1)
		{
			printf("Error. Write number from 1 to 4.\n");
			rewind(stdin);
		}

		switch (choose)
		{
		case 1:
			convertToNegative(BMP);
			break;
		case 2:
			convertToBlackAndWhite(BMP);
			break;
		case 3:
			countMedian = getIntFromKayboard("Enter median filtering value.(must be odd)");

			while (countMedian % 2 == 0)
			{
				printf("Enter odd value.\n");
				countMedian = getIntFromKayboard("Enter median filtering value.(must be odd)");
				rewind(stdin);
			}
			
			medianFiltering(BMP, countMedian);
			break;
		case 4:
			countGamma = getFloatFromKayboard("Enter the gamma correction value.");
			gammaCorrection(BMP, countGamma);
			break;
		default:
			break;
		}

		if (choose == 5)
		{
			break;
		}
	}
}

// Çàïóñê ïðîãðàììû: CTRL+F5 èëè ìåíþ "Îòëàäêà" > "Çàïóñê áåç îòëàäêè"
// Îòëàäêà ïðîãðàììû: F5 èëè ìåíþ "Îòëàäêà" > "Çàïóñòèòü îòëàäêó"

// Ñîâåòû ïî íà÷àëó ðàáîòû 
//   1. Â îêíå îáîçðåâàòåëÿ ðåøåíèé ìîæíî äîáàâëÿòü ôàéëû è óïðàâëÿòü èìè.
//   2. Â îêíå Team Explorer ìîæíî ïîäêëþ÷èòüñÿ ê ñèñòåìå óïðàâëåíèÿ âåðñèÿìè.
//   3. Â îêíå "Âûõîäíûå äàííûå" ìîæíî ïðîñìàòðèâàòü âûõîäíûå äàííûå ñáîðêè è äðóãèå ñîîáùåíèÿ.
//   4. Â îêíå "Ñïèñîê îøèáîê" ìîæíî ïðîñìàòðèâàòü îøèáêè.
//   5. Ïîñëåäîâàòåëüíî âûáåðèòå ïóíêòû ìåíþ "Ïðîåêò" > "Äîáàâèòü íîâûé ýëåìåíò", ÷òîáû ñîçäàòü ôàéëû êîäà, èëè "Ïðîåêò" > "Äîáàâèòü ñóùåñòâóþùèé ýëåìåíò", ÷òîáû äîáàâèòü â ïðîåêò ñóùåñòâóþùèå ôàéëû êîäà.
//   6. ×òîáû ñíîâà îòêðûòü ýòîò ïðîåêò ïîçæå, âûáåðèòå ïóíêòû ìåíþ "Ôàéë" > "Îòêðûòü" > "Ïðîåêò" è âûáåðèòå SLN-ôàéë.
