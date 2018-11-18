#include "util.h"

int main(int argc, char **argv)
{
    int fd;
    long count = 0;
    char buf[1024] = {0};
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY, 0);
        count = read(fd, buf, 1024);
        write(1, buf, count);
        close(fd);        
    }
    return 0;
}