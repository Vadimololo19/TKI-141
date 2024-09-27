#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** 
* @brief Функкция выбора формулы для счета 
* @param command - Выбор пользователя
* @paran l - длина
* @param w - ширина
* @param h - высота
* return Возвращает итоговое значение
*/
double get_final_value(int command, double l, double w, double h);

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
* @brief Функция проверки команды
* @remarks При неправильном вводе программа будет закрыта с кодом ошибки /c EXIT_FAILURE
* @return Возвращает ошибку если команды нет в списке
*/
double get_check_command();

/**
* @brief Точка входа в функцию
* @return Возвращает код ошибки
*/
int main()
{
	
	printf("enter the command\n1 - calculate volume of the cube\n2 - calculate surface area of cube\n");
	int command = get_check_command();
	printf("Enter lenght,width and height of cube\n");
	double l = get_above_zero_value(), w = get_above_zero_value(), h = get_above_zero_value();
	printf("Your answer = %lf", get_final_value(command, l, w, h));
	return 0;
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

enum Cube
{
	VolumeOfCube = 1,
	SurfaceAreaOfCube = 2
};
double get_final_value(int command,double l,double h, double w)
{
	enum Cube cube = command;
	if (cube == 1)
	{
		return get_volume(l, h, w);
	}
	else if(cube == 2)
	{
		return get_surface_area(l, h, w);
	}
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

double get_check_command()
{
	double input_ = input();
	if ((input_ != 1) ||(input_ != 2))
	{
		printf("No command");
		exit(EXIT_FAILURE);
	}
	return input_;
}
