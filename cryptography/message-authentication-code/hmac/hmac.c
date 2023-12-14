#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

char* to_hex_string(uint8_t *bytes, size_t len);
uint8_t hex_value(char hex_digit);
uint8_t* hex_string_to_byte_array(const char* hex_string, size_t *size);


int main(void) 
{
    // Generate key from hex string
    size_t key_len;
    char* key_string = "219942bb7cfa570c0c492bf7af990a33c0c3da45dcaa69b3c300cbd5ac03f40a";
    uint8_t* key = hex_string_to_byte_array(key_string, &key_len);      

    // Get data to sign (in general, this would be the message to sign)
    const char *data = "Here we have some data wie want to sign.";

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

uint8_t hex_value(char hex_digit) 
{
    if (hex_digit >= '0' && hex_digit <= '9') 
		return hex_digit - '0';
    if (hex_digit >= 'a' && hex_digit <= 'f') 
		return 10 + hex_digit - 'a';
    return 10 + hex_digit - 'A'; // assuming valid input
}

uint8_t* hex_string_to_byte_array(const char* hex_string, size_t *size) 
{
    size_t len = strlen(hex_string);
    *size = len / 2;
    uint8_t* byte_array = malloc(*size);
    
    for (size_t i = 0; i < *size; i++) 
	{
        byte_array[i] = (hex_value(hex_string[i * 2]) << 4) | hex_value(hex_string[i * 2 + 1]);
    }

    return byte_array;
}
