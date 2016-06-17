// Data structures: Template class List
// Header file
/*
	List()
		*Ham khoi tao danh sach rong
	List(int m)
		*Nhan vao gia tri m khong am
		*Ham khoi tao danh sach co m phan tu
	List(const List& L)
		*Nhan vao 1 danh sach L
		*Ham khoi tao danh sach tu danh sach L
	List& operator = (const List& L)
		*Nhan vao 1 danh sach L
		*Gan danh sach L cho danh sach hien thoi
	bool isEmpty() const
		*Tra ve true neu danh sach rong va nguoc lai
	int Length() const;
		*Tra ve size cua danh sach
	void Insert (const Item& x, int i)
		*Nhan vao Item x va vi tri i
		*Insert x vao vi tri i trong danh sach
	void Append (const Item& x)
		*Nhan vao Item x
		*Insert x vao cuoi danh sach
	void Delete (int i)
		*Nhan vao vi tri i
		*Xoa phan tu o vi tri i cua danh sach
	Item& Element (int i)
		*Nhan vao vi tri i
		*Tra ve phan tu i cua danh sach
	void Print()
		*In ra danh sach
*/

#ifndef LIST_H
#define LIST_H

template <class Student>
class ListIterator;

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
// Header file
/*
	ListIterator(const List<Item>& L)
		*Nhan vao List<Item> L
		*Ham khoi tao ListIterator
	void Start()
		*Set current = 0
	bool Valid() const
		*True neu current co chua phan tu, false neu nguoc lai
	void Advance()
		*Dieu kien Valid() = true
		*Tang gia tri cua current
	Item& Current() const
		*Dieu kien Valid() = true
		*Tra ve element o vi tri current
	void Add (const Item& x)
		*Nhan vao Item x
		*add x vao vi tri truoc current
	void Remove()
		*Loai phan tu vi tri current, chuyen current ra sau
*/

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

