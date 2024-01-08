#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <openssl/rand.h>

#define NUM_BYTES 16

char* to_hex_string(uint8_t *bytes, size_t len)
{
    char *hex_str = malloc(2 * len + 1);
    char *ptr = hex_str;
    for (size_t i = 0; i < len; i++) 
    {
        sprintf(ptr, "%02x", bytes[i]);
        ptr += 2; 
    }
    return hex_str;
}

int main(void) 
{
    uint8_t buffer[NUM_BYTES];
    RAND_bytes(buffer, NUM_BYTES);

    char *hex_str = to_hex_string(buffer, NUM_BYTES);
    printf("hex: %s\n", hex_str);
    free(hex_str);

    return EXIT_SUCCESS;
}




