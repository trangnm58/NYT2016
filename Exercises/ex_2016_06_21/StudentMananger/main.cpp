/**
 * Nguyen Minh Trang
 * 2016/06/19
 * Project: Student Manager
 */

#include<fstream>

#include "Class.h"
#include "ClassList.h"


/*--------- FUNCTIONS DECLARATIONS -----------*/
void readFromDatabase(ClassList<Class> &list, string fileName);
void saveToDatabase(ClassList<Class> &list, string fileName);
void insertNewClass(ClassList<Class> &list);
void insertNewStudent(ClassList<Class> &list);
void insertStudentMarks(ClassList<Class> &list);
void printClassList(ClassList<Class> &list);
void printClassInfo(ClassList<Class> &list);
void printStudentInfo(ClassList<Class> &list);


int main() {
	ClassList<Class> list;
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
void readFromDatabase(ClassList<Class> &list, string fileName) {
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
		list.append(c);
		
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
			list.element(i).list.append(s);
			
			// read student's marks
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list.element(i).list.element(j).setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list.element(i).list.element(j).setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			inStream >> testMark1 >> testMark2 >> examMark1 >> examMark2;
			list.element(i).list.element(j).setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
	
	inStream.close();
}

void saveToDatabase(ClassList<Class> &list, string fileName) {
	ofstream outStream;
	outStream.open(fileName.c_str());
	
	int numOfClasses = list.length();
	outStream << numOfClasses << endl;
	
	for (int i=0; i < numOfClasses; i++) {
		outStream << list.element(i).getName() << endl;
		outStream << list.element(i).getYear() << endl;
		
		int numOfStudents = list.element(i).list.length();
		outStream << numOfStudents << endl;
		for (int j=0; j < numOfStudents; j++) {
			outStream << list.element(i).list.element(j).getName() << endl;
			outStream << list.element(i).list.element(j).getBirthday() << endl;
			
			outStream << list.element(i).list.element(j).getMathMarks().testMark1 << " ";
			outStream << list.element(i).list.element(j).getMathMarks().testMark2 << " ";
			outStream << list.element(i).list.element(j).getMathMarks().examMark1 << " ";
			outStream << list.element(i).list.element(j).getMathMarks().examMark2 << endl;
			
			outStream << list.element(i).list.element(j).getPhysicsMarks().testMark1 << " ";
			outStream << list.element(i).list.element(j).getPhysicsMarks().testMark2 << " ";
			outStream << list.element(i).list.element(j).getPhysicsMarks().examMark1 << " ";
			outStream << list.element(i).list.element(j).getPhysicsMarks().examMark2 << endl;
			
			outStream << list.element(i).list.element(j).getChemistryMarks().testMark1 << " ";
			outStream << list.element(i).list.element(j).getChemistryMarks().testMark2 << " ";
			outStream << list.element(i).list.element(j).getChemistryMarks().examMark1 << " ";
			outStream << list.element(i).list.element(j).getChemistryMarks().examMark2 << endl;
		}
	}
	
	outStream.close();
}

void insertNewClass(ClassList<Class> &list) {
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
			list.append(c);
		}
	}
}

void insertNewStudent(ClassList<Class> &list) {
	int classId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.length()) {
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
				list.element(classId).list.append(s);
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

void insertStudentMarks(ClassList<Class> &list) {
	int classId, studentId;

	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.length()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= list.element(classId).list.length()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			int testMark1, testMark2, examMark1, examMark2;
			
			studentId--;  // change to index
			
			// Math
			cout << "Math:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list.element(classId).list.element(studentId).setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Physics
			cout << "Physics:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list.element(classId).list.element(studentId).setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Chemistry
			cout << "Chemistry:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			list.element(classId).list.element(studentId).setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
}

void printClassList(ClassList<Class> &list) {
	const char separator = ' ';
	
	cout << endl << "STT ";
	cout << left << setw(15) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Year";
	cout << "Number of Students" << endl;
	for (int i = 0; i < list.length(); i++) {
		list.element(i).printInfo();
	}
	cout << endl << endl;
}

void printClassInfo(ClassList<Class> &list) {
	int classId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.length()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		list.element(classId).printDetailInfo();
	}
}

void printStudentInfo(ClassList<Class> &list) {
	int classId, studentId;
	
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= list.length()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= list.element(classId).list.length()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			studentId--;  // change to index
			
			list.element(classId).printStudentInfo(studentId);
		}
	}
}

