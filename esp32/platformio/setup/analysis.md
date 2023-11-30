# Static Code Analysis 

Static analysis became an important part of software development cycle. 
It can identify potential bugs, vulnerabilities and security threats by 
doing an analysis on the source code level without having to test it on 
hardware or execute any code.

Before performing a static analysis check, make sure our project builds 
without errors. For information about how to build a project, see the 
`pio run` command. 



## Cppcheck

**Cppcheck** is a static analysis tool for C/C++ code. It provides a unique 
code analysis to detect bugs and focuses on detecting undefined behavior 
and dangerous coding constructs. The goal is to detect only real errors 
in the code (i.e. have very few false positives).

$ sudo apt install cppcheck

```
$ pio check -e esp32dev -vv
Checking esp32dev > cppcheck (platform: espressif32; board: esp32dev; framework: arduino)
-------------------------------------------------
src/main.cpp:3: [low:style] The function 'setup' is never used. [unusedFunction]
src/main.cpp:9: [low:style] The function 'loop' is never used. [unusedFunction]
=================================================

Component     HIGH    MEDIUM    LOW
-----------  ------  --------  -----
src            0        0        2

Total          0        0        2

Environment    Tool      Status    Duration
-------------  --------  --------  ------------
esp32dev       cppcheck  PASSED    00:00:10.890
=================================================
```

* `pio check`: This is the PlatformIO command to run static code analysis
    on both (native and embedded) files.

* `-e esp32dev`: This specifies the environment for which we want to run the check.

Additional flags to be passed to the command line to more precisely configure 
Cppcheck:
* --enable=<id>:  Enable additional checks. The available ids are: all, warning, style, performance, portability, information, unusedFunction, missingInclude

* --std=<id>: Set standard. The available options are: c89, c99, c11, c++03, c++11, c++14, c++17, c++20 (default)

* --language=<language>: Forces Cppcheck to check all files as the given language. Valid values are: c, c++.

* --platform=<type>: Specifies platform-specific types and sizes. The available built-in platforms are: unix32, unix64, win32A, win32W, win64, avr8, native, unspecified (default)

* -D<ID>: Define a preprocessor symbol. Example: -DDEBUG=1

* -U<ID>: Undefine preprocessor symbol. Use -U to explicitly hide certain #ifdef <ID> code paths from checking. Example: -UDEBUG

* --addon=cert.py: SEI CERT coding standard provides rules for secure coding in the 
    C programming language. The goal of these rules and recommendations is to develop 
    safe, reliable, and secure systems, for example by eliminating undefined behaviors 
    that can lead to undefined program behaviors and exploitable vulnerabilities.


## Clang-Tidy
Clang-Tidy is a clang-based C++ “linter” tool. Its purpose is to provide an extensible framework for diagnosing and fixing typical programming errors, like style violations, interface misuse, or bugs that can be deduced via static analysis.

```
$ sudo apt install clang-tidy
```

```
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
test_ignore = test_native
check_tool = clangtidy
```

Additional flags to be passed to the command line to more precisely configure 
Clang-Tidy:

* --checks=<string>: Comma-separated list of enabled checks (* default)

* --format-style=<string>: Style for formatting code around applied fixes: llvm, google, webkit, mozilla, none (default)

 

## References
* [Static Code Analysis](https://docs.platformio.org/en/stable/advanced/static-code-analysis/index.html)

* [Cppcheck](https://docs.platformio.org/en/stable/advanced/static-code-analysis/tools/cppcheck.html)

* [Clang-Tidy](https://docs.platformio.org/en/stable/advanced/static-code-analysis/tools/clang-tidy.html)