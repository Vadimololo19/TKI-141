#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция для расчета сопротивления соединения.
* @param R1 - значение первого резистора.
* @param R2 - значение второго резистора.
* @param R3 - значение третьего резистора.
* return Рассчет сопротивления всего соединения
*/
double get_r(double R1, double R2, double R3);

/**
* @brief Функция проверки введенных значений.
* @return возвращает 0 и значения, если проверки выполнены, или ошибку, если иначе
*/
double get_input();

/**
* @brief Точка входа
* @return Возвращает результат с кодом ошибки 0
*/
int main()
{
	puts("Enter the value of the three resistors");
	double R1 = get_input(), R2 = get_input(), R3 = get_input();
	double r = get_r(R1, R2, R3);
	printf("Final R = %lf", r);

	return 0;
}

double get_input()
{
	double input;
	if (scanf_s("%lf", &input) != 1 || (input <= 0))
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double get_r(double R1, double R2, double R3)
{
	return R1 + R2 + R3;
}