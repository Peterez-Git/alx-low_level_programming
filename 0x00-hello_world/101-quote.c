#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - Entry point of the program
 *
 * Return: 1 (indicating program completion)
 */
int main(void)
{
    int stderr_fd = open("/dev/stderr", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (stderr_fd == -1)
        return 1;

    char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    ssize_t len = strlen(message);
    ssize_t bytes_written = write(stderr_fd, message, len);

    close(stderr_fd);

    if (bytes_written != len)
        return 1;

    return 1;
}
