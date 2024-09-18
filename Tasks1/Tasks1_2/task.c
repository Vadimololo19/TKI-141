#include <stdio.h>
#include <math.h>
#include "stdlib.h"

/**
* @brief ������� �������� ��������� ������.
* @return ���������� ��������, ���� ����������, ��������� ���������, ���� �����.
*/

double get_input();

/**
* @brief ������� �������� ������ � ���������.
* @params bytes - �����, ������� ���� ������������.
*/
double get_mb(double bytes);
/**
* @brief ������� �������� ������ � ���������.
* @params bytes - �����, ������� ���� ������������.
*/
double get_gb(double bytes);

int main()
{
	double bytes,free_op,mb,gb;
	bytes = get_input();
	mb = get_mb(bytes);
	gb = get_gb(bytes);
	printf("mb = %lf\ngb = %lf", mb,gb);
	return 0;
}

double get_input()
{
	double input;

	if (scanf_s("%lf", &input) != 1) {
		printf("Input error");
		exit(EXIT_FAILURE);
	}

	return input;
}

double get_mb(double bytes)
{
	return bytes / 1048576;
}

double get_gb(double bytes)
{
	return bytes / 1073741824;
}