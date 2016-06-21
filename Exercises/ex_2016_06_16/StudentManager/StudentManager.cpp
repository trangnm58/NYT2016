#include "StudentManager.h"


StudentManager::StudentManager()
{
}


void StudentManager::showMenu()
{
	cout << "Choose:" << endl;
	cout << "1. Insert Students Info" << endl;
	cout << "2. Insert Student's Marks" << endl;
	cout << "3. Print Students List" << endl;
	cout << "4. Exit" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			insertStudentsInfo();
			break;
			
		case 2:
			if (studentList.size() == 0) {
				// there is no student in the list
				cout << "Please insert students info first!" << endl;
			} else {
				insertStudentMarks();
			}
			break;
			
		case 3:
			printStudentList();
			break;
			
		case 4:
			exit(0);
			
		default:
			cout << "Invalid choice!" << endl;
	}
}


void StudentManager::insertStudentsInfo()
{
	cout << "\nNumber of students: ";

	int numOfStudents;
	cin >> numOfStudents;

	if (numOfStudents <= 0) {
		cout << "Invalid input!" << endl;
	} else  {
		for (int i = 0; i < numOfStudents; i++) {
			int studentId = studentList.size() + 1;
			cout << "Student " << studentId << endl;

			// get name
			char name[NAME_LENGTH];
			cout << "\tName: ";
			cin.clear();
			fflush(stdin);
			cin.getline(name, NAME_LENGTH);
	
			// get birthday
			string birthday;
			cout << "\tBirthday: ";
			cin >> birthday;
			
			Student newStudent(studentId, name, birthday);
			studentList.push_back(newStudent);
		}
	}
}


void StudentManager::insertStudentMarks()
{
	cout << "Student's ID: ";

	int studentId;
	cin >> studentId;

	if (studentId - 1 >= studentList.size()) {
		cout << "Student " << studentId << " is not found!" << endl;
	} else {
		studentId--;  // change to index

		int winMark = 0;
		cout << "\tWindows Mark: ";
		cin >> winMark;
		
		int wordMark = 0;
		cout << "\tWord Mark: ";
		cin >> wordMark;
		
		int jiraMark = 0;
		cout << "\tJira Mark: ";
		cin >> jiraMark;
		
		studentList[studentId].setMarks(winMark, wordMark, jiraMark);
	}
}


void StudentManager::printStudentList()
{
	const char separator = ' ';
	
	cout << endl << "STT ";
	cout << left << setw(30) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Birthday";
	cout <<"Sum\tRank" << endl;

	for (int i = 0; i < studentList.size(); i++) {
		studentList[i].printInfo();
	}
	cout << endl;
}

