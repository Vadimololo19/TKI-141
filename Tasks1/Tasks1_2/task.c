#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
	puts("Введите значение в байтах");
	double bytes = get_input(), mb = get_mb(bytes), gb = get_gb(bytes);
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
	const double mb_value = 1048576;
	return bytes / mb_value;
}

double get_gb(double bytes)
{
	const double gb_value = 1073741824;
	return bytes / gb_value;
}