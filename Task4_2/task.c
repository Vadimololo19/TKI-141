
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
* @brief Функция выполнения первого задания
* @param arr - массив, задаваемый пользователем
* @param high_value - размер массива
* @remarks Выводит новый массив, нужный по заданию
*/
void task1(int* arr, int high_value);

/**
* @brief Функция выполнения второго задания
* @param arr - массив, задаваемый пользователем
* @param high_value - размер массива
* @remarks Выводит новый массив, нужный по заданию
*/
void task2(int* arr, int high_value);

/**
* @brief Функция удаления элемента из массива
* @param arr - массив, задаваемый пользователем
* @param delte_value - число, которое надо удалить
* @param high_value - размер массива
* @remarks Удаляя значение, уменьшает размер массива
*/
void remove_element(int* array, int delete_value, int high_value);

/**
* @brief Функция выполнения третьего задания
* @param D - массив, задаваемый пользователем
* @param high_value - размер массива
* @remarks Выводит новый массив, нужный по заданию
*/
void task3(int* D, int high_value);

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
		puts("Memory input");
		exit(EXIT_FAILURE);
	}
	else
	{
		fill_array(command, arr, low_value, high_value);
		print_array(arr, high_value);
		task1(arr, high_value);
		task2(arr, high_value);
		task3(arr, high_value);
	}
}

/**
* @brief Выбор исполняемой функции
* @param fill_random - заполнение рандомными числами 
* @param fill_input - заполнение числами пользователя
*/
enum Task
{
	fill_random = 1,
	fill_input,
};

void fill_array(const int command, int* array, int low_value, int high_value)
{
	switch ((enum Task)command)
	{
	case fill_random: fill_by_random(array, low_value, high_value); break;
	case fill_input: fill_by_input(array, low_value, high_value); break;
	default: puts("Command error"); exit(EXIT_FAILURE);
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

void fill_by_random(int* array, int low_value, int high_value)
{
	for (int i = 0; i < high_value; i++)
	{
		array[i] = rand() % (high_value - low_value + 1) + low_value;
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

void task1(int* arr, int high_value)
{
	int* arr_ = arr;
	int min = 100;
	int k = 0;
	for (int i = 0; i < high_value; i++)
	{
		if ((abs(arr_[i]) < min) && (arr_[i] != 0))
		{
			min = abs(arr_[i]);
			k = i;
		}
	}
	arr_[k] = 0;
	print_array(arr_, high_value);
}

void task2(int* arr, int high_value)
{
	int* arr_ = arr;
	for (int i = 0; i < high_value; i++)
	{
		if ((((arr_[i] / 10) % 2 == 0) && ((arr_[i] % 10) % 2 == 0)) && (arr_[i] % 10 > 1))
		{
			remove_element(arr_, i, high_value);
		}
		else if ((arr_[i] % 10 < 1) && (arr_[i] % 2 == 0))
		{
			remove_element(arr_, i, high_value);
		}
	}
	print_array(arr_, high_value);
}

void remove_element(int* array, int delete_value, int high_value)
{
	for (int i = delete_value; i < high_value - 1; ++i)
	{
		array[i] = array[i + 1];
		high_value--;
	}
}

void task3(int* D, int high_value)
{
	int* A = D;
	for (int i = 0; i < high_value; i++)
	{
		if ((i < 3) && (i > 12))
		{
			A[i] = D[i] - 1;
		}
		else
		{
			A[i] = -pow(D[i], 2);
		}
	}
	print_array(A, high_value);
}