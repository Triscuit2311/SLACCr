#include "Boot/boot.h"



void setup() {
  core_0_initialize();
}

void loop() {
  core_0_tick();
}


void setup1() {
  core_1_initialize();
}

void loop1() {
  core_1_tick();
}

