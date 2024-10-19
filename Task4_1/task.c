#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* @brief Функция выбора метода заполнения массива пользователем
* @param command - переменная для выбора метода заполнения массива
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param high_value - размер массива
* @remarks при неправильном вводе команды выводит ошибку
*/
void fill_array(const int command, int* array, int low_value, int high_value);

/**
* @brief Функция заполнения массива интервалом, который задал пользователь
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param high_value - размер массива
*/
void fill_by_input(int* array, int low_value, int high_value);

/**
* @brief Функция заполнения массива случайными числами
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param high_value - размер массива
*/
void fill_by_random(int* array, int low_value, int high_value);

/**
* @brief Функция вывода массива
* @param array - массив, задаваемый пользователем
* @param high_value - размер массива
*/
void print_array(int* array, int high_value);

/**
* @brief Функция ввода значения пользователем
* @remarks При несовпадении типов возращает код ошибки /c EXIT_FAILURE
*/
int input(void);

/**
* @brief Функция выполнения задания 1
* @param array - массив, задаваемый пользователем
* @param high_value - размер массива
* @return Возвращает сумму чисел согласно условию
*/
int task1(int* arr, int high_value);

/**
* @brief Функция выполнения задания 2
* @param array - массив, задаваемый пользователем
* @param high_value - размер массива
* @remarks Выводит индексы согласно условию
*/
void task2(int* arr, int high_value);

/**
* @brief Функция выполнения задания 3
* @param array - массив, задаваемый пользователем
* @param high_value - размер массива
* @remarks Выводит измененный массив
*/
void task3(int* arr, int high_value);

/**
* @brief Точка входа
* @return Возвращает код ошибки 0
*/ 
int main()
{
	puts("Enter command, low value, size of array");
	int command = input(), low_value = input(), high_value = input() + 1, *arr;
	arr = (int*)malloc(high_value * sizeof(int));
	if (arr == NULL) 
	{
		printf("Memory input");
		exit(EXIT_FAILURE);
	}
	else 
	{
		fill_array(command, arr, low_value, high_value);
		print_array(arr, high_value);
		printf("task1: %d\n", task1(arr, high_value));
		puts("task2: ");
		task2(arr, high_value);
		task3(arr, high_value);
	}
}

enum Task
{
	fill_random = 1,
	fill_input,
};

void fill_array(const int command, int* array,int low_value,int high_value)
{
	switch ((enum Task)command)
	{
	case fill_random: fill_by_random(array, low_value, high_value); break;
	case fill_input: fill_by_input(array,low_value,high_value); break;
	default: puts("Command error"); break;
	}
}

void fill_by_input(int* array, int low_value, int high_value)
{
	int n = low_value;
	for (int i = 0; i < high_value; i++)
	{
		array[i] = n;
		n++;
	}
}

void fill_by_random(int* array,int low_value, int high_value)
{
	for (int i = 0; i < high_value; i++)
	{
		array[i] = rand() % (high_value-low_value+1) + low_value;
	}
}

int input(void)
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		puts("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

void print_array(int* array, int high_value)
{
	puts("[");
	for (int i = 0; i < high_value; i++)
	{
		printf("%d,", array[i]);
	}
	puts("]");
}

int task1(int* arr,int high_value)
{
	int s = 0;
	for (int i = 0; i < high_value; i++)
	{
		if (abs(arr[i]) < 10)
		{
			s += arr[i];
		}
	}
	return s;
}

void task2(int* arr, int high_value)
{
	for (int i = 0; i < high_value; i++)
	{
		if ((arr[i] > arr[i + 1]) && (i != NULL))
		{
			printf("%d\n", i);
		}
	}
}

void task3(int* arr, int high_value)
{
	for (int i = 0; i < high_value; i++)
	{
		if (arr[i] % 3 == 0)
		{
			arr[i] *= arr[2];
		}
	}
	print_array(arr, high_value);
}