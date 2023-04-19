# Summary

This module uses a 3d printed spiral torsion spring (SPS) connected to the shaft of the motor. The angle is measured in this point and in the output of the spring, so torque can be measured knowing the mechanical properties of the SPS. The compliancy The thickness and revolutions of the spiral can be tuned for the application. The compliancy added to the system can be useful for manipulators and legged robots. The torsion sensing can help to prevent damage to the module.

<img src="/imgs/SEA.png" width="350">

The image is from a previous version.

The N20 is a format of small dc motors, there is a vast set of gearbox ratios and nominal voltage, so you can choose an specific one to match your demands. You also need to modify the SPS to attach its body to something.

In the current design, the shaft can rotate from -85° to +85° before crashing with the chasis.

# Parts

- Chasis
- Front plate
- SPS
- Shaft adpater
- 2 Angle sensor CJCMU-03
- N20 motor (i used one with 100 RPM at 6 V)
- 2 M3x10 sink bolts
- 2x3 pin header male connector

# Servo

I included a version that uses a different chasis and only one angle sensor, if you need something more simple. It has a wider range of rotation, but i have not implemented yet complete turns.

<img src="/imgs/servo.png" width="350">

# Fabrication

- The shaft adapter must be made with a 0.3 nozzle to get the right size. The motor wires must be soldered where the red circles are indicating. The pin that is in between is for the signal of the output sensor.

<img src="/imgs/solder.png" width="350">

# Test setup and program

I used an Arduino UNO and a L9110S dual motor driver. The test program uses the serial monitor to receive an angle input to rotate the shaft. I made two classes, one for the SEA and one for the servo. It requires two pwm pins, and two analog input pins. The wiring in the output sensor must be reversed, vcc in gnd and gnd in vcc in order to work with this routine, as the sensor is reversed in the assembly. 

Being more rigorous, a thorough mapping of signal/angle must me made to compare the sensors and calculate torsion. 

# Further work

- To characterize the SPS and use it to calculate torque.
