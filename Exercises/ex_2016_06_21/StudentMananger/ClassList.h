#ifndef CLASS_LIST_H
#define CLASS_LIST_H

template <class Class>
class ClassListIterator;

// Data structures: Template class ClassList
template <class Class>
class ClassList
{
	public:
		friend class ClassListIterator<Class>;
		ClassList();
		ClassList(int m);
		ClassList(const ClassList& L);
		virtual ~ClassList();
		
		ClassList& operator = (const ClassList& L);
		bool isEmpty() const { return elements == NULL; } 
		int length() const { return size; }
		void insert (const Class& x, int i);
		void append (const Class& x);
		void del (int i);
		Class& element (int i);
		void print();
	protected:
		Class* elements;
		int size;
};


// Data structures: Template class ClassListIterator
template <class Class>
class ClassListIterator
{
	public:
		ClassListIterator(ClassList<Class>& L);
		void start() { current = 0; }
		bool valid() const;
		void advance();
		Class& getCurrent() const;
		void add (const Class& x);
		void remove();
	protected:
		ClassList<Class>* listPtr;
		int current;
};

#include "ClassList.template"

#endif

