#pragma once

class LinkedList
{
private:
	Node	*head;	  //�Ӹ�
	Node	*tail;	  //����
	int		size = 0; //��ũ�� ����
public:
	LinkedList();
	~LinkedList();

	void AddNode(int value);
	void DeleteNode(int value);
	void Deletetail();
	void Deletehead();
	void PrintListValue();
	void DeleteList();
};