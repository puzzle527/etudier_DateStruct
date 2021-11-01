//#pragma once
//#include "stdafx.h"
//
//enum class city : int //클래스 크기 설정(int)
//{
//	MOSCOW,
//	LONDON,
//	SEOUL,
//	SEATTLE,
//	DUBAI,
//	SYDNEY
//};
//
//ostream& operator<<(ostream& os, const city c)
//{
//	switch (c)
//	{
//	case city::LONDON:
//		os << "런던";
//		return os;
//	case city::MOSCOW:
//		os << "모스크바";
//		return os;
//	case city::SEOUL:
//		os << "서울";
//		return os;
//	case city::SEATTLE:
//		os << "시애틀";
//		return os;
//	case city::DUBAI:
//		os << "두바이";
//		return os;
//	case city::SYDNEY:
//		os << "시드니";
//		return os;
//	default:
//		return os;
//	}
//}
//
//struct graph
//{
//	vector<vector<int>> data;
//	//주어진 개수의 노드로 구성된 노드를 구성하는 생성자
//	graph(int n)
//	{
//		data.reserve(n);
//		vector<int> row(n);
//		//엣지가 없는 비어있는 그래프
//		fill(row.begin(), row.end(), -1);
//
//		for (int i = 0; i < n; i++)
//		{
//			data.push_back(row);
//		}
//	}
//	//엣지 추가함수
//	void addEdge(const city c1, const city c2, int dis)
//	{
//		cout << "엣지 추가: " << c1 << "-" << c2 << "=" << dis << endl;
//
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = dis;
//		data[n2][n1] = dis;
//	}
//
//	void removeEdge(const city c1, const city c2)
//	{
//		cout << "엣지 삭제: " << c1 << "-" << c2 << endl;
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = -1;
//		data[n2][n1] = -1;
//	}
//};
