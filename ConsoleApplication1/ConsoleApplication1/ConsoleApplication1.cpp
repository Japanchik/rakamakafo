#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	FILE* f;
	int m, size;
	int* array;
	printf("Введите количество элементов массива: ");
	scanf("%d", &size);
	printf("\n");
	array = (int*)malloc(size * sizeof(int));
	printf("Массив случайных чисел: 'input.txt'\n");
	f = fopen("input.txt", "a");
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() - rand();
		fprintf(f, "%d ", array[i]);
	}
	fclose(f);
	printf("Отсортированный массив: 'output.txt'\n");
	f = fopen("output.txt", "a");
	time_t start = clock(); //время до сортировки
	long count = 0;
	for (int i = 1; i < size; i++)
	{
		m = array[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[j] < m)
				break;
			array[j + 1] = array[j];
			array[j] = m;
			count++;
		}
	}
	time_t stop = clock(); //время после сортировки
	for (int i = 0; i < size; i++) {
		fprintf(f, "%d ", array[i]);
	}
	fclose(f);
	double time = (stop - start) / 1000.0; //время сортировки
	printf("\n");
	printf("Время выполнения сортировки: ");
	printf("%lf\n", time);
	printf("Количество перестановок: ");
	printf("%o\n", count);
	system("pause");
}