#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

/**
* @brief Функция ввода числа пользователем
* @remarks При несовпадении форматов возвращает ошибку с кодом /c EXIT_FAILURE
*/
int input(void);

/** 
* @brief Функция заполнения матрицы числами пользователя
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица, которую необходимо заполнить
* @remarks Заполняет матрицу числами пользователя
*/
void fill_array_input(int lines, int* columns, int** matrix);

/**
* @brief Функция заполнения матрицы случайными числами
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица, которую необходимо заполнить
* @remarks Заполняет матрицу случайными числами
*/
void fill_array_random(int lines, int* columns, int** matrix);

/**
* @brief Фукнция вывода матрицы
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица со значениями
* @remarks Выводит в консоль матрицу
*/
void output_array(int lines, int* columns, int** matrix);

/**
* @brief Фукнция выполнения задания 1
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица со значениями
* @remarks Выводит матрицу согласно заданию
*/
void task1(int lines, int* columns, int** matrix);

/**
* @brief Фукнция выполнения задания 2
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы первой матрицы
* @param matrix - первая матрица, содержащая значения
* @param columns2 - массив, содержащий столбцы второй матрицы
* @param matrix2 - вторая матрица, содержащая значения, столбцы увеличены вдвое
* @remarks Выводит матрицу согласно заданию
*/
void task2(int lines, int* columns, int** matrix, int* columns2, int** matrix2);

/**
* @brief Функция обертка для заполения матрицы
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица со значениями
* @remarks Дает пользователю выбор как заполнить матрицу
*/
void fill_array(int lines, int* columns, int** matrix);

/**
* @brief Функция нахождения максимального значения в матрице
* @param lines - переменная, содержащая количество линий
* @param columns - массив, содержащий столбцы
* @param matrix - матрица со значениями
* @return Возвращает максимальное значение матрицы
*/
int find_max(int** matrix, int lines, int* columns);

/**
* @brief Фукнция нумератор команд
* @remarks fill_random с кодом 1 - команда заполнения случайными числами
* @remarks fill_input с кодом 2 - команда заполнения числами пользователя
* @remarks defaul - выход с ошибкой
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
    puts("Enter the lines count");
    int lines = input();
    int** matrix = (int**)malloc(lines * sizeof(int*));
    int* columns = (int*)malloc(lines * sizeof(int));

    int** matrix2 = (int**)malloc(lines * sizeof(int*));
    int* columns2 = (int*)malloc((lines*2) * sizeof(int));

    int max = find_max(matrix, lines, columns);
    fill_array(lines, columns, matrix);
    output_array(lines, columns, matrix);
    puts("task1: ");
    fill_array(lines, columns, matrix);
    task1(lines, columns, matrix);
    free(matrix);
    puts("task2: ");
    fill_array(lines, columns, matrix);
    task2(lines, columns, matrix, columns2, matrix2);
    return 0;
}

void fill_array(int lines, int* columns, int** matrix)
{
    puts("Enter command");
    int command = input();
    switch ((enum Task)command)
    {
    case fill_random: fill_array_random(lines, columns, matrix); break;
    case fill_input: fill_array_input(lines, columns, matrix); break;
    default: puts("Command error"); exit(EXIT_FAILURE);
    }
}

void fill_array_random(int lines, int* columns, int** matrix)
{
    for (int i = 0; i < lines; i++)
    {
        printf("Enter a value of columns of %d string: ", i);
        columns[i] = input();
        matrix[i] = (int*)malloc(columns[i] * sizeof(int));
        for (int j = 0; j < columns[i]; j++)
        {
            matrix[i][j] = rand() % ((9 + 1) + 1);
            printf("a[%d][%d]= %d \n", i, j,matrix[i][j]);
        }
    }
}

void fill_array_input(int lines, int* columns,int** matrix)
{
    for (int i = 0; i < lines; i++)
    {
        printf("Enter a value of columns of %d string: ", i);
        columns[i] = input();
        matrix[i] = (int*)malloc(columns[i] * sizeof(int));
        for (int j = 0; j < columns[i]; j++)
        {
            printf("a[%d][%d]= ", i, j);
            matrix[i][j] = input();
        }
    }
}

void output_array(int lines,int* columns,int** matrix)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int input(void)
{
	int input;
	if (scanf_s("%d", &input) != 1)
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}

void task1(int lines, int* columns, int** matrix)
{
    int min = 100;
    int** A = matrix;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            if (min > A[j][i])
            {
                min = A[j][i];
            }
        }
        for (int j = 0; j < columns[i]; j++)
        {
            if (min == A[j][i])
            {
                A[j][i] = 0;
            }
        }
    }
    output_array(lines, columns, A);
}

void task2(int lines,int* columns,int** matrix,int* columns2, int** matrix2)
{
    int** A = matrix;
    int** A_ = matrix2;
    int count = 0;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            count++;
        }
    }
    puts("--------------------------");
    output_array(lines, columns, A);
    for (int n = 0; n < lines; n++)
    {
        columns2[n] = columns[n]*2;
        matrix2[n] = (int*)malloc(columns2[n] * sizeof(int));
        for (int m = 0; m < columns2[n]; m++)
        {
            if (count != 0 && A[n][m] > 0)
            {
                A_[n][m] = A[n][m];
                count -= 1;
            }
            else
            {
                A_[n][m] = 0;
            }
            
        }
    }
    int max = find_max(A_, lines, columns2);
    puts("--------------------------");
    output_array(lines, columns2, A_);
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns2[i]; j++)
        {
            if (A_[i][j] == max)
            {
                for (int k = 0; k < lines; k++)
                {
                    A_[i][lines+k] = A_[lines - 1][k];
                }
            }
        }
    }
    puts("--------------------------");
    output_array(lines, columns2, A_);
}

int find_max(int** arr, int lines, int* columns)
{
    int** A = arr;
    int max = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns[i]; j++)
        {
            if (max < abs(A[i][j]))
            {
                max = A[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    return max;
}