#pragma once
//Exercise18
//�����˻� ����, ������
#include "stdafx.h"

bool linear_search(int N, vector<int>& S)
{
	for (auto i : S)
	{
		if (i == N)
			return true;
	}

	return false;
}

bool binary_search(int N, vector<int>& S)
{
	auto first = S.begin();
	auto last = S.end();

	while (true)
	{
		//distance() �Ÿ��Լ� floor() �ݿø��Լ�
		// ���� �˻� ������ �߰� ���Ҹ� mid_element�� ����
		auto range_length = distance(first, last);
		auto mid_element_index = floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		// mid_element�� N ���� ��
		//advance(iter, off) �ݺ��ڸ� off��ŭ �̵� 
		if (mid_element == N)
			return true;
		else if (mid_element > N)
			advance(last, -mid_element_index);
		else
			advance(first, mid_element_index);

		// ���� �˻� ������ �ϳ��� ���Ҹ� ���� �ִٸ� false�� ��ȯ
		if (range_length == 1)
			return false;
	}
}

void run_small_search_test()
{
	auto N = 2;
	vector<int> S{ 1,3,2,4,5,7,9,8,6 };

	sort(S.begin(), S.end());

	if (linear_search(N, S))
		cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�!" << endl;
	else
		cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;

	if (binary_search(N, S))
		cout << "���� �˻����� ���Ҹ� ã�ҽ��ϴ�!" << endl;
	else
		cout << "���� �˻����� ���Ҹ� ã�� ���߽��ϴ�." << endl;
}

void run_large_search_test(int size, int N)
{
	vector<int> S;
	//�õ尪�� ��� ���� ���� ����̽� ����
	random_device rd;
	//���� ������ 64��Ʈ����
	mt19937_64 rand(rd()); //rd�� ���� ���� ���� ���� �ʱ�ȭ

	//[1, size] �������� ���� ���� �߻�
	//1���� size ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����
	uniform_int_distribution<mt19937_64::result_type> uniform_dist(1, size);

	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	//�˻� �ð� ���� ����
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	bool search_result = binary_search(N, S);

	//�˻� �ð� ���� ����
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "���� �˻� ���� �ð�: " << diff.count() << endl;

	if (search_result)
		cout << "���Ҹ� ã�ҽ��ϴ�." << endl;
	else
		cout << "���Ҹ� ã�� ���߽��ϴ�." << endl;
}