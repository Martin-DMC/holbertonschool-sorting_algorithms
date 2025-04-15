#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
int maximus (int *arr, size_t n)
{
	int max = 0;
	size_t i = 0;

	while (i < n)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return (max);
}
int minimus (int *arr, size_t n)
{
        int min = arr[0];
        size_t i = 1;

        while (i < n)
        {
                if (arr[i] < min)
                {
                        min = arr[i];
                }
		i++;
        }
        return (min);
}
void counting_sort (int *arr, size_t n, int min, int max)
{
	size_t  rango, i, j, index;
	int *out;
	int *pizarra;
	int num;

	rango = (max - min) + 1;
	out = (int*) malloc(n * sizeof(int));
	pizarra = (int*) malloc(rango * sizeof(int));
	if (out == NULL || pizarra == NULL)
	{
		printf("Error de memoria. \n");
		return;
	}
	for (i = 0; i < rango; i++)
	{
		pizarra[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		num = arr[i];
		pizarra[num - min]++;
	}
	print_array(pizarra, rango);
	for (j = 1; j < rango; j++)
	{
		pizarra[j] += pizarra[j - 1]; 
	}
	print_array(pizarra, rango);
	for (i = n - 1; ; i--)
	{
		num = arr[i];
		index = pizarra[num - min] - 1;
		out[index] = num;
		pizarra[num - min]--;
		if (i == 0)
			break;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = out[i];
	}

	free(out);
	free(pizarra);
}

void main ()
{
	int votos[] = {2, 4, 1, 3, 1, 2, 4, 2, 1, 4, 6, 9, 8, 6, 5, 8, 7, 9, 5, 4, 7};
	int min, max;
	size_t votantes = sizeof(votos) / sizeof(votos[0]);

	min = minimus(votos, votantes);
	max = maximus(votos, votantes);

	print_array(votos, votantes);
	printf("\n");
	counting_sort(votos, votantes, min, max);
	printf("\n");
	print_array(votos, votantes);

}
