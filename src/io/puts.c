#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int puts(const char *s){
    if (write(1, s, strlen(s)) == -1)
        return 0;
    if (write(1, "\n", 1) == -1)
        return 0;
    return 1;
}
