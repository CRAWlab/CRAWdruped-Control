#include <ax12.h>
#include <BioloidController.h>
#include "First_steps.h"  // pose file generated from PyPose

BioloidController bioloid = BioloidController(1000000);

#define frames 6
int idx = 0;
int number_of_steps = 4;

// stand up slowly
void setup(){    
    delay(100);                    // recommended pause
    bioloid.loadPose(Forward);   // load the pose from FLASH, into the nextPose buffer
    bioloid.readPose();            // read in current servo positions to the curPose buffer
    bioloid.interpolateSetup(500); // set up for interpolation from current->next over 1/2 a second
    while(bioloid.interpolating > 0){  // do this while we have not reached our new pose
        bioloid.interpolateStep();     // move servos, if necessary. 
        delay(3);
    }
    
    // run the Go_forward sequence
    bioloid.playSeq(Go_Forward);
}

void loop(){
  int counter;
  counter = 1;
  
  while(counter <= number_of_steps){
    bioloid.play();
    counter++;
  }     
}
