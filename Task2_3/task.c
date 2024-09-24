#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Функция проверки введенных значений.
* @return возвращает значение, если выполнено успешно, или ошибку, если иначе
*/
int get_input();

/**
* @brief Точка входа
* @return Возвращает результат врограммы
*/
int main()
{
	int hour;
	for (int i = 0; i < 24; ++i)
	{
		printf("%d\n", i);
	}

	printf("Your hour?\n");

	hour = get_input();
	if (hour >= 0 && hour < 6)
	{
		printf("Good night");
	}
	else if (hour >= 6 && hour < 12)
	{
		printf("Good morning");
	}
	else if (hour >= 12 && hour < 17)
	{
		printf("Good day");
	}
	else if (hour >= 17 && hour <= 23)
	{
		printf("Good evening");
	}
	return 0;
}

int get_input()
{
	int input;
	if (scanf_s("%d", &input) != 1 || (input < 0) || (input >= 24))
	{
		printf("Input error");
		exit(EXIT_FAILURE);
	}
	return input;
}