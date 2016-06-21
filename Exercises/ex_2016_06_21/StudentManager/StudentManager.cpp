#include "StudentManager.h"


StudentManager::StudentManager()
{
	database.readFromDatabase(classList, "database.txt");
}


void StudentManager::showMenu()
{
	cout << "Choose:" << endl;
	cout << "1. Insert New Class" << endl;
	cout << "2. Insert New Student" << endl;
	cout << "3. Insert Student's Marks" << endl;
	cout << "4. Print Class List" << endl;
	cout << "5. Print Class Info" << endl;
	cout << "6. Print Student Info" << endl;
	cout << "7. Exit" << endl;

	int choice = 0;
	cin >> choice;

	switch (choice) {
		case 1:
			// insert new class
			insertNewClass();
			break;

		case 2:
			// insert new student
			insertNewStudent();
			break;

		case 3:
			// insert a specific student's marks
			insertStudentMarks();
			break;

		case 4:
			// print class list
			printClassList();
			break;

		case 5:
			// print class info
			printClassInfo();
			break;

		case 6:
			// print a specific student's info
			printStudentInfo();
			break;

		case 7:
			// save to database
			database.saveToDatabase(classList, "database.txt");
			exit(0);
		
		default:
			cout << "Invalid choice!" << endl;
	}
}


void StudentManager::insertNewClass()
{
	int numOfClasses = 0;
	cout << "\nNumber of classes: ";
	cin >> numOfClasses;

	if (numOfClasses <= 0) {
		cout << "Invalid input!" << endl;
	} else  {
		for (int i = 0; i < numOfClasses; i++) {
			int classId = classList.size() + 1;
			cout << "Class " << classId << endl;

			// get name
			char name[30];
			cout << "\tName: ";
			cin.clear();
			fflush(stdin);
			cin.getline(name, 30);

			// get birthday
			string year = "";
			cout << "\tYear: ";
			cin >> year;

			Class newClass(classId, name, year);
			classList.push_back(newClass);
		}
	}
}


void StudentManager::insertNewStudent()
{
	int classId = 0;
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= classList.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		int numOfStudents = 0;
		cout << "\nNumber of students: ";
		cin >> numOfStudents;

		if (numOfStudents <= 0) {
			cout << "Invalid input!" << endl;
		} else  {
			for (int i = 0; i < numOfStudents; i++) {
				int studentId = classList[classId].studentList.size() + 1;
				cout << "Student " << studentId << endl;
				
				// get name
				char name[30];
				cout << "\tName: ";
				cin.clear();
				fflush(stdin);
				cin.getline(name, 30);
		
				// get birthday
				string birthday = "";
				cout << "\tBirthday: ";
				cin >> birthday;
				
				Student newStudent(studentId, name, birthday, classId + 1);
				classList[classId].studentList.push_back(newStudent);
			}
		}
	}
}


void StudentManager::insertMarks(int& testMark1, int& testMark2, int& examMark1, int& examMark2) {
	cout << "\tTest Mark 1: ";
	cin >> testMark1;
	
	cout << "\tTest Mark 2: ";
	cin >> testMark2;
	
	cout << "\tExam Mark 1: ";
	cin >> examMark1;
	
	cout << "\tExam Mark 1: ";
	cin >> examMark2;
}


void StudentManager::insertStudentMarks()
{
	int classId = 0;
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= classList.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		int studentId = 0;
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= classList[classId].studentList.size()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			int testMark1, testMark2, examMark1, examMark2;
			
			studentId--;  // change to index
			
			// Math
			cout << "Math:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			classList[classId].studentList[studentId].setMathMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Physics
			cout << "Physics:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			classList[classId].studentList[studentId].setPhysicsMarks(testMark1, testMark2, examMark1, examMark2);
			
			// Chemistry
			cout << "Chemistry:" << endl;
			insertMarks(testMark1, testMark2, examMark1, examMark2);
			classList[classId].studentList[studentId].setChemistryMarks(testMark1, testMark2, examMark1, examMark2);
		}
	}
}


void StudentManager::printClassList()
{
	const char separator = ' ';
	
	cout << endl << "STT ";
	cout << left << setw(15) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Year";
	cout << "Number of Students" << endl;
	for (int i = 0; i < classList.size(); i++) {
		classList[i].printInfo();
	}
	cout << endl << endl;
}


void StudentManager::printClassInfo()
{
	int classId = 0;
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= classList.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		classList[classId].printDetailInfo();
	}
}


void StudentManager::printStudentInfo()
{
	int classId = 0;
	cout << "Class's ID: ";
	cin >> classId;
	
	if (classId - 1 >= classList.size()) {
		cout << "Class " << classId << " is not found!" << endl;
	} else {
		classId--;  // change to index
		
		int studentId = 0;
		cout << "Student's ID: ";
		cin >> studentId;
		
		if (studentId - 1 >= classList[classId].studentList.size()) {
			cout << "Student " << studentId << " is not found!" << endl;
		} else {
			studentId--;  // change to index
			
			classList[classId].printStudentInfo(studentId);
		}
	}
}

