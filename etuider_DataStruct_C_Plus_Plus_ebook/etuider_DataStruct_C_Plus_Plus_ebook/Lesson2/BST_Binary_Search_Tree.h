#pragma once
#include "stdafx.h"

struct node
{
	int		data;
	node*	left;
	node*	right;
};

struct bst
{
	node* root = nullptr;

	node* find(int val)
	{
		return find_impl(root, val);
	}

private:
	node* find_impl(node* current, int val)
	{
		if (!current)
		{
			cout << endl;
			return NULL;
		}
		if (current->data == val)
		{
			cout << val << "을(를) 찾았습니다." << endl;
			return current;
		}
		//val 값이 현재 노드 왼쪽에 있는 경우
		if (val < current->data)
		{
			cout << current->data << "에서 왼쪽으로 이동: ";
			return find_impl(current->left, val);
		}
		//val 값이 현재 노드 오른쪽에 있는 경우
		cout << current->data << "에서 오른쪽으로 이동: ";
		return find_impl(current->right, val);
	}
public:
	void insert(int val)
	{
		//root 비어있으면 root에 삽입
		if (!root)
			root = new node{ val, NULL, NULL };
		else
			insert_impl(root, val);
	}
private:
	void insert_impl(node* current, int val)
	{
		//룻트 노드의 값보다 작으면 왼쪽
		if (val < current->data)
		{
			//비어있으면 넣기
			if (!current->left)
			{
				current->left = new node{ val, NULL, NULL };
			}
			//아니면 다음 레프트 노드에서 인서트 호출
			else
				insert_impl(current->left, val);
		}
		//룻트 노드의 값보다 크면 오른쪽
		else
		{
			if (!current->right)
			{
				current->right = new node{ val, NULL, NULL };
			}
			else
			{
				insert_impl(current->right, val);
			}
		}
	}
public:
	//중위 순회 함수 inorder
	void inorder()
	{
		inorder_impl(root);
	}
private:
	void inorder_impl(node* start)
	{
		if (!start)
			return;
		inorder_impl(start->left); 		//왼쪽 서브트리 방문

		cout << start->data << " ";		//현재 노드 출력

		inorder_impl(start->right);		//오른쪽 서브 트리 방문
	}
public:
	//후손 노드를 찾는 함수
	node* successor(node* start)
	{
		auto current = start->right;
		while (current && current->left)
			current = current->left;
		return current;
	}
	void deleteValue(int val)
	{
		root = delete_impl(root, val);
	}
private:
	node* delete_impl(node* start, int val)
	{
		if (!start)
			return NULL;

		//왼쪽
		if (val < start->data)
			start->left = delete_impl(start->left, val);
		//오른쪽
		else if (val > start->data)
			start->right = delete_impl(start->right, val);
		else
		{
			if (!start->left) //자식 노드가 전혀없거나 왼쪽 자식 노드만 없는 경우
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}
			if (!start->right) //오론쪽 자식 노드만 없는 경우
			{
				auto tmp = start->left;
				delete start;
				return tmp;
			}
			//자식 노드가 둘 다 있는 경우
			auto succNode = successor(start);
			start->data = succNode->data;

			//오른쪽 서브 트리에서 후속(successor)을 찾아 삭제
			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
		
	}
};