#include <iostream>

using namespace std;

void QuickSort(int *arr, int start, int end);


int main(void)
{
	int arr[10] = { 4, 1, 2, 3, 9, 7, 8, 6, 10, 5 };

	QuickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

				//배열       시작        끝
void QuickSort(int *arr, int start, int end)
{
	if (start >= end) //원소가 하나인 경우
		return;

	int pivot = start; //기준점
	int i = start + 1; //왼쪽 시작 부분
	int j = end; //오른쪽 시작 부분
	int temp;

	while (i <= j) // i j가 엇갈릴 때까지 반복
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		
		if (i > j) //엇갈림
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);
}