#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void handler(int sig)
{
    if (sig == SIGUSR1) write(1, "1", 1);
    else if (sig == SIGUSR2) write(1, "0", 1);
}

int main(void)
{
    pid_t pid = getpid();
    printf("Server PID: %d\n", pid);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1) pause();
    return 0;
}
