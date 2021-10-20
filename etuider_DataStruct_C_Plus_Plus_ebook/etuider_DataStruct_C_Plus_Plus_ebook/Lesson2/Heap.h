#pragma once
#include "stdafx.h"

//매번 데이터를 받을 때마다 지금까지 받은 데이터의 중앙값을 계산
//매번 들어올 때마다 정렬 하면 O(N log N) 시간 복잡도
//힙을 통해 최적화하기

struct median
{
	//최대힙 : 루트 노드가 가장 큰 수
	priority_queue<int> maxHeap;
	//최소힙 : 루트 노드가 가장 작은 수
	priority_queue<int, vector<int>, greater<int>> minHeap;

	//새로 들어오는 수가기존 데이터의 중앙값보다 작으면 최대힙, 크면 최소힙 저장
	//두 힙의 최상단 원소를 이용하여 중앙값을 계산
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