#include <stdio.h>
#include <stdint.h>
#include "main.h"

uint32_t swap_uint32(uint32_t value) {
    return ((value & 0xFF000000) >> 24) |
           ((value & 0x00FF0000) >> 8) |
           ((value & 0x0000FF00) << 8) |
           ((value & 0x000000FF) << 24);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: add-nbo <file1> <file2>\n");
        return 1;
    }

    const char* file1_path = argv[1];
    const char* file2_path = argv[2];

    FILE* file1 = fopen(file1_path, "rb");
    if (file1 == NULL) {
        printf("Failed to open %s\n", file1_path);
        return 1;
    }

    FILE* file2 = fopen(file2_path, "rb");
    if (file2 == NULL) {
        printf("Failed to open %s\n", file2_path);
        fclose(file1);
        return 1;
    }

    uint32_t number1 = swap_uint32(read_uint32(file1));
    uint32_t number2 = swap_uint32(read_uint32(file2));

    fclose(file1);
    fclose(file2);

    uint32_t sum = number1 + number2;

    printf("%u(0x%03x) + %u(0x%03x) = %u(0x%03x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}

