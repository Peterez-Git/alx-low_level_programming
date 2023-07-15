#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    write(STDERR_FILENO, message, strlen(message));
    return 1;
}
