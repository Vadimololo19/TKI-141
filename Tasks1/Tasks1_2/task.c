#include <stdio.h>
#include <math.h>
#include "stdlib.h"

/**
* @brief Функция проверки введенных данных.
* @return Возвращает значение, если правильное, закрывает программу, если иначе.
*/

double get_input();

/**
* @brief Функция перевода байтов в мегабайты.
* @params bytes - байты, которые ввел пользователь.
* @return Возвращает значение в Мегабайтах.
*/
double get_mb(double bytes);
/**
* @brief Функция перевода байтов в гигабайты.
* @params bytes - байты, которые ввел пользователь.
* @return Возвращает значение в Гигабайтах.
*/
double get_gb(double bytes);

int main()
{
	double bytes,free_op,mb,gb;
	bytes = get_input();
	mb = get_mb(bytes);
	gb = get_gb(bytes);
	printf("mb = %lf\ngb = %lf", mb,gb);
	return 0;
}

double get_input()
{
	double input;

	if ((scanf_s("%lf", &input) != 1) || (input <= 0)) {
		printf("Input error");
		exit(EXIT_FAILURE);
	}

	return input;
}

double get_mb(double bytes)
{
	return bytes / 1048576;
}

double get_gb(double bytes)
{
	return bytes / 1073741824;
}