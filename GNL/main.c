#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *line;

    // Test edeceğin dosya adını değiştir
    fd = open("char.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    printf("---- Reading file ----\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[0] == '\0')
            printf("[EMPTY LINE]\n");
        else
            printf("%s", line);  // line içinde '\n' varsa yazdır
        free(line);
    }

    close(fd);
    return 0;
}
