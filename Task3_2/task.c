#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Проверка на верно введенные данные
* @return Возвращает ошибку при неудаче, иначе возрващает введенные нами данные
*/
double input(void);

/**
* @brief Функция счета факториала
* @param value - Значение факториал которого надо найти
* @return Возвращает значение факториала
*/
double factorial(double value);

/**
* @brief Функция считает сумму нескольких значений
* @param n - Верхнее значение последовательности
* @param e - Нижнее значение последовательсности
* @return Возвращает значение суммы 
*/
double summ(double n, double e);

/**
* @brief Функция проверяет на 0
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если число 0 или меньше, или значение если все хорошо
*/
double get_above_zero_value(void);

/**
* @brief Точка входа
* @return Возвращает значение функции с кодом ошибки 0
*/
int main(void)
{
	puts("Enter high value and then low value of summ");
	double n = get_above_zero_value(), e = get_above_zero_value(), func;
	func = summ(n,e);
	printf("%lf30\n", func);
	return 0;
}

double summ(double n,double e)
{
	double temporary_value, value = 0;
	for (int i = ceil(e); i < n + 1; i++)
	{
		temporary_value = pow(-1, i - 1) / factorial(2 * i - 1);
		value += temporary_value;
		temporary_value = 0;
	}
	return value;

}

double factorial(double value)
{
	double fact = 1;

	for (int i = 1; i <= value; i++) {
		fact *= i;
	}

	return fact;
}

double input(void) 
{
	double input;
	if (scanf_s("%lf", &input) != 1) 
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double get_above_zero_value(void)
{
	double input_ = input();
	if (input_ <= 0)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input_;
}
