#pragma once
//Activity 8

//class Student
//{
//private:
//	pair<int, int> name; //�л� ID <�̸�, ��>
//	bool vaccinated; //���� ���� ����
//
//public:
//	Student(pair<int, int> n, bool v)
//		: name(n), vaccinated(v) {}
//
//	auto get_name() { return name; }
//	auto is_vaccinated() { return vaccinated; }
//
//	//�̸��� ������ ���� ������� ���
//	bool operator==(const Student& p) const
//	{
//		return this->name == p.name;
//	}
//	//�̸��� �̿��Ͽ� �����ϵ��� ����
//	bool operator<(const Student& p) const
//	{
//		return this->name < p.name;
//	}
//	bool operator>(const Student& p) const
//	{
//		return this->name > p.name;
//	}
//};
//
////1���� max ������ ID�� ���� ������ �л� ������ �����մϴ�.
//auto generate_random_Student(int max)
//{
//	random_device rd;
//	mt19937_64 rand(rd());
//
//	//�л� ID ������ [1, max]�� ����
//	uniform_int_distribution<mt19937_64::result_type> uniform_dist(1, max);
//
//	//������ �л����� ����
//	auto random_name = make_pair(uniform_dist(rand), uniform_dist(rand));
//	auto is_vaccinated = uniform_dist(rand) % 2 ? true : false;
//
//	return Student(random_name, is_vaccinated);
//}
//
//bool needs_vaccination(Student P, vector<Student>& people)
//{
//	auto first = people.begin();
//	auto last = people.end();
//
//	while (1)
//	{
//		auto range_length = distance(first, last);
//		auto mid_element_index = floor(range_length / 2);
//		auto mid_element = *(first + mid_element_index);
//
//		//��Ͽ� �ش� �л��� �ְ�, ���� ������ ���� �ʾҴٸ� true ��ȯ
//		if (mid_element == P && mid_element.is_vaccinated() == false)
//			return true;
//		//��Ͽ� �ش� �л��� �ְ�, ���� ������ �޾Ҵٸ� false ��ȯ
//		else if (mid_element == P && mid_element.is_vaccinated() == true)
//			return false;
//		else if (mid_element > P)
//			advance(last, -mid_element_index);
//		if (mid_element < P)
//			advance(first, mid_element_index);
//
//		//��Ͽ� �ش� �л��� ���ٸ� true ��ȯ
//		if (range_length == 1)
//			return true;
//	}
//}
//
//void search_test(int size, Student p)
//{
//	vector<Student> people;
//
//	//������ �л� ���� ��� ����
//	for (auto i = 0; i < size; i++)
//		people.push_back(generate_random_Student(size));
//
//	sort(people.begin(), people.end());
//
//	//���� �˻� ���� �� �ð� ����
//	auto begin = chrono::steady_clock::now();
//
//	bool serach_result = needs_vaccination(p, people);
//
//	auto end = chrono::steady_clock::now();
//	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
//
//	cout << "���� �˻� �ҿ� �ð�: " << diff.count() << "us" << endl;
//
//	if (serach_result)
//		cout << p.get_name().first << " " << p.get_name().second << "���� ���� �ʿ�" << endl;
//	else
//		cout << p.get_name().first << " " << p.get_name().second << "���� ���� �ʿ�X" << endl;
//}