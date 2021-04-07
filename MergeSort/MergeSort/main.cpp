//���� 2751�� �ð��ʰ�

#include <iostream>

using namespace std;

int tmp[1000001];

void MergeSort(int arr[], int left, int right); //����
void Merge(int arr[], int left, int right);     //����

int main(void)
{
	int N;

	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	MergeSort(arr, 0, N - 1);

	for(int i = 0; i < N; i++)
	{
		cout << arr[i] << endl;
	}
	

	delete[] arr;
	return 0;
}

void MergeSort(int arr[], int left, int right)
{
	if (left == right)
		return; //�� ������ �����ϱ� ��

	int mid;

	mid = (left + right) / 2; //�߰� �����
	MergeSort(arr, left, mid); //����Ʈ���� �߰� ������
	MergeSort(arr, mid + 1, right); //�߰� + 1���� ����Ʈ ������
	//�� �������������� �ݺ�
	Merge(arr, left, right);
}

void Merge(int arr[], int left, int right)
{
	int L, R, K, a; //���ʹ迭�� ù��° �ε���, �����ʹ迭�� ù��° �ε���, �ӽù迭�� �ε���,

	int mid = (left + right) / 2; //�߰� �����
	L = left;
	R = mid + 1;
	K = left; //�ӽù迭�� �ε����� left����

	while (L <= mid && R <= right)
	{
		//arr[R]�� arr[L] ���� ũ�ų� ������ arr[L++] �ƴϸ� arr[R++]
		tmp[K++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
	}
	if (L > mid) //������ �� ����Ǿ����� �����ʺ����� ����
		for (a = R; a <= right; a++)
			tmp[K++] = arr[a];
	else
		for (a = L; a <= mid; a++)
			tmp[K++] = arr[a];
	//�ӽù迭���� ���迭�� ����
	for (a = left; a <= right; a++)
		arr[a] = tmp[a];
}