#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <encoding/hex.h>

uint8_t* load_binary_file(const char *filename, size_t *size);
uint8_t *encrypt(uint8_t *key, uint8_t *iv, uint8_t *data, int data_len, int *ciphertext_len);

int main() 
{
    // Generate a random key and IV
    uint8_t key[EVP_MAX_KEY_LENGTH];
    uint8_t iv[EVP_MAX_IV_LENGTH];
    RAND_bytes(key, sizeof(key)); 
    RAND_bytes(iv, sizeof(iv));
    

    // Encrypt the input string
    char *filename = "tux.png";
    size_t bytes_in_file;    
    uint8_t *data = load_binary_file(filename, &bytes_in_file);
    printf("Load: %s [%ld bytes]\n", filename, bytes_in_file);

    int ciphertext_len;
    uint8_t *ciphertext = encrypt(key, iv, data, bytes_in_file, &ciphertext_len);

     // Print results
    char* hex_ciphertext = to_hex_string(ciphertext, ciphertext_len);
    printf("Encrypted: %s\n", hex_ciphertext);
    free(hex_ciphertext);
    free(ciphertext);
    free(data);

    return 0;
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

uint8_t *encrypt(uint8_t *key, uint8_t *iv, uint8_t *data, int data_len, int *ciphertext_len)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);

    // Encrypt the input string
    uint8_t *encrypted = (uint8_t *)malloc(data_len);
    EVP_EncryptUpdate(ctx, encrypted, ciphertext_len, data, data_len);
   
    // Finalize the encryption
    int padding_len;
    EVP_EncryptFinal_ex(ctx, encrypted + *ciphertext_len, &padding_len);
    *ciphertext_len += padding_len;

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);

    return encrypted;
}
