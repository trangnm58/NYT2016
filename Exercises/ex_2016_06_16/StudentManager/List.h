#ifndef LIST_H
#define LIST_H

template <class Student>
class ListIterator;


// Data structures: Template class List
template <class Student>
class List
{
	public:
		friend class ListIterator<Student>;
		List();
		List(int m);
		List(const List& L);
		virtual ~List();
		
		List& operator = (const List& L);
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


// Data structures: Template class ListIterator
template <class Student>
class ListIterator
{
	public:
		ListIterator(List<Student>& L);
		void start() { current = 0; }
		bool valid() const;
		void advance();
		Student& getCurrent() const;
		void add (const Student& x);
		void remove();
	protected:
		List<Student>* listPtr;
		int current;
};

#include "List.template"

#endif

