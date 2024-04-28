#include "List.h"
#include <iostream>
using namespace std;

List::List(int s) 
{
	size = s;
	Elem* new_elem = new Elem;
	head = new_elem;
	tail = new_elem;

	for (int i = 0; i < size - 1; i++) 
	{
		Elem* new_elem = new Elem;
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
	}
	beg.elem = head;
	end.elem = tail;
}

List::List(const List& l) 
{
	Elem* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
}

List::~List() 
{
	Elem* curr = head;
	while (curr != nullptr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}


List& List::operator= (const List& l)
{
	if (this == &l)return *this;

	if (head != nullptr)
	{
		Elem* curr = head;
		while (curr != nullptr)
		{
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	Elem* elem = l.head;
	while (elem != nullptr) {
		PushBack(elem->data);
		elem = elem->next;
	}
	beg.elem = head;
	end.elem = tail;
	return *this;
}

int& List::operator[] (int i)
{
	Elem* curr = head;
	for (int j = 0; j < i; j++) {
		curr = curr->next;
	}
	return curr->data;
}

List List::operator*(List& l)
{
	List base = *this;
	int s = this->size;
	List temp;

	for (int i = 0; i < s; i++)
	{
		temp.PushBack(base[i] * l[i]);
	}

	return temp;
}

int& List::operator()() {
	return size;
}


ListIterator List::first()
{
	return beg;
}

ListIterator List::last()
{
	return end;
}

void List::PushBack(int a)
{
	Elem* new_elem = new Elem;
	new_elem->data = a;

	if (size == 0)
	{
		head = new_elem;
		tail = new_elem;
		size++;
		beg.elem = head;
		end.elem = tail;
	}
	else
	{
		tail->next = new_elem;
		new_elem->prev = tail;
		tail = new_elem;
		size++;
		end.elem = tail;
	}
	
}

void List::PopBack()
{
	Elem* curr = tail;
	tail = curr->prev;
	delete curr;
	tail->next = nullptr;
	size--;
	end.elem = tail;
}


ListIterator::ListIterator() {
	elem = nullptr;
}

ListIterator::ListIterator(const ListIterator& it) {
	elem = it.elem;
}

ListIterator& ListIterator::operator=(const ListIterator& a)
{
	elem = a.elem;
	return *this;
}

int& ListIterator::operator*() const
{
	return elem->data;
}

ListIterator& ListIterator::operator+ (const int& a)
{
	for (int i = 0; i < a; ++i) {
		elem = elem->next;	
	}
	return *this;
}