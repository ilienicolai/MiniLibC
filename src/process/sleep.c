#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long rez = syscall(__NR_nanosleep, req, rem);
    if (rez < 0) {
        errno = -rez;
        return -1;
    }
    return 0;
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    nanosleep(&req, &rem);
    return req.tv_sec;      //returnare secunde ramase
}

