#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> 

char *encode_base16(uint8_t byte);

int main(void)
{
    uint8_t value = 0xce;

    char *hex = encode_base16(value);

    printf("0x%02x: '%s'\n", value, hex);
    assert(strcmp("ce", hex) == 0);
    free(hex);

    return 0;
}

char *CHAR_TABLE = "0123456789abcdef";

// TODO: Implement functions
