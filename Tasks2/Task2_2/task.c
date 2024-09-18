#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
* @brief Функция проверки введенных значений.
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/

double get_input();

/**
* @brief Точка входа
* @param a - значение константы, данной по задаче
* @param x = значение переменной, заданной пользователем
* @param y - значение функции
*/

int main()
{
	const double a = 0.9;
	double x, y;
	x = get_input();
	if (x > 1)
	{
		y = a * log10(x) + sqrt(fabs(x));
	}
	else
	{
		y = 2 * a * cos(x) + 3 * powl(x, 2);
	}
	printf("Function y = %lf", y);
	return 0;
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