#readme

Summary
- Arduino sketch that controls a two-motor demo car with directional LEDs and a speaker.
- Main source: [CarDemo_Lab7.ino](CarDemo_Lab7.ino)
- Key control functions: [`moveForwards`](CarDemo_Lab7.ino), [`moveBackwards`](CarDemo_Lab7.ino), [`turnLeft`](CarDemo_Lab7.ino), [`turnRight`](CarDemo_Lab7.ino), [`idle`](CarDemo_Lab7.ino)

Pin mapping (defined in [CarDemo_Lab7.ino](CarDemo_Lab7.ino))
- Right motor: [`m1_in1`](CarDemo_Lab7.ino), [`m1_in2`](CarDemo_Lab7.ino)
- Left motor: [`m2_in1`](CarDemo_Lab7.ino), [`m2_in2`](CarDemo_Lab7.ino)
- Motor enables / switches: [`motor_switch`](CarDemo_Lab7.ino), [`turn_left`](CarDemo_Lab7.ino), [`turn_right`](CarDemo_Lab7.ino), [`left_motor_enable`](CarDemo_Lab7.ino), [`right_motor_enable`](CarDemo_Lab7.ino)
- LEDs: [`fwd_led`](CarDemo_Lab7.ino) (green forward), [`back_led`](CarDemo_Lab7.ino) (red reverse)
- Speaker: [`speaker`](CarDemo_Lab7.ino)

Behavior
- If the forward switch (`motor_switch`) is active (LOW), the sketch calls [`moveForwards`](CarDemo_Lab7.ino): both motors enabled, forward pins set, green LED on, continuous tone at 1500 Hz.
- If both turn switches indicate the special condition (left HIGH and right LOW) the sketch calls [`moveBackwards`](CarDemo_Lab7.ino): both motors enabled in reverse, red LED on, periodic beeps (every $1500\,\text{ms}$).
- If only left or right turn switches are active, the sketch calls [`turnLeft`](CarDemo_Lab7.ino) or [`turnRight`](CarDemo_Lab7.ino) respectively: motors drive to rotate the car in place; speaker silent.
- If no inputs are active, [`idle`](CarDemo_Lab7.ino) disables motors, LEDs, and speaker.

Notes
- Serial is initialized at 9600 baud for debugging.
- Backing beep interval is controlled by a timer using millis(); the interval constant in the sketch is $1500\,\text{ms}$.

How to use
- Open [CarDemo_Lab7.ino](CarDemo_Lab7.ino) in the Arduino IDE or VS Code with Arduino extension.
- Select the correct board/port and upload.
- Change wiring to suit your needs.
- Observe LEDs, speaker, and motor directions according to switch positions.

References
- Source file: [CarDemo_Lab7.ino](CarDemo_Lab7.ino)
- Functions: [`moveForwards`](CarDemo_Lab7.ino), [`moveBackwards`](CarDemo_Lab7.ino), [`turnLeft`](CarDemo_Lab7.ino), [`turnRight`](CarDemo_Lab7.ino), [`idle`](CarDemo_Lab7.ino)