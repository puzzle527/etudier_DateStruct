#pragma once
//Activity07
#include "stdafx.h"
#include <openssl/md5.h>

class BloomFilter
{
	int nHashes;
	vector<bool> bits;

	static constexpr int hashSize = 128 / 8;
	unsigned char hashValue[hashSize];
public:

	BloomFilter(int size, int hashes) : bits(size), nHashes(hashes)
	{
		if (nHashes > hashSize)
		{
			throw("�ؽ� �Լ� ������ �ʹ� �����ϴ�.");
		}
		if (size > 255)
		{
			throw("������� ũ�Ⱑ 255���� Ŭ �� �����ϴ�.");
		}
	}

	void hash(const string& key)
	{
		MD5(reinterpret_cast<const unsigned char*>(key.data()), key.length(), hashValue);
	}

	void add(const string& key)
	{
		hash(key);
		for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++)
		{
			bits[*it % bits.size()] = true;
		}
		cout << "��� ���Ϳ� �߰�: " << key << endl;
	}

	bool mayContain(const string& key)
	{
		hash(key);
		for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++)
		{
			if (!bits[*it % bits.size()])
			{
				cout << key << " : ����� �� �ִ� �̸����Դϴ�." << endl;
				return false;
			}
		}
		cout << key << " : �̹� ��� ���Դϴ�." << endl;
		return true;
	}
};
