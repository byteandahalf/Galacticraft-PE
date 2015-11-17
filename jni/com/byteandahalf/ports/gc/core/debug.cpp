#include "debug.h"

void DEBUG::crash_game() {
	void (*suicide)() = (void (*)()) 0;
	suicide();
}
