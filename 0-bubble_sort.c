#include "sort.h"
#include <stdio.h>
#include <stddef.h>
/**
 * bubble_sort - implementa el algoritmo bubble sort para ordenar
 * @array: puntero al array a ordenar
 * @size: tamaño del array a ordenar
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t it = 0, j, change;

	if (array == NULL || size < 2)
		return;
	while (it < (size - 1))
	{
		change = 0;
		j = 0;
		while (j < (size - it - 1))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				change = 1;
				print_array(array, size);
			}
			j++;
		}
		if (change == 0)
			break;
	}
}
