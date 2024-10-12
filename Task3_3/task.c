#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
* @brief ������� ������� ����� � 1 �� n-��� �������.
* @param n - �������� ���������� �������������.
* @return ���������� �������� �����.
*/
float get_sum(float low_value, float high_value, float epsilon);

/**
* @brief ������� �������� ����� ��������.
* @remarks ��� ������������ ����� ��������� ����� ������� � ����� ������ /c EXIT_FAILURE.
* @return ���������� �������� ��� �������� �����.
*/
float input(void);

/**
* @brief ���������� ���������� �������
* @param x - �������� ���������
* @param n - ������ ������� ��������
* @return ���������� ����������� ����������� �������
*/
float get_current(float x, int n);

/**
* @brief ����������� �������� �������
* @param x - �������� ���������
* @return ���������� �������� �������
*/
float get_function(float x);

/**
* @brief ������� ����� ���� ��������
* @param x - �������� ���������
* @param function - �������� �������
* @param summ - �������� ����� 
*/
void get_output(float x, float function, float summ);

/**
* @brief ������� �������� ���������
* @param low_value - ������ �������� ���������
* @param high_value - ������� �������� ���������
* @remarks ��������� � /c EXIT_FAILURE ���� �������� �� ������������� �����������
* @return ��������� true ���� ����������� �������
*/
float check_interval(float low_value, float high_value);

/**
* @brief ������� �������� ����
* @param h_step - �������� ����
* @remarks ��������� � /c EXIT_FAILURE ���� ��� �� ������������� �����������
* @return ���������� true ���� ����������� �������
*/
float check_step(float h_step);


int main(void)
{
	float const epsilon = pow(20, -4),low_value = input(), high_value = input(), h_step = input();
	
	float x = low_value;
	while (x <= high_value + DBL_EPSILON)
	{
		get_output(x, get_function(x), get_sum(x,high_value,epsilon));
		x += h_step;
	}

	return 0;
}

void get_output(float x, float function, float summ)
{
	printf("%10.1f | %15.6f | %15.6f\n", x, function, summ);
}

float get_current(float x,int n)
{
	return pow((n+1)/(2*x),-1);
}

float get_sum(float low_value,float high_value, float epsilon)
{
	float current = low_value;
	float sum = 0;
	int n = 0;

	while (current > epsilon - DBL_EPSILON) //
	{
		sum += current;
		current *= get_current(low_value, n);
		n++;
	}

	return sum;
}
float get_function(float x)
{
	return pow(M_E, 2 * x);
}
float input(void)
{
	float input;
	if (scanf_s("%f", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}
float check_interval(float low_value, float high_value)
{
	if (high_value - low_value < DBL_EPSILON) {
		printf("Interval error");
		exit(EXIT_FAILURE);
	}
}
float check_step(float h_step)
{
	if (h_step < DBL_EPSILON) 
	{
		printf("Step error");
		exit(EXIT_FAILURE);
	}
}

