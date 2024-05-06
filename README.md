# Project 5: Starting the File System
Initial implementation of the Very, Very Simple File System (VVSFS). Contains the ability to create an image file on disk, as well as functions to read block from and write block to the image file.

## Building
* `make` to build. Creates an executable called `testfs`.
* `make` to build `testfs` and run the tests.
* `make clean` to remove all object files.
* `make pristine` to remove all object files, `libvvsfs.a`, and `testfs`.

VS Code:
* The default build task runs `make`.

## Files
* `testfs.c`: Contains tests that can be run to test file system.
* `image.c`: Contains functions to open/create the image file and close it.
* `block.c`: Contains functions to read and write blocks to the image.

## Functions
* `main()`
    * `test_image_open`: Test opening the image file.
    * `test_bread_bwrite`: Test reading and writing a block.
* `image_open`: Opens the image file from disk.
* `image_close`: Closes the image file.
* `bread`: Reads a block from the image file.
* `bwrite`: Writes a block to the image file.
## Usage
`./testfs`
