#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
size_t contador (int *arr)
{
	size_t i = 0;

	while (arr[i])
	{
		i++;
	}
	return (i);
}
int maximus (int *arr)
{
	int max = 0;
	int i = 0;

	while (arr[i])
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return (max);
}
int minimus (int *arr)
{
        int min = arr[0];
        int i = 0;

        while (arr[i])
        {
                if (arr[i] < min)
                {
                        min = arr[i];
                }
        }
        return (min);
}
void counting_sort (int *arr, size_t n, int min, int max)
{
	size_t  rango, i, j;
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
	for (i; i >= 0; i--)
	{
		 
	}


}

void main ()
{
	int votos[] = {2, 4, 1, 3, 1, 2, 4, 2, 1, 4};
	int min, max;
	size_t votantes;

	votantes = contador(votos);
	min = minimus(votos);
	max = maximus(votos);

	print_array(votos, votantes);
	printf("\n");
	counting_sort(votos, votantes, min, max);
	printf("\n");
	print_array(votos, votantes);

}
