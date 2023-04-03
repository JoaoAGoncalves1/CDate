#include "CDate.h"

CDate::CDate() {
	/*
	this->day = 1;
	this->month = 1;
	this->year = 2020;
	setDayOfTheWeek();
	*/
	setToday();
	setDayOfTheWeek();
}
CDate::CDate(int day, int month, int year) {
	setMonth(month);
	setYear(year);
	setDay(day, month);	
	setDayOfTheWeek();
}
void CDate::printDate() {
	std::cout << "Dia:" << this->day << std::endl;
	std::cout << "Mes:" << this->month << std::endl;
	std::cout << "Ano:" << this->year << std::endl;
	std::cout << "Dia da semana: " << this->day_of_the_week << std::endl;
}
void CDate::oneLinePrintDate() {
	std::cout << this->day << "/" << this->month << "/" << this->year << "/" << std::endl;
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
std::string CDate::getDayOfTheWeek() {
	return this->day_of_the_week;
}
std::string CDate::getDayOfTheWeek(CDate date) {
	return date.day_of_the_week;
}
void CDate::setDay(int day, int month){
	if (this->month == 2 && checkLeapYear(this->year)) {		// if leap year
		if (days_of_month[this->month - 1] >= day && day > 0) {			// 28 days
			this->day = day;
		}
		else 
			this->day = 1;
	}
	else if ((days_of_month[this->month - 1]) > day && day > 0) {	//else not leap year
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
void CDate::setDayOfTheWeek() {				// 01/01/2000 saturday
	unsigned long int total_days = 0;
	total_days = total_days + getDay();
	for (int i = 2000; i < (getYear() - 1); i++) {
		if (checkLeapYear(i)) {
			total_days += 366;
		}
		else
			total_days += 365;
	}
	for (int i = 0; i < (getMonth() - 1); i++) {
		total_days += days_of_month[i];
	}
	if (!(checkLeapYear(getYear()) && getMonth() > 1))
		total_days--;

	total_days = total_days % 7;			//since 01/01/2000 was saturday; the first if should be saturday
	if (total_days == 0)
		day_of_the_week = "sabado";
	else if (total_days == 1)
		day_of_the_week = "domingo";
	else if (total_days == 2)
		day_of_the_week = "segunda_feira";
	else if (total_days == 3)
		day_of_the_week = "terca_feira";
	else if (total_days == 4)
		day_of_the_week = "quarta_feira";
	else if (total_days == 5)
		day_of_the_week = "quinta_feira";
	else if (total_days == 6)
		day_of_the_week = "sexta_feira";
}
int CDate::checkLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 1;
	}else
		return 0;
}
unsigned long int CDate::daysBetweenDates(CDate data1, CDate data2){
	unsigned int total_days1, total_days2;
	total_days1 = data1.getDay();
	total_days2 = data2.getDay();
	for (int i = 2000; i < (data1.getYear() - 1); i++) {
		if (checkLeapYear(i)) {
			total_days1 += 366;
		}
		else 
			total_days1 += 365;
	}
	for (int i = 0; i < (data1.getMonth() - 1); i++) {		 
		total_days1 += days_of_month[i];
	}
	if (!(checkLeapYear(data1.getYear()) && data1.getMonth() > 1))
		total_days1--;
	for (int i = 2000; i < (data2.getYear()); i++) {
		if (checkLeapYear(i)) {
			total_days2 += 366;
		}
		else
			total_days2 += 365;
	}
	for (int i = 0; i < (data2.getMonth() - 1); i++) {
		total_days2 += days_of_month[i];
	}
	if (!(checkLeapYear(data2.getYear()) && data2.getMonth() > 1))
		total_days2--;
	unsigned int result = std::abs(static_cast<int>(total_days1) - static_cast<int>(total_days2));
	return result;
}
void CDate::incrementDays(int i) {

	int total_days = this->getDay();
	int days_in_this_month = days_of_month[this->getMonth()];
/*
	if (this->month != 2 && (days_in_this_month >= total_days + i))
		total_days += 6;
	else if (this->month == 2 && checkLeapYear(this->year)) {
	//se for ano bissexto
		if (days_in_this_month >= total_days + i)
			total_days += 6;
		else
			for (int j = 0; j < i; ) (days_of_month[])
	}
	else if (this->month == 2 && !checkLeapYear(this->year) && ((days_in_this_month - 1) > total_days + i)){
	//se não for ano bissexto
		if (days_in_this_month - 1 >= total_days + i)
			total_days += 6;
		
	else if (this->month != 2 && (days_in_this_month < total_days + i)) {
	//se dias ultrapassarem

	}
	*/
		int aux = 0;
		aux = total_days;
		for (int j = 0; j < i; j++) {
			if (days_in_this_month >= total_days) {
				total_days++;
				aux++;
			}
			else if (this->month < 12) {
				this->month++;
				aux = 0;
			}
			else
				this->year++;
				aux = 0;
		}
}
void CDate::setToday(){
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);
	//std::cout << tm.tm_mday << "/" << (tm.tm_mon + 1) << "/" << (tm.tm_year + 1900) << std::endl;
	this->day = tm.tm_mday;
	this->month = tm.tm_mon + 1;
	this->year = tm.tm_year + 1900;
}