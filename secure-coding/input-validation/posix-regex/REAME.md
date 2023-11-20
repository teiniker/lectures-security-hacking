# Regular Expressions in C 

The C standard library does not include a regular expression library by default, 
unlike some other languages. 
However, **POSIX (Portable Operating System Interface)** compliant systems, like Unix, 
Linux, and macOS, include regular expression capabilities in their libraries.

_Example_: Validate a given mail address
```C
int main() 
{
    char *input = "example@example.com";
    char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    // Compile the regular expression
    regex_t regex;
    int ret = regcomp(&regex, pattern, REG_EXTENDED);

    // Execute the regular expression
    ret = regexec(&regex, input, 0, NULL, 0);
    if(ret) 
    {
        return 1; // Invalid mail address
    }     
    printf("Valid mail address: %s\n", input);

    // Free the compiled regular expression
    regfree(&regex);
    return 0;
}
``` 

This program does the following:

* **Compile the Regular Expression**: `regcomp()` is used to compile the regular expression. 
    `REG_EXTENDED`` is a flag for extended regular expressions.

* **Execute the Regular Expression**: `regexec()` checks if the regular expression matches 
    the input string.

* **Memory Management**: It's important to free the compiled regular expression using 
    `regfree()` to avoid memory leaks.

## Regex API

In order to use the POSIX regex API you must include the `regex.h` header file.

* `int regcomp(regex_t *restrict preg, const char *restrict regex, int cflags)`\
    This function is used to compile a regular expression into a form
    that is suitable for subsequent `regexec()` searches.

* `int regexec(const regex_t *restrict preg, const char *restrict string,
                   size_t nmatch, regmatch_t pmatch[restrict .nmatch],
                   int eflags)`\
    This function is used to match a null-terminated string against the
    precompiled pattern `preg`.  `nmatch` and `pmatch` are used to
    provide information regarding the location of any matches.

* `size_t regerror(int errcode, const regex_t *restrict preg,
                   char errbuf[restrict .errbuf_size], size_t errbuf_size)`\
    This function is used to turn the error codes that can be returned
    by both `regcomp()` and `regexec()` into error message strings.

* `void regfree(regex_t *preg)`\
    Supplying `regfree()`` with a precompiled pattern buffer, preg, will
       free the memory allocated to the pattern buffer by the compiling
       process.

## References

* [regex — Linux manual page](https://man7.org/linux/man-pages/man3/regex.3.html)

*Egon Teiniker, 2023, GPL v3.0* 