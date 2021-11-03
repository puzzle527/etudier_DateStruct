#pragma once
//Activity06
#include "stdafx.h"

struct URLService
{
	using ActualURL = string;
	using TinyURL = string;

private:
	unordered_map<TinyURL, ActualURL> data;

public:
	pair<bool, ActualURL> lookup(const TinyURL& url) const
	{
		auto it = data.find(url);
		if (it == data.end())
			return make_pair(false, string());
		else
			return make_pair(true, it->second);
	}

	bool registerURL(const ActualURL& actualURL, const TinyURL& tinyURL)
	{
		auto found = lookup(tinyURL).first;
		if (found)
			return false;
		data[tinyURL] = actualURL;
		return true;
	}

	bool deregisterURL(const TinyURL& tinyURL)
	{
		auto found = lookup(tinyURL).first;
		if (found)
		{
			data.erase(tinyURL);
			return true;
		}
		return false;
	}

	void printURLs() const
	{
		for (const auto& entry : data)
		{
			std::cout << entry.first << " -> " << entry.second << std::endl;
		}
		std::cout << std::endl;
	}
};
