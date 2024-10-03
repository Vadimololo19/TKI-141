#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция расчета объема
* @param length - значение длины
* @param width - значение ширины
* @param height - значение высоты
* @return Вывод объема
*/
double get_volume(double length, double width, double height);

/**
* @brief Функция расчета площади
* @param length - значение длины
* @param width - значение ширины
* @param height - значение высоты
* @return Выводит итоговую площадь
*/
double get_surface_area(double length, double width, double height);

/**
* @brief Функция проверки введенных значений.
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/
double input(void);

/**
* @brief Функция проверяет на 0
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если число 0 или меньше, или значение если все хорошо
*/
double get_above_zero_value(void);

/**
* @brief Функция проверки введенного целого числа
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если число не integer
*/
int input_of_integer(void);

enum Choice
{
	Volume = 1,
	SurfaceArea = 2
};

/**
* @brief Точка входа в функцию
* @return Возвращает код ошибки
*/
int main(void)
{
	printf("Enter lenght,width and height of cube\n");
	double length = get_above_zero_value(), width = get_above_zero_value(), height = get_above_zero_value();
	printf("enter the command\n1 - calculate volume of the cube\n2 - calculate surface area of cube\n");
	int command = input_of_integer();
	switch((enum Choice) command)
	{
	case Volume: printf("%lf",get_volume(length, width, height)); break;
	case SurfaceArea: printf("%lf", get_surface_area(length, width, height)); break;
	default: puts("Not command/Input error");
	}
	return 0;
}

int input_of_integer(void)
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
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

double get_volume(double length, double width, double height)
{
	return length * width * height;
}

double get_surface_area(double length, double height, double width)
{
	const double s1 = length * height, s2 = length * width, s3 = height * width;
	return (s1 + s2 + s3) * 2;
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