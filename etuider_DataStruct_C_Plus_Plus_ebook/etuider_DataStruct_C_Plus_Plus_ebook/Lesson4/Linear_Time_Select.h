#pragma once
//Exercise21

//두 반복자 사이의 중간 값을 찾는 함수
template<typename T>
auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last)
{
	//정렬
	quick_sort<T>(begin, last);

	//가운데(median) 원소 반복자를 반환
	return begin + (distance(begin, last) / 2);
}

//피벗 위치 반복자를 인자로 받는 형태의 분할 함수
template<typename T>
auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end,
	typename vector<T>::iterator pivot)
{
	//피벗 위치는 함수 인자로 주어지므로,
	//벡터 시작과 마지막 원소를 가리키는 반복자를 정의합니다.
	auto left_iter = begin;
	auto right_iter = end;

	while (1)
	{
		//벡터의 첫 번째 원소부터 시작하여 피벗보다 큰 원소를 찾습니다.
		while (*left_iter < *pivot && left_iter != right_iter)
			left_iter++;
		//벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
		while (*right_iter >= *pivot && left_iter != right_iter)
			right_iter--;

		//만약 left_iter와 right_iter가 같다면 교환할 원소가 없음을 의미합니다.
		//그렇지 않으면 left_iter와 right_iter가 가리키는 원소를 서로 교환합니다.
		if (left_iter == right_iter)
			break;
		else
			iter_swap(left_iter, right_iter);
	}

	if (*pivot > *right_iter)
		iter_swap(pivot, right_iter);

	return right_iter;
}

template<typename T>
typename vector<T>::iterator linear_time_select(typename vector<T>::iterator begin,
												typename vector<T>::iterator last, size_t i)
{
	auto size = distance(begin, last);

	if (size > 0 && i < size)
	{
		//다섯 개 원소 구분하여 만들 부분 벡터 Vi의 개수 계산
		auto num_Vi = (size + 4) / 5;
		size_t j = 0;
		//각각의 Vi에서 중앙값을 찾아 벡터 M에 저장
		vector<T> M;
		for (; j < size / 5; j++)
		{
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + 5;

			M.push_back(*find_median<T>(b, l));
		}

		if (j * 5 < size)
		{
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + (size % 5);

			M.push_back(*find_median<T>(b, l));
		}

		//Vi의 중앙값으로 구성된 벡터 M에서 다시 중앙값 q를 찾음
		auto median_of_medians = (M.size() == 1) ? M.begin() :
			linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);

		//분할 연산을 적용하고 피벗 q의 위치 k를 찾음
		auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
		auto k = distance(begin, partition_iter) + 1;

		if (i == k)
			return partition_iter;
		else if (i < k)
			return linear_time_select<T>(begin, partition_iter - 1, i);
		else if (i > k)
			return linear_time_select<T>(partition_iter + 1, last, i - k);
	}
	else
	{
		return begin;
	}
};