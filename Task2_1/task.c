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
double get_volume(double l, double w, double h);

/**
* @brief Функция расчета площади
* @param l - значение длины
* @param w - значение ширины
* @param h - значение высоты
* @return Выводит итоговую площадь
*/
double get_surface_area(double l, double w, double h);

/**
* @brief Функция проверки введенных значений.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/
double input();

/**
* @brief Функция проверяет на 0
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если число 0 или меньше, или значение если все хорошо
*/
double get_above_zero_value();

/**
* @brief Функция проверки введенного целого числа
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если число не integer
*/
int input_of_integer();

enum Choice
{
	Volume = 1,
	SurfaceArea = 2
};

/**
* @brief Точка входа в функцию
* @return Возвращает код ошибки
*/
int main()
{
	printf("Enter lenght,width and height of cube\n");
	double l = get_above_zero_value(), w = get_above_zero_value(), h = get_above_zero_value();
	printf("enter the command\n1 - calculate volume of the cube\n2 - calculate surface area of cube\n");
	int command = input_of_integer();
	switch((enum Choice) command)
	{
	case Volume: printf("%lf",get_volume(l, w, h)); break;
	case SurfaceArea: printf("%lf", get_surface_area(l, w, h)); break;
	default: puts("Not command/Input error");
	}
	return 0;
}

int input_of_integer()
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double input()
{
	double input;
	if (scanf_s("%lf", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

double get_volume(double l, double w, double h)
{
	return l * w * h;
}

double get_surface_area(double l, double h, double w)
{
	double s1 = l * h, s2 = l * w, s3 = h * w;
	return (s1 + s2 + s3) * 2;
}

double get_above_zero_value()
{
	double input_ = input();
	if (input_ <= 0)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input_;
}