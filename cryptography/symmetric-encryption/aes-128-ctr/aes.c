#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <encoding/hex.h>

int main() 
{
    // Initialize variables
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    char *input_string = "This is a test string for encryption";
    int len = strlen(input_string);
    unsigned char encrypted[len];
    unsigned char decrypted[len];

    // Generate a random key and IV
    RAND_bytes(key, sizeof(key)); 
    RAND_bytes(iv, sizeof(iv));

    // Create and initialize the context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    // Initialize the encryption operation
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);

    // Encrypt the input string
    EVP_EncryptUpdate(ctx, encrypted, &len, (unsigned char*)input_string, len);
   
    int ciphertext_len = len;
    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, encrypted + len, &len);
    ciphertext_len += len;

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);


    // Decrypt the encrypted string
    ctx = EVP_CIPHER_CTX_new();

    EVP_DecryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);

    EVP_DecryptUpdate(ctx, decrypted, &len, encrypted, ciphertext_len);

    int plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);
    plaintext_len += len;

    // Clean up the decryption context
    EVP_CIPHER_CTX_free(ctx);

    // Null-terminate the decrypted string
    decrypted[plaintext_len] = '\0';

    // Print results
    printf("Encrypted: ");
    for (int i = 0; i < ciphertext_len; i++) printf("%02x", encrypted[i]);
    printf("\nDecrypted: %s\n", decrypted);

    return 0;
}
