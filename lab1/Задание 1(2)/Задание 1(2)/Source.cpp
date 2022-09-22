#include<stdio.h>
#include<locale.h>
int main()
{
    setlocale(LC_ALL, "ru");
    double a;
    printf("¬ведите длину ребра - ");
    scanf_s("%lf", &a);
    printf("\nS = %f\n",4 * a * a);
    printf("V = %f\n", a * a * a);
    return 0;
}