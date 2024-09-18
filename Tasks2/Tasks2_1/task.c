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

double get_V(double l, double w, double h);

/**
* @brief Функция расчета площади
* @param l - значение длины
* @param w - значение ширины
* @param h - значение высоты
* @return Выводит итоговую площадь
*/

double get_S(double l, double w, double h);

/**
* @brief Функция проверки введенных значений.
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/

double get_input();

int main()
{
	double l, w, h;
	l = get_input();
	w = get_input();
	h = get_input();
	double V = get_V(l, w, h);
	double S = get_S(l, w, h);
	printf("V = %lf\nS = %lf", V, S);
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
double get_V(double l, double w, double h)
{
	double V = l * w * h;
	return V;
}

double get_S(double l, double h, double w)
{
	double S1, S2, S3, S;
	S1 = l * h;
	S2 = l * w;
	S3 = h * w;
	S = (S1 + S2 + S3) * 2;
	return S;
}