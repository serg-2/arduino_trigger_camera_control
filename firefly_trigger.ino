/*
  Trigger for
  HawkEye Split 4k camera
*/

const int VIDEO_PIN = 1;    // video trigger pin
const int FOTO_PIN = 2;     // foto trigger pin
const int PWM_PIN = 7;      // PWM input pin

const int FOTO_VALUE = 1800;
const int VIDEO_VALUE = 1900;

const int DOWNLEVEL_VALUE = 200; // Default time for timeout for triggering
const int PAUSE_VALUE = 1000; // Pause between commands

// Function for triggering pin
void trigger_pin(int pin) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pin, LOW);
  delay(DOWNLEVEL_VALUE);
  digitalWrite(pin, HIGH);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(PAUSE_VALUE);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize pin for video capture
  pinMode(VIDEO_PIN, OUTPUT);
  digitalWrite(VIDEO_PIN, HIGH);
  // initialize pin for foto capture
  pinMode(FOTO_PIN, OUTPUT);
  digitalWrite(FOTO_PIN, HIGH);
  // Initialize Serial for debug
  // Serial.begin(9600);
  // Initialize PWM on PWM pin
  pinMode(PWM_PIN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Read Pulse
  int value = pulseIn(PWM_PIN, HIGH);

  if(value > 0 && value < 2000)  {
    if (value > VIDEO_VALUE - 50 && value < VIDEO_VALUE + 50) {
      // Serial.println("VIDEO Triggered");
      trigger_pin(VIDEO_PIN);
    } else if (value > FOTO_VALUE - 50 && value < FOTO_VALUE + 50) {
      // Serial.println("FOTO Triggered");
      trigger_pin(FOTO_PIN);
    }
  }
  // 50 Hz
  delay(20);
}
