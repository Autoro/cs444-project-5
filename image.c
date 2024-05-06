#include <fcntl.h>
#include <unistd.h>
#include "image.h"

int image_fd = 0;

int image_open(char* filename, int truncate)
{
    int flags = O_CREAT | O_RDWR;
    if (truncate)
    {
        flags |= O_TRUNC;
    }

    image_fd = open(filename, flags, 0600);

    return image_fd;
}

int image_close(void)
{
    return close(image_fd);
}
