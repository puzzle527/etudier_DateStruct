//#pragma once
//#include "stdafx.h"
//
//enum class city : int
//{
//	MOSCOW,
//	LONDON,
//	SEOUL,
//	SEATTLE,
//	DUBAI,
//	SYDNEY
//};
//
//std::ostream& operator<<(std::ostream& os, const city c)
//{
//	switch (c)
//	{
//	case city::LONDON:
//		os << "����";
//		return os;
//	case city::MOSCOW:
//		os << "��ũ��";
//		return os;
//	case city::SEOUL:
//		os << "����";
//		return os;
//	case city::SEATTLE:
//		os << "�þ�Ʋ";
//		return os;
//	case city::DUBAI:
//		os << "�ι���";
//		return os;
//	case city::SYDNEY:
//		os << "�õ��";
//		return os;
//	default:
//		return os;
//	}
//}
//
////���� ����Ʈ�� �̿��� �׷���
////���� ����Ʈ : �� ��忡 ������ ��带 ����Ʈ�� �����ϰ� ����
//struct graph
//{
//	vector<vector<pair<int, int>>> data;
//
//	graph(int n)
//	{
//		data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
//	}
//
//	void addEdge(const city c1, const city c2, int dis)
//	{
//		cout << "���� �߰�: " << c1 << "-" << c2 << "=" << dis << endl;
//
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1].push_back({ n2, dis });
//		data[n2].push_back({ n1, dis });
//	}
//	void removeEdge(const city c1, const city c2)
//	{
//		cout << "���� ����: " << c1 << "-" << c2 << endl;
//
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair)
//		{
//			return pair.first == n2;
//		});
//		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair)
//		{
//			return pair.first == n1;
//		});
//		
//	}
//};