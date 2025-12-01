# microprocessor_projectaiub
The prototype was able to autonomously navigate and  avoid obstacles by making directional decisions in real time. The experiment highlights the potential of  microcontroller-based systems for robotics education and lays the foundation for future advancements such as  machine learning-based navigation and multi-sensor integration. 
Explanation: 
An Arduino Uno microcontroller was used as the central controller of the robot car. A Motor Driver Shield was 
mounted on top of the Arduino Uno to drive four DC motors, which were connected to the M1, M2, M3, and M4 
terminals of the shield. To detect obstacles, an ultrasonic sensor was employed, where the Trig pin was connected 
to analog pin A0 and the Echo pin was connected to analog pin A1 of the Arduino. For directional scanning, a 
servo motor was attached to the front of the chassis, and its signal pin was connected to digital pin 9, while its 
power pins were connected to 5V and GND. The ultrasonic sensor itself was mounted on the servo horn, allowing 
it to rotate left and right for obstacle detection. The entire system was powered using a battery pack connected to 
the motor shield, and jumper wires were used to establish the necessary electrical connections. The robot car was 
then programmed through the Arduino IDE with logic to move forward, detect obstacles, reverse when necessary, 
and turn left or right depending on the available clearance. Thank You.
