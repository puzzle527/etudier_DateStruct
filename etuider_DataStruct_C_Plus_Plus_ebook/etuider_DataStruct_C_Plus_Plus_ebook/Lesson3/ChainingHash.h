#pragma once
//Exercise14
#include "stdafx.h"

//using uint = unsigned int;
//
//class hash_map
//{
//	vector<list<int>> data;
//
//public:
//	hash_map(size_t n)
//	{
//		data.resize(n);
//	}
//
//	void insert(uint value)
//	{
//		int n = data.size();
//		data[value % n].push_back(value);
//		cout << value << " »ðÀÔ" << endl;
//	}
//
//	bool find(uint value)
//	{
//		int n = data.size();
//		auto& entries = data[value % n];
//		return std::find(entries.begin(), entries.end(), value) != entries.end();
//	}
//
//	void erase(uint value)
//	{
//		int n = data.size();
//		auto& entries = data[value & n];
//		auto iter = std::find(entries.begin(), entries.end(), value);
//
//		if (iter != entries.end())
//		{
//			entries.erase(iter);
//			cout << value << " »èÁ¦" << endl;
//		}
//	}
//};
