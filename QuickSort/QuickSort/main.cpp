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

				//�迭       ����        ��
void QuickSort(int *arr, int start, int end)
{
	if (start >= end) //���Ұ� �ϳ��� ���
		return;

	int pivot = start; //������
	int i = start + 1; //���� ���� �κ�
	int j = end; //������ ���� �κ�
	int temp;

	while (i <= j) // i j�� ������ ������ �ݺ�
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		
		if (i > j) //������
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