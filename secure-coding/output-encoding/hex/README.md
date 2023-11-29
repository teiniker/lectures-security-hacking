# Hex Encoding 

# Using the Bash

We have to install the following package:

```
$ sudo apt install xxd 
```
xxd creates a hex dump of a given file or standard input.  
It can also convert a hex dump back to its original binary form. 


```
$ echo "Security&Hacking" | xxd -p
5365637572697479264861636b696e670a
```

```
$ echo "5365637572697479264861636b696e670a" | xxd -r -p
Security&Hacking
```


## References

* [Hex Encode and Decode in C](https://nachtimwald.com/2017/09/24/hex-encode-and-decode-in-c/)

