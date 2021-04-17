#pragma once

#include "stdafx.h"

template <typename T>
struct cir_list_node
{
	T* data; //����ִ� ��
	cir_list_node* next; //���� ����Ű�� ��� ������
	cir_list_node* prev; //�ڸ� ����Ű�� ��� ������

	~cir_list_node()
	{
		delete data;
	}
};

template <typename T>
struct cir_list
{
public:
	using node = cir_list_node<T>;
	using node_ptr = node * ;
private:
	node_ptr head;
	size_t n;
public:
	cir_list() : n(0) //������
	{
		head = new node{ NULL, NULL, NULL }; //��� NULL�� ������ �⺻ ���
		head->next = head;
		head->prev = head;
	}

	size_t size() const //������ ��ȯ �Լ�
	{
		return n;
	}

	void insert(const T& value) //�� �κ� �����Լ�
	{
		node_ptr newNode = new node{ new T(value), NULL, NULL };
		n++;
		//n == 1
		auto dummy = head->prev;
		dummy->next = newNode;
		newNode->prev = dummy;
		if (head == dummy)
		{
			dummy->prev = newNode;
			newNode->next = dummy;
			head = newNode;
			return;
		}
		//n > 1
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void erase(const T& value) //���� ã�� �����ϴ� �Լ�
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy) //��ȸ�� �� ������
		{
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next; //��忬��
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next; //���� �����ϰ� ������带 ���� �ʱ�ȭ
				delete cur; //������
				n--; //������ -1 ����
				return;
			}
			cur = cur->next; //��ȸ�ϸ鼭 �ݺ�
		}
	}

	struct cir_list_it //iterator
	{
	private:
		node_ptr ptr;
	public:
		cir_list_it(node_ptr p) : ptr(p) {}

		T& operator*() //������ �����ε� ����Ű�� �� �����Լ�
		{
			return *(ptr->data);
		}

		node_ptr get() //���� �ּ� ��ȯ
		{
			return ptr;
		}

		cir_list_it& operator++() //�������� ������ �����ε� �����ּҷ� �̵�
		{
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int) //��������
		{
			cir_list_it it = *this;
			++(*this);
			return it;
		}

		cir_list_it operator--()
		{
			ptr = ptr->prev;
			return *this;
		}

		cir_list_it operator--(int)
		{
			cir_list_it it = *this;
			--(*this);
			return it;
		}

		friend bool operator==(const cir_list_it& it1, const cir_list_it& it2)
		{
			return it1.ptr == it2.ptr;
		}

		friend bool operator!=(const cir_list_it& it1, const cir_list_it& it2)
		{
			return it1.ptr != it2.ptr;
		}
	};

	cir_list_it begin()
	{
		return cir_list_it{ head };
	}

	cir_list_it begin() const
	{
		return cir_list_it{ head };
	}

	cir_list_it end()
	{
		return cir_list_it{ head->prev };
	}

	cir_list_it end() const
	{
		return cir_list_it{ head->prev };
	}

	cir_list(const cir_list<T>& other) : cir_list()
	{
		//�Ʒ� �ڵ�� ���Ҹ� �������� ����������,
		//���� ���Ḯ��Ʈ�̱� ������ ������ �����ϴ�.
		for (const auto& i : other)
			insert(i);
	}

	cir_list(const initializer_list<T>& il) : head(NULL), n(0)
	{
		//�Ʒ� �ڵ�� ���Ҹ� �������� ����������,
		//���� ���Ḯ��Ʈ�̱� ������ ������ �����ϴ�.
		for (const auto*& i : il)
			insert(i);
	}

	~cir_list()
	{
		while (size())
		{
			erase(*(head->data));
		}
		delete head;
	}
};

struct playlist
{
	cir_list<int> list;

	void insert(int song)
	{
		list.insert(song);
	}

	void erase(int song)
	{
		list.erase(song);
	}

	void loopOnce()
	{
		for (auto& song : list)
			cout << song << " ";
		cout << endl;
	}
};