#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02

long read(int fd, void *buf, long count);
long write(int fd, const void *buf, long count);
int open(const char *pathname, int flags, int mode);
int close(int fd);
void exit(int status);