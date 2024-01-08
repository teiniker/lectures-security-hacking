## AES-128 CTR Mode

This C program demonstrates the use of OpenSSL for symmetric encryption and decryption 
using the AES-128-CTR (Counter Mode) algorithm.

The code provides a clear example of symmetric encryption and decryption using OpenSSL's 
EVP interface, which is designed to provide a high-level abstraction for cryptographic 
operations. 

The use of AES in CTR mode provides secure encryption, and the use of random keys and 
IVs for each operation is a best practice for security.


## Encryption

Let's break down the OpenSSL functions used for encryption:

* **RAND_bytes()**
    ```C++
    RAND_bytes(key, sizeof(key)); 
    RAND_bytes(iv, sizeof(iv));
    ```
    These calls generate cryptographically strong random bytes for the key and initialization 
    vector (IV). In AES-CTR, the IV is commonly referred to as the nonce. It's crucial for 
    security that these are random and unique for each encryption operation.

* **EVP_CIPHER_CTX_new()**
    ```C++
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    ```
    This function allocates a new EVP_CIPHER_CTX, which is a generic cipher context used 
    for encryption or decryption. It's part of OpenSSL's high-level EVP (Envelope) interface.

* **EVP_EncryptInit_ex()**
    ```C++
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);
    ```
    This initializes the cipher context ctx for encryption with the AES-128-CTR cipher. 
    It sets up the key and IV for the encryption operation. 
    EVP_aes_128_ctr() specifies the cipher.

* **EVP_EncryptUpdate()**
    ```C++
    EVP_EncryptUpdate(ctx, encrypted, &len, (unsigned char*)input_string, len);
    ```
    This function encrypts a portion of the input data (input_string). It can be 
    called multiple times if the data is being read in blocks. 
    
    The encrypted output is stored in encrypted, and len is updated to the length of 
    the encrypted data.

* **EVP_EncryptFinal_ex()**
    ```C++
    EVP_EncryptFinal_ex(ctx, encrypted + len, &len);
    ```
    Finalizes the encryption. Any remaining ciphertext is written at the end of the 
    encrypted array. It's important for block ciphers in modes like CBC, but in CTR mode, 
    it might not be necessary. However, it's still good practice to call it.


* **EVP_CIPHER_CTX_free()**
    ```C++
    EVP_CIPHER_CTX_free(ctx);
    ```
    Cleans up and frees the EVP_CIPHER_CTX object. It's crucial to avoid memory leaks.


## Decryption

Let's break down the OpenSSL functions used for decryption:

* **EVP_DecryptInit_ex(), EVP_DecryptUpdate(), EVP_DecryptFinal_ex()**
    ```C++
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ctr(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decrypted, &len, encrypted, ciphertext_len);
    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);
    ```
    These functions are analogous to their encryption counterparts but are used 
    for decryption. They initialize the context for decryption, decrypt the data, 
    and finalize the decryption, respectively.

* **Null-Terminating the Decrypted String**
    ```C++
    decrypted[plaintext_len] = '\0';
    ```
    Since the decrypted data might not be null-terminated and is treated as a 
    string in the printf statement, this line ensures proper null-termination.


## References

* [Encrypting/Decrypting a file using OpenSSL EVP](https://medium.com/@amit.kulkarni/encrypting-decrypting-a-file-using-openssl-evp-b26e0e4d28d4)

*Egon Teiniker, 2023-2024, GPL v3.0* 