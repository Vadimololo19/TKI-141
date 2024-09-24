#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция расчета объема
* @param l - значение длины
* @param w - значение ширины
* @param h - значение высоты
* @return Вывод объема
*/
double get_v(double l, double w, double h);

/**
* @brief Функция расчета площади
* @param l - значение длины
* @param w - значение ширины
* @param h - значение высоты
* @return Выводит итоговую площадь
*/
double get_s(double l, double w, double h);

/**
* @brief Функция проверки введенных значений.
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/
double get_input();

/**
* @brief Точка входа в функцию
* @return Возвращает значения объема (v) и площади (s)
*/
int main()
{
	double l = get_input(), w = get_input(), h = get_input();
	double v = get_v(l, w, h);
	double s = get_s(l, w, h);
	printf("V = %lf\nS = %lf", v, s);
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
double get_v(double l, double w, double h)
{
	return l * w * h;
}

double get_s(double l, double h, double w)
{
	double s1 = l * h, s2 = l * w, s3 = h * w;
	return (s1 + s2 + s3) * 2;
}