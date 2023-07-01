#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <openssl/sha.h>


void print_as_hex_string(uint8_t *hash, size_t len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%02x", hash[i]);
    }
}

int main(void) 
{
    uint8_t data[] = "Hello, World!";
    uint8_t hash[SHA256_DIGEST_LENGTH];
    
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, sizeof(data) - 1);
    SHA256_Final(hash, &sha256);

    print_as_hex_string(hash, SHA256_DIGEST_LENGTH);
    printf("\n");

    return EXIT_SUCCESS;
}