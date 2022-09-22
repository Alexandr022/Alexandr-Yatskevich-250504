#include <stdio.h>
#include <locale.h> 
int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    printf("Введите число собранных грибов\n");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("Мы нашли 1 гриб в лесу\n");
    }
    else if (a % 10 == 1)
    {
        printf("Мы нашли %d гриб в лесу\n",a);
    }
    else if ((a % 10 > 4 && a % 10 < 10) || a % 10 == 0 )
    {
        printf("Мы нашли %d грибов в лесу\n", a);
    }
    else if (a == 12 || a == 13 || a == 14)
    {
        printf("Мы нашли %d грибов в лесу\n", a);
        return 0;
    }
    else if (a % 10 > 1 && a % 10 < 5)
    {
        printf("Мы нашли %d гриба в лесу\n", a);
    }
        return 0;
}