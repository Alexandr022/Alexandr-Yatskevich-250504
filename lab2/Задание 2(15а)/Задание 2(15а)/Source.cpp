#include<stdio.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "ru");
	int a, sum = 0, proiz = 1, sum1 = 0, proiz1 = 1;
	printf("������� ����� - ");
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
	printf("����� �������� ������ %d\n", sum1);
	printf("������������ �������� ������ %d\n", proiz1);
	printf("����� ������ ������ %d\n", sum);
	printf("������������ ������ ������ %d\n", proiz);
	return 0;
}
