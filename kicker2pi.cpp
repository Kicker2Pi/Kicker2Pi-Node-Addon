#include <wiringPi.h>

#include <stdio.h>

#include <iostream>

using std::cout;
using std::endl;
using std::flush;

#define LEFT 17
#define RIGHT 27
#define BUTTON 22

long int lastLeft = 0;
long int lastRight = 0;
long int lastButton = 0;

void interrupt_left(void)
{
  long int now = millis();
  if (now - lastLeft > 1000)
  {
    lastLeft = now;
    cout << "Interrupt: left rising to high! Time was " << now << "ms since start." << endl;  
  }
  else
  {
//    cout << "Bounce Left!" << endl;
  }
}
void interrupt_right(void)
{
  long int now = millis();
  if (now - lastRight > 1000)
  {
    lastRight = now;
    cout << "Interrupt: right rising to high! Time was " << now << "ms since start." << endl;
  }
  else
  {
//    cout << "Bounce Right!" << endl;
  }
}
void interrupt_button(void)
{
  long int now = millis();
  if (now - lastButton > 1000)
  {
    lastButton = now;
    cout << "Interrupt: button rising to high! Time was " << now << "ms since start." << endl;
  }
  else
  {
//    cout << "Bounce Button!" << endl;
  }
}


int main ()
{
  if (wiringPiSetupGpio() == -1)
  {
    return 1;
  }

  pinMode(LEFT, INPUT);
  pullUpDnControl(LEFT, PUD_UP);
  wiringPiISR(LEFT, INT_EDGE_FALLING, interrupt_left);

  pinMode(RIGHT, INPUT);
  pullUpDnControl(RIGHT, PUD_UP);
  wiringPiISR(RIGHT, INT_EDGE_FALLING, interrupt_right);

  pinMode(BUTTON, INPUT);
  pullUpDnControl(BUTTON, PUD_UP);
  wiringPiISR(BUTTON, INT_EDGE_FALLING, interrupt_button);


  cout << "Waiting" << endl;
  while(true)
  {
  }

}

