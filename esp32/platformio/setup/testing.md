# PlatformIO Unit Testing

PlatformIO Unit Testing allows us to segregate each part of the firmware/program 
and test that the individual parts are working correctly. 

Using PlatformIO you can execute the same tests on the **local host machine (native)**, 
on the multiple local **embedded devices/boards (connected to local host machine)**, 
or on both. When testing both, PlatformIO builds firmware on the host machine, uploads 
it into a target device, starts tests and collects the test results into test reports. 
The final information will be shown on the host side with informative output and statistics.

```
$ pio test -vvv
```

## Test Types

Before writing a test, we need to decide where it will be executed later: on the 
host machine or on the target device connected to the host machine. Tests that are 
written for the target device typically will not work on your host machine due to 
the missing peripheral and other connectivity.

### Native
Native tests are intended for the project components that are **independent of 
physical hardware**. We can also use them in pair with **Mocking frameworks**.
```
$ pio test -e native
```


### Embedded
Embedded tests are intended for the **target devices (boards, hardware)**. They 
allow you to deeply test all project components that are part of your firmware.

```
$ pio test -e esp32dev -vv
```

Embedded tests with the PlatformIO Unit Testing Runner:
* It builds a special firmware intended for your target using a compatible embedded development platform
* Uploads a firmware to the end target (flashes device)
* Connects to the target using a Serial interface and test_port
* Gathers Serial output from the target and parses test result on the host machine
* Provides test results.


## Hybrid
The tests that work on a host machine and on the embedded target are hybrid 
tests. You can run them using Native development platform or embedded development
platforms.

```
$ pio test -vv

================= SUMMARY ==========================
Environment    Test           Status    Duration
-------------  -------------  --------  ------------
esp32dev       test_embedded  PASSED    00:00:13.800
native         test_native    PASSED    00:00:00.263
====================================================
```



## Testing Frameworks

PlatformIO supports the most popular testing frameworks and allows you to easily 
switch between them using the test_framework option in "platformio.ini". 

We can mix different frameworks in the same project. 

* **Unity**: The goal has been to keep it small and functional. Unity was designed to 
    be cross-platform. It works hard to stick with C standards while still providing 
    support for the many embedded C compilers that bend the rules. 

* **GoogleTest**: is a testing framework developed by the Testing Technology team 
    with Google’s specific requirements and constraints in mind. Whether you work 
    on Linux, Windows, or a Mac, if you write C++ code, GoogleTest can help you.
    It works also embedded for ESP32 and ESP8266.

## References
* [Unit Testing](https://docs.platformio.org/en/stable/advanced/unit-testing/index.html)

* [pio test](https://docs.platformio.org/en/stable/core/userguide/cmd_test.html)

* [Unity](https://docs.platformio.org/en/stable/advanced/unit-testing/frameworks/unity.html)
* [GoogleTest](https://docs.platformio.org/en/stable/advanced/unit-testing/frameworks/googletest.html)