#include "stdafx.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList()
{

}

void LinkedList::AddNode(int value)
{
	Node *node = new Node;

	size++; //리스트 사이즈 증가

	node->value = value;
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

void LinkedList::DeleteNode(int value)
{
	Node *ptr = head;
	Node *temp = ptr;

	while (ptr != nullptr)
	{
		if (ptr->value == value)
		{
			break;
		}
		else
		{
			temp = ptr;
			ptr = ptr->next;
		}
	}
	if (ptr == nullptr)
		cout << "찾을 수 없는 노드 입니다." << endl;
	else
	{
		size--;
		cout << "삭제된 노드의 값 : " << ptr->value << endl;
		temp->next = ptr->next; //삭제할 노드를 제외하고 연결
		delete ptr;
	}
}

void LinkedList::Deletetail()
{
	Node *ptr = head;
	Node *temp = new Node;

	while (ptr->next != nullptr)
	{
		temp = ptr;
		ptr = ptr->next;
	}
	size--;
	tail = temp;
	tail->next = nullptr;
	delete ptr;
	//delete temp; //물어보기
}

void LinkedList::Deletehead()
{
	Node *temp = head;

	head = temp->next;
	size--;
	delete temp;
}

void LinkedList::PrintListValue()
{
	Node *temp = head;

	while (temp != nullptr)
	{
		cout << temp->value << "->";
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::DeleteList()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		head = temp->next;
		delete temp;
		temp = head;
	}
	delete head;
	size = 0;
	cout << "리스트 할당해제" << endl;
}

