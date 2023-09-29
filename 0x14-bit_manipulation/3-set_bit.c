#include "main.h"

/**
 * Peter Anthony Pepple's  Work
 * set_bit - This command or function sets or establishes a bit at a given index to one
 * @n: This parameter refers to the pointer to the number to change
 * @index: This parameter Specifies the  index of the bit to set to one
 *
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
