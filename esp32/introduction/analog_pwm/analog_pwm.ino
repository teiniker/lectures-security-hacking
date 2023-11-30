const int LED_RED = 16;    // GPIO16

// setting PWM properties
const int PWM_FREQUENCY = 5000;
const int PWM_CHANNEL = 0;
const int PWM_RESOLUTION = 8;

void setup() 
{
  // configure LED PWM functionalitites
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(LED_RED, PWM_CHANNEL);
}

void loop() 
{
  // increase the LED brightness
  for(int duty_cycle = 0; duty_cycle <= 255; duty_cycle++)
  {   
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, duty_cycle);
    delay(10);
  }

  // decrease the LED brightness
  for(int duty_cycle = 255; duty_cycle >= 0; duty_cycle--)
  {
    // changing the LED brightness with PWM
    ledcWrite(PWM_CHANNEL, duty_cycle);   
    delay(10);
  }
}
