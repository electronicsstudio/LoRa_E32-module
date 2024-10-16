#include <SoftwareSerial.h>   

SoftwareSerial mySerial(11, 10); // RX, TX

void setup() {
  Serial.begin(9600);     // Begin hardware serial communication
  mySerial.begin(9600);   // Begin software serial communication
}

void loop() {

  // Check if data is available on hardware serial
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    mySerial.println(input);  // Send the input to software serial
  }
 
  // Check if data is available on software serial
  if (mySerial.available() > 0) {
    String input = mySerial.readString();
    Serial.println(input);  // Print the received data on the serial monitor
  }
}
