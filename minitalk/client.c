#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        write(1, "Usage: ./client <PID> <message>\n", 32);
        return 1;
    }
    pid_t pid = (pid_t)atoi(argv[1]);
    char *msg = argv[2];
    while (*msg) {
        for (int i = 7; i >= 0; i--) {
            if ((*msg >> i) & 1) kill(pid, SIGUSR1);
            else kill(pid, SIGUSR2);
            usleep(200);
        }
        msg++;
    }
    return 0;
}
