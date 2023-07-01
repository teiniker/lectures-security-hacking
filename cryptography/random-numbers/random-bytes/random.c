#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <openssl/rand.h>

#define NUM_BYTES 16

void print_as_hex_string(uint8_t *hash, size_t len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%02x", hash[i]);
    }
}

int main(void) 
{
    uint8_t buffer[NUM_BYTES];

    if (RAND_bytes(buffer, sizeof(buffer)) != 1) 
    {
        fprintf(stderr, "Error generating random bytes.\n");
        return EXIT_FAILURE;
    }

    printf("Generated %d random bytes: ", NUM_BYTES);
    print_as_hex_string(buffer, NUM_BYTES);
    printf("\n");

    return EXIT_SUCCESS;
}




