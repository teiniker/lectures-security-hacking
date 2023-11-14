# Security and Hacking in C/C++

This repository contains examples for **security aspects in embedded software development in C/C++**.
Common weaknesses and vulnerabilities are shown - hacking, and possible solutions are presented to make 
software more secure.

The following topics will be covered:

* **Ethical Hacking** 
    * [Introduction](exploits/introduction/)
    * Security Testing
        * Environment
            * [Introduction](exploits/environment/introduction/)
            * [Memory Management](exploits/environment/memory/)
        * Exploits
            * C-String Attacks 
                * [Format String](exploits/c-string-attacks/format-string/)
                * [Buffer Overflow ](exploits/c-string-attacks/buffer-overflow/)
            * [OS Command Injection](exploits/command-injection/)
            * [File Handling](exploits/file-handling/)
            * [SQL Processing](exploits/sql-processing/)

    * Reverse Engineering   
        * [Static Analysis](reverse-engineering/analysis-static/)
        * [Dynamic Analysis](reverse-engineering/analysis-dynamic/)
        * [Firmware Analysis](reverse-engineering/analysis-firmware/)
    
    * [Hardware Hacking](hardware-hacking/)
        

* **Secure Software Development**
    * [Introduction](secure-coding/introduction/) 
    * Secure Coding
        * [Data Representation](secure-coding/representation/)
        * [Input Validation](secure-coding/input-validation/)
        * [Output Encoding](secure-coding/output-encoding/)
        * [Error Handling](secure-coding/error-handling/)   
    * Cryptography in Practice
        * [OpenSSL](cryptography/openssl/)
        * [Random Numbers](cryptography/random-numbers/)
        * [Message Digest](cryptography/message-digest/)
        * Message Authentication Code
        * Symmetric Encryption 

If you need a refresher in C/C++ programming, feel free to use the following repositories:

* [Computer Science and Programming in C/C++](https://github.com/teiniker/teiniker-lectures-computerscience/tree/master)

* [Embedded Computing by Example](https://github.com/teiniker/teiniker-lectures-embeddedcomputing)

*Egon Teiniker, 2023, GPL v3.0* 
