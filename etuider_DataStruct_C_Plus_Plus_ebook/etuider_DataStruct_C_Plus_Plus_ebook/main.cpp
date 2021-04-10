#include "stdafx.h"

int main(void)
{
	array<int, 10> arr;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	//cout << arr[0] << endl;

	for (auto element : arr)
	{
		cout << element << endl;
	}

	return 0;
}