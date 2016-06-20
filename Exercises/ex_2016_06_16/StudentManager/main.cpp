/**
 * Nguyen Minh Trang
 * 2016/06/17
 * Project: Student Manager
 */

#include<vector>

#include "Student.h"


/*--------- FUNCTIONS DECLARATIONS -----------*/
void printList(vector<Student> list);
void insertStudentsInfo(vector<Student> &list);
void insertStudentMarks(vector<Student> &list);


int main() {
	vector<Student> list;
	int choice;

	while (true) {
		cout << "Choose:" << endl;
		cout << "1. Insert Students Info" << endl;
		cout << "2. Insert Student's Marks" << endl;
		cout << "3. Print Students List" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		if (choice == 1) {
			insertStudentsInfo(list);
		} else if (choice == 2) {
			if (list.size() == 0) {
				// there is no student in the list
				cout << "Please insert students info first!" << endl;
			} else {
				insertStudentMarks(list);
			}
		} else if (choice == 3) {
			printList(list);
		} else if (choice == 4) {
			break;
		}
	}
	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void printList(vector<Student> list) {
	const char separator = ' ';
	
	cout << endl << "STT ";
	cout << left << setw(30) << setfill(separator) << "Name";
	cout << left << setw(15) << setfill(separator) << "Birthday";
	cout <<"Sum\tRank" << endl;
	for (int i = 0; i < list.size(); i++) {
		list[i].printInfo();
	}
	cout << endl;
}

void insertStudentsInfo(vector<Student> &list) {
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
			
			Student s(i + 1, name, birthday);
			list.push_back(s);
		}
	}
}

void insertStudentMarks(vector<Student> &list) {
	int winMark, wordMark, jiraMark;
	int studentId;

	cout << "Student's ID: ";
	cin >> studentId;

	if (studentId - 1 >= list.size()) {
		cout << "Student " << studentId << " is not found!" << endl;
	} else {
		studentId--;  // change to index
	
		cout << "\tWindows Mark: ";
		cin >> winMark;
		
		cout << "\tWord Mark: ";
		cin >> wordMark;
		
		cout << "\tJira Mark: ";
		cin >> jiraMark;
		
		list[studentId].setMarks(winMark, wordMark, jiraMark);
	}
}

