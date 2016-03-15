#include <wiringPi.h>

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

  // Starte die WiringPi-Api (wichtig)
  if (wiringPiSetup() == -1)
    return 1;

  // Schalte GPIO 17 (=WiringPi Pin 0) auf Ausgang
  pinMode(0, INPUT);

  // Dauerschleife
  while(1) {
    // LED an
    if (digitalRead(0)==1) {
       cout << "Yey" << endl;      
    }
    delay(100);
  }
}
