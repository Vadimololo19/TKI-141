#include <stdio.h>
#include <math.h>


/**
 * @brief ������� ��� ���������� �������� a.
 * @param x �������� ���������� x.
 * @param y �������� ���������� y.
 * @param z �������� ���������� z.
 * @return ��������� ���������� a.
*/
double get_a(double x, double y, double z);

/**
 * @brief ������� ��� ���������� �������� b.
 * @param x �������� ���������� x.
 * @param y �������� ���������� y.
 * @param z �������� ���������� z.
 * @return ��������� ���������� b.
*/
double get_b(double x, double y, double z);

/**
 * @brief ����� ����� � ���������.
 * @return ���������� � ������ ������.
*/
int main() {
	const double x = 2.0;
	const double y = 0.7;
	const double z = -1.0;

	double a = get_a(x, y, z);
	double b = get_b(x, y, z);

	printf("a = %f \nb = %f", a, b);

	return 0;
}
double get_a(double x, double y, double z) {
	return cbrt(x * y * z + fabs(z * sin(y)));
}
double get_b(double x, double y, double z) {
	return y * cos(x * z * sin(y)) + 3;
}
