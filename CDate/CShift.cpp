#include "CShift.h"


CShift::CShift() {
	this->date_of_next_shift = CDate();
	this->name_Of_Shift_Chief = "Antonio";
}
CShift::CShift (std::string name, CDate date) {
	this->date_of_next_shift = date;
	this->name_Of_Shift_Chief = name;
}
std::string CShift::getName() {
	return this->name_Of_Shift_Chief;
}
void CShift::setName(std::string name){
	this->name_Of_Shift_Chief = name;
}
void CShift::setArrayOfShiftDates(CDate date) {
	this->array_Shift_Dates[] = date;
}
void CShift::printNextShift() {
	std::cout << "Proximo piquete dia:";
	this->date_of_next_shift.oneLinePrintDate();
}
std::string CShift::getShiftThisDay(CDate date) {
	return date.getDayOfTheWeek();
}
int CShift::checkDateForShift(CDate date) {

	return 0;
}