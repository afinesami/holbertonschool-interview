#include "sort.h"
/**
 * freegrid - frees a matrix
 * @grid: double poiter to free
 * Return: No return
 */
void freegrid(int **grid)
{
	int i;

	for (i = 0; i < 10; i++)
		free(grid[i]);
	free(grid);
}
/**
 * power_ten- calculates power of 10
 * @power: power to calculate
 * Return: 10**power
 */
int power_ten(int power)
{
	int i, result = 1;

	for (i = 0; i < power; i++)
		result *= 10;
	return (result);
}
/**
 * sort_in_matrix - sort by one digit in a matrix
 * @array: array to sort
 * @tmp: matrix to put the sorted numbers
 * @size: size of arrray
 * @level: digit to apply sortting
 * Return: 0 if the digit is the mostright digit, otherwise 0
 */
int sort_in_matrix(int *array, int **tmp, size_t size, int level)
{
	int n, index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, k, max = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		n = (array[i] % power_ten(level)) / power_ten(level - 1);
		tmp[n][index[n]++] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	k = 0;
	j = 0;
	for (i = 0; i < 10; i++)
	{
		while (index[i] != 0 && k < index[i])
		{
			array[j + k] = tmp[i][k];
			k++;
		}
		j += k;
		k = 0;
	}
	print_array(array, size);

	if (max / power_ten(level) == 0)
		return (0);
	return (1);

}
/**
 * radix_sort - apply radix sort to array
 * @array: array to sort
 * @size: size of the array
 *
 * Return: No return
 */
void radix_sort(int *array, size_t size)
{
	int **tmp, flag = 1, level = 1;
	size_t i;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		tmp[i] = malloc(sizeof(int) * size);
	while (flag)
		flag = sort_in_matrix(array, tmp, size, level++);
	freegrid(tmp);
}
