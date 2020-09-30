#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

#define LINE_SIZE   32

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    int line[LINE_SIZE];
    int direction;
    size_t i, size;

    if (ac < 3)
    {
        fprintf(stderr, "Usage: %s <R/L> <n1> [n2...]\n", av[0]);
        return (EXIT_FAILURE);
    }

    /* Command line arguments to array of int */
    size = ac - 2;
    if (size > LINE_SIZE)
        size = LINE_SIZE;
    for (i = 0; i < size; i++)
        line[i] = atoi(av[i + 2]);

    /* Print the array */
    print_array(line, size);

    /* Parse direction */
    switch (*(av[1]))
    {
    case 'L':
        direction = SLIDE_LEFT;
        printf("Slide to the left\n");
        break;
    case 'R':
        direction = SLIDE_RIGHT;
        printf("Slide to the right\n");
        break;
    default:
        fprintf(stderr, "Unknown direction '%c'. Please use 'L' or 'R'", *(av[1]));
        return (EXIT_FAILURE);
    }

    /* Slide and merge */
    if (!slide_line(line, size, direction))
    {
        fprintf(stderr, "Failed to slide and merge line\n");
        return (EXIT_FAILURE);
    }

    /* Print the array */
    print_array(line, size);

    return (EXIT_SUCCESS);
}
