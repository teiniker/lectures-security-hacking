# Message Authentication Code Using the OpenSSL Library 

**Hash-based Message Authentication Code (HMAC)** is a cryptographic technique that 
combines a **secret key** with a message to ensure both **data integrity and authentication**. 

It applies a **hash function** (like SHA-256) to the message and the key in a specific way, 
producing a fixed-size output known as the HMAC value. This value is unique to the combination 
of the message and the key, meaning any change in either will result in a different HMAC. 

HMACs are widely used in various security applications and protocols to verify the authenticity 
and integrity of messages.


## OpenSSL API 

The OpenSSL HMAC function uses the following parameters:
```C
unsigned char *HMAC(const EVP_MD *evp_md, const void *key, int key_len,
                    const unsigned char *data, size_t data_len,
                    unsigned char *md, unsigned int *md_len);
```

* **EVP_MD *evp_md**: This specifies the hash function to be used for the 
    HMAC calculation. In this case, it's SHA-256, a popular cryptographic 
    hash function that produces a 256-bit hash value.

* **void *key**: This is the secret key used for HMAC computation. It should be 
    a sequence of bytes (unit8_t*) and its security is crucial for the 
    HMAC's effectiveness.

* **int key_len**: The length of the key in bytes. This tells the function how 
    many bytes from the key array should be used.
    For HMAC with SHA-256, a key length of 32 bytes (256 bits) is typically 
    recommended. 

* **unsigned char *data**: This is the data for which the HMAC is being calculated. 
    The data is treated as a sequence of bytes.

* **size_t data_len**: The length of the data in bytes. For strings, strlen provides 
    the number of characters up to (but not including) the terminating null byte.

* **unsigned char *md**: A pointer to a buffer where the computed HMAC value will be 
    stored. This buffer should be large enough to hold the output, which 
    for SHA-256 is 32 bytes.

* **unsigned int *md_len**: A pointer to an `unsigned int` that will be set to the length of 
    the computed HMAC. For SHA-256, this will usually be set to 32 bytes.


## References

* [HMAC](https://www.openssl.org/docs/man3.1/man3/HMAC.html)

*Egon Teiniker, 2023, GPL v3.0* 
