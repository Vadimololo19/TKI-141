#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>

/**
* @brief Функция считает нашу функцию 
* @param x - значение аргумента
* @return Возвращает значения функции
*/
float get_equation(float x);

/**
 * @brief Проверяет, можно ли вычислить функцию для заданного значения x.
 * @param x Значение x, которое требуется проверить.
 * @return true, если функцию можно вычислить для данного значения x, false в противном случае.
 */
bool get_check_x(float x);

/**
* @brief Проверка на введенное значение
* @return возрващает значение, если верное, иначе ошибку
*/
float input();

/**
 * @brief Проверяет корректность интервала.
 * @param x_start Начальное значение интервала.
 * @param x_fin Конечное значение интервала.
 * @return Возвращет ошибку если интервао задан неверно
 */
void check_interval(const float x_start, const float x_fin);

/**
* @brief Проверяет коррекность шага
* @param x_step Значение шага
* @return Возвращает ошибку если шаг задан неверно
*/
void check_step(const float x_step);

/**
* @brief Точка входа
* @return Возвращает значение функции с заданным в цикле корнем
*/
int main()
{   
    const float x_start = input(), x_fin = input(), x_step = input();
    check_interval(x_start, x_fin);
    check_step(x_step);
    float x = x_start;

    while (x <= x_fin + DBL_EPSILON) {
        if (!get_check_x(x_start)) {
            printf("X not in function %.2f\n", x);
        }
        else {
            printf("x = %f y = %f\n", x, get_equation(x));
        }
        x += x_step;
    }

	return 0;
}

bool get_check_x(float x) 
{
    return x > 0;
}

void check_interval(const float x_start, const float x_fin)
{
    if (x_fin - x_start < DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}
void check_step(const float x_step)
{
    if (x_step <= DBL_EPSILON)
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
}

float input() {
    float input;
    if (scanf_s("%f", &input) != 1) 
    {
        puts("Input error");
        exit(EXIT_FAILURE);
    }
    return input;
}

float get_equation(float x)
{   
    return 0.1 * pow(x, 2) - x * log(x);
}



