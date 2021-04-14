#pragma once

#include "stdafx.h"

template <typename T>
class dynamic_array
{
	T* data;
	size_t n;

public:
	//ũ�⸦ ���� ������
	dynamic_array(int n)
	{
		this->n = n;
		data = new T[n];
	}

	//���� ������
	dynamic_array(const dynamic_array<T>& other)
	{
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	//�迭 ��� �ε��� ����
	T& operator[](int index)
	{
		return data[index];
	}
	const T& operator[](int index) const
	{
		return data[index];
	}

	//at �Լ� �ε��� ����
	T& at(int index)
	{
		if (index < n)
			return data[index];
		throw "Index out of range";
	}

	//�迭�� ũ�� ��ȯ �Լ�
	size_t size() const
	{
		return n;
	}

	//�Ҹ��� �޸� �� ����
	~dynamic_array()
	{
		delete[] data;
	}

	
	T* begin() { return data; }
	const T* begin() const { return data; }
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//friend �Լ� ���������� ����
	//operator ������ �����ε� �Լ�
	//�ΰ��� �迭�� ��ġ�� �Լ�
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
	{
		dynamic_array<T> result(arr1.size() + arr2.size()); //��ĥ �迭 ����
		copy(arr1.begin(), arr1.end(), result.begin()); //������ �迭�� ù��° �迭 ����
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size()); //������ �迭�� ù��° �迭 ����� ���� �ε������� �ι�° �迭 ����

		return result;
	}

	//�迭 ������ ���ڵ��� ��Ʈ���� �ٲ��ִ� �Լ�
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