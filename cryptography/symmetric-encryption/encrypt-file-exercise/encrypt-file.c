#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <encoding/hex.h>

uint8_t* load_binary_file(const char *filename, size_t *size);
uint8_t *encrypt(char *key_string, char *iv_string, uint8_t *data, int data_len, int *ciphertext_len);

int main() 
{
    char *key_string ="9af28734437d8ae34f343d61c682bf2c2a8051644e4323628b277286d3b25617fde17a70ce019ec9f94a12d98f9cc2c8e07b95a93595854e2f31e99fc0fb3476";
    char *iv_string = "91b2da070a7ae4ca44e0915ad6abed8b";    

    // Encrypt the input string
    char *filename = "tux.png";
    size_t bytes_in_file;    
    uint8_t *data = load_binary_file(filename, &bytes_in_file);
    printf("Load: %s [%ld bytes]\n", filename, bytes_in_file);

    int ciphertext_len;
    uint8_t *ciphertext = encrypt(key_string, iv_string, data, bytes_in_file, &ciphertext_len);

     // Print results
    char* hex_ciphertext = to_hex_string(ciphertext, ciphertext_len);
    printf("Encrypted: %s\n", hex_ciphertext);
    // Encrypted: 7732c5224017ae7dd54edbf2f10a5caa94...
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

uint8_t *encrypt(char *key_string, char *iv_string, uint8_t *data, int data_len, int *ciphertext_len)
{
    size_t key_len = strlen(key_string);
    uint8_t* key = hex_string_to_byte_array(key_string, &key_len);      

    size_t iv_len = strlen(key_string);
    uint8_t* iv = hex_string_to_byte_array(key_string, &iv_len);      

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
    free(key);
    free(iv);

    return encrypted;
}
