#pragma once
#include "CDate.h"

#define size_of_Shift_Date 50

class CShift{
	public:
		CShift();
		CShift(std::string/*name_Of_Shift_Chief*/, CDate/*date_of_next_shift*/);		
		std::string getName();					//create a shift
		void setName(std::string);				//chief's name
		void setArrayOfShiftDates(CDate);				//chief's name
		void printNextShift();					//date that will be incremented
		std::string getShiftThisDay(CDate);		//shift's day of the week
		int checkDateForShift(CDate);
//		void setDa

	private:
		CDate date_of_next_shift;
		CDate array_Shift_Dates[size_of_Shift_Date];
		std::string name_Of_Shift_Chief;
};

