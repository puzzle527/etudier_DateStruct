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
	void DeleteNode() //노드 자기자신을 삭제하는 함수
	{
		prev->next = next; //이전 노드의 다음을 가르키는 포인터에 자신 노드의 다음을 가리키는 포인터 대입
		next->prev = prev; //다음 노드의 이전을 가리키는 포인터에 자신 노드의 이전을 가리키는 포인터 대입 -> 자기 자신의 앞과 뒤 노드 연결
		delete this; //자기자신 삭제
	}
};

class DoubleLinkedList
{
private:
	Node	*head = nullptr;
	Node	*tail = nullptr;
	int		 size = 0;
public:
	DoubleLinkedList()
	{
		head = new Node; //비어있는 머리
		tail = new Node; //비어있는 꼬리 미리 생성

		head->next = tail;
		tail->prev = head; //서로 연결
	}
	~DoubleLinkedList()
	{
		while (head->next != tail)
		{
			head->next->DeleteNode();
		}
		delete head;
		delete tail;
	}
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