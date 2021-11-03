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
			throw("해시 함수 개수가 너무 많습니다.");
		}
		if (size > 255)
		{
			throw("블룸필터 크기가 255보다 클 수 없습니다.");
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
		cout << "블룸 필터에 추가: " << key << endl;
	}

	bool mayContain(const string& key)
	{
		hash(key);
		for (auto it = &hashValue[0]; it < &hashValue[nHashes]; it++)
		{
			if (!bits[*it % bits.size()])
			{
				cout << key << " : 사용할 수 있는 이메일입니다." << endl;
				return false;
			}
		}
		cout << key << " : 이미 사용 중입니다." << endl;
		return true;
	}
};
