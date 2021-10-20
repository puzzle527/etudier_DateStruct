#pragma once

#include "stdafx.h"

struct node //�������� �� ���� ���� ������ �Ŵ���
{
	//����Ʈ��
	string position; //��å
	node* first; //���� ��忡 ���� ��ũ �ΰ�
	node* second;
};

//���α׷������� node ����ü�� ���� ���� X org_tree�� ����
//ȸ���� �������� ��Ÿ���� Ʈ��
struct org_tree
{
	node* root; //��Ʈ��� CEO�� ��Ÿ��

	//��Ʈ��带 �����ϴ� �Լ�
	//���ο� Ʈ���� ����� ���� �Լ�
	static org_tree create_org_structure(const string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	//Ư�� ��å �̸��� �ش��ϴ� ��带 ã�Ƽ� ��ȯ�ϴ� �Լ�
	static node* find(node* root, const string& value)
	{
		if (root == NULL) //����
			return NULL;

		if (root->position == value) //CEO
			return root;

		auto firstFound = org_tree::find(root->first, value); // ���� �˻�

		if (firstFound != NULL) //������ ��ȯ
			return firstFound;

		return org_tree::find(root->second, value); //������ ������ �˻�
	}

	//�������� ���� ������ �߰��ϴ� �Լ�
	//���� : ����� ��å, �λ� ������ ��å
	//����� ��å�� �̹� Ʈ���� ����
	bool addSubordinate(const string& manager, const string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			cout << manager << "��(��) ã�� �� �����ϴ�: " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;

		return true;
	}

	//Ʈ����ȸ
	//���� ��ȸ : ���� ��带 ���� �湮 -> ���� ����� ���� ���� ��� -> ���� ����� ������ ���� ���
	//preoder traversal
	//������� ������� �湮
	static void preOrder(node* start)
	{
		if (!start)
			return;

		cout << start->position << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}
	//���� ��ȸ : ���� ��带 ���� �湮 -> ���� ��� -> ������ ���
	//in-order traversal
	static void inOrder(node* start)
	{
		if (!start)
			return;

		inOrder(start->first);
		cout << start->position << ", " << endl;
		inOrder(start->second);
	}
	//���� ��ȸ : ���ڽ� ���� ��� ���� �湮 -> ���� ���
	//post-order traversal
	static void postOrder(node* start)
	{
		if (!start)
			return;

		postOrder(start->first);
		postOrder(start->second);
		cout << start->position << ", ";
	}
	//���� ���� ��ȸ : �� �� -> �� �Ʒ� / ���� ��� -> ������ ���
	//level order traversal ��Ʈ������ �ܰ躰�� ���ʴ�� ����
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