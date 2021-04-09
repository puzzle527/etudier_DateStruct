//���� 1181�� ���ĺ� ����

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

	//STL sort(ù��°, ������, �������� �Լ�(�̿밡��<bool>))
	//true �״�� false ����
	sort(arr, arr + N, Compare);

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == arr[i - 1])
			continue;
		cout << arr[i] << endl;
	}

	return 0;
}