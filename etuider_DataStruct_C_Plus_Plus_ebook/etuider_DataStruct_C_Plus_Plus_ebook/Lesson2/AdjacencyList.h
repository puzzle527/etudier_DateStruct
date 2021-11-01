#pragma once
#include "stdafx.h"

enum class city : int
{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c)
{
	switch (c)
	{
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATTLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;
	}
}

//인접 리스트를 이용한 그래프
//인접 리스트 : 각 노드에 인접한 노드를 리스트로 저장하고 있음
struct graph
{
	vector<vector<pair<int, int>>> data;

	graph(int n)
	{
		data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	}

	void addEdge(const city c1, const city c2, int dis)
	{
		cout << "엣지 추가: " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({ n2, dis });
		data[n2].push_back({ n1, dis });
	}
	void removeEdge(const city c1, const city c2)
	{
		cout << "엣지 삭제: " << c1 << "-" << c2 << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair)
		{
			return pair.first == n2;
		});
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair)
		{
			return pair.first == n1;
		});
		
	}
};