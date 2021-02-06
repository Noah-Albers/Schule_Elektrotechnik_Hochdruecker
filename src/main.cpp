#include "Main.h"
#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"
#include "CompileConfig.h"

State* currentState;

bool diffcultyEasy=true;

void openGameState(State* state){
  // Checks if a previous state is still existing
  if(currentState!=NULL){
    // Executes the exit-code
    currentState->onStateClose();

    // Deletes the object
    delete currentState;
  }

  logger::debug("Opening next state: "+state->getStateName());

  // Opens the new state
  currentState=state;
}

void setup() {
  // Starts the serial output
  Serial.begin(115200);
  
  // Sets the log-level to log all
  logger::setLogLevel(logger::ALL);
  
  // Sets all leds to outout
  for(int i=0;i<AMOUNT_LEDS;i++)
    pinMode(LED_PINS[i],OUTPUT);

  logger::debug(String(AMOUNT_LEDS)+" led's have been set to pinmode(Output).");

  // Opens the first state
  openGameState(new StateWaitForStart);
}

void loop() {
  // Executes the tick event the open state
  currentState->onTick();
}
