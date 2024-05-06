#include <string.h>
#include "ctest.h"
#include "image.h"
#include "block.h"

void test_image_open(void)
{
    CTEST_ASSERT(image_open("test_image.txt", 1) != -1, "testing opening image");
}

void test_image_close(void)
{
    CTEST_ASSERT(image_close() != -1, "testing closing image");
}

void test_bread_bwrite(void)
{
    image_open("test_image.txt", 1);

    unsigned char data[2];
    data[0] = (unsigned char)52;
    data[1] = (unsigned char)50;

    bwrite(0, data);

    unsigned char block[BLOCK_SIZE];
    bread(0, block);

    int same_elements = 0;
    for (int i = 0; i < 2; i++)
    {
        if (block[i] == data[i])
        {
            same_elements++;
        }
    }

    CTEST_ASSERT(same_elements == 2, "testing block write");

    image_close();
}

int main(void)
{
    CTEST_VERBOSE(1);

    test_image_open();
    test_image_close();
    test_bread_bwrite();

    CTEST_RESULTS();
    CTEST_EXIT();
}
