#include "Shifts_Def.h"
void define_Shifts() {
	CDate data_piquete(12,03,2023);
	CShift primero_turno("Primeiro piquete", data_piquete);
	for (int i = 0; i < size_of_Shift_Date; i++) {
		primero_turno.setArrayOfShiftDates(data_piquete);
		data_piquete = data_piquete.incrementDays(i);
	}
}