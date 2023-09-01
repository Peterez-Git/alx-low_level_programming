#include "main.h"

/**
 * Peter Anthony's Pepple's  Work
 * set_bit - This command sets or establishes a bit at a given index to one
 * @n: This refers to the pointer to the number to change
 * @index: Specifies the  index of the bit to set to one
 *
 * Return: positive one for success, negative one  for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
