#include "main.h"

/**
 * get_bit - this function created returns the value of a bit at an index in a decimal number
 * @n: this parameter is the number to search
 * @index: This parameter represents the index of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
