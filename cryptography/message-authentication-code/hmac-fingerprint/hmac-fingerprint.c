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
    uint8_t *result = calculate_fingerprint(key_string, data, bytes_in_file, &result_len);
    char *result_string = to_hex_string(result, result_len);
    printf("HMAC: %s\n", result_string);
    free(result_string);
    
    // Clean up
    free(result);
    free(data);

    return EXIT_SUCCESS;
}

uint8_t* load_binary_file(const char *filename, size_t *size) 
{
    FILE *file;
    uint8_t *buffer;

    // Open the file in binary mode
    file = fopen(filename, "rb");
    if (file == NULL) 
    {
        perror("Error opening file");
        return NULL;
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    // Allocate memory for the entire file
    buffer = (uint8_t*)malloc(*size);
    if (buffer == NULL) 
    {
        perror("Memory error");
        fclose(file);
        return NULL;
    }

    // Copy the file into the buffer
    if (fread(buffer, 1, *size, file) != *size) 
    {
        perror("Reading error");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Close the file and return the buffer
    fclose(file);
    return buffer;
}

uint8_t *calculate_fingerprint(char* key_string, uint8_t* data, size_t size, size_t *result_len)
{
    size_t key_len;
    uint8_t* key = hex_string_to_byte_array(key_string, &key_len);      

    uint8_t *result = (uint8_t*)malloc(EVP_MAX_MD_SIZE);
    HMAC(EVP_sha256(), key, key_len, data, size, result, (unsigned int *)result_len);

    free(key);

    return result;
}

