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

	size++; //����Ʈ ������ ����

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
		cout << "�ش��ϴ� �ε��� ���� �����ϴ�." << endl;
		return;
	}

	Node *ptr = head;
	Node *tmp = ptr;
	Node *node = new Node; //�����߰� �Ǵ� ���

	node->value = value;
	node->next = nullptr;

	for (int i = 0; i < index - 1; i++)
	{
		tmp = ptr; //�� ����� �� ��ġ
		ptr = ptr->next; //�� ����� ��ġ
	}
	tmp->next = node;
	node->next = ptr; //�� ���� ������ �ִ� �����ġ�� �⸮Ų��.
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
		cout << "ã�� �� ���� ��� �Դϴ�." << endl;
	else
	{
		size--;
		cout << "������ ����� �� : " << ptr->value << endl;
		temp->next = ptr->next; //������ ��带 �����ϰ� ����
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
	//delete temp; //�����
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
	cout << "����Ʈ �Ҵ�����" << endl;
}

