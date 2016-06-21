#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include<vector>

#include "Student.h"

using namespace std;


const int NAME_LENGTH = 30;


class StudentManager {
	public:
		StudentManager();

		void showMenu();
		void insertStudentsInfo();
		void insertStudentMarks();
		void printStudentList();

	private:
		vector<Student> studentList;
};

#endif

