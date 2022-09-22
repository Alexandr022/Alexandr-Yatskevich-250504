#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "ru");
	int a, sum = 0, proiz = 1, sum1 = 0, proiz1 = 1;
	printf("Введите число - ");
	scanf_s("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		if (i % 2 == 0)
		{
			sum += i * i * i;
			proiz *= i * i * i;
		}
		if (i % 2 == 1)
		{
			sum1 += i * i * i;
			proiz1 *= i * i * i;
		}
	}
	printf("Сумма нечетных членов %d\n", sum1);
	printf("Произведение нечетных членов %d\n", proiz1);
	printf("Сумма четных членов %d\n", sum);
	printf("Произведение четных членов %d\n", proiz);
	return 0;
}
