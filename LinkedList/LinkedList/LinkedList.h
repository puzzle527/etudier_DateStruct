#pragma once
template <typename T>

class LinkedList
{
private:
	Node<T>	*head;	  //�Ӹ�
	Node<T>	*tail;	  //����
	int		size = 0; //��ũ�� ����
public:
	LinkedList();
	~LinkedList();

	void AddNode(T _value);
};