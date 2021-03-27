#include "stdafx.h"
#include "LinkedList.h"

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{

}

template<typename T>
void LinkedList<T>::AddNode(T _value)
{
	Node<T> *node = new Node<T>;

	size++; //리스트 사이즈 증가

	node->value = _value;
	node->next = nullptr;

	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = tail->next;
	}
}

