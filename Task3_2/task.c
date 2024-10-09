#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Функция счета реккурентной функции
* @param k - Параметр, заданный пользователем
* @return Возвращает посчитанную функцию при k 
*/
float get_current(int k);

/**
* @brief Функция считает сумму с 1 по n-ный элемент
* @param n - значение задаваемое пользователем
* @return Возвращает значение суммы 
*/
float get_sum(int n);

/**
* @brief Функция считает сумму с e-ного элемента по n-ный элемент 
* @param e - нижнее значение
* @param n - верхнее значение
* @return Возвращает значение суммы
*/
float get_sum_e(int e,int n);

/**
* @brief Функция проверки ввода значения
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return возвращает значение при успешном вводе
*/
int get_count(void);

/**
* @brief Функция првоерки интервала для части б)
* @param e - нижнее значение интервала
* @param n - верхнее значение интервала
* @remarks При неправильной проверке программа будет закрыта с кодом ошибки /c EXIT_FAILURE
*/
void check_interval(int e, int n);

/**
* @brief Функция проверки на ноль 
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возрващает значение если без ошибки
*/
int check_zero_value(void);

/**
* @brief Точка входа
* @return Возвращает значение функции с кодом ошибки 0
*/
int main(void)
{
	puts("Enter counts of values.");
	int count = check_zero_value();
	puts("Enter accuracy of calculation.");
	int e = check_zero_value();
	check_interval(e, count);
	printf("Summ of %d member of the sequence: %f\n", count, get_sum(count));
	printf("Summ of member of the sequence with accuracy: %f\n", get_sum_e(e,count));
	
	return 0;
}

float get_current(int k)
{
	return (-1.0) / (2 * k * (2 * k + 1));
}
float get_sum(int n)
{
	float current = -(1/6.0);
	float sum = current;

	for (int i = 1; i < n; i++) 
	{
		current *= get_current(i);
		sum += current;
	}

	return sum;
}
float get_sum_e(int e,int n) 
{
	float current = get_current(e);
	float sum = current;

	for (int i = e; i < n; i++)
	{
		current *= get_current(i);
		sum += current;
	}

	return sum;
}
int get_count(void)
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}
void check_interval(int e, int n)
{
	if (n < e)
	{
		puts("Error of Interval");
		exit(EXIT_FAILURE);
	}
}
int check_zero_value(void)
{
	int input_ = get_count();
	if (input_ <= 0)
	{
		puts("Error Input");
		exit(EXIT_FAILURE);
	}
	return input_;
}
