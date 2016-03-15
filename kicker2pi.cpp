#include <wiringPi.h>

#include <stdio.h>

#include <iostream>

using std::cout;
using std::endl;
using std::flush;

unsigned LEFT = 17;
unsigned RIGHT = 27;
unsigned BUTTON = 22;

void interrupt_left(void)
{
    cout << "Interrupt: left rising to high!" << endl;
}
void interrupt_right(void)
{
    cout << "Interrupt: right rising to high!" << endl;
}
void interrupt_button(void)
{
    cout << "Interrupt: button rising to high!" << endl;
}


int main ()
{
  if (wiringPiSetupGpio() == -1)
  {
    return 1;
  }

  pinMode(LEFT, INPUT);
  wiringPiISR(LEFT, INT_EDGE_FALLING, interrupt_left);

  pinMode(RIGHT, INPUT);
  wiringPiISR(RIGHT, INT_EDGE_FALLING, interrupt_right);

  pinMode(BUTTON, INPUT);
  wiringPiISR(BUTTON, INT_EDGE_FALLING, interrupt_button);


  cout << "Waiting" << endl;
  while(true)
  {
  }

}

