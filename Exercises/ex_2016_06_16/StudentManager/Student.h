#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<iomanip>
using namespace std;


class Student {
	public:
		Student();
		Student(int id, string name, string birthday);

		void setMarks(int winMark, int wordMark, int jiraMark);
		int getSum() const;
		string getRank() const;
		void printInfo();

		string name;
		string birthday;
		int winMark;
		int wordMark;
		int jiraMark;

	private:
		int id;
		int sum;
		string rank;
};

#endif

