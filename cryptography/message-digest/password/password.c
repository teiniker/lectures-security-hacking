#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <openssl/rand.h>
#include <openssl/evp.h>

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

void sha256(uint8_t* data, size_t data_len, uint8_t hash_value[32]) 
{
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(ctx, data, data_len);

    unsigned int lengthOfHash = 0;
    EVP_DigestFinal_ex(ctx, hash_value, &lengthOfHash);
    EVP_MD_CTX_free(ctx);
}

void generate_salt(uint8_t salt[16]) 
{
    RAND_bytes(salt, 16); 
}

void create_hashed_password(const char* password, const uint8_t salt[16], uint8_t hash[32]) 
{
    size_t password_len = strlen(password);
    size_t total_len = password_len + 16;

    uint8_t* salted_password = malloc(total_len);

    // Concatenate salt and password
    memcpy(salted_password, salt, 16);
    memcpy(salted_password + 16, password, password_len);

    // Hash the salted password
    sha256(salted_password, total_len, hash);
    free(salted_password);
}


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
