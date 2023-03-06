#include "CDate.h"

CDate::CDate() {
	this->day = 1;
	this->month = 1;
	this->year = 2020;
}
CDate::CDate(int day, int month, int year) {
	setMonth(month);
	setYear(year);
	setDay(day, month);	
}
void CDate::printDate() {
	std::cout << "Dia:" << this->day << std::endl;
	std::cout << "Mes:" << this->month << std::endl;
	std::cout << "Ano:" << this->year << std::endl;
}
int CDate::getDay() {
	return day;
}
int CDate::getMonth() {
	return month;
}
int CDate::getYear() {
	return year;
}
void CDate::setDay(int day, int month){
	if (this->month == 2 && checkLeapYear(this->year, this->day)) {		// if leap year
		if (days_of_month[this->month - 1] > day && day > 0) {			// 28 days
			this->day = day;
		}
	}
	else if ((days_of_month[this->month - 1] - 1) > day && day > 0) {	//else not leap year
		this->day = day;
	}
	else
		this->day = 1;
}
void CDate::setMonth(int month){
	if (month > 12 || month < 0) {
		this->month = 1;
	}
	else
		this->month = month;
}
void CDate::setYear(int year){
	if (year < 2000) {
		this->year = 2000;
	}
	else 
		this->year = year;
}
int CDate::checkLeapYear(int year, int day) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}else
		return 0;
}