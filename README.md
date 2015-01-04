Simple-TRIAC-Arduino
====================

### AC Voltage dimmer with Zero cross detection
A simple Arduino sketch that lets you dim a bulb by inputting the values into the serial monitor. The code is based upoun the sample code of the [Digital AC Dimmer Module](http://www.inmojo.com/store/inmojo-market/item/digital-ac-dimmer-module/) by Inmojo.
Originally written by Charith Fernanado. I just made it be able to accept values.

#### Instructions
Attach the Zero cross pin of the module to Arduino External Interrupt pin
Select the correct Interrupt # from the below table:
(the Pin numbers are digital pins, NOT physical pins:
digital pin 2 [INT0]=physical pin 4 
and digital pin 3 [INT1]= physical pin 5)

 Pin    |  Interrrupt # | Arduino Platform  |
 -------|:-------------:|------------------:|
 2      |  0            |  All              |
 3      |  1            |  All              |
 18     |  5            |  Arduino Mega Only|
 19     |  4            |  Arduino Mega Only|
 20     |  3            |  Arduino Mega Only|
 21     |  2            |  Arduino Mega Only|

In this the program pin 2 is chosen
