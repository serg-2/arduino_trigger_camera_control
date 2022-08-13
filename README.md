# arduino_trigger_camera_control

Trigger to down upon PWM signal

Inav Example:
```
# aux addition. 
aux 20 40 1 1275 1425
aux 21 40 1 1475 1625
aux 22 41 1 1275 1425
aux 23 41 1 1675 1825
# smix addition
smix 0 0 9 100 0 -1
```
Passtrough PWM 6 RC channel to first Servo output.

Now you can use servo pad for camera tirggering.

Used Seeeduino XIAO

(double shortcircuit RST to enter bootloader to upload sketch)
