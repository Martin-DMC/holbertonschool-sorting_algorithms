#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - organiza un array con metodo de seleccion
 * @array: puntero al array
 * @size: tamaño del array
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i = 0, j = 0, index = 0;

	if (array == NULL)
		return;
	while (i < (size - 1))
	{
		index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
			j++;
		}
		if (index != i)
		{
			tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
