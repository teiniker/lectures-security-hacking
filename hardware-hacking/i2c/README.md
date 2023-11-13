# Inter-Integrated Circuit (I2C)

I2C is a **serial communication protocol** for low-speed devices.

The I2C protocol uses three lines: 
* **Serial Data line (SDA)** for transmitting data
* **Serial Clock line (SCL)** to determine when the data gets read
* **Ground line (GND)**

SDA and SCL lines are connected to the peripherals and they are **open drain drivers**, 
meaning that both lines need to be connected to resistors.

Voltages vary from **1.8 V, 3.3 V, and 5.0 V**, and transfers can occur at four different speeds: 
* 100 kHz, or the **initial speed according to I2C specifications** 
* 400 kHz, which is the **fast mode** 
* 1 MHz, called **high speed mode**
* 3.2 MHz, called **ultrafast mode**

## Protocol 

I2C uses a **controller-peripheral configuration**:
* The components transfer data over the SDA line, bit by bit, in eight-bit sequences. 
* The controller, or multiple controllers, manages the SCL line. 
* An I2C architecture supports more than one controller and one or more peripherals, 
    each with unique addresses used for communication.

![I2C Message](../i2c/i2c-message.png)

* The controller begins each message with a **START condition** that signals the beginning 
of the message. 
* Then it sends the **peripheral’s address**, which is usually 7 bits long but can be as long as 10 bits. 
    This allows for up to 128 (if using 7-bit addresses) or 1024 peripherals (if using 10-bit addresses) 
    on the same bus. 
* The controller also appends a **Read/Write bit** that indicates the kind of operation to perform. 
* An **ACK/NACK bit** indicates what the following data segment will be. 
* I2C divides the actual **data** into **eight-bit sequences**, each of which ends in another ACK/NACK bit. 
* The controller ends the message by sending the **STOP condition**.


## Hardware Tools 
The [Bus Pirate](../tools/BusPirate/) firmware has built-in support for I2C. 
It also has a couple of useful macros that we can use to analyze and attack I2C communications.


## References

* [I2C-Bus](https://www.i2c-bus.org/)

* Fotios Chantzis, Ioannis Stais, Paulino Calderon, Evangelos Deirmentzoglou, Beau Woods. 
    **Practical IoT Hacking: The Definitive Guide to Attacking the Internet of Things.**
    No Starch Press, 2021. 
    * Chapter 8: SPI and I2C 


*Egon Teiniker, 2023, GPL v3.0* 