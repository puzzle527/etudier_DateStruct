#pragma once

#include "stdafx.h"

struct singly_ll_node //�̱۸���Ʈ ��� ����ü
{
	int data;
	singly_ll_node* next;
};

class singly_ll //�̱۸���Ʈ ����ü 
{
public:

	using node = singly_ll_node;
	using node_ptr = node * ;

private:
	node_ptr head;

public:
	void push_front(int val)
	{
		auto new_node = new node{ val, NULL };
		if (head != NULL)
			new_node->next = head;
		head = new_node;
	}
	void pop_front()
	{
		auto first = head;
		if (head)
		{
			head = head->next;
			delete first;
		}
	}
	struct singly_ll_iterator //�̱۸���Ʈ �ݺ��� ����
	{
	private:
		node_ptr ptr;

	public:
		//iterator ������
		singly_ll_iterator(node_ptr p) : ptr(p) {}
		//�ݺ���
		int& operator*() { return ptr->data; } //*������ �����ε�
		node_ptr get() { return ptr; } //������ �� �Լ�
		//�ݺ��� ���� ����
		singly_ll_iterator& operator++() //��������
		{
			ptr = ptr->next;
			return *this;
		}
		singly_ll_iterator& operator++(int) //��������
		{
			singly_ll_iterator result = *this;
			++(*this);
			return result;
		}
		//�ιݺ��ڰ� ������ �Ǵ��ϴ� ���� ����
		friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right)
		{
			return left.ptr == right.ptr;
		}
		friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right)
		{
			return left.ptr != right.ptr;
		}
	};
	//begin(), end()
	singly_ll_iterator begin() { return singly_ll_iterator(head); }
	singly_ll_iterator end() { return singly_ll_iterator(NULL); }
	singly_ll_iterator begin() const { return singly_ll_iterator(head); }
	singly_ll_iterator end() const { return singly_ll_iterator(NULL); }

	//���Ͽ��Ḯ��Ʈ ������
	singly_ll() = default;
	//���� ������
	singly_ll(const singly_ll& other) : head(NULL)
	{
		if (other.head)
		{
			head = new node{ 0, NULL };
			auto cur = head;
			auto it = other.begin();
			while (true)
			{
				cur->data = *it;

				auto tmp = it;
				++tmp;
				if (tmp == other.end())
					break;

				cur->next = new node{ 0, NULL };
				cur = cur->next;
				it = tmp;
			}
		}
	}
	//�ʱ�ȭ ����Ʈ
	singly_ll(const initializer_list<int>& ilist) : head(NULL)
	{
		for (auto it = rbegin(ilist); it != rend(ilist); it++)
			push_front(*it);
	}
};

