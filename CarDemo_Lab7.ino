// Right Motor
#define m1_in1 10 // Forward Pin when High
#define m1_in2 11 // Backwards Pin when High
// Left Motor
#define m2_in1 6  // Forward Pin when High
#define m2_in2 5  // Backwards Pin when High
// Motor Enables through Greyhill 
#define motor_switch A4 // Analog input ACTIVE LOW
#define turn_left A5  // Analog input ACTIVE HIGH
#define turn_right A2 // Analog input ACTIVE LOW
#define left_motor_enable 2 // Enables left motor to spin
#define right_motor_enable 3  // Enables right motor to spin
// LEDs
#define back_led 12 // On when moving backwards (RED LED)
#define fwd_led 13  // On when moving forwards (GREEN LED)
// SPKR
#define speaker 9 // Output for speaker -- Play constant tone @ 1500hz going forwards, and 3000hz going backwards

// Variables for spkr
unsigned long previousTime = 0;
const long interval = 1500;

void setup() {
  // MOTOR CONTROLS
  pinMode(m1_in1, OUTPUT);
  pinMode(m1_in2, OUTPUT);
  pinMode(m2_in1, OUTPUT);
  pinMode(m2_in2, OUTPUT);

  // INPUT SWITCHES GREYHILL
  pinMode(left_motor_enable, OUTPUT);
  pinMode(right_motor_enable, OUTPUT);
  pinMode(turn_left, INPUT_PULLUP);
  pinMode(turn_right, INPUT_PULLUP);
  pinMode(motor_switch, INPUT_PULLUP);

  // ACCESSORY OUTPUTS
  pinMode(back_led, OUTPUT);
  pinMode(fwd_led, OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(motor_switch) == LOW) {
    moveForwards();
  } // Check first if fwd switch is on
  else if ((digitalRead(turn_left) == HIGH) && (digitalRead(turn_right) == LOW) ) {
    moveBackwards();
  } // Check then if both turn switches are 'on', if so move backwards
  else if (digitalRead(turn_left) == HIGH) {
    turnLeft();
  } // Then check if only left switch is 'on'
  else if (digitalRead(turn_right) == LOW) {
    turnRight();
  } // Then check if only right switch is 'on'
  else {
    idle();
  } // If nothing is switched, make sure all accessory outputs are off
}

void idle() {
  digitalWrite(left_motor_enable, LOW);
  digitalWrite(right_motor_enable, LOW);
  digitalWrite(fwd_led, LOW);
  digitalWrite(back_led, LOW);
  noTone(speaker);
} // Idle function deactivating motors, leds, and speaker

void moveForwards()
{
  tone(speaker, 1500);  // Constant tone that plays when moving forwards
  digitalWrite(fwd_led, HIGH);  // Turn on Green LED
  // Enable Motors
  digitalWrite(left_motor_enable, HIGH);
  digitalWrite(right_motor_enable, HIGH);
  // Drive Motors
  digitalWrite(m1_in1, HIGH);
  digitalWrite(m1_in2, LOW);
  digitalWrite(m2_in1, HIGH);
  digitalWrite(m2_in2, LOW);
} // moveForwards

void moveBackwards()
{
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= interval) {
    tone(speaker, 500, 500); // Beeping Sound that plays while backing up 
    previousTime = currentTime;
  } // Checks if a second has passed and if so send a beep.
  digitalWrite(back_led, HIGH); // Turn Red LED on
  // Enable Motors
  digitalWrite(left_motor_enable, HIGH);
  digitalWrite(right_motor_enable, HIGH);
  // Drive Motors
  digitalWrite(m1_in2, HIGH);
  digitalWrite(m1_in1, LOW);
  digitalWrite(m2_in2, HIGH);
  digitalWrite(m2_in1, LOW);
} // moveBackwards()

void turnRight()
{
  // Enable Motors
  digitalWrite(left_motor_enable, HIGH);
  digitalWrite(right_motor_enable, HIGH);
  // Drive Motors
  digitalWrite(m1_in2, HIGH);
  digitalWrite(m1_in1, LOW);
  digitalWrite(m2_in1, HIGH);
  digitalWrite(m2_in2, LOW);
  noTone(speaker);  // Make sure speaker is silent
} // turnRight()

void turnLeft()
{
  // Enable Motors
  digitalWrite(left_motor_enable, HIGH);
  digitalWrite(right_motor_enable, HIGH);
  // Drive Motors
  digitalWrite(m1_in1, HIGH);
  digitalWrite(m1_in2, LOW);
  digitalWrite(m2_in2, HIGH);
  digitalWrite(m2_in1, LOW);
  noTone(speaker);  // Make sure speaker is silent 
} // turnLeft()
