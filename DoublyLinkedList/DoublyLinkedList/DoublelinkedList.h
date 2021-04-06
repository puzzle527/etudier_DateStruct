#pragma once

struct Node
{
public:
	int			 value = 0;
	struct Node	*prev = nullptr;
	struct Node	*next = nullptr;
};

class DoubleLinkedList
{
private:
	Node	*head = nullptr;
	Node	*tail = nullptr;
	int		 size = 0;
public:
	void Addhead(int val);





	void Addhead(int val)
	{
		Node *ptr = new Node;
		ptr->value = val;
		size++;

		if (size == 0)
		{
			head = ptr;
			tail = ptr;
		}
		else
		{
			ptr->next = head;
			head->prev = ptr;
			head = ptr;
		}
	}

};