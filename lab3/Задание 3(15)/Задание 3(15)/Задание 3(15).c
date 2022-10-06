#include <stdio.h>
#include <stdlib.h>
int inp_check_choose();
int inp_check_arrsize();
void inp_check_arrelem(int mass[], int size, int array[]);
void rand_inp_check(int mass[], int size, int array[]);
int shift(int mass[], int size, int array[]);
int main()
{
    int mass[100], array[100];
    int array_size = 0;
    int option = 0;
    array_size = inp_check_arrsize();
    option = inp_check_choose();
    switch (option)
    {
    case 1:
        inp_check_arrelem(mass, array_size, array);
        break;
    case 2:
        rand_inp_check(mass, array_size, array);
        break;
    default:
        return 0;
        break;
    }
    printf(shift(mass, array_size, array));
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
    while (inp>=100 || inp<=0)
    {
        printf("Wrong input. Enter a number from 1 to 100\n");
        scanf_s("%i", &inp);
        rewind(stdin);
    }
    return inp;
}
void inp_check_arrelem(int mass[], int size, int array[])
{
    printf("Enter elements in array 1\n");
    for (int i = 0; i < size; i++)
    {
        while (scanf_s("%d", &mass[i]) == 0)
        {
            printf("Wrong input.\n");
            scanf_s("%i", &mass[i]);
            rewind(stdin);
        }
    }
    printf("Enter elements in array 2\n");
    for (int j = 0; j < size; j++)
    {
        while (scanf_s("%d", &array[j]) == 0)
        {
            printf("Wrong input.\n");
            scanf_s("%i", &array[j]);
            rewind(stdin);
        }
    }
}
void rand_inp_check(int mass[], int size, int array[])
{
    printf("Array 1:\n");
    for (int i = 0; i < size; i++)
    {
        mass[i] = rand();
        printf("The %dth element of array is %d\n", i + 1, mass[i]);
    }
    printf("Array 2:\n");
    for (int j = 0; j < size; j++)
    {
        array[j] = rand();
        printf("The %dth element of array is %d\n", j + 1, array[j]);
    }
}
int shift(int mass[], int size, int array[])
{
    int i = 0;
    if (mass[i] > array[i]) {
        for (i = size - 1; i >= 0; i--) {
            mass[i] = mass[i] + array[i];
            if (mass[i] < 0) {
                mass[i] += 10;
                mass[i - 1] -= 1;
            }
        }
        printf("\nArray: \n");
        for (int i = 0; i < size; i++) {
            printf("%d ", mass[i]);
        }
    }
    else {
        for (i = size - 1; i >= 0; i--) {
            array[i] = array[i] + mass[i];
            if (array[i] < 0) {
                array[i] += 10;
                array[i - 1] -= 1;
            }
        }
        printf("\nArray: \n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
    }
}