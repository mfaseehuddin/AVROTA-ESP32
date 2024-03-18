#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

void toggleResetArduino();

BluetoothSerial SerialBT;

#define ARDUINO_RESET_PIN 2 // Example GPIO pin for Arduino reset
bool hasReset = false;      // Flag to ensure reset happens only once per connection

void setup()
{
  Serial.begin(115200);
  SerialBT.begin("ESP32 Serial Bridge"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(ARDUINO_RESET_PIN, OUTPUT);
  digitalWrite(ARDUINO_RESET_PIN, HIGH); // Ensure Arduino is not in reset
}

void loop()
{
  // Check for Bluetooth connection
  if (SerialBT.hasClient())
  {
    if (!hasReset)
    {            // Check if the reset has already been performed
      // delay(100); // Wait for the client to get ready
      toggleResetArduino();
      hasReset = true; // Prevent further resets until next disconnect
    }
  }
  else
  {
    hasReset = false; // Reset the flag when the client disconnects
  }

  // The above logic is a little touch and go, we need to find a better way to indicate a reset is needed
  // When the Bluetooth port is opened what happens?


  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
  }
  delay(1);
  // delayMicroseconds(500); // This is a hack to prevent the AVRDUDE from crashing
}

void toggleResetArduino()
{
  Serial.println("Resetting the Arduino");
  // Pull the RESET pin LOW
  digitalWrite(ARDUINO_RESET_PIN, LOW);
  // Wait for a bit
  delay(200); // 100 milliseconds is typically enough
  // Bring the RESET pin back HIGH
  digitalWrite(ARDUINO_RESET_PIN, HIGH);
}
