#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include<vector>

#include "Class.h"
#include "Database.h"

using namespace std;


class StudentManager
{
	public:
		StudentManager();
		
		void showMenu();
		
		void insertNewClass();
		void insertNewStudent();
		void insertStudentMarks();

		void printClassList();
		void printClassInfo();
		void printStudentInfo();

	private:
		vector<Class> classList;
		Database database;
		
		void insertMarks(int& testMark1, int& testMark2, int& examMark1, int& examMark2);
};

#endif

