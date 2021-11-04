#pragma once
//Exercise18
//이진검색 구현, 성능평가
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
		//distance() 거리함수 floor() 반올림함수
		// 현재 검색 범위의 중간 원소를 mid_element에 저장
		auto range_length = distance(first, last);
		auto mid_element_index = floor(range_length / 2);
		auto mid_element = *(first + mid_element_index);

		// mid_element와 N 값을 비교
		//advance(iter, off) 반복자를 off만큼 이동 
		if (mid_element == N)
			return true;
		else if (mid_element > N)
			advance(last, -mid_element_index);
		else
			advance(first, mid_element_index);

		// 현재 검색 범위에 하나의 원소만 남아 있다면 false를 반환
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
		cout << "선형 검색으로 원소를 찾았습니다!" << endl;
	else
		cout << "선형 검색으로 원소를 찾지 못했습니다." << endl;

	if (binary_search(N, S))
		cout << "이진 검색으로 원소를 찾았습니다!" << endl;
	else
		cout << "이진 검색으로 원소를 찾지 못했습니다." << endl;
}

void run_large_search_test(int size, int N)
{
	vector<int> S;
	//시드값을 얻기 위한 랜덤 디바이스 생성
	random_device rd;
	//난수 생성기 64비트버젼
	mt19937_64 rand(rd()); //rd를 통해 난수 생성 엔진 초기화

	//[1, size] 범위에서 정수 난수 발생
	//1부터 size 까지 균등하게 나타나는 난수열을 생성하기 위한 균등 분포 정의
	uniform_int_distribution<mt19937_64::result_type> uniform_dist(1, size);

	for (auto i = 0; i < size; i++)
		S.push_back(uniform_dist(rand));

	//검색 시간 측정 시작
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();

	bool search_result = binary_search(N, S);

	//검색 시간 측정 종료
	chrono::steady_clock::time_point end = chrono::steady_clock::now();

	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "이진 검색 수행 시간: " << diff.count() << endl;

	if (search_result)
		cout << "원소를 찾았습니다." << endl;
	else
		cout << "원소를 찾지 못했습니다." << endl;
}