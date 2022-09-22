#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "ru");
    int a,b,c,n;
    printf("Введите n\n");
    scanf_s("%d", &n);
    for (a = 1, b = 2, c = 3; a * b * c < n; ++a, ++b, ++c);
    if (a * b * c > n)
    {
        printf("Нет\n");
    }
    else
    {
        printf("Да \n%d=%d*%d*%d\n", n, a, b, c);
    }
    return 0;
}





