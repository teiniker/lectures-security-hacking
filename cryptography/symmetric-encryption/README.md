# Symmetric Encryption Using the OpenSSL Library 

The **libcrypto** library within OpenSSL provides functions for performing symmetric 
encryption and decryption operations across a wide range of algorithms and modes. 


## OpenSSL API 

The EVP cipher routines are a high-level interface to certain symmetric ciphers.

* RAND_bytes(key, sizeof(key))\
    Generate cryptographically strong random bytes for the key.     

* EVP_CIPHER_CTX *EVP_CIPHER_CTX_new(void)\
    Creates a cipher context.

    Returns a pointer to a newly created EVP_CIPHER_CTX for success and NULL for failure.


* int EVP_EncryptInit_ex(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type, ENGINE *impl, const unsigned char *key, const unsigned char *iv)\
    Sets up cipher context ctx for encryption with cipher type. 
    * type is typically supplied by calling EVP_CIPHER_fetch().
    * key is the symmetric key to use 
    * iv is the IV to use (if necessary), the actual number of bytes used for the key and IV depends on the cipher. 

* int EVP_DecryptUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl, const unsigned char *in, int inl)\
    Encrypts a portion of the input data (input_string). It can be called multiple times if the data is being read in blocks. The encrypted output is stored in encrypted, and len is updated to the length of the encrypted data.

* int EVP_EncryptFinal_ex(EVP_CIPHER_CTX *ctx, unsigned char *out, int *outl)\
    If padding is enabled (the default) then EVP_EncryptFinal_ex() encrypts the 
    “final” data, that is any data that remains in a partial block. 

    If padding is disabled then EVP_EncryptFinal_ex() will not encrypt any more 
    data and it will return an error if any data remains in a partial block: that 
    is if the total data length is not a multiple of the block size.

    Return 1 for success and 0 for failure.



## References
* [EVP Symmetric Encryption and Decryption](https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption)


* OpenSSL API Documentation
    * [EVP_CIPHER_CTX_new()](https://www.openssl.org/docs/man1.1.1/man3/EVP_CIPHER_CTX_new.html)
    * [EVP_EncryptInit_ex()](https://www.openssl.org/docs/manmaster/man3/EVP_EncryptInit_ex.html)
    * [EVP_DecryptUpdate()](https://www.openssl.org/docs/manmaster/man3/EVP_DecryptUpdate.html)