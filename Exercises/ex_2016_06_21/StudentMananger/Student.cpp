#include "Student.h"

Student::Student()
{
}

Student::Student(int id, string name, string birthday, int classId)
		: id(id), name(name), birthday(birthday), classId(classId)
{
	this->setMathMarks(0, 0, 0, 0);
	this->setPhysicsMarks(0, 0, 0, 0);
	this->setChemistryMarks(0, 0, 0, 0);
}

void Student::setMathMarks(int testMark1, int testMark2, int examMark1, int examMark2)
{
	testMark1 >= 0 ? this->math.testMark1 = testMark1 : this->math.testMark1 = 0;
	testMark2 >= 0 ? this->math.testMark2 = testMark2 : this->math.testMark2 = 0;
	examMark1 >= 0 ? this->math.examMark1 = examMark1 : this->math.examMark1 = 0;
	examMark2 >= 0 ? this->math.examMark2 = examMark2 : this->math.examMark2 = 0;
	
	// calculate the sum
	this->math.sum = this->math.testMark1 + this->math.testMark2 + this->math.examMark1 + this->math.examMark2;
}

void Student::setPhysicsMarks(int testMark1, int testMark2, int examMark1, int examMark2)
{
	testMark1 >= 0 ? this->physics.testMark1 = testMark1 : this->physics.testMark1 = 0;
	testMark2 >= 0 ? this->physics.testMark2 = testMark2 : this->physics.testMark2 = 0;
	examMark1 >= 0 ? this->physics.examMark1 = examMark1 : this->physics.examMark1 = 0;
	examMark2 >= 0 ? this->physics.examMark2 = examMark2 : this->physics.examMark2 = 0;
	
	// calculate the sum
	this->physics.sum = this->physics.testMark1 + this->physics.testMark2 + this->physics.examMark1 + this->physics.examMark2;
}

void Student::setChemistryMarks(int testMark1, int testMark2, int examMark1, int examMark2)
{
	testMark1 >= 0 ? this->chemistry.testMark1 = testMark1 : this->chemistry.testMark1 = 0;
	testMark2 >= 0 ? this->chemistry.testMark2 = testMark2 : this->chemistry.testMark2 = 0;
	examMark1 >= 0 ? this->chemistry.examMark1 = examMark1 : this->chemistry.examMark1 = 0;
	examMark2 >= 0 ? this->chemistry.examMark2 = examMark2 : this->chemistry.examMark2 = 0;
	
	// calculate the sum
	this->chemistry.sum = this->chemistry.testMark1 + this->chemistry.testMark2 + this->chemistry.examMark1 + this->chemistry.examMark2;
}

void Student::printInfo()
{
	const char separator = ' ';

	cout << id << "   ";
	cout << left << setw(30) << setfill(separator) << name;
	cout << left << setw(15) << setfill(separator) << birthday;
	cout << left << setw(6) << setfill(separator) << math.sum;
	cout << left << setw(9) << setfill(separator) << physics.sum;
	cout << chemistry.sum << endl;
}

