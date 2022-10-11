#include <stdio.h>
#include <stdlib.h>
int inp_check_choose();
int inp_check_arrsize();
void inp_check_arrelem(int mass[], int size);
void rand_inp_check(int mass[], int size);
int shift(int mass[], int size);
int main()
{
    int mass[100];
    int array_size = 0;
    int option = 0;
    array_size = inp_check_arrsize();
    option = inp_check_choose();
    switch (option)
    {
    case 1:
        inp_check_arrelem(mass, array_size);
        break;
    case 2:
        rand_inp_check(mass, array_size);
        break;
    default:
        return 0;
        break;
    }
    printf(shift(mass, array_size));
 }
int inp_check_choose()
{
    int inp;
    printf("Print 1 for manual input or 2 to random\n");
    scanf_s("%d", &inp);
    while (inp != 1 && inp != 2)
    {
        printf_s("Wrong input. Enter number 1 or 2\n");
        scanf_s("%d", &inp);
        rewind(stdin);
    }
    return inp;
}
int inp_check_arrsize()
{
    int inp;
    printf("Enter the size of the array (the size should not exceed 100)\n");
    scanf_s("%d", &inp);
    while (inp <=0 || inp >= 101)
    {
        printf("Wrong input. Enter a number from 1 to 100\n");
        scanf_s("%i", &inp);
        rewind(stdin);
    }
    return inp;
}
void inp_check_arrelem(int mass[], int size)
{
    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        while (scanf_s("%d", &mass[i]) == 0)
        {
            printf("Wrong input.\n");
            scanf_s("%i", &mass[i]);
            rewind(stdin);
        }
    }
}
void rand_inp_check(int mass[], int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = (rand()%10);
        printf("the %dth element of array is %d\n", i+1, mass[i]);
    }
}
int shift(int mass[], int size)
{
    int arr[100] = { 0 };
    int m;
    printf("Enter shift\n");
    scanf_s("%d", &m);
    for (int j = 0; j < size; j++)
    {
        if (mass[j] % 2 == 0)
        {
            arr[(j - m + size) % size] = mass[j];
            mass[j] = 0;
        }
    }
    for (int j = 0; j < size; j++)
    {
        if (arr[j] != 0)
        {
            mass[j] = arr[j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", mass[i]);
    }
}