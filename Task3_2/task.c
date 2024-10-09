#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

float get_current(int k);
float get_sum(int n);
float get_sum_e(int e,int n);
int get_count(void);
void check_interval(int e, int n);
int check_zero_value(void);
/**
* @brief Точка входа
* @return Возвращает значение функции с кодом ошибки 0
*/
int main(void)
{
	puts("Enter counts of values.");
	int count = check_zero_value();
	puts("Enter accuracy of calculation.");
	int e = check_zero_value();
	check_interval(e, count);
	printf("Summ of %d member of the sequence: %f\n", count, get_sum(count));
	printf("Summ of member of the sequence with accuracy: %f\n", get_sum_e(e,count));
	
	return 0;
}
//enum and switchcase
// a_k_1 = (-1)/(2*k*(2*k+1)) * a_k where a_k = (-1) / (2 * n * (2 * n + 1)) where n = 1
float get_current(int k)
{
	return (-1.0) / (2 * k * (2 * k + 1));
}
float get_sum(int n)
{
	float current = -(1/6.0);
	float sum = current;

	for (int i = 1; i < n; i++) 
	{
		current *= get_current(i);
		sum += current;
	}

	return sum;
}
float get_sum_e(int e,int n) 
{
	float current = get_current(e);
	float sum = current;

	for (int i = e; i < n; i++)
	{
		current *= get_current(i);
		sum += current;
	}

	return sum;
}
int get_count(void)
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}
void check_interval(int e, int n)
{
	if (n < e)
	{
		puts("Error of Interval");
		exit(EXIT_FAILURE);
	}
}
int check_zero_value(void)
{
	int input_ = get_count();
	if (input_ <= 0)
	{
		puts("Error Input");
		exit(EXIT_FAILURE);
	}
	return input_;
}
