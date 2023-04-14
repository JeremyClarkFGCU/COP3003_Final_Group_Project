#ifndef TIMERS_H
#define TIMERS_H

// Needed for Sleep function on Windows Operating system.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
void delay(float seconds) {
	int ms = seconds * 1000;
	Sleep(ms);
}// Delay n seconds

#endif
