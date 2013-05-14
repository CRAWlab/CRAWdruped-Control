#include <ax12.h>
#include <BioloidController.h>
#include <Commander.h>    // header file for reading Joystick input
#include "First_steps.h"  // pose file generated from PyPose

Commander command = Commander();
BioloidController bioloid = BioloidController(1000000);

#define frames 6
int idx = 0;
int number_of_steps = 2;
int counter = 1;

// The setup loop is what runs at startup
void setup(){ 
    // set up serial
    Serial.begin(38400);

    // wait, then check the voltage (LiPO safety)
    delay (1000);
    float voltage = (ax12GetRegister (1, AX_PRESENT_VOLTAGE, 1)) / 10.0;
    Serial.print ("System Voltage: ");
    Serial.print (voltage);
    Serial.println (" volts.");
    
    // if the voltage is under 10V, don't run any other code
    if (voltage < 10.0)              
        while(1);  // while loop keeps other code from running (it's always true)

    delay(100);                        // recommended pause
    bioloid.loadPose(Forward);         // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();                // read in current servo positions to the curPose buffer
    bioloid.interpolateSetup(500);     // set up for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
}


// Main program loop
void loop(){

//----- Uncomment to run the sequence an infinite number of times ----------------------
//        //Select the sequence to run
//         bioloid.playSeq(Go_Forward);
//         
//         // while there are more steps of the sequence, run the next  m
//         while(bioloid.playing){
//               bioloid.play();
//               command.ReadMsgs();
//         }
//----- End of uncommenting for running indefinitely -----------------------------------
  
  
 

//----- Uncomment below to run the sequence number_of_steps number of times ------------  
//    while(counter <= number_of_steps){
//        //Select the sequence to run
//         bioloid.playSeq(Go_Forward);
//         
//         // while there are more steps of the sequence, run the next  m
//         while(bioloid.playing){
//               bioloid.play();
//               command.ReadMsgs();
//         }
//         
//         // Print the value of the counter variable to the Serial Monitor
//         Serial.println(counter);
//
//         // increment the counter by 1
//         counter++;
//    }
//----- End of uncommenting for running a sequence number_of_steps number of times -----




//----- Uncomment below to run sequence when 1 is input in Serial Monitor --------------    
//    //----- Try to read a 1 from the serial monitor to execute the sequence -----
//    // if there's any serial data available, read it:
//    while (Serial.available() > 0) {
//
//      // look for the next valid integer in the incoming serial stream:
//      int go = Serial.parseInt(); 
//      
//      Print the value of the go variable to the Serial Monitor
//      Serial.print("go = ");
//      Serial.println (go);
//      
//      //Select the sequence to run
//      bioloid.playSeq(Go_Forward);
//         
//      // while there are more steps of the sequence, run the next  m
//      while(bioloid.playing){
//        bioloid.play();
//        command.ReadMsgs();
//        }
//      }
//    }
//----- End of uncommenting for running sequence from Serial Monitor -------------------


//----- Uncomment below to run sequence when commander button is pressed ---------------    
  // take commands from a commander or computer
  
  // if there are messages from the commander 
  //  && that there is not a sequence currently running 
  if(command.ReadMsgs() > 0 && bioloid.runningSeq == 0){
    
    // if the command in the buffer is button R3, then run the sequence
    if(command.buttons&BUT_R3){
         //Select the sequence to run
         bioloid.playSeq(Go_Forward);
         
         // while there are more steps of the sequence, run the next  m
         while(bioloid.playing){
               bioloid.play();
               command.ReadMsgs();
         }
      }
    }
//----- End of uncommenting for running sequence from Commander button -----------------
    
} // End of main program loop
