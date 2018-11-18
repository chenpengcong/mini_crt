#include "util.h"

extern int main(int argc, char **argv);

void mini_crt_entry() 
{
    int argc;
    char **argv;
    int status = 42;
    char* rbp_reg = 0;
    asm("mov %%rbp, %0 \n\t":"=m"(rbp_reg):);
    argc = *((int *)(rbp_reg + 8));
    argv = (char **)(rbp_reg + 16);
    status = main(argc, argv);
    exit(status);
}