#include <stdio.h>
#include <math.h>


/**
 * @brief функция для вычисления значения a.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @param z Значение переменной z.
 * @return Результат вычисления a.
*/
double get_a(double x, double y, double z);

/**
 * @brief функция для вычисления значения b.
 * @param x Значение переменной x.
 * @param y Значение переменной y.
 * @param z Значение переменной z.
 * @return Результат вычисления b.
*/
double get_b(double x, double y, double z);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main() {
	const double x = 2.0, y = 0.7, z = -1.0;
	double a = get_a(x, y, z), b = get_b(x, y, z);

	printf("a = %f \nb = %f", a, b);

	return 0;
}
double get_a(double x, double y, double z) {
	return cbrt(x * y * z + fabs(z * sin(y)));
}
double get_b(double x, double y, double z) {
	return y * cos(x * z * sin(y)) + 3;
}