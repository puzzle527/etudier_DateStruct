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
			cout << val << "��(��) ã�ҽ��ϴ�." << endl;
			return current;
		}
		//val ���� ���� ��� ���ʿ� �ִ� ���
		if (val < current->data)
		{
			cout << current->data << "���� �������� �̵�: ";
			return find_impl(current->left, val);
		}
		//val ���� ���� ��� �����ʿ� �ִ� ���
		cout << current->data << "���� ���������� �̵�: ";
		return find_impl(current->right, val);
	}
public:
	void insert(int val)
	{
		//root ��������� root�� ����
		if (!root)
			root = new node{ val, NULL, NULL };
		else
			insert_impl(root, val);
	}
private:
	void insert_impl(node* current, int val)
	{
		//��Ʈ ����� ������ ������ ����
		if (val < current->data)
		{
			//��������� �ֱ�
			if (!current->left)
			{
				current->left = new node{ val, NULL, NULL };
			}
			//�ƴϸ� ���� ����Ʈ ��忡�� �μ�Ʈ ȣ��
			else
				insert_impl(current->left, val);
		}
		//��Ʈ ����� ������ ũ�� ������
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
	//���� ��ȸ �Լ� inorder
	void inorder()
	{
		inorder_impl(root);
	}
private:
	void inorder_impl(node* start)
	{
		if (!start)
			return;
		inorder_impl(start->left); 		//���� ����Ʈ�� �湮

		cout << start->data << " ";		//���� ��� ���

		inorder_impl(start->right);		//������ ���� Ʈ�� �湮
	}
public:
	//�ļ� ��带 ã�� �Լ�
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

		//����
		if (val < start->data)
			start->left = delete_impl(start->left, val);
		//������
		else if (val > start->data)
			start->right = delete_impl(start->right, val);
		else
		{
			if (!start->left) //�ڽ� ��尡 �������ų� ���� �ڽ� ��常 ���� ���
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}
			if (!start->right) //������ �ڽ� ��常 ���� ���
			{
				auto tmp = start->left;
				delete start;
				return tmp;
			}
			//�ڽ� ��尡 �� �� �ִ� ���
			auto succNode = successor(start);
			start->data = succNode->data;

			//������ ���� Ʈ������ �ļ�(successor)�� ã�� ����
			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
		
	}
};