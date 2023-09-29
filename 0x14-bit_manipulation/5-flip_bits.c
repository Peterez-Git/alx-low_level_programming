#include "main.h"

/**
 * By Peter Anthony Pepple
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: This variable created represents tht first number
 * @m: while this outer one represents the second number
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
