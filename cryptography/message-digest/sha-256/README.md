# Message Digest Using the OpenSSL Library 

**Secure Hash Algorithm 256-bit (SHA-256)** is a cryptographic hash function 
that produces a fixed-size 256-bit (32-byte) hash. 

It's a member of the SHA-2 family, designed by the National Security Agency (NSA) 
and published by the National Institute of Standards and Technology (NIST). 

SHA-256 is widely used in various security applications and protocols, including 
TLS and SSL, PGP, SSH, and IPsec. 

It works by taking an input (or 'message') and producing a fixed-length string, 
which appears random, ensuring data integrity by making it computationally 
infeasible to generate the same hash from two different inputs or to determine 
the original input from the hash.


## OpenSSL API 

Using an OpenSSL message digest/hash function, consists of the following steps:

* Create a Message Digest context
    * `EVP_MD_CTX_new()` is used to create a new digest context.
* Initialise the context by identifying the algorithm to be used (built-in algorithms are defined in evp.h)
    * `EVP_DigestInit_ex()` initializes the digest context for SHA-256.

* Provide the message whose digest needs to be calculated. Messages can be divided into sections and provided over a number of calls to the library if necessary
    * `EVP_DigestUpdate()` is used to hash the data.

* Caclulate the digest
    * `EVP_DigestFinal_ex()` finalizes the digest and retrieves the hash.

* Clean up the context if no longer required
    * `EVP_MD_CTX_free()` is used to free the digest context.

Message digest algorithms are identified using an EVP_MD object. These are built-in to the library and obtained through appropriate library calls (e.g. such as EVP_sha256() or EVP_sha512()).


## References

* [EVP Message Digests](https://wiki.openssl.org/index.php/EVP_Message_Digests)

*Egon Teiniker, 2023, GPL v3.0* 
