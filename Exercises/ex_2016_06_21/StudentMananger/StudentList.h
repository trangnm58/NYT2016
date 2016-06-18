// Data structures: Template class List
// Header file

#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

template <class Student>
class StudentListIterator;

template <class Student>
class StudentList
{
	public:
		friend class StudentListIterator<Student>;
		StudentList();
		StudentList(int m);
		StudentList(const StudentList& L);
		virtual ~StudentList();
		
		StudentList& operator = (const StudentList& L);
		bool isEmpty() const { return elements == NULL; } 
		int length() const { return size; }
		void insert (const Student& x, int i);
		void append (const Student& x);
		void del (int i);
		Student& element (int i);
		void print();
	protected:
		Student* elements;
		int size;
};

// Data structures: Template class StudentListIterator
// Header file

template <class Student>
class StudentListIterator
{
	public:
		StudentListIterator(StudentList<Student>& L);
		void start() { current = 0; }
		bool valid() const;
		void advance();
		Student& getCurrent() const;
		void add (const Student& x);
		void remove();
	protected:
		StudentList<Student>* listPtr;
		int current;
};

#include "StudentList.template"

#endif

