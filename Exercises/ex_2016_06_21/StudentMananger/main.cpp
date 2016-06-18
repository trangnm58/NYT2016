/**
 * Nguyen Minh Trang
 * 2016/06/18
 * Project: Student Manager
 */

#include "Class.h"
#include "ClassList.h"


/*--------- FUNCTIONS DECLARATIONS -----------*/
void insertNewClass(ClassList<Class> &list);
void insertNewStudent(ClassList<Class> &list);
void insertStudentMarks(ClassList<Class> &list);
void printClassList(ClassList<Class> &list);
void printClassInfo(ClassList<Class> &list);
void printStudentInfo(ClassList<Class> &list);


int main() {
	ClassList<Class> list;
	int choice;

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
			break;
		}
	}
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
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

