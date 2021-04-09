//백준 1181번 알파벳 정렬

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool Compare(string a, string b)
{
	if (a.size() != b.size())
		return a.length() < b.length();
	else
		return a < b;
}

int main(void)
{
	int N;
	string arr[20001];
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, arr[i]);
	}

	//STL sort(첫번째, 마지막, 내가만든 함수(이용가능<bool>))
	//true 그대로 false 정렬
	sort(arr, arr + N, Compare);

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == arr[i - 1])
			continue;
		cout << arr[i] << endl;
	}

	return 0;
}