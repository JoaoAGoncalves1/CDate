#pragma once
#include <iostream>

unsigned static const int days_of_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

class CDate{

	public:
		CDate();						// 01/01/2020 by default
		CDate(int/*day*/, int/*month*/ ,int/*year*/);
		int checkLeapYear(int /*year*/, int/*month*/);	// returns 1 if the year is a leap year and 0 if it is not
		void printDate();				
		int getDay();
		int getMonth();
		int getYear();
		void setDay(int/*day*/, int/*month*/);
		void setMonth(int);
		void setYear(int);
	
	private:
		unsigned int day, month, year;
};

