#pragma once

#include "stdafx.h"

template <typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	//크기를 가진 생성자
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}

	//복사 생성자
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	//배열 방식 인덱스 접근
	T& operator[](int index)
	{
		return data[index];
	}
	const T& operator[](int index) const
	{
		return data[index];
	}

	//at 함수 인덱스 접근
	T& at(int index)
	{
		if (index < n)
			return data[index];
		throw "Index out of range";
	}

	//배열의 크기 반환 함수
	size_t size() const
	{
		return n;
	}

	//소멸자 메모리 릭 방지
	~dynamic_array()
	{
		delete[] data;
	}

	
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//friend 함수 접근제한자 무시
	//operator 연산자 오버로딩 함수
	//두개의 배열을 합치는 함수
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size()); //합칠 배열 생성
		copy(arr1.begin(), arr1.end(), result.begin()); //생성된 배열에 첫번째 배열 복사
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size()); //생성된 배열의 첫번째 배열 복사된 다음 인덱스부터 두번째 배열 복사

		return result;
	}

	//배열 내부의 인자들을 스트링을 바꿔주는 함수
	string to_string(const string& sep = ", ")
	{
		if (n == 0)
			return "";

		ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
		{
			os << sep << data[i];
		}
		return os.str();
	}
};