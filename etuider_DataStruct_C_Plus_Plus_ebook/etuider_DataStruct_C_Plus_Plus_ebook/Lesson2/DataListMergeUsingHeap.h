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
	}

	vector<int> result;
	while (!heap.empty())
	{
		pop_heap(heap.begin(), heap.end(), comparator);
		auto min = heap.back();

		result.push_back
	}
}
