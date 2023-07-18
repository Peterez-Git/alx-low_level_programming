#include <stdio.h>
/**
 * main - A script that prints the sizes of the various data types in C
 *
 * Return: always 0 (success)
 */
int main(void)
{
char k;
int l;
long int m;
long long int n;
float o;

printf("Size of char: %lu byte(s)\n", (unsigned long)sizeof(k));
printf("Size of an int: %lu  byte(s)\n", (unsigned long)sizeof(l));
printf("Size of a long int: %lu  byte(s)\n", (unsigned long)sizeof(m));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(n));
printf("Size of a float: %lu  byte(s)\n", (unsigned long)sizeof(o));
return (0);
}
