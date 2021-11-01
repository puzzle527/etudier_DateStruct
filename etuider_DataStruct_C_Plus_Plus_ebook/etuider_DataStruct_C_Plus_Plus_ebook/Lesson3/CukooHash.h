#pragma once
//Exercise15
#include "stdafx.h"

//class hash_map
//{
//	vector<int> data1;
//	vector<int> data2;
//	int size;
//
//	//해시함수 두개 정의
//	int hash1(int key) const
//	{
//		return key % size;
//	}
//	int hash2(int key) const
//	{
//		return (key / size) % size;
//	}
//public:
//	hash_map(int n) : size(n)
//	{
//		data1 = vector<int>(size, -1);
//		data2 = vector<int>(size, -1);
//	}
//
//	//룩업 함수 : 파인드 함수
//	vector<int>::iterator lookup(int key)
//	{
//		auto hash_value1 = hash1(key);
//		if (data1[hash_value1] == key)
//		{
//			cout << "1번 테이블에서 " << key << " 찾음" << endl;
//			return data1.begin() + hash_value1;
//		}
//
//		auto hash_value2 = hash2(key);
//		if (data2[hash_value2] == key)
//		{
//			cout << "2번 테이블에서 " << key << " 찾음" << endl;
//			return data2.begin() + hash_value2;
//		}
//
//		return data2.end();
//	}
//
//	void erase(int key)
//	{
//		auto position = lookup(key);
//		if (position != data2.end())
//		{
//			*position = -1;
//			cout << key << " 에 해당하는 원소를 삭제" << endl;
//		}
//		else
//		{
//			cout << key << "찾지 못함" << endl;
//		}
//	}
//	void insert(int key)
//	{
//		insert_impl(key, 0, 1);
//	}
//	
//private:
//	void insert_impl(int key, int cnt, int table)
//	{
//		if (cnt >= size)
//		{
//			cout << key << " 삽입 시 순환발생! 재해싱 필요" << endl;
//			return;
//		}
//
//		if (table == 1)
//		{
//			int hash = hash1(key);
//			if (data1[hash] == -1)
//			{
//				cout << table << "번 테이블에 " << key << " 삽입" << endl;
//				data1[hash] = key;
//			}
//			else
//			{
//				int old = data1[hash];
//				data1[hash] = key;
//				cout << table << "번 테이블에 " << key << "삽입: 기존의 " << old << "이동 -> ";
//				insert_impl(old, cnt + 1, 2);
//			}
//		}
//		else
//		{
//			int hash = hash2(key);
//			if (data2[hash] == -1)
//			{
//				cout << table << "번 테이블에 " << key << " 삽입" << endl;
//				data2[hash] = key;
//			}
//			else
//			{
//				int old = data2[hash];
//				data2[hash] = key;
//				cout << table << "번 테이블에 " << key << "삽입: 기존의 " << old << "이동 -> ";
//				insert_impl(old, cnt + 1, 1);
//			}
//		}
//	}
//public:
//	void print()
//	{
//		cout << "Index: ";
//		for (int i = 0; i < size; i++)
//			cout << i << '\t';
//		cout << endl;
//
//		cout << "Data1: ";
//		for (auto i : data1)
//			cout << i << '\t';
//		cout << endl;
//
//		cout << "Data2: ";
//		for (auto i : data2)
//			cout << i << '\t';
//		cout << endl;
//	}
//
//};
