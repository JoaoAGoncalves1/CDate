#pragma once
#include "CDate.h"
class CShift{
	public:
		CShift();
		CShift(std::string, CDate);
		std::string getName();					//create a shift
		void setName(std::string);				//chief's name
		void printNextShift();					//date that will be incremented
		std::string getShiftThisDay(CDate);		//shift's day of the week
		int checkDateForShift(CDate);
//		void setDa
	private:
		CDate date_of_next_shift;
		CDate array_Shift_Dates[50];
		std::string name_Of_Shift_Chief;
};

