# Open SSL 

OpenSSL is a robust, full-featured open-source toolkit that implements the 
**Secure Sockets Layer (SSL)** and **Transport Layer Security (TLS)** protocols, 
as well as a full-strength general-purpose cryptography library. 

It is written in C and allows developers to secure their applications against 
eavesdropping and tampering.

## Setup

Debian 11.5 (Bullseye) comes with OpenSSL 1.1.1 pre-installed. Therefore, we don't need 
to install it separately. 

We can check the installed version of OpenSSL by running the following command in our 
terminal:

```
$ openssl version
OpenSSL 1.1.1n  15 Mar 2022
```

We can also search for the needed lib files:
```
$ find /usr/lib /usr/local/lib -name libcrypto.*
/usr/lib/x86_64-linux-gnu/libcrypto.so
/usr/lib/x86_64-linux-gnu/libcrypto.a

$ find /usr/lib /usr/local/lib -name libssl.*
/usr/lib/x86_64-linux-gnu/libssl.so
/usr/lib/x86_64-linux-gnu/libssl.a
```

Thus, we can include these paths in our `Makefile`:
```
CC=gcc
CFLAGS=-std=c17 -g -Wall
INCLUDES=-I/usr/include/openssl/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -lssl -lcrypto
...
```

## Cryptographic Algorithms
As for the cryptographic algorithms implemented in OpenSSL, it includes a 
wide range of cryptographic algorithms, such as:

* **Hashing Algorithms**: MD5, SHA-1, SHA-2 (224, 256, 384, 512), SHA-3, and RIPEMD-160.
* **Symmetric Key Algorithms**: AES, DES, 3DES, Blowfish, IDEA, RC2, RC4, RC5, and Camellia.
* **Asymmetric Key Algorithms**: RSA, DSA, and Elliptic Curve (EC).
* **Cryptographic Protocols**: SSL, TLS, DTLS.
* Other: HMAC, CMAC, CSPRNG, PBKDF2, PKCS, and X.509 certificate handling.

Note that some of these algorithms are considered insecure and are included 
for backward compatibility. Always ensure to use the latest and most secure 
algorithms for your applications.

## References

