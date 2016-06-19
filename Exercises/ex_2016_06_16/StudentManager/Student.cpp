#include "Student.h"

Student::Student()
{
}

Student::Student(int id, string name, string birthday)
		: id(id), name(name), birthday(birthday)
{
	this->setMarks(0, 0, 0);
	this->rank = "Unranked";
}

void Student::setMarks(int winMark, int wordMark, int jiraMark)
{
	winMark >= 0 ? this->winMark = winMark : this->winMark = 0;
	wordMark >= 0 ? this->wordMark = wordMark : this->wordMark = 0;
	jiraMark >= 0 ? this->jiraMark = jiraMark : this->jiraMark = 0;
	
	// calculate the sum
	sum = this->winMark + this->wordMark + this->jiraMark;
	
	// calculate the rank
	if (sum >= 24) {
		rank = "Exellence";
	} else if (sum < 24 && sum >= 18) {
		rank = "Good";
	} else {
		rank = "Average";
	}
}

void Student::printInfo()
{
	const char separator = ' ';

	cout << left << setw(4) << setfill(separator) << id;
	cout << left << setw(30) << setfill(separator) << name;
	cout << left << setw(15) << setfill(separator) << birthday;
	cout << sum << "\t" << rank << endl;
}

