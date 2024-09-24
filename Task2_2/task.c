#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция проверки введенных значений.
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе.
*/
double get_input();

/**
* @brief Функция счета функции при условиях.
* @return Вовзращает значение функции при x > 1 или x <= 1.
*/
double get_function(double a, double x);

/**
* @brief Точка входа.
* @param y - значение функции.
*/
int main()
{
	const double a = 0.9;
	double x = get_input(), y = get_function(a, x);
	printf("Function y = %lf", y);
	return 0;
}

double get_function(double a, double x)
{
	if (x > 1)
	{
		return a * log10(x) + sqrt(fabs(x));
	}
	else
	{
		return 2 * a * cos(x) + 3 * powl(x, 2);
	}
}

double get_input()
{
	double input;
	if (scanf_s("%lf", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}