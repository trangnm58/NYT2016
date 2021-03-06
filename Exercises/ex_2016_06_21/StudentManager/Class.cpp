#include "Class.h"


Class::Class()
{
}


Class::Class(int id, string name, string year)
	: id(id), name(name), year(year)
{
}


void Class::printInfo()
{
	const char separator = ' ';
	
	cout << id << "   ";
	cout << left << setw(15) << setfill(separator) << name;
	cout << left << setw(15) << setfill(separator) << year;
	cout << studentList.size() << endl;
}


void Class::printDetailInfo()
{
	const char separator = ' ';
	
	cout << "Class's name: " << name << endl;
	cout << "Year: " << year << endl << endl;
	
	cout << endl << "STT ";
	cout << left << setw(30) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Birthday";
	cout << left << setw(6) << setfill(separator) << "Math";
	cout << left << setw(9) << setfill(separator) << "Physics";
	cout << "Chemistry" << endl;
	for (int i = 0; i < studentList.size(); i++) {
		studentList[i].printInfo();
	}
	cout << endl << endl;
}


void Class::printStudentInfo(int studentId) {
	const char separator = ' ';
	
	cout << "Class's name: " << name << endl;
	cout << "Year: " << year << endl << endl;
	
	cout << endl << "STT ";
	cout << left << setw(30) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Birthday";
	cout << left << setw(6) << setfill(separator) << "Math";
	cout << left << setw(9) << setfill(separator) << "Physics";
	cout << "Chemistry" << endl;
	
	studentList[studentId].printInfo();
	cout << endl << endl;
}

