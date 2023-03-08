#pragma once
#include <iostream>
#include <string>
#include <ctime>

unsigned static const int days_of_month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

class CDate{

	public:
		CDate();												// 01/01/2020 by default
		CDate(int/*day*/, int/*month*/ ,int/*year*/);
		int checkLeapYear(int /*year*/);						// returns 1 if the year is a leap year and 0 if it is not
		void printDate();			
		void oneLinePrintDate();
		int getDay();
		int getMonth();
		int getYear();
		std::string getDayOfTheWeek();
		std::string getDayOfTheWeek(CDate);
		void setDay(int/*day*/, int/*month*/);
		void setMonth(int);
		void setYear(int);
		unsigned long int daysBetweenDates(CDate, CDate);
		void setDayOfTheWeek();
		CDate setToday();
	private:
		std::string day_of_the_week;
		unsigned int day, month, year;
};

