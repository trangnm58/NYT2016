/**
 * Nguyen Minh Trang
 * 2016/06/19
 * Project: Student Manager
 */

#include<fstream>
#include<vector>

#include "Class.h"

using namespace std;


/*--------- FUNCTIONS DECLARATIONS -----------*/
void readFromDatabase(vector<Class> &list, string fileName);
void saveToDatabase(vector<Class> &list, string fileName);
void insertNewClass(vector<Class> &list);
void insertNewStudent(vector<Class> &list);
void insertStudentMarks(vector<Class> &list);
void printClassList(vector<Class> &list);
void printClassInfo(vector<Class> &list);
void printStudentInfo(vector<Class> &list);


int main() {
	vector<Class> list;
	int choice;

	// read data from file
	readFromDatabase(list, "database.txt");

	while (true) {
		cout << "Choose:" << endl;
		cout << "1. Insert New Class" << endl;
		cout << "2. Insert New Student" << endl;
		cout << "3. Insert Student's Marks" << endl;
		cout << "4. Print Class List" << endl;
		cout << "5. Print Class Info" << endl;
		cout << "6. Print Student Info" << endl;
		cout << "7. Exit" << endl;
		cin >> choice;

		if (choice == 1) {
			// insert new class
			insertNewClass(list);
		} else if (choice == 2) {
			// insert new student
			insertNewStudent(list);
		} else if (choice == 3) {
			// insert a specific student's marks
			insertStudentMarks(list);
		} else if (choice == 4) {
			// print class list
			printClassList(list);
		} else if (choice == 5) {
			// print class info
			printClassInfo(list);
		} else if (choice == 6) {
			// print a specific student's info
			printStudentInfo(list);
		} else if (choice == 7) {
			// save data to file
			saveToDatabase(list, "database.txt");		
			break;
		}
	}
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void readFromDatabase(vector<Class> &list, string fileName) {
	ifstream inStream;
	inStream.open(fileName.c_str());
	
	int numOfClasses;
	inStream >> numOfClasses;
	
	for (int i=0; i < numOfClasses; i++) {
		string name, year;
		string temp;  // placeholder for endline, to clear ifstream for getline()
		
		inStream.ignore(INT_MAX, '\n');
		getline(inStream, name);

		inStream >> year;

		Class c(i + 1, name, year);
		list.push_back(c);
		
		// read students data in the class
		int numOfStudents;
		
		inStream >> numOfStudents;
		
		for (int j=0; j < numOfStudents; j++) {
			string name, birthday;
			int testMark1, testMark2, examMark1, examMark2;

			inStream.ignore(INT_MAX, '\n');
			getline(inStream, name);
			
			inStream >> birthday;
			
			Student s(j + 1, name, birthday, i + 1);
			list[i].list.push_back(s);
			
			// read student's marks
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list[i].list[j].setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list[i].list[j].setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list[i].list[j].setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
	
	inStream.close();
}

void saveToDatabase(vector<Class> &list, string fileName) {
	ofstream outStream;
	outStream.open(fileName.c_str());
	
	int numOfClasses = list.size();
	outStream << numOfClasses << endl;
	
	for (int i=0; i < numOfClasses; i++) {
		outStream << list[i].getName() << endl;
		outStream << list[i].getYear() << endl;
		
		int numOfStudents = list[i].list.size();
		outStream << numOfStudents << endl;
		for (int j=0; j < numOfStudents; j++) {
			outStream << list[i].list[j].getName() << endl;
			outStream << list[i].list[j].getBirthday() << endl;
			
			outStream << list[i].list[j].getMathMarks().testMark1 << " ";
			outStream << list[i].list[j].getMathMarks().testMark2 << " ";
			outStream << list[i].list[j].getMathMarks().examMark1 << " ";
			outStream << list[i].list[j].getMathMarks().examMark2 << endl;
			
			outStream << list[i].list[j].getPhysicsMarks().testMark1 << " ";
			outStream << list[i].list[j].getPhysicsMarks().testMark2 << " ";
			outStream << list[i].list[j].getPhysicsMarks().examMark1 << " ";
			outStream << list[i].list[j].getPhysicsMarks().examMark2 << endl;
			
			outStream << list[i].list[j].getChemistryMarks().testMark1 << " ";
			outStream << list[i].list[j].getChemistryMarks().testMark2 << " ";
			outStream << list[i].list[j].getChemistryMarks().examMark1 << " ";
			outStream << list[i].list[j].getChemistryMarks().examMark2 << endl;
		}
	}
	
	outStream.close();
}

void insertNewClass(vector<Class> &list) {
	int numOfClasses;

	cout << "\nNumber of classes: ";
	cin >> numOfClasses;
	if (numOfClasses <= 0) {
		cout << "Invalid input!" << endl;
	} else  {
		for (int i = 0; i < numOfClasses; i++) {
			char name[30];
			string year;

			cout << "Class " << i + 1 << endl;
			// get name
			cout << "\tName: ";
			cin.clear();
			fflush(stdin);
			cin.getline(name, 30);

			// get birthday
			cout << "\tYear: ";
			cin >> year;

			Class c(i + 1, name, year);
			list.push_back(c);
		}
	}
}

void insertNewStudent(vector<Class> &list) {
	int classId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		int numOfStudents;
	
		cout << "\nNumber of students: ";
		cin >> numOfStudents;
		if (numOfStudents <= 0) {
			cout << "Invalid input!" << endl;
		} else  {
			for (int i = 0; i < numOfStudents; i++) {
				char name[30];
				string birthday;
				
				cout << "Student " << i + 1 << endl;
				// get name
				cout << "\tName: ";
				cin.clear();
				fflush(stdin);
				cin.getline(name, 30);
		
				// get birthday
				cout << "\tBirthday: ";
				cin >> birthday;
				
				Student s(i + 1, name, birthday, classId + 1);
				list[classId].list.push_back(s);
			}
		}
	}
}

void insertMarks(int& testMark1, int& testMark2, int& examMark1, int& examMark2) {
	cout << "\tTest Mark 1: ";
	cin >> testMark1;
	
	cout << "\tTest Mark 2: ";
	cin >> testMark2;
	
	cout << "\tExam Mark 1: ";
	cin >> examMark1;
	
	cout << "\tExam Mark 1: ";
	cin >> examMark2;
}

void insertStudentMarks(vector<Class> &list) {
	int classId, studentId;

	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= list[classId].list.size()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			int testMark1, testMark2, examMark1, examMark2;
			
			studentId--;  // change to index
			
			// Math
			cout << "Math:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list[classId].list[studentId].setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Physics
			cout << "Physics:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list[classId].list[studentId].setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Chemistry
			cout << "Chemistry:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list[classId].list[studentId].setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
}

void printClassList(vector<Class> &list) {
	const char separator = ' ';
	
	cout << endl << "STT ";
	cout << left << setw(15) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Year";
	cout << "Number of Students" << endl;
	for (int i = 0; i < list.size(); i++) {
		list[i].printInfo();
	}
	cout << endl << endl;
}

void printClassInfo(vector<Class> &list) {
	int classId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		list[classId].printDetailInfo();
	}
}

void printStudentInfo(vector<Class> &list) {
	int classId, studentId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= list[classId].list.size()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			studentId--;  // change to index
			
			list[classId].printStudentInfo(studentId);
		}
	}
}

