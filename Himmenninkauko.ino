/* A simple example, using the IRsmallDecoder library, 
 * for testing remote controls that use the NEC protocol.
 *
 * Note: for the NEC extended protocol, just define IR_SMALLD_NECx instead of IR_SMALLD_NEC 
 *
 * In this example it's assumed that the IR sensor is connected to digital pin 2 and 
 * the pin is usable for external interrupts.
 * For more information on the boards' usable pins, see the library documentation at:
 * https://github.com/LuisMiCa/IRsmallDecoder
 * or the README.pdf file in the extras folder of this library. 
 */
 
#define IR_SMALLD_NEC        //1st: define which protocol to use and then,
#include <IRsmallDecoder.h>  //2nd: include the library;
IRsmallDecoder irDecoder(2); //3rd: create one decoder object with the correct digital pin;
irSmallD_t irData;           //4th: declare one decoder data structure;

 int BLUE = 0;
  int RED = 0;
  int GREEN = 0;
  int steppi = 17;




 
void setup() {
  Serial.begin(115200);
  Serial.println("Waiting for a NEC remote control IR signal...");
  Serial.println("held\t addr\t cmd");
 
 
}

void loop() {
  if(irDecoder.dataAvailable(irData)) {    //5th: if the decoder has some new data available,       
    Serial.print(irData.keyHeld,HEX);      //6th: do something with the data.
    Serial.print("\t ");
    Serial.print(irData.addr,HEX); 
    Serial.print("\t ");
    Serial.println(irData.cmd,DEC);  


if (irData.cmd == 31){ 
  BLUE=BLUE + steppi;
  if (BLUE >= 255 ) { BLUE = 255;}
   
 analogWrite(9, BLUE ); }



if (irData.cmd == 9){ 
    BLUE = BLUE - steppi;
    if (BLUE <= 0) { BLUE=0;}
    
  analogWrite(9, BLUE); }




if (irData.cmd == 27){
  RED = RED + steppi;
if (RED >= 255) {RED = 255;}

  analogWrite(10, RED); }

if (irData.cmd == 13){ 
RED = RED - steppi;
if (RED <=0) {RED =0;}
  
  analogWrite(10, RED); }




if (irData.cmd == 23){ 
GREEN = GREEN + steppi;
if (GREEN >= 255) {GREEN =255;}
  
analogWrite(11, GREEN); }


if (irData.cmd == 17){ 
 GREEN = GREEN - steppi;
 if (GREEN <=0) { GREEN = 0;}
  
analogWrite(11, GREEN); }


if (irData.cmd == 22){ 

BLUE = 0;
RED = 0;
GREEN = 0;


analogWrite(9, BLUE);
analogWrite(10, RED);
analogWrite(11, GREEN);  
 }

if (irData.cmd == 77){ 

BLUE = 255;
RED = 255;
GREEN = 255;


analogWrite(9, BLUE);
analogWrite(10, RED);
analogWrite(11, GREEN);  
 }




    
  }
}
