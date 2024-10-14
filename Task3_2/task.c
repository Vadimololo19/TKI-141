#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Функция счета реккурентной функции.
* @param k - Параметр, заданный пользователем.
* @return Возвращает посчитанную функцию при k.
*/
float get_current(int k);

/**
* @brief Функция считает сумму с 1 по n-ный элемент.
* @param n - значение задаваемое пользователем.
* @return Возвращает значение суммы.
*/
float get_sum(float e);

/**
* @brief Функция проверки ввода значения.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
* @return возвращает значение при успешном вводе.
*/
int get_count(void);

/**
* @brief Функция првоерки интервала для части б).
* @param e - нижнее значение интервала.
* @param n - верхнее значение интервала.
* @remarks При неправильной проверке программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
*/
void check_interval(float e, int n);

/**
* @brief Функция проверки на ноль.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
* @return Возрващает значение если без ошибки.
*/
int check_zero_value(void);

/**
* @brief Функция проверка e
* @param e - погрешность для проверки
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
* @return Возвращает e если без ошибки
*/
void check_e(float e);

/**
* @brief Функция счета суммы по n-ому члену
* @param n - переменна заданная пользователем
* @return Фукнция возвращает значение суммы по n-ому члену
*/
float get_sum_n(int n);

/**
* @brief Фукнция счета суммы с погрешностью e
* @param e - погрешность заданная пользователем
* @return Возвращает значение посчитанной функции
*/
float get_count_e(void);

/**
* @brief Функция проверки на ноль.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE.
* @return Возрващает значение если без ошибки.
*/
float check_zero_value_e(void);

/**
* @brief Точка входа.
* @return Возвращает значение функции с кодом ошибки 0.
*/
int main(void)
{
	puts("Enter counts of values.");
	int count = check_zero_value();
	puts("Enter accuracy of calculation.");
	float e = check_zero_value_e();
	check_e(e);
	check_interval(e, count);
	printf("Summ of %d member of the sequence: %f\n", count, get_sum_n(count));
	printf("Summ of member of the sequence with start: %f\n", get_sum(e));
	
	return 0;
}

float get_current(int k)
{
	return (-1.0) / (2 * k * (2 * k + 1));
}
float get_sum(float e)
{
	float current = -(1/6.0);
	float sum = 0;

	for (int i = 1; fabs(current) >= e + DBL_EPSILON; i++) 
	{
		sum += current;
		current *= get_current(i);
	}
	return sum;
}
float get_sum_n(int n)
{
	float current = -(1 / 6.0);
	float sum = current;

	for (int i = 1; i < n; i++)
	{
		current *= get_current(i);
		sum += current;
	}
	return sum;
}
int get_count(void)
{
	int input =0;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}
void check_interval(float e, int n)
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
void check_e(float e)
{
	if (e >= 1 && e <= 0)
	{
		puts("Error of accuracy");
		exit(EXIT_FAILURE);
	}
}
float get_count_e(void)
{
	float input = 0.0;
	if (scanf_s("%f", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}
float check_zero_value_e(void)
{
	float input_ = get_count_e();
	if (input_ <= 0)
	{
		puts("Error Input");
		exit(EXIT_FAILURE);
	}
	return input_;
}