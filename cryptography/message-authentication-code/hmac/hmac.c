#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include <encoding/hex.h>

int main(void) 
{
    // Generate key from hex string
    size_t key_len;
    char* key_string = "319942bb7cfa570c0c492bf7af990a33c0c3da45dcaa69b3c300cbd5ac03f40a";
    uint8_t* key = hex_string_to_byte_array(key_string, &key_len);      

    // Get data to sign (in general, this would be the message to sign)
    const char *data = "Here we have some data we want to sign!";

    // Allocate memory for the result
    unsigned int len = EVP_MAX_MD_SIZE;
    uint8_t *result = (uint8_t*)malloc(len);

    // Calculate the HMAC
    HMAC(EVP_sha256(), key, key_len, (uint8_t*)data, strlen(data), result, &len);

    // Print the HMAC
    printf("HMAC: %s\n", to_hex_string(result, len));

    // Clean up
    free(result);
    
    return EXIT_SUCCESS;
}

