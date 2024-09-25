#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief �������� �� ����� ��������� ������
* @return ���������� ������ ��� �������, ����� ���������� ��������� ���� ������
*/
double get_input();

/**
* @brief ������� ����� ����������
* @param value - �������� ��������� �������� ���� �����
* @return ���������� �������� ����������
*/
double factorial(double value);

/**
* @brief ������� ������� ����� ���������� ��������
* @param n - ������� �������� ������������������
* @param e - ������ �������� �������������������
* @return ���������� �������� ����� 
*/
double summ(double n, double e);

/**
* @brief ����� �����
* @return ���������� �������� ������� � ����� ������ 0
*/
int main()
{
	puts("Enter high value and then low value of summ");
	double x = get_input(), e = get_input(), func;
	func = summ(x,e);
	printf("%lf30\n", func);
	additional_quest();
	return 0;
}

double summ(double n,double e)
{
	double temporary_value, value = 0;
	for (int i = ceil(e); i < n + 1; i++)
	{
		temporary_value = pow(-1, i - 1) / factorial(2 * i - 1);
		value += temporary_value;
		temporary_value = 0;
	}
	return value;

}

double factorial(double value)
{
	double fact = 1;

	for (int i = 1; i <= value; i++) {
		fact *= i;
	}

	return fact;
}

double get_input() 
{
	double input;
	if (scanf_s("%lf", &input) != 1 || input < 0) 
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

int additional_quest()
{
	int first, second, third, four;
	for (int i = 1000; i < 10000; i++)
	{
		first = i / 1000;
		second = i / 100 % 10;
		third = i / 10 % 10;
		four = i % 10;
		if ((first + four == second + third) && (i % 6 == 0) && (i % 27 == 0))
		{
			printf("Additional task = %d\n",i);
		}
	}
}