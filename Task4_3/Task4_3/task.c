#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
* @brief Функция ввода целого числа.
* @return целое число.
*/
int input(void);

/**
* @brief Функция выделения памяти.
* @param rows значение параметра rows.
* @param column значение параметра column.
* @return массив.
*/
int** create_array(const size_t rows, const size_t column);

/**
* @brief Функция копирования массива.
* @param array передаёт массив array.
* @param rows значение параметра rows.
* @param column значение параметра column.
* @return массив.
*/
int** copy_array(const int** array, const size_t rows, const size_t column);

/**
* @brief Функция проверки массива на пустоту.
* @param arr указатель на массив.
*/
void check_array(const int** arr);

/**
* @brief Функция заполнения массива случайными числами.
* @param array передаёт массив array.
* @param rows значение параметра rows.
* @param column значение параметра column.
*/
void fill_random(int** array, const size_t rows, const size_t column);

/**
* @brief Функция заполнения массива вводимыми числами.
* @param array передаёт массив array.
* @param rows значение параметра rows.
* @param column значение параметра column.
*/
void fill_input(int** array, const size_t rows, const size_t column);

/**
* @brief Функция-нумератор.
* @param input вызов функции ввода.
* @param random вызов функции заполнения.
*/
enum Task
{
    user_input = 1,
    random_input,
};

/**
* @brief Функция вывода массива.
* @param array передаёт массив.
* @param rows количество строк.
* @param column количество столбцов.
*/
void print_array(int** array, const size_t rows, const size_t column);

/**
* @brief Функция заполнения массива
* @param command - переменная команды заданной пользователем
* @param array - наш массив
* @param rows - строки массива
* @param column - столбцы массива
*/
void fill_array(const int command, int** array, const size_t rows, const size_t column);

/**
* @brief Функция выполнения задания 1
* @param array_copy - копия массива для безопасного взаимодейтсвия 
* @param rows - строки массива
* @param column - столбцы массива
* @remarksВыполняет заданеи 1
*/
void task1(int** array_copy, const size_t rows, const size_t column);

/**
* @brief Функция нахождения максимального значения в массиве
* @param array - наш массив
* @param rows - строки массива
* @param column - столбцы массива
* return возвращает максимальное значение в массиве
*/
int find_max(int** array, const size_t rows, const size_t column);

/**
* @brief Функция выполнения задания 2
* @param array - исходный массив
* @param rows - строки исходного массива
* @param column - столбцы исходного массива
* @param array2 - новый расширенный массив
* @param column2 - рассширенное кол-во столбцов
* @param max - максимальное значение из массива
* @param actual_rows - фактическое количество строк
* @remarks Выполняет задание 2
*/
void task2(int** array, const size_t rows, const size_t column, int** array2, const size_t column2, const int max, size_t* actual_rows);

/**
* @brief Функция полной чистки массива
* @param array - наш массив
* @param rows - строки массива
*/
void free_array(int** array, const size_t rows);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void)
{
    puts("Rows:");
    const size_t rows = input();
    puts("Column:");
    const size_t column = input();
    puts("1 for user input, 2 for random input");
    const int command = input();

    int** array = create_array(rows, column);
    fill_array(command, array, rows, column);
    print_array(array, rows, column);

    puts("Task1");
    int** array_copy1 = copy_array(array, rows, column);
    task1(array_copy1, rows, column);
    print_array(array_copy1, rows, column);
    free(array_copy1);

    puts("Task2");
    const int max = find_max(array, rows, column);
    const size_t column2 = column; 
    int** array2 = create_array(rows * 2, column2); 
    size_t actual_rows = 0; 
    task2(array, rows, column, array2, column2, max, &actual_rows);
    print_array(array2, actual_rows, column2);

    free_array(array, rows);
    free(array);
    free_array(array2, actual_rows);
    free(array2);

    return 0;
}

void free_array(int** array,const size_t rows)
{
    for (size_t i = 0; i < rows; i++) 
    {
        free(array[i]);
    }
}

void fill_array(const int command, int** array, const size_t rows, const size_t column)
{
    switch ((enum Task)command)
    {
    case user_input: fill_input(array, rows, column); break;
    case random_input: fill_random(array, rows, column); break;
    default: printf("Incorrect value"); exit(EXIT_FAILURE);
    }
}

int input()
{
    int input = 0;
    if (scanf_s("%d", &input) != 1)
    {
        printf("Incorrect value");
        exit(EXIT_FAILURE);
    }
    return input;
}

int** create_array(const size_t rows, const size_t column)
{
    int** array = (int**)malloc(sizeof(int*) * rows);
    for (size_t i = 0; i < rows; i++)
    {
        array[i] = (int*)malloc(sizeof(int) * column);
    }
    check_array(array);
    return array;
}

int** copy_array(const int** array, const size_t rows, const size_t column)
{
    check_array(array);
    int** array_copy = (int**)malloc(sizeof(int*) * rows);
    for (size_t i = 0; i < rows; i++)
    {
        array_copy[i] = (int*)malloc(sizeof(int) * column);
    }
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            array_copy[x][y] = array[x][y];
        }
    }
    check_array(array_copy);
    return array_copy;
}

void check_array(const int** arr)
{
    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(EXIT_FAILURE);
    }
}

void fill_random(int** array, const size_t rows, const size_t column)
{
    srand(time(NULL));
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            array[x][y] = rand() % 100;
        }
    }
}

void fill_input(int** array, const size_t rows, const size_t column)
{
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            array[x][y] = input();
        }
    }
}

void print_array(int** array, const size_t rows, const size_t column)
{
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }
}

void task1(int** array_copy, const size_t rows, const size_t columns)
{
    for (size_t y = 0; y < columns; y++)
    {
        int min = INT_MAX;
        size_t min_row = 0;
        for (size_t x = 0; x < rows; x++)
        {
            if (array_copy[x][y] < min)
            {
                min = array_copy[x][y];
                min_row = x;
            }
        }
        array_copy[min_row][y] = 0;
    }
}

int find_max(int** array, const size_t rows, const size_t column)
{
    int max = array[0][0];
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            if (abs(array[x][y]) >= abs(max))
            {
                max = array[x][y];
            }
        }
    }
    return max;
}

void task2(int** array, const size_t rows, const size_t column, int** array2, const size_t column2, const int max, size_t* actual_rows)
{
    size_t new_row = 0;
    for (size_t x = 0; x < rows; x++)
    {
        for (size_t y = 0; y < column; y++)
        {
            array2[new_row][y] = array[x][y];
        }
        new_row++;
        for (size_t y = 0; y < column; y++)
        {
            if (abs(array[x][y]) == abs(max))
            {
                for (size_t z = 0; z < column; z++)
                {
                    array2[new_row][z] = array[rows - 1][z];
                }
                new_row++;
                break; 
            }
        }
    }
    *actual_rows = new_row; 
}