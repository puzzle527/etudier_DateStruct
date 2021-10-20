#pragma once

#include "stdafx.h"

struct node //한직원에 두 명의 부하 직원을 거느림
{
	//이진트리
	string position; //직책
	node* first; //하위 노드에 대한 링크 두개
	node* second;
};

//프로그램에서는 node 구조체를 직접 조작 X org_tree로 조작
//회사의 조직도를 나타내는 트리
struct org_tree
{
	node* root; //루트노드 CEO를 나타냄

	//루트노드를 생성하는 함수
	//새로운 트리를 만드는 정적 함수
	static org_tree create_org_structure(const string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	//특정 직책 이름에 해당하는 노드를 찾아서 반환하는 함수
	static node* find(node* root, const string& value)
	{
		if (root == NULL) //없음
			return NULL;

		if (root->position == value) //CEO
			return root;

		auto firstFound = org_tree::find(root->first, value); // 왼쪽 검사

		if (firstFound != NULL) //있으면 반환
			return firstFound;

		return org_tree::find(root->second, value); //없으면 오른쪽 검사
	}

	//조직도에 부하 직원을 추가하는 함수
	//인자 : 상사의 직책, 부사 직원의 직책
	//상사의 직책은 이미 트리에 존재
	bool addSubordinate(const string& manager, const string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			cout << manager << "을(를) 찾을 수 없습니다: " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << endl;

		return true;
	}

	//트리순회
	//전위 순회 : 현재 노드를 먼저 방문 -> 현재 노드의 왼쪽 하위 노드 -> 현재 노드의 오른쪽 하위 노드
	//preoder traversal
	//재귀적인 방식으로 방문
	static void preOrder(node* start)
	{
		if (!start)
			return;

		cout << start->position << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}
	//중위 순회 : 왼쪽 노드를 먼저 방문 -> 현재 노드 -> 오른쪽 노드
	//in-order traversal
	static void inOrder(node* start)
	{
		if (!start)
			return;

		inOrder(start->first);
		cout << start->position << ", " << endl;
		inOrder(start->second);
	}
	//후위 순회 : 두자식 먼저 노드 먼저 방문 -> 현재 노드
	//post-order traversal
	static void postOrder(node* start)
	{
		if (!start)
			return;

		postOrder(start->first);
		postOrder(start->second);
		cout << start->position << ", ";
	}
	//레벨 순서 순회 : 맨 위 -> 맨 아래 / 왼쪽 노드 -> 오른쪽 노드
	//level order traversal 루트노드부터 단계별로 차례대로 나열
	static void levelOrder(node* start)
	{
		if (!start)
			return;

		queue<node*> q;
		q.push(start);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto current = q.front();
				q.pop();

				cout << current->position << ", ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}
			cout << endl;
		}
	}
};