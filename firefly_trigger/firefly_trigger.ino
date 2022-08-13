/*
  Trigger for
  HawkEye Split 4k camera
*/

const int VIDEO_PIN = 1;    // video trigger pin
const int FOTO_PIN = 2;     // foto trigger pin
const int PWM_PIN = 7;      // PWM input pin

const int foto_values[] = { 1300, 1350, 1400, 1500, 1550, 1600 };
const int video_values[] = { 1300, 1350, 1400, 1700, 1750, 1800 };

const int HALF_MIN_AUX_STEP = 25;

const int DOWNLEVEL_VALUE = 200; // Default time for timeout for triggering

// Function for triggering pin
void trigger_pin(int pin) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(pin, LOW);
  delay(DOWNLEVEL_VALUE);
  digitalWrite(pin, HIGH);
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
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

  if (value > 0 && value < 2000)  {
    // Check Video array
    for (int i = 0; i < sizeof(video_values) / sizeof(int); i++) {
      if (value > video_values[i] - HALF_MIN_AUX_STEP && value < video_values[i] + HALF_MIN_AUX_STEP) {
        // Serial.println("VIDEO Triggered");
        trigger_pin(VIDEO_PIN);
      }
    }

    // Check Foto array
    for (int i = 0; i < sizeof(foto_values) / sizeof(int); i++) {
      if (value > foto_values[i] - HALF_MIN_AUX_STEP && value < foto_values[i] + HALF_MIN_AUX_STEP) {
        // Serial.println("FOTO Triggered");
        trigger_pin(FOTO_PIN);
      }
    }
  }
  // 10 Hz
  delay(100);
}
