#include <math.h>
//int i=0;
//double analogValue=0;
//int analogValue2 =0; 
//void setup() {
//  // put your setup code here, to run once:
//Serial.begin(9600);
//}

//void loop() {
//  // put your main code here, to run repeatedly:
//  analogValue = sin(2*3.1415*10000*i);
//  analogValue2 = map(analogValue,-1,1,0,255);
//  //analogWrite(A0,50);
//  Serial.print(analogValue2);
//  i++;
//  if(i>255)
//    i=0;
//
//}

void setup() {
  Serial.begin(115200);
}

void loop() { // Generate a Sine wave
  for (int deg = 0; deg < 360; deg = deg + 16){
    dacWrite(25, int(128 + 80 * (sin(deg*PI/180))));
}
for (int deg = 0; deg < 360; deg = deg + 16){
    dacWrite(25, int(128 + 80 *0.5* (sin(deg*PI/180))));
}
for (int deg = 0; deg < 360; deg = deg + 16){
    dacWrite(25, int(128 + 80 * 0.25*(sin(deg*PI/180))));
}
for (int deg = 0; deg < 360; deg = deg + 16){
    dacWrite(25, int(128 + 80 *0.125 *(sin(deg*PI/180))));
}
}

// ESP32 has two 8-bit DAC (digital to analog converter) channels, connected to GPIO25 (Channel 1) and GPIO26 (Channel 2)
// Square wave   = amplitude . sin(x) + sin(3.x) / 3 +  sin (5.x) / 5 + sin (7.x) / 7  + sin (9.x) / 9  + sin (11.x) / 11  Odd harmonics
// Triangle wave = amplitude . sin(x) - 1/3^2.sin(3.x) +  1/5^2.sin(5.x) - 1/7^2.sin (7.x) + 1/9^2.sin(9.x) - 1/11^2.sin (11.x) Odd harmonics
// dacWrite(25, int(128 + 80 * (sin(deg*PI/180)))); // GPIO Pin mode (OUTPUT) is set by the dacWrite function
// dacWrite(25, int(128 + 80 * (sin(deg*PI/180)+sin(3*deg*PI/180)/3+sin(5*deg*PI/180)/5+sin(7*deg*PI/180)/7+sin(9*deg*PI/180)/9+sin(11*deg*PI/180)/11))); // Square
// dacWrite(25, int(128 + 80 * (sin(deg*PI/180)+1/pow(3,2)*sin(3*deg*PI/180)+1/pow(5,2)*sin(5*deg*PI/180)+1/pow(7,2)*sin(7*deg*PI/180)+1/pow(9,2)*sin(9*deg*PI/180)))); // Triangle
