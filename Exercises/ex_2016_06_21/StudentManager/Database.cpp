#include "Database.h"


Database::Database()
{
}


void Database::readFromDatabase(vector<Class> &classList, string fileName)
{
	ifstream inStream;
	inStream.open(fileName.c_str());
	
	int numOfClasses = 0;
	inStream >> numOfClasses;
	
	for (int i=0; i < numOfClasses; i++) {
		string name = "";
		inStream.ignore(INT_MAX, '\n');
		getline(inStream, name);

		string year = "";
		inStream >> year;

		int classId = i + 1;
		Class newClass(classId, name, year);
		classList.push_back(newClass);
		
		// read students data in the class
		int numOfStudents = 0;
		inStream >> numOfStudents;
		
		for (int j=0; j < numOfStudents; j++) {
			string name = "";
			inStream.ignore(INT_MAX, '\n');
			getline(inStream, name);
			
			string birthday = "";
			inStream >> birthday;

			int studentId = j + 1;
			Student newStudent(studentId, name, birthday, i + 1);
			classList[i].studentList.push_back(newStudent);

			// read student's marks
			int testMark1, testMark2, examMark1, examMark2;

			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			classList[i].studentList[j].setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			classList[i].studentList[j].setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			classList[i].studentList[j].setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
	
	inStream.close();
}


void Database::saveToDatabase(vector<Class> &classList, string fileName)
{
	ofstream outStream;
	outStream.open(fileName.c_str());
	
	int numOfClasses = classList.size();
	outStream << numOfClasses << endl;
	
	for (int i=0; i < numOfClasses; i++) {
		outStream << classList[i].getName() << endl;
		outStream << classList[i].getYear() << endl;
		
		int numOfStudents = classList[i].studentList.size();
		outStream << numOfStudents << endl;

		for (int j=0; j < numOfStudents; j++) {
			outStream << classList[i].studentList[j].getName() << endl;
			outStream << classList[i].studentList[j].getBirthday() << endl;
			
			outStream << classList[i].studentList[j].getMathMarks().testMark1 << " ";
			outStream << classList[i].studentList[j].getMathMarks().testMark2 << " ";
			outStream << classList[i].studentList[j].getMathMarks().examMark1 << " ";
			outStream << classList[i].studentList[j].getMathMarks().examMark2 << endl;
			
			outStream << classList[i].studentList[j].getPhysicsMarks().testMark1 << " ";
			outStream << classList[i].studentList[j].getPhysicsMarks().testMark2 << " ";
			outStream << classList[i].studentList[j].getPhysicsMarks().examMark1 << " ";
			outStream << classList[i].studentList[j].getPhysicsMarks().examMark2 << endl;
			
			outStream << classList[i].studentList[j].getChemistryMarks().testMark1 << " ";
			outStream << classList[i].studentList[j].getChemistryMarks().testMark2 << " ";
			outStream << classList[i].studentList[j].getChemistryMarks().examMark1 << " ";
			outStream << classList[i].studentList[j].getChemistryMarks().examMark2 << endl;
		}
	}
	
	outStream.close();
}

