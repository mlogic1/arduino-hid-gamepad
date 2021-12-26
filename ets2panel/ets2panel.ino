#include <Joystick.h>

// Create Joystick
Joystick_ joystick;

const int pinToButtonMap1 = 9; // return button
const int pinToButtonMap2 = 11; // hazard lights

void setup() {
  pinMode(pinToButtonMap1, INPUT_PULLUP);
  pinMode(pinToButtonMap2, INPUT_PULLUP);

  joystick.begin();
}

int lastButtonState1 = 0;
int lastButtonState2 = 0;

void loop() {
  // Read pin values
  int currentButtonState = !digitalRead(pinToButtonMap1);
  if (currentButtonState != lastButtonState1)
  {
    joystick.setButton(0, currentButtonState);
    lastButtonState1 = currentButtonState;
  }

  currentButtonState = !digitalRead(pinToButtonMap2);
  if (currentButtonState != lastButtonState2)
  {
    joystick.setButton(1, currentButtonState);
    lastButtonState2 = currentButtonState;
  }

  delay(50);
}
