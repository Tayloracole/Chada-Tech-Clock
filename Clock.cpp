//Taylor Cole
//9/18/26
//Project One

#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <sstream>
//Constructor: Intializes clock and validates times
Clock::Clock(int h, int m, int s) {
	hours = (h >= 0 && h < 24) ? h : 0;
	minutes = (m >= 0 && m < 60) ? m : 0;
	seconds = (s >= 0 && s < 60) ? s : 0;
}

//Helper method
std::string Clock::twoDigitPad(int number) const {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}
//Formats current time into 12-hour format
std::string Clock::format12Hour() const {
	int displayHour = hours % 12;
	if (displayHour == 0) displayHour = 12;
	std::string amPm = (hours >= 12) ? "P.M." : "A.M."; //Determine which time it is (am/pm)

	return twoDigitPad(displayHour) + ":" + twoDigitPad(minutes) + ":" + twoDigitPad(seconds) + " " + amPm;

}
//Formats the time to 24-hour format (military time)
std::string Clock::format24Hour() const {
	return twoDigitPad(hours) + ":" + twoDigitPad(minutes) + ":" + twoDigitPad(seconds);
}
//Increments clock by 1 hour
void Clock::addOneHour() {
	hours = (hours + 1) % 24;
}
//Increments clock by 1 minute
void Clock::addOneMinute() {
	minutes = (minutes + 1) % 60;
	if (minutes == 0) {
		addOneHour(); //hour roll-over
	}
}
//Increments clock by 1 second
void Clock::addOneSecond() {
	seconds = (seconds + 1) % 60;
	if (seconds == 0) {
		addOneMinute(); //minute roll-over
	}
//Taylor Cole
//9/18/26
//Project One

#include "Clock.h"
#include <iostream>
#include <iomanip>
#include <sstream>
//Constructor: Intializes clock and validates times
Clock::Clock(int h, int m, int s) {
	hours = (h >= 0 && h < 24) ? h : 0;
	minutes = (m >= 0 && m < 60) ? m : 0;
	seconds = (s >= 0 && s < 60) ? s : 0;
}

//Helper method
std::string Clock::twoDigitPad(int number) const {
	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << number;
	return ss.str();
}
//Formats current time into 12-hour format
std::string Clock::format12Hour() const {
	int displayHour = hours % 12;
	if (displayHour == 0) displayHour = 12;
	std::string amPm = (hours >= 12) ? "P.M." : "A.M."; //Determine which time it is (am/pm)

	return twoDigitPad(displayHour) + ":" + twoDigitPad(minutes) + ":" + twoDigitPad(seconds) + " " + amPm;

}
//Formats the time to 24-hour format (military time)
std::string Clock::format24Hour() const {
	return twoDigitPad(hours) + ":" + twoDigitPad(minutes) + ":" + twoDigitPad(seconds);
}
//Increments clock by 1 hour
void Clock::addOneHour() {
	hours = (hours + 1) % 24;
}
//Increments clock by 1 minute
void Clock::addOneMinute() {
	minutes = (minutes + 1) % 60;
	if (minutes == 0) {
		addOneHour(); //hour roll-over
	}
}
//Increments clock by 1 second
void Clock::addOneSecond() {
	seconds = (seconds + 1) % 60;
	if (seconds == 0) {
		addOneMinute(); //minute roll-over
	}
}

//Side-by side clocks displayed
void Clock::displayClocks() const {
	const int innerWidth = 23; 

	
	std::string time12 = format12Hour();
	std::string time24 = format24Hour();

	//Calculate spaces needed for perfect centering
	int pad12 = innerWidth - time12.length();
	int pad24 = innerWidth - time24.length();
	//top border
	std::cout << "*************************** ***************************\n";
	std::cout << "*      12-Hour Clock      * *      24-Hour Clock      *\n";

	// Print 12-Hour Clock
	std::cout << "* " << std::string(pad12 / 2, ' ') << time12 << std::string(pad12 - (pad12 / 2), ' ') << " * ";

	// Print 24-Hour Clock 
	std::cout << "* " << std::string(pad24 / 2, ' ') << time24 << std::string(pad24 - (pad24 / 2), ' ') << " *\n";
	//bottom border
	std::cout << "*************************** ***************************\n";
}
//Display menu with options
void Clock::displayMenu() const {
	std::cout << "\n***************************\n";
	std::cout << "* 1 - Add One Hour          *\n";
	std::cout << "* 2 - Add One Minute        *\n";
	std::cout << "* 3 - Add One Second        *\n";
	std::cout << "* 4 - Exit				  *\n";
	std::cout << "****************************\n";
	std::cout << "Enter your choice: ";
}
