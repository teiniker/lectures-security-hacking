# Message Digest Using OpenSSL

The digest functions output the message digest of a supplied file or files in hexadecimal.

To see the list of supported algorithms, use the `list --digest-commands` command.
```
$ openssl list -digest-commands
blake2b512        blake2s256        gost              md4               
md5               rmd160            sha1              sha224            
sha256            sha3-224          sha3-256          sha3-384          
sha3-512          sha384            sha512            sha512-224        
sha512-256        shake128          shake256          sm3   
```

```
$ openssl dgst -sha256 tux.jpg
SHA256(wordlist.txt)= f10d0bd0feaf432600b5910a2a0390a2abb289869428b9a90ac5a46f50409abef
```

## References
* [openssl-dgst](https://www.openssl.org/docs/man1.1.1/man1/openssl-dgst.html)

*Egon Teiniker, 2023, GPL v3.0*  