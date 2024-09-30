#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция проверки введенных значений.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе.
*/
double input();

/**
* @brief Функция счета функции при условиях.
* @return Вовзращает значение функции если x > 1.
*/
double calculate_x1(double a,double x);

/**
* @brief Функция счета функции при условиях.
* @return Вовзращает значение функции если x <= 1.
*/
double calculate_x2(double a, double x);

/**
* @brief Точка входа.
* @return Возвращает с кодом ошибки.
*/
int main()
{
	const double a = 0.9;
	double x = input(), y;
	if (x > 1)
	{
		y = calculate_x1(a, x);
	}
	else
	{
		y = calculate_x2(a, x);
	}
	printf("Function y = %lf", y);
	return 0;
}

double calculate_x1(double a,double x)
{
	return a * log10(x) + sqrt(fabs(x));
}

double calculate_x2(double a,double x)
{
	return 2 * a * cos(x) + 3 * powl(x, 2);
}

double input()
{
	double input;
	if (scanf_s("%lf", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}