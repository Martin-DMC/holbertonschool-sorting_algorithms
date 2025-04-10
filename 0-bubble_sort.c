#include "sort.h"
#include <stdio.h>
#include <stddef.h>

/**
 */
void bubble_sort(int *array, size_t size)
{
	int *tmp;
	size_t it = 0, change, loop = 0;

	while (it < (size - loop))
	{
		change = 0;
		while (it <= (size - loop))
		{
			if (array[it] > array[it + 1])
			{
				tmp = array[it];
				array[it] = array[it + 1];
				array[it + 1] = tmp;
				change = 1;
			}
			j++;
		}
		if (change != 0)
			print_array(array, size);
		loop++;
		it++;
	}
}
