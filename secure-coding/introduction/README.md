# Introduction to Secure Coding

Secure coding in C/C++ involves adopting practices and guidelines to write code that is robust, reliable, 
and resistant to attacks. Given the power and complexity of C and C++, secure coding is particularly 
important in these languages. 

Secure coding in C/C++ requires a deep understanding of the language's features and idiosyncrasies, 
as well as a commitment to ongoing learning and vigilance against new types of threats.

Here are some key aspects:

* **Input Validation**: Ensure that your program properly validates input before processing it. 
    This is crucial for avoiding vulnerabilities like buffer overflows and injection attacks.

* **Memory Management**: Properly allocate and deallocate memory to avoid leaks and dangling pointers. 
    Use smart pointers in C++ to automate memory management where possible.
    It is also vital to carefully manage buffer sizes and use functions that limit the amount of data 
    written to buffers.
    Certain functions in C/C++ are known to be insecure (e.g., strcpy, sprintf). 
    Prefer safer alternatives (like strncpy, snprintf) that limit buffer sizes.

* **Error Handling**: Implement robust error handling and avoid exposing sensitive information in error messages.

* **Secure Library Use**: When using third-party libraries, ensure they are up-to-date and free from known      
    vulnerabilities.


## Common Problems in C/C++ Code 
Excerpt from the CWE/SANS TOP 25 Most Dangerous Software Errors list (with focus on C/C++)

* CWE-787 Out-of-bounds Write
* CWE-20  Improper Input Validation
* CWE-125 Out-of-bounds Read
* CWE-78  Improper Neutralization of Special Elements used in an OS Command (**OS Command Injection**)
* CWE-416 Use After Free
* CWE-22  Improper Limitation of a Pathname to a Restricted Directory (**Path Traversal**)
* CWE-190 Integer Overflow or Wraparound
* CWE-798 Use of Hard-coded Credentials
* CWE-77  Improper Neutralization of Special Elements used in a Command (**Command Injection**)
* CWE-119 Improper Restriction of Operations within the Bounds of a Memory Buffer
* CWE-400 Uncontrolled Resource Consumption
* CWE-611 Improper Restriction of XML External Entity Reference
* CWE-94  Improper Control of Generation of Code (**Code Injection**)


## References

* [CWE/SANS TOP 25 Most Dangerous Software Errors](https://www.sans.org/top25-software-errors/)
* [CWE Most Important Hardware Weaknesses](https://cwe.mitre.org/scoring/lists/2021_CWE_MIHW.html)
  
* [SEI CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c)
* [SEI CERT C++ Coding Standard](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682)