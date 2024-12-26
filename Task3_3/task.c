#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
* @brief Функция считает сумму с 1 по n-ный элемент.
* @param n - значение задаваемое пользователем.
* @return Возвращает значение суммы.
*/
double get_sum(double low_value, double high_value, double epsilon);

/**
* @brief Функция проверки ввода значения.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
* @return возвращает значение при успешном вводе.
*/
double input(void);

/**
* @brief Высчитывет рекурентую функцию
* @param x - значение аргумента
* @param n - индекс взятого элемента
* @return Возвращает посчитанную рекурентную функцию
*/
double get_current(double x, int n);

/**
* @brief Высчитывает заданную функцию
* @param x - значение аргумента
* @return Возвращает значение функции
*/
double get_function(double x);

/**
* @brief Удобный вывод всех значений
* @param x - значение аргумента
* @param function - значение функции
* @param summ - значение суммы 
*/
void get_output(double x, double function, double summ);

/**
* @brief Функция проверки интервала
* @param low_value - нижнее значение интервала
* @param high_value - верхнее значение интервала
* @remarks завершает с /c EXIT_FAILURE если интервал не удовлетворяет требованиям
* @return возврщает true если выполняется условие
*/
double check_interval(double low_value, double high_value);

/**
* @brief Функция проверки шага
* @param h_step - значение шага
* @remarks завершает с /c EXIT_FAILURE если шаг не удовлетворяет требованиям
* @return возвращает true если выполянется условие
*/
double check_step(double h_step);


int main(void)
{
	double const epsilon = pow(20, -4),low_value = input(), high_value = input(), h_step = input();
	
	double x = low_value;
	while (x <= high_value + DBL_EPSILON)
	{
		get_output(x, get_function(x), get_sum(x,high_value,epsilon));
		x += h_step;
	}

	return 0;
}

void get_output(double x, double function, double summ)
{
	printf("%10.1lf | %15.6lf | %15.6lf\n", x, function, summ);
}

double get_current(double x,int n)
{
	return pow((n+1)/(2*x),-1);
}

double get_sum(double low_value,double high_value, double epsilon)
{
	double current = low_value;
	double sum = 0;
	int n = 0;

	while (current > epsilon - DBL_EPSILON) 
	{
		sum += current;
		current *= get_current(low_value, n);
		n++;
	}

	return sum;
}
double get_function(double x)
{
	return pow(M_E, 2 * x);
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
double check_interval(double low_value, double high_value)
{
	if (high_value - low_value < DBL_EPSILON) {
		printf("Interval error");
		exit(EXIT_FAILURE);
	}
}
double check_step(double h_step)
{
	if (h_step < DBL_EPSILON) 
	{
		printf("Step error");
		exit(EXIT_FAILURE);
	}
}

