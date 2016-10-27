#pragma once
#include "Exeption.h"
#include "Vector.h"

template <class T>
class List
{
private:
	struct list
	{
		T object;
		list* next;
	};
	list *head;

	int listSize = 0;
public:

	List();
	List(const List &a);
	int getListSize();
	void add(T objectForAdd);
	void show();
	List& operator--();
	List operator+(List a);
	List& operator=(List &a);
	
	bool operator==(List &b);
	bool operator()();
	bool operator<(List a);
	List& operator/(T a);
	T& operator[](int i)
	{
		if (i < 0 || i >listSize) throw IncorretIndex();
		list *temp = head;
		for (int j = 0; j < i; j++)
		{
			temp = temp->next;
		}
		return temp->object;
	}
	
	//~List();
};

template<class T> List<T> & List<T>::operator/(T a)
{
	if (a == NULL) throw NullDevision();
	list *temp = head;
	while (temp != NULL)
	{
		temp->object /= a;
		temp = temp->next;
	}
	return *this;
}

template <class T> List<T>::List()
{
	head = NULL;
}


template <class T> List<T>::List(const List &a)
{

	this->head = a.head;
	this->listSize = a.listSize;
}

template <class T> int List<T>::getListSize()
{
	return this->listSize;
}

template <class T> void List<T>::add(T objectForAdd)
{
	if (listSize > 4) throw ListOverflow();
	list *temp = new list;
	temp->object = objectForAdd;
	temp->next = head;
	head = temp;
	this->listSize++;
}


template <class T> void List<T>::show()
{
	list *temp = new list;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->object << endl;
		temp = temp->next;
	}
	delete temp;
}

template <> void List<Vector>::show()
{
	list *temp = new list;
	temp = head;
	while (temp != NULL)
	{
		cout << "{" << temp->object.getX() << ";" << temp->object.getY() << "}" << endl;
		temp = temp->next;
	}
	delete temp;
}

template <class T> List<T>& List<T>::operator=(List &a)
{
	
	this->head = a.head;
	return *this;
}


template <class T> List<T> List<T>::operator+(List a)
{
	List New;

	list *temp = this->head;
	list *temp2 = temp;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = a.head;
	New.head = temp2;
	return New;
}

template <class T> bool List<T>::operator<(List b)
{
	if (this->head.object < b->head.object)
	{
		return true;
	}
	else
		return false;
}



/*template <> bool List<Vector>::operator<(List<Vector> b)
{
	if (head->object.modul() < b.head->object.modul())
		return true;
	else
		return false;
}*/

template <class T> bool List<T>::operator()()
{
	if (this->head != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class T> bool List<T>::operator==(List &list2)
{
	if (typeid(this) != typeid(list2))
	{
		return false;
	}
	if (this->getListSize() != list2.getListSize())
	{
		return false;
	}
	list *temp = this->head;
	list *temp2 = list2.head;
	while (temp != NULL)
	{
		if (temp->object == temp2->object)
		{
			temp = temp->next;
			temp2 = temp2->next;
		}
		else { return false; }
	}
	return true;
}

template <class T> List<T>& List<T>::operator--()
{
	if (this->listSize <= 0) throw EmptyList();
	list *temp = this->head->next;
	delete this->head;
	this->head = temp;
	this->listSize--;
	return *this;
}



/*List::~List()
{
list *temp = new list;
temp = head->next;
while (temp != NULL)
{
temp = head->next;
delete head;
head = temp;
}
delete temp;
}*/