#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * heap_sort -  sorts an array of integers in ascending order
 *
 * @array: array of integers
 * @size: long array
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t heapsize = size;

	set_max_heap(array, size);
	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[0], &array[i]);
		heapsize--;
		sift_down(array, 0, heapsize);
	}
}

/**
 * set_max_heap - builds a heap from a list in O(n) operations
 *
 * @array: array of integers
 * @size: long array
 *
 */
void set_max_heap(int *array, size_t size)
{
	int i;

	for (i = size / 2; i >= 0; i--)
	{
		sift_down(array, i, size);
	}
}

/**
 * sift_down - to sift the new first element to its
 * appropriate index in the heap.
 *
 * @array: array of integers
 * @i: long array
 * @heapsize: integer
 *
 */
void sift_down(int *array, size_t i, size_t heapsize)
{
	size_t n = sizeof(array) + 2;
	size_t c = 2 * i + 1;

	if (c >= heapsize)
	{
		return;
	}

	if ((c + 1 < heapsize) && collate(array[c + 1], array[c]) > 0)
	{
		c++;
	}

	if (collate(array[c], array[i]) > 0)
	{
		swap(&array[c], &array[i]);
		print_array(array, n);
		sift_down(array, c, heapsize);
	}
}

/**
 * swap - the first element of the list with the final element.
 * Decrease the considered range of the list by one.
 *
 * @a: integer
 * @b: integer
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * collate - if child is larger than i, swap positions.
 *
 * @a: integer
 * @b: integer
 * Return: integer
 *
 */
int collate(int a, int b)
{
	if (a > b)
	{
		return (1);
	}
	else if (a < b)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
