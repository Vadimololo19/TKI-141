#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**
* @brief Функция выбора метода заполнения массива пользователем
* @param command - переменная для выбора метода заполнения массива
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param size_array - размер массива
* @remarks при неправильном вводе команды выводит ошибку
*/
void fill_array(const int command, size_t* array, const size_t low_value, const size_t high_value, const size_t size_array);

/**
* @brief Функция заполнения массива интервалом, который задал пользователь
* @param array - массив, задаваемый пользователем
* @param size_array - размер массива
*/
void fill_by_input(size_t* array, const size_t size_array);

/**
* @brief Функция заполнения массива случайными числами
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param size_array - размер массива
*/
void fill_by_random(size_t* array, const size_t low_value, const size_t high_value, const size_t size_array);

/**
* @brief Функция вывода массива
* @param array - массив, задаваемый пользователем
* @param size_array - размер массива
*/
void print_array(const size_t* array, const size_t size_array);

/**
* @brief Функция ввода значения пользователем
* @remarks При несовпадении типов возращает код ошибки /c EXIT_FAILURE
*/
int input(void);

/**
* @brief Функция проверки введенного значени
* @remarks если значение 0 и меньше возвращает код ошибки /c EXIT_FAILURE
*/
size_t get_above_zero_value(void);

/**
* @brief Функция выполнения задания 1
* @param arr - массив, задаваемый пользователем
* @param size_array - размер массива
* @return Возвращает сумму чисел согласно условию
*/
int task1(const size_t* arr, const size_t size_array);

/**
* @brief Функция выполнения задания 2
* @param arr - массив, задаваемый пользователем
* @param size_array - размер массива
* @remarks Выводит индексы согласно условию
*/
void task2(const size_t* arr, const size_t size_array);

/**
* @brief Функция выполнения задания 3
* @param arr - массив, задаваемый пользователем
* @param size_array - размер массива
* @remarks Выводит измененный массив
*/
void task3(size_t* arr, const size_t size_array);

/**
* @brief Выбор исполняемой функции
* @param fill_random - заполнение случайными числами
* @param fill_input - заполнение числами пользователя
*/
enum Task
{
	fill_random = 1,
	fill_input,
};

/**
* @brief Точка входа
* @return Возвращает код ошибки 0
*/
int main(void)
{
	srand(time(NULL));
	puts("Enter command,size of array, low and high value of array");
	int command = input();
	size_t* arr;
	size_t size_array = get_above_zero_value(), low_value = get_above_zero_value(), high_value = get_above_zero_value();
	arr = (size_t*)malloc(size_array * sizeof(size_t));
	if (arr == NULL)
	{
		printf("Memory input");
		exit(EXIT_FAILURE);
	}
	fill_array(command, arr, low_value, high_value, size_array);
	print_array(arr, size_array);
	printf("task1: %d\n", task1(arr, size_array));
	puts("task2: ");
	task2(arr, size_array);
	puts("task3: ");
	task3(arr, size_array);
	free(arr);

	return 0;
}

void fill_array(const int command, size_t* array, const size_t low_value, const size_t high_value, const size_t size_array)
{
	switch ((enum Task)command)
	{
	case fill_random: fill_by_random(array, low_value, high_value, size_array); break;
	case fill_input: fill_by_input(array, size_array); break;
	default: puts("Command error"); exit(EXIT_FAILURE);
	}
}

void fill_by_input(size_t* array, const size_t size_array)
{
	for (int i = 0; i < size_array; i++)
	{
		array[i] = input();
	}
}

void fill_by_random(size_t* array, const size_t low_value, const size_t high_value, const size_t size_array)
{
	for (int i = 0; i < size_array; i++)
	{
		array[i] = rand() % (high_value - low_value + 1) + low_value;
	}
}

int input(void)
{
	int input = 0;
	if (scanf("%d", &input) != 1)
	{
		puts("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

size_t get_above_zero_value(void)
{
	int input_ = input();
	if (input <= 0)
	{
		puts("Input error");
		exit(EXIT_FAILURE);
	}
	return input_;
}

void print_array(const size_t* array, const size_t size_array)
{
	puts("[");
	for (int i = 0; i < size_array; i++)
	{
		printf("%d,", array[i]);
	}
	puts("]");
}

int task1(const size_t* arr, const size_t size_array)
{
	int s = 0;
	for (int i = 0; i < size_array; i++)
	{
		if (abs(arr[i]) < 10)
		{
			s += arr[i];
		}
	}
	return s;
}

void task2(const size_t* arr, const size_t size_array)
{
	for (int i = 0; i < size_array - 1; i++)
	{
		if ((arr[i] > arr[i + 1]))
		{
			printf("%d\n", i);
		}
	}
}

void task3(size_t* arr, const size_t size_array)
{
	for (int i = 0; i < size_array; i++)
	{
		if (arr[i] % 3 == 0)
		{
			arr[i] *= arr[2];
		}
	}
	print_array(arr, size_array);
}

