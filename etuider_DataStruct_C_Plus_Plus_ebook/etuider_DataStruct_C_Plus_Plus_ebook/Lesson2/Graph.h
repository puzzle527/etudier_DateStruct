//#pragma once
//#include "stdafx.h"
//
//enum class city : int //Ŭ���� ũ�� ����(int)
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
//struct graph
//{
//	vector<vector<int>> data;
//	//�־��� ������ ���� ������ ��带 �����ϴ� ������
//	graph(int n)
//	{
//		data.reserve(n);
//		vector<int> row(n);
//		//������ ���� ����ִ� �׷���
//		fill(row.begin(), row.end(), -1);
//
//		for (int i = 0; i < n; i++)
//		{
//			data.push_back(row);
//		}
//	}
//	//���� �߰��Լ�
//	void addEdge(const city c1, const city c2, int dis)
//	{
//		cout << "���� �߰�: " << c1 << "-" << c2 << "=" << dis << endl;
//
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = dis;
//		data[n2][n1] = dis;
//	}
//
//	void removeEdge(const city c1, const city c2)
//	{
//		cout << "���� ����: " << c1 << "-" << c2 << endl;
//		auto n1 = static_cast<int>(c1);
//		auto n2 = static_cast<int>(c2);
//		data[n1][n2] = -1;
//		data[n2][n1] = -1;
//	}
//};
