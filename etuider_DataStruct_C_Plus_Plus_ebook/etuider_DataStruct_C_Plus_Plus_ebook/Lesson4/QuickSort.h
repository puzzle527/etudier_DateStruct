#pragma once
//Exercise20

//���ҵ����� ���� �Լ�
template<typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	//�� ���� �ݺ��� ����
	//�ϳ��� �ǹ�, �������� ���� ����, ��
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (1)
	{
		//ù��° ���Һ��� �����Ͽ� �ǹ����� ū ���Ҹ� ã���ϴ�.
		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
			left_iter++;
		//���� ������ ���Һ��� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã���ϴ�.
		while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
			right_iter--;

		//���� left_iter�� right_iter�� ���ٸ� ��ȯ�� ���Ұ� ������ �ǹ��մϴ�.
		//�׷��� ������ left_iter�� right_iter�� ����Ű�� ���Ҹ� ���� ��ȯ�մϴ�.
		if (left_iter == right_iter)
			break;
		else
			iter_swap(left_iter, right_iter); //iter_swap �ݺ��ڰ� ����Ű�� ���� ��ȯ
	}

	if (pivot_val > *right_iter)
		iter_swap(begin, right_iter);

	return right_iter;
}

template<typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last)
{
	if (distance(begin, last) >= 1)
	{
		//���� �۾� ����
		auto partition_iter = partition<T>(begin, last);

		//���� �۾��� ���� ������ ���͸� ��������� ����
		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}

template <typename T>
void print_vector(vector<T> arr)
{
	for (auto i : arr)
		cout << i << " ";

	cout << endl;
}

void run_quick_sort_test()
{
	vector<int>    S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
	vector<float>  S2{ 45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f };
	vector<double> S3{ 45.6, 1.0, 3.8 , 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0 };
	vector<char>   C{ 'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y' };

	cout << "���ĵ��� ���� �Է� ����:" << endl;
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
	cout << endl;

	// arr.end()�� �� ������ ���� ������ ����Ű�Ƿ� arr.end() - 1 ���·� ȣ���մϴ�.
	quick_sort<int>(S1.begin(), S1.end() - 1);
	quick_sort<float>(S2.begin(), S2.end() - 1);
	quick_sort<double>(S3.begin(), S3.end() - 1);
	quick_sort<char>(C.begin(), C.end() - 1);

	cout << "�� ���� ���� ���� ����:" << endl;
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
	cout << endl;
}
