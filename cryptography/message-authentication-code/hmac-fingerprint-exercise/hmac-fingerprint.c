#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#include <encoding/hex.h>

uint8_t *calculate_fingerprint(char* key_string, uint8_t* data, size_t size, size_t *result_len);
uint8_t* load_binary_file(const char *filename, size_t *size); 

int main(void) 
{
    // Generate key from hex string
    char* key_string = "319942bb7cfa570c0c492bf7af990a33c0c3da45dcaa69b3c300cbd5ac03f40a";

    // Load file from filesystem 
    const char *filename = "tux.png";
    size_t bytes_in_file;    
    uint8_t *data = load_binary_file(filename, &bytes_in_file);
    printf("Load: %s [%ld bytes]\n", filename, bytes_in_file);

    // Calculate the HMAC
    size_t result_len;
    uint8_t *result = calculate_fingerprint(key_string, (uint8_t*) data, bytes_in_file, &result_len);
    printf("HMAC: %s\n", to_hex_string(result, result_len));

    // Clean up
    free(result);
    free(data);

    return EXIT_SUCCESS;
}

// TODO: Implement functions here