#include "search_algos.h"

/**
* find_index - finds the index of the 1st occurrence of a value in an array
*@an_array:    (int*)  sorted array of integers
*@start:       (int)   index indicating the start of the sub-array
*@end:         (int)   index indicating the end of the sub-array
*@val:         (int)   value to be finded
*Return:		pos:	(int)   index where value is located or -1 otherwise
*/

int find_index(int *an_array, size_t start, size_t end, int val)
{
	size_t i, index, pos, len;

	if (start == end)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i < end; i++)
	{
		printf("%d", an_array[i]);
		if (i < end - 1)
			printf(", ");
	}
	printf("\n");

	pos = index = (start + end - 1) / 2;
	len = end - start;

	if (len > 0 && (an_array[index] == val) && (an_array[index - 1] > val))
		pos = index;

	else if ((an_array[index] == val) && (an_array[index - 1] == val))
		pos = find_index(an_array, start, index + 1, val);

	else if (an_array[index] < val)
		pos = find_index(an_array, index + 1, end, val);

	else if (an_array[index] > val)
		pos = find_index(an_array, start, index + 1, val);

	else if (an_array[index] == val)
		pos = index;

	else
		pos = -1;

	return (pos);
}

/**
 * advanced_binary - Finds an item and its position in an sorted array
 * @array:  (int)       Array of elements
 * @size:   (size_t)    Lenght of the array
 * @value:  (int)       value to be located in the array
  * Return:	@pos:    (int)       index position if found or -1 otherwise
 */

int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = (!array || size < 1) ? -1 : find_index(array, 0, size, value);
	return (index);
}
