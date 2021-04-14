#pragma once

#include "stdafx.h"

struct singly_ll_node //싱글리스트 노드 구조체
{
	int data;
	singly_ll_node* next;
};

class singly_ll //싱글리스트 구조체 
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
	struct singly_ll_iterator //싱글리스트 반복자 구현
	{
	private:
		node_ptr ptr;

	public:
		//iterator 생성자
		singly_ll_iterator(node_ptr p) : ptr(p) {}
		//반복자
		int& operator*() { return ptr->data; } //*연사자 오버로딩
		node_ptr get() { return ptr; } //포인터 겟 함수
		//반복자 증가 연산
		singly_ll_iterator& operator++() //선행증가
		{
			ptr = ptr->next;
			return *this;
		}
		singly_ll_iterator& operator++(int) //후행증가
		{
			singly_ll_iterator result = *this;
			++(*this);
			return result;
		}
		//두반복자가 같은지 판단하는 관계 연산
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

	//단일연결리스트 생성자
	singly_ll() = default;
	//복사 생성자
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
	//초기화 리스트
	singly_ll(const initializer_list<int>& ilist) : head(NULL)
	{
		for (auto it = rbegin(ilist); it != rend(ilist); it++)
			push_front(*it);
	}
};

