# ESP32 PWM (Analog Output)

The ESP32 has a LED **PWM controller with 16 independent channels** that can be configured to 
generate PWM signals with different properties.

Here’s the steps we will have to follow to dim an LED with PWM using the Arduino IDE:

1. We need to choose a **PWM channel**. There are 16 channels from `0` to `15`.

2. We need to set the **PWM signal frequency**. For an LED, a frequency of `5000 Hz` is fine to use.

3. We also need to set the signal’s **duty cycle resolution**: We have resolutions from `1` to `16` bits.      
    We will use `8-bit` resolution, which means you can control the LED brightness using a value 
    from `0` to `255`.

4. We need to specify to which **GPIO** or GPIOs the signal will appear upon. 
    For that you’ll use the following function:
    ```C
    ledcAttachPin(GPIO, channel)
    ```
    
    This function accepts two arguments. The first is the GPIO that will output the signal, 
    and the second is the channel that will generate the signal.

5. Finally, to control the LED brightness using PWM, we use the following function:
    ```C
    ledcWrite(channel, dutycycle)
    ```C

    This function accepts as arguments the channel that is generating the PWM signal, and the 
    duty cycle.


## References
* [ESP32 PWM with Arduino IDE (Analog Output)](https://randomnerdtutorials.com/esp32-pwm-arduino-ide/)