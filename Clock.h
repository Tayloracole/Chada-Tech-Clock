

#ifndef CLOCK_H
#define CLOCK_H

#include <string>

class Clock { //create clock class
private:
	int hours;
	int minutes;
	int seconds;

	//Helper methods
	std::string twoDigitPad(int number) const;
	std::string format12Hour() const;
	std::string format24Hour() const;

public: //constructor to initialize time
	Clock(int h = 0, int m = 0, int s = 0);

	//methods to increment time
	void addOneHour();
	void addOneMinute();
	void addOneSecond();
	//methods to display info
	void displayClocks() const; //outputs both clock formats
	void displayMenu() const; //outputs menu for options
};

#endif 
