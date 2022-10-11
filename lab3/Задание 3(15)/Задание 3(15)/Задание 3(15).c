#include <stdio.h> 
#include <stdlib.h>
int inp_check_choose();
void inp_check_arrelem(int mass[], int array[], char str[], int size);
void rand_check(int mass[], int array[], char str[], int size);
int summ(int mass[], int array[], char str[], int size);
int main()
{
    int mass[100], array[100];
    int option;
    char str[100];
    int size = 30;
    option = inp_check_choose();
    switch (option)
    {
    case 1:
        rand_check(mass, array, str, size);
        break;
    case 2:
        inp_check_arrelem(mass, array, str, size);
        break;
    default:
        return 0;
        break;
    }
    printf(summ(mass, array, str, size));
}
int inp_check_choose()
{
    int inp;
    printf("Print 1 for random input or 2 for manual input\n");
    while ((scanf_s("%d", &inp)) != 1 && inp != 2)
    {
        printf("Wrong input. Enter number 1 or 2\n");
        rewind(stdin);
    }
    return inp;
}
void inp_check_arrelem(int mass[], int array[], char str[], int size)
{
    while (getchar() != '\n');
    printf("Enter 1 number: ");
    gets(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] > '9' || str[i] < '0')
        {
            printf("Wrong input");
            rewind(stdin);
        }
    }
    for (int i = 0; i < size; i++)
    {
        mass[i] = str[i] - '0';
    }
    printf("Enter 2 number: ");
    gets(str);
    for (int i = 0; i < size; i++)
    {
        if (str[i] > '9' || str[i] < '0')
        {
            printf("Wrong input");
            rewind(stdin);
        }
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = str[i] - '0';
    }
}
void rand_check(int mass[], int array[], char str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand() % 10;
        array[i] = rand() % 10;
    }
    printf("1 number = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", mass[i]);
    }
    printf("\n2 number = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
}
int summ(int mass[], int array[], char str[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] += array[i];
        mass[i + 1] += (mass[i] / 10);
        mass[i] %= 10;
    }
    printf("\nResult = ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", mass[i]);
    }
}