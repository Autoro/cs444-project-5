#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "block.h"

const int BLOCK_SIZE = 4096;

void set_image_pos(int block_num)
{
    int offset = BLOCK_SIZE * block_num;
    int result = lseek(image_fd, offset, SEEK_SET);
    if (result == -1)
    {
        perror("lseek");
        exit(1);
    }
}

unsigned char* bread(int block_num, unsigned char* block)
{
    set_image_pos(block_num);
    read(image_fd, block, BLOCK_SIZE);

    return block;
}

void bwrite(int block_num, unsigned char* block)
{
    set_image_pos(block_num);
    write(image_fd, block, BLOCK_SIZE);
}
