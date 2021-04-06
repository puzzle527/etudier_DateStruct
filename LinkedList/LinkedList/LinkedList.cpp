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

void LinkedList::AddNode(int value, int index)
{
	if (index > size || index < 0)
	{
		cout << "해당하는 인덱스 값은 없습니다." << endl;
		return;
	}

	Node *ptr = head;
	Node *tmp = ptr;
	Node *node = new Node; //새로추가 되는 노드

	node->value = value;
	node->next = nullptr;

	for (int i = 0; i < index - 1; i++)
	{
		tmp = ptr; //들어갈 노드의 전 위치
		ptr = ptr->next; //들어갈 노드의 위치
	}
	tmp->next = node;
	node->next = ptr; //새 노드는 기존에 있는 노드위치를 기리킨다.
	size++;
}

void LinkedList::Addhead(int value)
{
	Node *ptr = new Node();

	size++;
	ptr->next = head;
	ptr->value = value;
	head = ptr;
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

