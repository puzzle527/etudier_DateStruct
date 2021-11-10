//#pragma once
////Exercise21
//
////�� �ݺ��� ������ �߰� ���� ã�� �Լ�
//template<typename T>
//auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last)
//{
//	//����
//	quick_sort<T>(begin, last);
//
//	//���(median) ���� �ݺ��ڸ� ��ȯ
//	return begin + (distance(begin, last) / 2);
//}
//
////�ǹ� ��ġ �ݺ��ڸ� ���ڷ� �޴� ������ ���� �Լ�
//template<typename T>
//auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end,
//	typename vector<T>::iterator pivot)
//{
//	//�ǹ� ��ġ�� �Լ� ���ڷ� �־����Ƿ�,
//	//���� ���۰� ������ ���Ҹ� ����Ű�� �ݺ��ڸ� �����մϴ�.
//	auto left_iter = begin;
//	auto right_iter = end;
//
//	while (1)
//	{
//		//������ ù ��° ���Һ��� �����Ͽ� �ǹ����� ū ���Ҹ� ã���ϴ�.
//		while (*left_iter < *pivot && left_iter != right_iter)
//			left_iter++;
//		//������ ������ ���Һ��� �����Ͽ� �������� �ǹ����� ���� ���Ҹ� ã���ϴ�.
//		while (*right_iter >= *pivot && left_iter != right_iter)
//			right_iter--;
//
//		//���� left_iter�� right_iter�� ���ٸ� ��ȯ�� ���Ұ� ������ �ǹ��մϴ�.
//		//�׷��� ������ left_iter�� right_iter�� ����Ű�� ���Ҹ� ���� ��ȯ�մϴ�.
//		if (left_iter == right_iter)
//			break;
//		else
//			iter_swap(left_iter, right_iter);
//	}
//
//	if (*pivot > *right_iter)
//		iter_swap(pivot, right_iter);
//
//	return right_iter;
//}
//
//template<typename T>
//typename vector<T>::iterator linear_time_select(typename vector<T>::iterator begin,
//												typename vector<T>::iterator last, size_t i)
//{
//	auto size = distance(begin, last);
//
//	if (size > 0 && i < size)
//	{
//		//�ټ� �� ���� �����Ͽ� ���� �κ� ���� Vi�� ���� ���
//		auto num_Vi = (size + 4) / 5;
//		size_t j = 0;
//		//������ Vi���� �߾Ӱ��� ã�� ���� M�� ����
//		vector<T> M;
//		for (; j < size / 5; j++)
//		{
//			auto b = begin + (j * 5);
//			auto l = begin + (j * 5) + 5;
//
//			M.push_back(*find_median<T>(b, l));
//		}
//
//		if (j * 5 < size)
//		{
//			auto b = begin + (j * 5);
//			auto l = begin + (j * 5) + (size % 5);
//
//			M.push_back(*find_median<T>(b, l));
//		}
//
//		//Vi�� �߾Ӱ����� ������ ���� M���� �ٽ� �߾Ӱ� q�� ã��
//		auto median_of_medians = (M.size() == 1) ? M.begin() :
//			linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);
//
//		//���� ������ �����ϰ� �ǹ� q�� ��ġ k�� ã��
//		auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
//		auto k = distance(begin, partition_iter) + 1;
//
//		if (i == k)
//			return partition_iter;
//		else if (i < k)
//			return linear_time_select<T>(begin, partition_iter - 1, i);
//		else if (i > k)
//			return linear_time_select<T>(partition_iter + 1, last, i - k);
//	}
//	else
//	{
//		return begin;
//	}
//};
//
//template<typename T>
//vector<T> merge(vector<T>& arr1, vector<T>& arr2)
//{
//	vector<T> merged;
//
//	auto iter1 = arr1.begin();
//	auto iter2 = arr2.begin();
//
//	while (iter1 != arr1.end() && iter2 != arr2.end())
//	{
//		if (*iter1 < *iter2)
//		{
//			merged.emplace_back(*iter1);
//			iter1++;
//		}
//		else
//		{
//			merged.emplace_back(*iter2);
//			iter2++;
//		}
//	}
//
//	if (iter1 != arr1.end())
//	{
//		for (; iter1 != arr1.end(); iter1++)
//			merged.emplace_back(*iter1);
//	}
//	else
//	{
//		for (; iter2 != arr2.end(); iter2++)
//			merged.emplace_back(*iter2);
//	}
//	return merged;
//}
//
//template<typename T>
//vector<T> merge_sort(vector<T> arr)
//{
//	if (arr.size() > 1)
//	{
//		auto mid = size_t(arr.size() / 2);
//		auto left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
//		auto right_half = merge_sort(vector<T>(arr.begin() + mid, arr.end()));
//
//		return merge<T>(left_half, right_half);
//	}
//
//	return arr;
//}
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
//void run_linear_select_test()
//{
//	std::vector<int> S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
//
//	std::cout << "�Է� ����:" << std::endl;
//	print_vector<int>(S1);
//
//	std::cout << "���ĵ� ����:" << std::endl;
//	print_vector<int>(merge_sort<int>(S1));
//
//	std::cout << "3��° ����: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 3) << std::endl;
//	std::cout << "5���� ����: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 5) << std::endl;
//	std::cout << "11��° ����: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 11) << std::endl;
//}