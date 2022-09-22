#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "russian");
    int a, b, c;
    printf("¬ведите первое число - ");
    scanf_s("%d", &a);
    printf("¬ведите второе число - ");
    scanf_s("%d", &b);
    printf("¬ведите третье число - ");
    scanf_s("%d", &c);
    if (b % 2==0 || c % 2==0 || a % 2==0 )
    {
        printf("—реди чисел имеетс€ четное");
    }
    else
    {
        printf("—реди чисел нет четных");
    }
    return 0;
}