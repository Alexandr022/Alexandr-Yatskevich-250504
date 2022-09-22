#include <stdio.h>
#include <locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "ru");
	double a, b, c, x1, x2, discrim,d;
	printf("Введите значения a,b,c для неравенства ax^2+bx+c<0 - \n");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);
	d = (b * b) - 4 * a * c;
	discrim = sqrt(d);
	if (d > 0 && a > 0)
	{
		x1 = ((-b) + discrim) / (2 * a);
		x2 = ((-b) - discrim) / (2 * a);
		printf(" ( %2.1lf;", x2);
		printf(" %2.1lf )\n", x1);
	}
	if (d > 0 && a < 0)
	{
		x1 = ((-b) + discrim) / (2 * a);
		x2 = ((-b) - discrim) / (2 * a);
		printf("(-Бесконечность;%lf)U(%lf;бесконечность)\n", x1, x2);
	}
	if (d == 0 && a > 0)
	{
		printf("Нет решения\n");
	}
	if (a == 0)
	{
		double v = 0;
		v = -c / b;
		printf("(-Бесконечность;%lf\n)", v);
	}
	if (d == 0 && a < 0)
	{
		x1 = (-b + discrim) / (2 * a);
		printf("Все значения кроме x1 = %lf\n", x1);
	}
	if (d < 0 && a > 0)
	{
		printf("Нет решения\n");
	}
	if (d < 0 && a < 0)
	{
		printf("Все значения\n");
	}
	return 0;
}