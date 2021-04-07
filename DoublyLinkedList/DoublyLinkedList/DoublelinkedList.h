#pragma once

#include <iostream>

using namespace std;

struct Node
{
public:
	Node	*prev;
	Node	*next;
	int		 value;
	Node()
	{
		prev = next = nullptr;
		value = 0;
	}
	Node(int val, Node *ptr) //ptr 뒤에 추가한다.
	{
		value = val;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
		//this는 멤버 함수가 호출된 객체의 주소를 가리키는 숨겨진 포인터
	}
	void DeleteNode()
	{
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};

class DoubleLinkedList
{
private:
	Node	*head = nullptr;
	Node	*tail = nullptr;
	int		 size = 0;
public:
	void PrintList()
	{
		Node* cur = head; 
		while (cur != nullptr) 
		{ 
			if (cur->next == nullptr) 
			{ 
				cout << cur->value << endl; 
			} 
			else 
			{ 
				cout << cur->value << " ↔ "; 
			}
			cur = cur->next; 
		}

	}

	void Addhead(int val)
	{
		Node *ptr = new Node;
		ptr->value = val;

		if (head == nullptr)
		{
			tail = head;
		}
		else
		{
			ptr->next = head;
			head->prev = ptr;
		}
		head = ptr;
		size++;
	}

	void Addtail(int val)
	{
		Node *ptr = new Node;
		ptr->value = val;
		
		if (tail == nullptr)
		{
			head = tail;
		}
		else
		{
			ptr->prev = tail;
			tail->prev = head;
			head->next = tail;
			tail->next = ptr;
		}
		tail = ptr;
		size++;
	}

};