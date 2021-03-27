#pragma once

class LinkedList
{
private:
	Node	*head;	  //머리
	Node	*tail;	  //꼬리
	int		size = 0; //링크의 길이
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