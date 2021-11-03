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
//		//모든 비트가 1로 설정 되어있는지 확인
//		bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)];
//
//		if (result)
//			cout << key << ": 있을 수 있음" << endl;
//		else
//			cout << key << ": 절대 없음" << endl;
//	}
//
//	void insert(int key)
//	{
//		data[hash(0, key)] = true;
//		data[hash(1, key)] = true;
//		data[hash(2, key)] = true;
//		cout << key << "삽입: ";
//
//		for (auto a : data)
//			cout << a << " ";
//		cout << endl;
//	}
//};