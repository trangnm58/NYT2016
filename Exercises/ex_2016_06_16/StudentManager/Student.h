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
		void printInfo();

	private:
		int id;
		string name;
		string birthday;
		
		int winMark;
		int wordMark;
		int jiraMark;
		int sum;
		string rank;
};

#endif

