#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <openssl/evp.h>

char* to_hex_string(uint8_t *bytes, size_t len);

int main(void) 
{
    uint8_t data[] = "Hello, World!";   
    uint8_t hash[32];  // SHA-256 Hash value length = 32 bytes

    // Calculate hash value: data -> hash
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(ctx, data, sizeof(data));
    unsigned int lengthOfHash = 0;
    EVP_DigestFinal_ex(ctx, hash, &lengthOfHash);
    EVP_MD_CTX_free(ctx);

    char* hash_str = to_hex_string(hash, 32);
    printf("hex: %s\n", hash_str);
    free(hash_str);
    
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
