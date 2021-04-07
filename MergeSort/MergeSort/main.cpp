//백준 2751번 시간초과

#include <iostream>

using namespace std;

int tmp[1000001];

void MergeSort(int arr[], int left, int right); //분할
void Merge(int arr[], int left, int right);     //병합

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
		return; //다 나누어 졌으니까 끝

	int mid;

	mid = (left + right) / 2; //중간 만들기
	MergeSort(arr, left, mid); //레프트에서 중간 나누기
	MergeSort(arr, mid + 1, right); //중간 + 1에서 라이트 나누기
	//다 나누어질때까지 반복
	Merge(arr, left, right);
}

void Merge(int arr[], int left, int right)
{
	int L, R, K, a; //왼쪽배열의 첫번째 인덱스, 오른쪽배열의 첫번째 인덱스, 임시배열의 인덱스,

	int mid = (left + right) / 2; //중간 만들기
	L = left;
	R = mid + 1;
	K = left; //임시배열의 인덱스는 left부터

	while (L <= mid && R <= right)
	{
		//arr[R]이 arr[L] 보다 크거나 같으면 arr[L++] 아니면 arr[R++]
		tmp[K++] = arr[L] <= arr[R] ? arr[L++] : arr[R++];
	}
	if (L > mid) //왼쪽은 다 복사되었으니 오른쪽변수들 복사
		for (a = R; a <= right; a++)
			tmp[K++] = arr[a];
	else
		for (a = L; a <= mid; a++)
			tmp[K++] = arr[a];
	//임시배열에서 원배열로 복사
	for (a = left; a <= right; a++)
		arr[a] = tmp[a];
}