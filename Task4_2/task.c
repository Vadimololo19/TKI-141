#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/**
* @brief Функция выбора метода заполнения массива пользователем
* @param command - переменная для выбора метода заполнения массива
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param size_array - размер массива
* @remarks при неправильном вводе команды выводит ошибку
*/
void fill_array(const int command, int* array, const int low_value, const int high_value, const size_t size_array);

/**
* @brief Функция заполнения массива интервалом, который задал пользователь
* @param array - массив, задаваемый пользователем
* @param size_array - размер массива
*/
void fill_by_input(int* array, const size_t size_array);

/**
* @brief Функция заполнения массива случайными числами
* @param array - массив, задаваемый пользователем
* @param low_value - начало массива
* @param size_array - размер массива
*/
void fill_by_random(int* array, const int low_value, const int high_value, const size_t size_array);

/**
* @brief Функция вывода массива
* @param array - массив, задаваемый пользователем
* @param size_array - размер массива
*/
void print_array(const int* array, const size_t size_array);

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
* @brief Функция проверки меньшего и большего значений интервала выбора чисел для рандомного заполнения массива
* @param low_value - меньшее значение
* @param high_value - большее значение
* @remarks при непрохождении проверки возвращает код ошибки /c EXIT_FAILURE
*/
void check_interval(const int low_value, const int high_value);

/**
* @brief Функция проверки массива
* @param arr - массив, который мы проверяем на NULL
* @remarks при непрохождении проверки возвращает код ошибки /c EXIT_FAILURE
*/
void check_array(int* const arr);

/**
* @brief Функция перекопирования массива
* @param arr - изачальный массив
* @param size_array - размер массивов
* @return Возвращает массив со значениями изначального массива
*/
int* copy_array(int* const arr, const size_t size_array);

/**
 * @brief Функция создания массива
 * @param size_array - размер создаваемого массива
 * @return возвращает созданный по размеру массив
 */
int* create_array(size_t const size_array);

/**
* @brief Функция выполнения первого задания
* @param arr - массив который мы изменяем
* @param size_arrray - размер нашего массива 
* @remarks Заменяет минимальный положительный элемент по модулю
*/
void task1(int* arr, const size_t size_array);

/**
* @brief Функция выполнения второго задания
* @param arr - массив котороый мы изменяем
* @param size_array - размер нашего массива
* @remarks Удаляет из массива все элементы, первая и последняя цифры которого четные
* @return Возвращает новый размер, по которому мы построим массив, аналогичный измененному по заданию, но без мусора
*/
size_t task2(int* arr, const size_t size_array);

/**
* @brief Функция удаления элемента из массива
* @param arr - массив, который изменяем
* @param size_array - размер нашего массива
* @param delete_value - элемент который мы удаляем
* @remarks удаляет элемент из массива
*/
void remove_element(int* arr, size_t size_array, const size_t delete_value);

/**
* @brief Функция выполнения третьего задания
* @param arr - массив, который мы изменяем
* @param size_array - размер нашего массива
* @remarks Из элементов массива D сформировать массив A той же размерности по правилу: элементы с 3-го по 12-й находятся по формуле Ai = -Di2, остальные по формуле Ai = Di-1
*/
void task3(int* arr, const size_t size_array);

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
	size_t size_array = get_above_zero_value();
	int low_value = input(), high_value = input();
	check_interval(low_value, high_value);
	int* arr = create_array(size_array);
	fill_array(command, arr, low_value, high_value, size_array);
	print_array(arr, size_array);

	int* arr1 = copy_array(arr, size_array), *arr2 = copy_array(arr,size_array), *arr3 = copy_array(arr,size_array);
	task1(arr1, size_array);
	print_array(arr1, size_array);

	size_t new_size = task2(arr2, size_array);
	print_array(arr2, new_size);

	task3(arr3, size_array);
	print_array(arr3, size_array);
	
	free(arr);
	free(arr1);
	free(arr2);
	free(arr3);
	return 0;
}

int* create_array(size_t const size_array)
{
	int* arr = (int*)malloc(size_array * sizeof(int));
	check_array(arr);
	return arr;
}

int* copy_array(int* const arr, const size_t size_array)
{
	int* arr_ = create_array(size_array);
	for (size_t i = 0; i < size_array; i++)
	{
		arr_[i] = arr[i];
	}
	return arr_;
}

void check_array(int* const arr)
{
	if (arr == NULL)
	{
		printf("Memory input");
		exit(EXIT_FAILURE);
	}
}

void check_interval(const int low_value, const int high_value)
{
	if (low_value > high_value)
	{
		puts("Interval error");
		exit(EXIT_FAILURE);
	}
}

void fill_array(const int command, int* array, const int low_value, const int high_value, const size_t size_array)
{
	switch ((enum Task)command)
	{
	case fill_random: fill_by_random(array, low_value, high_value, size_array); break;
	case fill_input: fill_by_input(array, size_array); break;
	default: puts("Command error"); exit(EXIT_FAILURE);
	}
}

void fill_by_input(int* array, const size_t size_array)
{
	for (size_t i = 0; i < size_array; i++)
	{
		array[i] = input();
	}
}

void fill_by_random(int* array, const int low_value, const int high_value, const size_t size_array)
{
	for (size_t i = 0; i < size_array; i++)
	{
		array[i] = rand() % (high_value - low_value + 1) + low_value;
	}
}

int input(void)
{
	int input = 0;
	if (scanf_s("%d", &input) != 1)
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
	return (size_t)input_;
}

void print_array(const int* array, const size_t size_array)
{
	puts("[");
	for (size_t i = 0; i < size_array; i++)
	{
		printf("%d,", array[i]);
	}
	puts("]");
}

void task1(int* arr, const size_t size_array)
{
	int min_index= 0;
	for (size_t i = 0; i < size_array; i++)
	{
		if ((arr[i] < arr[min_index]) && (arr[i] > 0))
		{
			min_index = i;
		}
	}
	arr[min_index] = 0;
}

size_t task2(int* arr, const size_t size_array)
{
	size_t deleted_size = 0;
	for (size_t i = 0; i < size_array; i++)
	{
		if (((arr[i] / 10) % 2 == 0) && (((arr[i] % 10) % 2) == 0) && (arr[i] % 10 > 1))
		{
			remove_element(arr, size_array, i);
			deleted_size += 1;
		}
		else if ((arr[i] % 10 < 1) && (arr[i] % 2 == 0))
		{
			remove_element(arr, size_array, i);
			deleted_size += 1;
		}
	}
	return size_array - deleted_size;
}

void remove_element(int* arr,size_t size_array,const size_t delete_value) 
{
	for (size_t i = delete_value; i < size_array; i++)
	{
		arr[i] = arr[i + 1];
		size_array--;
	}
}

void task3(int* arr, const size_t size_array)
{
	
	for (size_t i = 0; i < size_array; i++)
	{
		if ((i < 3) && (i > 12))
		{
			arr[i] = arr[i] - 1;
		}
		else
		{
			arr[i] = -pow(arr[i], 2);
		}
	}
}