/*
AC Voltage dimmer with Zero cross detection
Author: Charith Fernanado http://www.inmojo.com
.. with a few modifications by Ishan Marikar.
License: Creative Commons Attribution Share-Alike 3.0 License. 

Attach the Zero cross pin of the module to Arduino External Interrupt pin
Select the correct Interrupt # from the below table:
(the Pin numbers are digital pins, NOT physical pins:
digital pin 2 [INT0]=physical pin 4 
and digital pin 3 [INT1]= physical pin 5)

 Pin    |  Interrrupt # | Arduino Platform
 ---------------------------------------
 2      |  0            |  All
 3      |  1            |  All
 18     |  5            |  Arduino Mega Only
 19     |  4            |  Arduino Mega Only
 20     |  3            |  Arduino Mega Only
 21     |  2            |  Arduino Mega Only

In the program pin 2 is chosen
 */

int AC_LOAD = 3;    // Output to Opto Triac pin
int dimming = 128;  // Dimming level (0-128)  0 = ON, 128 = OFF
/* Due to timing problems, the use of ‘0’ can sometimes make the circuit 
flicker. It is safer to use a value slightly higher than ‘0’
*/

int lastValue = 0;
int i = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);  
// Chooses '0' as interrupt for the zero-crossing
}
// the interrupt function must take no parameters and return nothing
void zero_crosss_int()  
// function to be fired at the zero crossing to dim the light
{
  // Firing angle calculation : 1 full 50Hz wave =1/50=20ms  
  // Every zerocrossing thus: (50Hz)-> 10ms (1/2 Cycle) For 60Hz => 8.33ms

  // 10ms=10000us
  // (10000us - 10us) / 128 = 75 (Approx) For 60Hz =>65
  int dimtime = (65*dimming);    // For 60Hz =>65     
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(10);         // triac On propogation delay
                                 //(for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}
void loop()  {
  i = Serial.parseInt();
  Serial.
    if(lastValue != i)
    {
      dimming = i;
    }
  
 }
 
