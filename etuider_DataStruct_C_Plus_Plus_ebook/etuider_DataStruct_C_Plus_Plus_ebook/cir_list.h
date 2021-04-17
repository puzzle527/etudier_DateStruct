#pragma once

#include "stdafx.h"

template <typename T>
struct cir_list_node
{
	T* data; //들어있는 값
	cir_list_node* next; //앞을 가리키는 노드 포인터
	cir_list_node* prev; //뒤를 가리키는 노드 포인터

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
	cir_list() : n(0) //생성자
	{
		head = new node{ NULL, NULL, NULL }; //모두 NULL로 구성된 기본 노드
		head->next = head;
		head->prev = head;
	}

	size_t size() const //사이즈 반환 함수
	{
		return n;
	}

	void insert(const T& value) //앞 부분 삽입함수
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

	void erase(const T& value) //값을 찾아 삭제하는 함수
	{
		auto cur = head, dummy = head->prev;
		while (cur != dummy) //순회다 할 때까지
		{
			if (*(cur->data) == value)
			{
				cur->prev->next = cur->next; //노드연결
				cur->next->prev = cur->prev;
				if (cur == head)
					head = head->next; //헤드면 삭제하고 다음노드를 헤드로 초기화
				delete cur; //노드삭제
				n--; //사이즈 -1 감소
				return;
			}
			cur = cur->next; //순회하면서 반복
		}
	}

	struct cir_list_it //iterator
	{
	private:
		node_ptr ptr;
	public:
		cir_list_it(node_ptr p) : ptr(p) {}

		T& operator*() //연산자 오버로딩 가르키는 값 리턴함수
		{
			return *(ptr->data);
		}

		node_ptr get() //현재 주소 반환
		{
			return ptr;
		}

		cir_list_it& operator++() //선행증가 연산자 오버로딩 다음주소로 이동
		{
			ptr = ptr->next;
			return *this;
		}

		cir_list_it operator++(int) //후행증가
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
		//아래 코드는 원소를 역순으로 삽입하지만,
		//원형 연결리스트이기 때문에 문제가 없습니다.
		for (const auto& i : other)
			insert(i);
	}

	cir_list(const initializer_list<T>& il) : head(NULL), n(0)
	{
		//아래 코드는 원소를 역순으로 삽입하지만,
		//원형 연결리스트이기 때문에 문제가 없습니다.
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