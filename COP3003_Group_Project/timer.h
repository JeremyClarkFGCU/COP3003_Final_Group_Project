#ifndef TIMER_H
#define TIMER_H

// =============
// Include files
// =============

// Needed for Sleep function on Windows Operating system.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif// End of items needed for Sleep function.

void wait(float seconds) {
	int milliseconds = int(seconds * 1000);
	Sleep(milliseconds);
}// End Wait

#endif
