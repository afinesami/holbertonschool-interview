#include "sandpiles.h"
/**
 * print_grid2 - prints a grid
 *
 * @grid: grid to print
 * Return: no return
 *
 */
void print_grid2(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * add - sum two grids
 * @grid1: 1st grid to sum
 * @grid2: 2d grid to sum
 * Return: no return
 *
 */
void add(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] +=  grid2[i][j];
	}

}
/**
 * tupple - excecutes one step tupple
 * @grid: grid to analize
 * @tmp: how much to add to grid sandpiles
 * Return: no return
 *
 */
void tupple(int grid[3][3], int tmp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			tmp[i][j] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				tmp[i][j] -= 4;
				if (i + 1 < 3)
					tmp[i + 1][j] += 1;
				if (j + 1 < 3)
					tmp[i][j + 1] += 1;
				if (i - 1 >= 0)
					tmp[i - 1][j] += 1;
				if (j - 1 >= 0)
					tmp[i][j - 1] += 1;
			}
		}
	}
}
/**
 * stable - checks if grid is stable
 * @grid: grid to analize
 * Return: 1 true o false
 *
 *
 */
int stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * sandpiles_sum - add two grids
 * @grid1: 1st grid to add
 * @grid2: 2nd grid to add
 * Return: no return
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int tmp[3][3];

	add(grid1, grid2);
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid2(grid1);
		tupple(grid1, tmp);
		add(grid1, tmp);
	}

}
