/**
 * Nguyen Minh Trang
 * 2016/06/16
 * Program: Student Manager
 * hoang.phan@niteco.se
 */

#include <iostream>
using namespace std;


struct Student
{
	char name[30];
	char birthday[8];
	int winMark;
	int wordMark;
	int jiraMark;
	int sum;
	string rank;
};
typedef struct Student Student;


/*--------- FUNCTIONS DECLARATIONS -----------*/
void printList(Student* students, int numOfStudent);
void insertStudentsInfo(Student* students, int numOfStudents);
void insertStudentMarks(Student* students, int studentId);


int main() {
	Student *students;
	int choice;
	int numOfStudents = 0;
	
	while (true) {
		cout << "\nChoose:" << endl;
		cout << "1. Insert Students Info" << endl;
		cout << "2. Insert Student's Marks" << endl;
		cout << "3. Print Students List" << endl;
		cout << "4. Exit" << endl << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "Number of students: ";
			cin >> numOfStudents;
			if (numOfStudents <= 0) {
				cout << "Invalid input!" << endl;
				return 1;
			}

			students = new Student[numOfStudents];

			insertStudentsInfo(students, numOfStudents);
		} else if (choice == 2) {
			if (numOfStudents == 0) {
				cout << "Please insert students info first!";
			} else {
				int studentId;
				cout << "Student's ID: ";
				cin >> studentId;

				insertStudentMarks(students, studentId);
			}
		} else if (choice == 3) {
			printList(students, numOfStudents);
		} else if (choice == 4) {
			break;
		}
	}

	return 0;
}


/*--------- FUNCTIONS DEFINITIONS -----------*/
void printList(Student* students, int numOfStudents) {
	// table headings with spaces and tabs
	cout << "\nSTT\tName\t\tBirthday\tSum\tRank" << endl;

	for (int i = 0; i < numOfStudents; i++) {
		cout << i+1 << "\t" << students[i].name << "\t" << students[i].birthday
			<< "\t" << students[i].sum << "\t" << students[i].rank << endl;
	}
}

void insertStudentsInfo(Student* students, int numOfStudents) {
	for (int i=0; i < numOfStudents; i++) {
		cout << "Student " << i+1 << endl;
		// name
		cout << "Name: ";
		cin.clear();
		fflush(stdin);
		cin.getline(students[i].name, 30);

		// birthday
		cout << "Birthday: ";
		cin >> students[i].birthday;
		
		// set default marks and rank
		students[i].winMark = 0;
		students[i].wordMark = 0;
		students[i].jiraMark = 0;
		students[i].sum = 0;
		students[i].rank = "Unranked";
	}
}

void insertStudentMarks(Student* students, int studentId) {
	studentId--;
	cout << "\tWindows Mark: ";
	cin >> students[studentId].winMark;
	
	cout << "\tWord Mark: ";
	cin >> students[studentId].wordMark;
	
	cout << "\tJira Mark: ";
	cin >> students[studentId].jiraMark;
	
	students[studentId].sum = students[studentId].winMark + students[studentId].wordMark + students[studentId].jiraMark;
	
	if (students[studentId].sum >= 24) {
		students[studentId].rank = "Exellence";
	} else if (students[studentId].sum < 24 && students[studentId].sum >= 18) {
		students[studentId].rank = "Good";
	} else {
		students[studentId].rank = "Average";
	}
}

