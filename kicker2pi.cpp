#include <wiringPi.h>

#include <stdio.h>

#include <iostream>

using std::cout;
using std::endl;
using std::flush;

#define LEFT 17;
#define RIGHT 27;
#define BUTTON 22;

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
  pullUpDnControl(LEFT, PUD_DOWN);
  wiringPiISR(LEFT, INT_EDGE_FALLING, interrupt_left);

  pinMode(RIGHT, INPUT);
  pullUpDnControl(RIGHT, PUD_DOWN);
  wiringPiISR(RIGHT, INT_EDGE_FALLING, interrupt_right);

  pinMode(BUTTON, INPUT);
  pullUpDnControl(BUTTON, PUD_DOWN);
  wiringPiISR(BUTTON, INT_EDGE_FALLING, interrupt_button);


  cout << "Waiting" << endl;
  while(true)
  {
  }

}

