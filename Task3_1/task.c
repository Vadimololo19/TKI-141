#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief ������� ������� ���� ������� � ��������� �� �� ����������� �����
* @param y - �������� �������
* @return ���������� �������� x � y ���� ����� ���������, x � ������ ���� ������
*/
double get_func(double x_start, double x_fin, double x_step);

/**
* @brief �������� �� ��������� ��������
* @return ���������� ��������, ���� ������, ����� ������
*/
double get_input();

/**
 * @brief ��������� ������������ ��������� � ����.
 * @param xStart ��������� �������� ���������.
 * @param xFinish �������� �������� ���������.
 * @param xStep ��� ���������.
 */
void check_interval(double x_start, double x_fin, double x_step);

/**
* @brief ����� �����; � ����� for ���������� ������� ������ �� 1 �� 2 � ����� 0.1
* @return ���������� �������� ������� � �������� � ����� ������
*/
int main()
{   
    const double x_start = get_input(), x_fin = get_input(), x_step = get_input();
    check_interval(x_start, x_fin, x_step);
    get_func(x_start, x_fin, x_step);
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

