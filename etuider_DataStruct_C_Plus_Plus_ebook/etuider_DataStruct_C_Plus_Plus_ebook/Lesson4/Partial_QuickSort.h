//#pragma once
////Activity09
//
//template<typename T>
//auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end)
//{
//	auto pivot_val = *begin;
//	auto left_iter = begin + 1;
//	auto right_iter = end;
//
//	while (1)
//	{
//		//������ ù ��° ���Һ��� �����Ͽ� �ǹ����� ū ���Ҹ� ã���ϴ�.
//		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
//			left_iter++;
//
//		//������ ������ ���Һ��� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã���ϴ�.
//		while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
//			right_iter--;
//
//		//���� left_iter�� right_iter�� ���ٸ� ��ȯ�� ���Ұ� ������ �ǹ��մϴ�.
//		//�׷��� ������ left_iter�� right_iter�� ����Ű�� ���Ҹ� ���� ��ȯ�մϴ�.
//		if (left_iter == right_iter)
//			break;
//		else
//			iter_swap(left_iter, right_iter);
//
//	}
//
//	if (pivot_val > *right_iter)
//		iter_swap(begin, right_iter);
//
//
//	return right_iter;
//}
//
//template <typename T>
//void partial_quick_sort(typename std::vector<T>::iterator begin,
//	typename std::vector<T>::iterator last,
//	size_t k)
//{
//	// ���Ϳ� �ϳ� �̻��� ���Ұ� ���� �ִ� ���
//	if (std::distance(begin, last) >= 1)
//	{
//		// ���� ������ ����
//		auto partition_iter = partition<T>(begin, last);
//
//		// ���� ���꿡 ���� ������ �� ���͸� ��������� ����
//		partial_quick_sort<T>(begin, partition_iter - 1, k);
//
//		// ���� ������ �ǹ� ��ġ�� k���� ������ ������ �κ� ���͵� ����
//		if (std::distance(begin, partition_iter) < k)
//			partial_quick_sort<T>(partition_iter, last, k);
//	}
//}
//
//template <typename T>
//void quick_sort(typename std::vector<T>::iterator begin,
//	typename std::vector<T>::iterator last)
//{
//	// ���� ���Ϳ� �ϳ� �̻��� ���Ұ� �ִٸ�
//	if (std::distance(begin, last) >= 1)
//	{
//		// ���� �۾��� ����
//		auto partition_iter = partition<T>(begin, last);
//
//		// ���� �۾��� ���� ������ ���͸� ��������� ����
//		quick_sort<T>(begin, partition_iter - 1);
//		quick_sort<T>(partition_iter, last);
//	}
//}
//
//
//template <typename T>
//void print_vector(std::vector<T> arr)
//{
//	for (auto i : arr)
//		std::cout << i << " ";
//
//	std::cout << std::endl;
//}
//
//template <typename T>
//auto generate_random_vector(T size)
//{
//	std::vector<T> V;
//	V.reserve(size);
//
//	std::random_device rd;
//	std::mt19937 rand(rd());
//
//	std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);
//
//	for (T i = 0; i < size; i++)
//		V.push_back(uniform_dist(rand));
//
//	return std::move(V);
//}
//
//template <typename T>
//void test_partial_quicksort(size_t size, size_t k)
//{
//	// ������ ���͸� �����ϰ�, ���纻�� ����� �� �˰��� ���� �׽�Ʈ ����.
//	auto random_vec = generate_random_vector<T>(size);
//	auto random_vec_copy(random_vec);
//
//	std::cout << "�Է� ����: " << std::endl;
//	print_vector<T>(random_vec);
//
//	// �κ� �� ���� �˰��� ���� �ð� ����
//	auto begin1 = std::chrono::steady_clock::now();
//	partial_quick_sort<T>(random_vec.begin(), random_vec.end() - 1, k);
//	auto end1 = std::chrono::steady_clock::now();
//	auto diff1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
//
//	std::cout << std::endl;
//	std::cout << "�κ� �� ���� ���� �ð�: " << diff1.count() << "us" << std::endl;
//
//	std::cout << "(ó�� " << k << "�� ���Ҹ�) �κ� ���ĵ� ����: ";
//	print_vector<T>(random_vec);
//
//	// ��ü �� ���� �˰��� ���� �ð� ����
//	auto begin2 = std::chrono::steady_clock::now();
//	quick_sort<T>(random_vec_copy.begin(), random_vec_copy.end() - 1);
//	auto end2 = std::chrono::steady_clock::now();
//	auto diff2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
//
//	std::cout << std::endl;
//	std::cout << "��ü �� ���� ���� �ð�: " << diff2.count() << "us" << std::endl;
//
//	std::cout << "��ü ���ĵ� ����: ";
//	print_vector<T>(random_vec_copy);
//}
