#pragma once
const int MAX_SIZE = 25;

struct Elem {
	int data = 0;
	Elem* next = nullptr;
	Elem* prev = nullptr;
};

class ListIterator
{
	friend class List;
	Elem* elem;
public:
	ListIterator();
	ListIterator(const ListIterator& it);
	ListIterator& operator=(const ListIterator& a);
	int& operator*() const;
	ListIterator& operator+ (const int& a);
};

class List
{
	int size;
	Elem* head = nullptr;
	Elem* tail = nullptr;
	ListIterator beg;
	ListIterator end;

public:
	List() { size = 0; head = nullptr; Elem* tail = nullptr;};
	List(int s);
	List(const List& l);
	~List();

	ListIterator first();
	ListIterator last();
	void PushBack(int a);
	void PopBack();

	List& operator= (const List& l);
	int& operator[] (int i);
	int& operator()();
	List operator*(List& l);
	
};

