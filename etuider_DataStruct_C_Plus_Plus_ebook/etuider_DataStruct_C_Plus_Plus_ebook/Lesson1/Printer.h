#pragma once

#include "./stdafx.h"

class Job
{
	int id;
	std::string user;
	int pages;

	static int count;

public:
	Job(const std::string& u, int p) : user(u), pages(p), id(++count) {}

	friend std::ostream& operator<<(std::ostream& os, const Job& j)
	{
		os << "id: " << j.id << ", �����: " << j.user << ", ��������: " << j.pages << "��";
		return os;
	}
};

int Job::count = 0;

template <size_t N>
class Printer
{
	std::queue<Job> jobs;

public:
	bool addNewJob(const Job& job)
	{
		if (jobs.size() == N)
		{
			std::cout << "�μ� ��⿭�� �߰� ����: " << job << std::endl;
			return false;
		}

		std::cout << "�μ� ��⿭�� �߰�: " << job << std::endl;
		jobs.push(job);
		return true;
	}

	void startPrinting()
	{
		while (!jobs.empty())
		{
			std::cout << "�μ� ��: " << jobs.front() << std::endl;
			jobs.pop();
		}
	}
};
