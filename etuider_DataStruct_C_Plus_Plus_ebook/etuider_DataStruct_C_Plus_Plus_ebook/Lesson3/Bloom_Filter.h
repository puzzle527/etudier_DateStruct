#pragma once
//Exercise17
#include "stdafx.h"

//class bloom_filter
//{
//	vector<bool> data;
//	int nBits;
//
//	int hash(int num, int key)
//	{
//		switch (num)
//		{
//		case 0: return key % nBits;
//		case 1: return (key / 7) % nBits;
//		case 2: return (key / 11) % nBits;
//		}
//		return 0;
//	}
//
//public:
//	bloom_filter(int n) : nBits(n)
//	{
//		data = vector<bool>(nBits, false);
//	}
//
//	void lookup(int key)
//	{
//		//��� ��Ʈ�� 1�� ���� �Ǿ��ִ��� Ȯ��
//		bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)];
//
//		if (result)
//			cout << key << ": ���� �� ����" << endl;
//		else
//			cout << key << ": ���� ����" << endl;
//	}
//
//	void insert(int key)
//	{
//		data[hash(0, key)] = true;
//		data[hash(1, key)] = true;
//		data[hash(2, key)] = true;
//		cout << key << "����: ";
//
//		for (auto a : data)
//			cout << a << " ";
//		cout << endl;
//	}
//};