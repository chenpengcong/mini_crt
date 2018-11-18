#include "util.h"
long read(int fd, void *buf, long count)
{
    long ret;
    asm("movq $0, %%rax \n\t"
        "movq %1, %%rdi \n\t"
        "movq %2, %%rsi \n\t"
        "movq %3, %%rdx \n\t"
        "syscall \n\t"
        "movq %%rax, %0 \n\t"
        :"=m"(ret)
        :"m"(fd),"m"(buf),"m"(count)
        :"rax", "rdi", "rsi", "rdx");
    return ret; 
}

long write(int fd, const void *buf, long count)
{
    long ret;
    asm("movq $1, %%rax \n\t"
        "movq %1, %%rdi \n\t"
        "movq %2, %%rsi \n\t"
        "movq %3, %%rdx \n\t"
        "syscall \n\t"
        "movq %%rax, %0 \n\t"
        :"=m"(ret)
        :"m"(fd),"m"(buf),"m"(count)
        :"rax", "rdi", "rsi", "rdx");
    return ret; 
}

int open(const char *pathname, int flags, int mode)
{
    long fd;
    asm("movq $2, %%rax \n\t"
        "movq %1, %%rdi \n\t"
        "movq %2, %%rsi \n\t"
        "movq %3, %%rdx \n\t"
        "syscall \n\t"
        "movq %%rax, %0 \n\t"
        :"=m"(fd)
        :"m"(pathname),"m"(flags),"m"(mode)
        :"rax", "rdi", "rsi", "rdx");
    return fd; 
}

int close(int fd)
{
    long ret;
    asm("movq $3, %%rax \n\t"
        "movq %1, %%rdi \n\t"
        "syscall \n\t"
        "movq %%rax, %0 \n\t"
        :"=m"(ret)
        :"m"(fd)
        :"rax", "rdi");
    return ret;  
}

void exit(int status)
{
    asm("movq $60, %%rax \n\t"
        "movq %0, %%rdi \n\t"    
        "syscall \n\t"
        :
        :"m"(status));
}