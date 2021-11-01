#pragma once
//Exercise13
#include "stdafx.h"

//uint unsinged int 대신 사용
//using uint = unsigned int;
//
//class hash_map
//{
//	vector<int> data;
//public:
//	hash_map(size_t n)
//	{
//		//n크기 벡터 -1로 초기화
//		data = vector<int>(n, -1);
//	}
//
//	void insert(uint value)
//	{
//		int n = data.size();
//		data[value % n] = value;
//		cout << value << " 삽입" << endl;
//	}
//
//	bool find(uint value)
//	{
//		int n = data.size();
//		return (data[value % n] == value);
//		//해시 값 위치에 저장된 값이 value와 같은지 검사
//	}
//
//	void erase(uint value)
//	{
//		int n = data.size();
//		if (data[value % n] == value)
//		{
//			data[value % n] = -1;
//			cout << value << " 삭제" << endl;
//		}
//	}
//};
