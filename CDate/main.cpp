#include "CShift.h"

using namespace std;

int main() {

	CDate dataPiquete(17, 1, 2023);
	CShift piquete("Jorge", dataPiquete);
	piquete.printNextShift();
	dataPiquete.setToday();
	return 0;
}