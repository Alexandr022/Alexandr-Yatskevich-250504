#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "russian");
    int a, b, c;
    printf("������� ������ ����� - ");
    scanf_s("%d", &a);
    printf("������� ������ ����� - ");
    scanf_s("%d", &b);
    printf("������� ������ ����� - ");
    scanf_s("%d", &c);
    if (b % 2==0 || c % 2==0 || a % 2==0 )
    {
        printf("����� ����� ������� ������");
    }
    else
    {
        printf("����� ����� ��� ������");
    }
    return 0;
}