#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<iomanip>

using namespace std;


struct Subject
{
	int testMark1;
	int testMark2;
	int examMark1;
	int examMark2;
	int sum;
};
typedef struct Subject Subject;


class Student {
	public:
		Student();
		Student(int id, string name, string birthday, int classId);

		string getName() const { return name; }
		string getBirthday() const { return birthday; }
		Subject getMathMarks() const { return math; }
		Subject getPhysicsMarks() const { return physics; }
		Subject getChemistryMarks() const { return chemistry; }

		void setMathMarks(int testMark1, int testMark2, int examMark1, int examMark2);
		void setPhysicsMarks(int testMark1, int testMark2, int examMark1, int examMark2);
		void setChemistryMarks(int testMark1, int testMark2, int examMark1, int examMark2);

		void printInfo();

	private:
		int id;
		string name;
		string birthday;
		int classId;
		
		Subject math;
		Subject physics;
		Subject chemistry;
};

#endif

