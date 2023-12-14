#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <openssl/rand.h>
#include <openssl/evp.h>

char* to_hex_string(uint8_t *bytes, size_t len); // Already implemented

void generate_salt(uint8_t salt[16]) ;
void create_hashed_password(const char* password, const uint8_t salt[16], uint8_t hash[32]);


int main(void) 
{
    const char* password = "your_password";
    uint8_t salt[16];
    uint8_t hash[32];

    // Generate the salt
    RAND_bytes(salt, 16);
    char* salt_hex = to_hex_string(salt, 16);
    printf("salt: %s\n", salt_hex);

    create_hashed_password(password, salt, hash);
    char* hex = to_hex_string(hash, 32);
    printf("hash: %s\n", hex);
    free(hex);
    
    // Free the allocated memory 
    free(salt_hex);
    return EXIT_SUCCESS;
}

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

// TODO: Implement functions here