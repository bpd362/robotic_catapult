# robotic_catapult
Utilizes the ELEGOO Smart Robot Car kit to create a remotely controlled catapult car

This code impliments the basic drive functions of the ELEGOO Smart Robot Car into a custom library to refrence throughout. 
The program recieves IR input through the car's onboard IR reciever as well as any (optionally) additional recievers connected for additional reliability
An additional relay controlled motor is mounted on the rear of the robot on which is mounted the catapult arm. Additionally a servo is also mounted in for reseting the catapult arm, this servo also acts as a stop for the catapult arm ensuring the projectile is released at an optimal angle.
IR input is recieved and corolated to either one of the main drive controls or the catapult launch code
