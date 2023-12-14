# Generating Psuedo Random Numbers using OpenSSL

The following command line generates a number of random bytes, which can 
either be output raw, as `Base64` or as `HEX`:

```
$ openssl rand -hex 16
f05a4f9bef09d057c355c6e28fec5543

$ openssl rand -base64 16
gokRIzPgvBsnQd5fshD9fg==
```
Parameters:
* **rand**: Generate pseudo-random bytes.
* **-hex**: Show the output as a hex string.
* **-base64**: Perform base64 encoding on the output.
* **-out file**: Write to file instead of standard output.

This command generates random bytes using a **cryptographically secure pseudo random number generator (CSPRNG)**.


## References

* [openssl-rand](https://www.openssl.org/docs/man3.0/man1/openssl-rand.html)


*Egon Teiniker, 2023, GPL v3.0*    