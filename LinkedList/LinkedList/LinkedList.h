#pragma once
template <typename T>

class LinkedList
{
private:
	Node<T>	*head;	  //머리
	Node<T>	*tail;	  //꼬리
	int		size = 0; //링크의 길이
public:
	LinkedList();
	~LinkedList();

	void AddNode(T _value);
};