#include "main.h"

uint32_t read_uint32(FILE* file) {
    uint32_t number;
    fread(&number, sizeof(number), 1, file);
    return number;
}

