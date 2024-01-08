#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include <encoding/hex.h>

uint8_t *calculate_fingerprint(char* key_string, uint8_t* data, size_t size, size_t *result_len);

int main(void) 
{
    // Generate key from hex string
    char* key_string = "319942bb7cfa570c0c492bf7af990a33c0c3da45dcaa69b3c300cbd5ac03f40a";

    // Data to sign
    const char *data = "Here we have some data we want to sign!";

    // Calculate the HMAC
    size_t result_len;
    uint8_t *result = calculate_fingerprint(key_string, (uint8_t*) data, strlen(data), &result_len);
    char *result_string = to_hex_string(result, result_len);
    printf("HMAC: %s\n", result_string);

    // Clean up
    free(result);
    free(result_string);

    return EXIT_SUCCESS;
}

uint8_t *calculate_fingerprint(char* key_string, uint8_t* data, size_t size, size_t *result_len)
{
    size_t key_len = strlen(key_string);
    uint8_t* key = hex_string_to_byte_array(key_string, &key_len);      

    uint8_t *result = (uint8_t*)malloc(EVP_MAX_MD_SIZE);
    HMAC(EVP_sha256(), key, key_len, data, size, result, (unsigned int *)result_len);

    free(key);

    return result;
}
