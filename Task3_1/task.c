#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция считает нашу функцию и проверяет ее на возможность счета
* @param y - значение функции
* @return Возвращает значения x и y если можно посчитать, x и ошибку если нельзя
*/
double get_func(double x_start, double x_fin, double x_step);

/**
* @brief Проверка на введенное значение
* @return возрващает значение, если верное, иначе ошибку
*/
double get_input();

/**
 * @brief Проверяет корректность интервала и шага.
 * @param xStart Начальное значение интервала.
 * @param xFinish Конечное значение интервала.
 * @param xStep Шаг интервала.
 */
void check_interval(double x_start, double x_fin, double x_step);

/**
* @brief Функция счета факториала
* @param value - Значение, от которого ищут факториал
* @return Возвращает значение факториала
*/
double factorial(double value);

/**
* @brief Точка входа; в цикле for происходит перебор корней от 1 до 2 с шагом 0.1
* @return Возвращает значение функции с заданным в цикле корнем
*/
int main()
{   
    const double x_start = get_input(), x_fin = get_input(), x_step = get_input();
    double additional_n = get_input();
    check_interval(x_start, x_fin, x_step);
    get_func(x_start, x_fin, x_step);
    printf("additional quest = %lf", factorial(additional_n));
	return 0;
}

void check_interval(double x_start, double x_fin, double x_step) {
    if (x_fin - x_start < x_step) {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
    else if (x_step <= 0) {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}

double get_input() {
    double input;
    if (scanf_s("%lf", &input) != 1) 
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
    return input;
}

double get_func(double x_start,double x_fin,double x_step)
{   
    double y;
    for (double i = x_start; i < x_fin + 0.01; i += x_step)
    {   
        y = 0.1 * powl(i, 2) - i * log(i);
        if (!isnan(y))
        {
            printf("x = %lf y = %lf\n", i, 0.1 * powl(i, 2) - i * log(i));
        }
        else
        {
            printf("x = %lf Not in function\n",i);
        }
    }
}

double factorial(double value)
{
    double fact = 1;

    for (int i = 1; i <= value; i++) {
        fact *= i;
    }

    return fact;
}


