#include <unistd.h>
/**
 * main - Entry point of the program
 *
 * Return: Always 1 (error)
 */
int main(void)
{
    const char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    ssize_t len = sizeof("and that piece of art is useful\" - Dora Korpar, 2015-10-19\n") - 1;

    if (write(2, message, len) != len)
        return 1;
    return (1);
}
