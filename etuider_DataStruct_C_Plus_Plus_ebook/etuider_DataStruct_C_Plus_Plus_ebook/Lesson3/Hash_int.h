#pragma once
//Exercise13
#include "stdafx.h"

//uint unsinged int ��� ���
//using uint = unsigned int;
//
//class hash_map
//{
//	vector<int> data;
//public:
//	hash_map(size_t n)
//	{
//		//nũ�� ���� -1�� �ʱ�ȭ
//		data = vector<int>(n, -1);
//	}
//
//	void insert(uint value)
//	{
//		int n = data.size();
//		data[value % n] = value;
//		cout << value << " ����" << endl;
//	}
//
//	bool find(uint value)
//	{
//		int n = data.size();
//		return (data[value % n] == value);
//		//�ؽ� �� ��ġ�� ����� ���� value�� ������ �˻�
//	}
//
//	void erase(uint value)
//	{
//		int n = data.size();
//		if (data[value % n] == value)
//		{
//			data[value % n] = -1;
//			cout << value << " ����" << endl;
//		}
//	}
//};
