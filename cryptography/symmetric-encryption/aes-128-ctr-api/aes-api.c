#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <encoding/hex.h>


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

uint8_t* decrypt(uint8_t *key, uint8_t *iv, uint8_t *encrypted_data, int encrypted_len, int *plaintext_len)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);

    uint8_t *decrypted = (uint8_t *)malloc(encrypted_len);
    EVP_DecryptUpdate(ctx, decrypted, plaintext_len, encrypted_data, encrypted_len);

    int padding_len;
    EVP_DecryptFinal_ex(ctx, decrypted + *plaintext_len, &padding_len);
    *plaintext_len += padding_len;

    // Clean up the decryption context
    EVP_CIPHER_CTX_free(ctx);

    return decrypted;
}

int main(void) 
{
    // Generate a random key and IV
    uint8_t key[EVP_MAX_KEY_LENGTH];
    uint8_t iv[EVP_MAX_IV_LENGTH];
    RAND_bytes(key, sizeof(key)); 
    RAND_bytes(iv, sizeof(iv));

    // Encrypt the input string
    char *input_string = "This is a test string for encryption";
    int len = strlen(input_string);
    int ciphertext_len;
    uint8_t *ciphertext = encrypt(key, iv, (uint8_t *)input_string, len, &ciphertext_len);

    // Decrypt the encrypted string
    int plaintext_len;
    uint8_t *plaintext = decrypt(key, iv, ciphertext, ciphertext_len, &plaintext_len);

    // Print results
    plaintext[plaintext_len] = '\0';
    char* hex_ciphertext = to_hex_string(ciphertext, ciphertext_len);
    printf("Encrypted: %s\n", hex_ciphertext);
    printf("Decrypted: %s\n", plaintext);

    free(hex_ciphertext);
    free(ciphertext);
    free(plaintext);

    return 0;
}
