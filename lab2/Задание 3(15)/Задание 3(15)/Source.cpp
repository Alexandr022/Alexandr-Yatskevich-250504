#include <stdio.h>
#include<locale.h>
#include<math.h>
static int
factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}
int main()
{
	setlocale(LC_ALL, "ru");
	float x = 0;
	printf("¬ведите число x - ");
	scanf_s("%f", &x);
	x = (x * 3.14) / 180;
	float s=0;
	for (int k = 0; k <=100; k++)
	{
		s += (pow(-1, k) * (pow(x, 2*k + 1)) / factorial(2 * k + 1));
	}
	printf("Sinx = %f", s);
	return 0;
}