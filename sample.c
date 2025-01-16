#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    // Ensure the user supplied exactly one command-line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the specified file in binary mode
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", argv[1]);
        return -1;
    }

    // Seek to the end of the file to determine its size
    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Error determining file size.\n");
        fclose(file);
        return -1;
    }

    // Get the file size using ftell()
    long file_size = ftell(file);
    if (file_size == -1) {
        fprintf(stderr, "Error determining file size.\n");
        fclose(file);
        return -1;
    }

    // Close the file
    fclose(file);

    // Print the file size
    printf("%ld\n", file_size);

    return 0;
}

