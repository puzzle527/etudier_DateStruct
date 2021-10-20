#pragma once
#include "stdafx.h"

//�Ź� �����͸� ���� ������ ���ݱ��� ���� �������� �߾Ӱ��� ���
//�Ź� ���� ������ ���� �ϸ� O(N log N) �ð� ���⵵
//���� ���� ����ȭ�ϱ�

struct median
{
	//�ִ��� : ��Ʈ ��尡 ���� ū ��
	priority_queue<int> maxHeap;
	//�ּ��� : ��Ʈ ��尡 ���� ���� ��
	priority_queue<int, vector<int>, greater<int>> minHeap;

	//���� ������ �������� �������� �߾Ӱ����� ������ �ִ���, ũ�� �ּ��� ����
	//�� ���� �ֻ�� ���Ҹ� �̿��Ͽ� �߾Ӱ��� ���
	void insert(int data)
	{
		if (maxHeap.size() == 0)
		{
			maxHeap.push(data);
			return;
		}

		if (maxHeap.size() == minHeap.size())
		{
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);

			return;
		}

		if (maxHeap.size() < minHeap.size())
		{
			if (data > get())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);
			return;
		}

		if (data < get())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);
	}

	double get()
	{
		if (maxHeap.size() == minHeap.size())
			return (static_cast<double>(maxHeap.top()) + static_cast<double>(minHeap.top())) / 2.0;
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();
		return maxHeap.top();
	}
};