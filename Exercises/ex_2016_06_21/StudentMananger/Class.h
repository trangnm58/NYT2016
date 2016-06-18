#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<iomanip>

#include "Student.h"
#include "StudentList.h"

using namespace std;


class Class {
	public:
		Class();
		Class(int id, string name, string year);

		void printInfo();
		void printDetailInfo();
		void printStudentInfo(int studentId);
		
		StudentList<Student> list;
	private:
		int id;
		string name;
		string year;
};

#endif

