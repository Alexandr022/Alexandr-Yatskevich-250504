#include <stdio.h>
#include <locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "ru");
	double a, b, c, x1, x2, discrim,d;
	printf("������� �������� a,b,c ��� ����������� ax^2+bx+c<0 - \n");
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
		printf("(-�������������;%lf)U(%lf;�������������)\n", x1, x2);
	}
	if (d == 0 && a > 0)
	{
		printf("��� �������\n");
	}
	if (a == 0)
	{
		double v = 0;
		v = -c / b;
		printf("(-�������������;%lf\n)", v);
	}
	if (d == 0 && a < 0)
	{
		x1 = (-b + discrim) / (2 * a);
		printf("��� �������� ����� x1 = %lf\n", x1);
	}
	if (d < 0 && a > 0)
	{
		printf("��� �������\n");
	}
	if (d < 0 && a < 0)
	{
		printf("��� ��������\n");
	}
	return 0;
}