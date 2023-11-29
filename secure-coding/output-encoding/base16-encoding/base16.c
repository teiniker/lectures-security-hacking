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
char nibble_to_char(uint8_t nibble)
{
    if(nibble <= 0xf) // 00000000 bis 00001111
    {
        return CHAR_TABLE[nibble];
    }
    else            // default
    {
        return ' ';
    }        
}

char *encode_base16(uint8_t byte)
{
    char *output = malloc(3 * sizeof(char));

    uint8_t lo_bits = byte & 0x0f;
    uint8_t hi_bits = (byte >> 4) & 0x0f;

    output[0] = nibble_to_char(hi_bits);
    output[1] = nibble_to_char(lo_bits);
    output[2] = '\0';

    return output;
}
