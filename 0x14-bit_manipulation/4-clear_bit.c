#include "main.h"

/**
 * By Peter Anthony Pepple
 * clear_bit - this function created, returns the value of a given bit to 0
 * @n: This exist as a pointer to the number to change
 * @index: this is the location or index of the bit to clear
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
