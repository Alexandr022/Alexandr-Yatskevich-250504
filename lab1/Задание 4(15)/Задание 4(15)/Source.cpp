#include <stdio.h>
#include <locale.h> 
int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    printf("������� ����� ��������� ������\n");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("�� ����� 1 ���� � ����\n");
    }
    else if (a % 10 == 1)
    {
        printf("�� ����� %d ���� � ����\n",a);
    }
    else if ((a % 10 > 4 && a % 10 < 10) || a % 10 == 0 )
    {
        printf("�� ����� %d ������ � ����\n", a);
    }
    else if (a == 12 || a == 13 || a == 14)
    {
        printf("�� ����� %d ������ � ����\n", a);
        return 0;
    }
    else if (a % 10 > 1 && a % 10 < 5)
    {
        printf("�� ����� %d ����� � ����\n", a);
    }
        return 0;
}