#pragma once
//Activity11
 
//���� �����
//struct Work
//{
//	int id;
//	int start;
//	int end;
//
//public:
//	Work(int i, int s, int e) : id(i), start(s), end(e) {}
//
//	inline bool operator<(const Work& work) const
//	{
//		return this->end < work.end;
//	}
//	inline bool operator==(const Work& work) const
//	{
//		return (id == work.id && start == work.start && end == work.end);
//	}
//
//	friend ostream& operator<<(ostream& os, Work& work);
//};
//
//ostream& operator<<(ostream& os, Work& work)
//{
//	os << "[" << work.id << "] " << work.start
//		<< " -> " << work.end << "\t"
//		<< "|";
//	for (int i = 1; i < 20; i++)
//	{
//		if (i < work.start)
//			cout << " ";
//		else if (i >= work.start && i < work.end)
//			cout << "*";
//		else
//			cout << " ";
//	}
//	cout << "|" << endl;
//
//
//	return os;
//}
//
//vector<Work>& scheduling(vector<Work>& V, list<Work>& work_list)
//{
//	
//	work_list.sort([](Work& lwork, Work& rwork) { return lwork.end < rwork.end; });
//
//	while (!work_list.empty())
//	{
//		auto& temp = *work_list.begin();
//		V.push_back(temp);
//		work_list.remove_if([temp](Work work) { return temp.end > work.start; });
//		work_list.remove(temp);
//	}
//	return V;
//}

//����
// ��� �۾��� ID�� <���� �ð�, ���� �ð�> ������ ǥ����
//struct Task
//{
//	unsigned ID;
//	unsigned start_time;
//	unsigned end_time;
//};
//
//auto initialize_tasks(int num_tasks, int max_end_time)
//{
//	std::random_device rd;
//	std::mt19937 rand(rd());
//	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, max_end_time);
//
//	std::list<Task> tasks;
//
//	for (unsigned i = 0; i < num_tasks; i++)
//	{
//		auto start_time = uniform_dist(rand);
//		auto end_time = uniform_dist(rand);
//
//		if (start_time == end_time) end_time++;
//		if (start_time > end_time) std::swap(start_time, end_time);
//
//		tasks.push_back({ i + 1, start_time, end_time });
//	}
//
//	return tasks;
//}
//
//auto job_scheduling(std::list<Task> tasks)
//{
//	// �۾� ���� �ð��� �������� ����
//	tasks.sort([](const auto& lhs, const auto& rhs) {
//		return lhs.end_time < rhs.end_time;
//		});
//
//	for (auto curr_task = tasks.begin(); curr_task != tasks.end(); curr_task++)
//	{
//		auto next_task = std::next(curr_task, 1);
//
//		// ���� �۾��� �ð��� ��ġ�� �۾��� ����
//		while (next_task != tasks.end() &&
//			next_task->start_time < curr_task->end_time)
//		{
//			next_task = tasks.erase(next_task);
//		}
//	}
//
//	return tasks;
//}
//
//void print(std::list<Task>& tasks, int max_end_time)
//{
//	for (auto t : tasks) {
//		std::cout << "[" << t.ID << "] " << t.start_time << " -> " << t.end_time << "\t|";
//
//		int i = 0;
//		for (; i < t.start_time; i++) std::cout << " ";
//		for (; i < t.end_time; i++) std::cout << "*";
//		for (; i < max_end_time; i++) std::cout << " ";
//		std::cout << "|" << std::endl;
//	}
//}
//
//int main()
//{
//	int num_tasks = 10;
//	int max_end_time = 20;
//
//	auto tasks = initialize_tasks(num_tasks, max_end_time);
//	std::cout << "[��ü �۾�]" << std::endl;
//	print(tasks, max_end_time);
//
//	auto scheduled_tasks = job_scheduling(tasks);
//	std::cout << "\n[������ ������ �۾�]" << std::endl;
//	print(scheduled_tasks, max_end_time);
//}