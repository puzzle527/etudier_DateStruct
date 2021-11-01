#pragma once

#include "stdafx.h"

struct node
{
	int data;
	int listPosition;
	int dataPosition;
};

vector<int> merge(const vector<vector<int>>& input)
{
	auto comparator = [](const node& left, const node& right)
	{
		if (left.data == right.data)
			return left.listPosition > right.listPosition;
		return left.data > right.data;
	};

	vector<node> heap;
	for (int i = 0; i < input.size(); i++)
	{
		heap.push_back({ input[i][0], i, 0 });
		push_heap(heap.begin(), heap.end(), comparator);
		//push_heap : begin 부터 end - 1 까지 comparator(최대힙) 정렬(comprator == true)이 되어있으면 
		//begin 부터 end 까지 comparator(최대힙) 정렬
		//std::vector<int> v1 = { 1, 3, 8, 15, 105 };
		//std::vector<int> v2 = { 2, 3, 10, 11, 16, 20, 25 };
		//std::vector<int> v3 = { -2, 100, 1000 };
		//std::vector<int> v4 = { -1, 0, 14, 18 };
	}

	vector<int> result;
	while (!heap.empty())
	{
		pop_heap(heap.begin(), heap.end(), comparator);
		auto min = heap.back();
		heap.pop_back();

		result.push_back(min.data);
		int nextIndex = min.dataPosition + 1;
		if (nextIndex < input[min.listPosition].size())
		{
			heap.push_back({ input[min.listPosition][nextIndex], min.listPosition, nextIndex });
			push_heap(heap.begin(), heap.end(), comparator);
		}
	}

	return result;
}
