
unsigned int sleep(unsigned int seconds);

typedef long long time_t;
struct timespec {
    time_t tv_sec;
    long long tv_nsec;
};
int nanosleep(const struct timespec *req, struct timespec *rem);
