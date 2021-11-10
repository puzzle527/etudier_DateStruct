//#pragma once
////Exercise24
////최단 작업 우선 스케줄링(작업시간이 가장 적게 걸리는 순으로 정렬)
//
//template<typename T>
//auto compute_waiting_times(vector<T>& service_times)
//{
//	vector<T> W(service_times.size());
//	W[0] = 0;
//
//	for (auto i = 1; i < service_times.size(); i++)
//		W[i] = W[i - 1] + service_times[i - 1];
//
//	return W;
//}
//
//template<typename T>
//void print_vector(vector<T>& V)
//{
//	for (auto& i : V)
//	{
//		//출력값 길이지정
//		cout.width(2);
//		cout << i << " ";
//	}
//	cout << endl;
//}
//
//template<typename T>
//void compute_and_print_waiting_times(vector<T>& service_times)
//{
//	auto waiting_times = compute_waiting_times<int>(service_times);
//
//	cout << "- 처리 시간: ";
//	print_vector<T>(service_times);
//
//	cout << "- 대기 시간: ";
//	print_vector<T>(waiting_times);
//
//	//평균 대기 시간			//누적값 합연산(iter.first, iter.last, casting type)
//	auto ave_waiting_times = accumulate(waiting_times.begin(), waiting_times.end(), 0.0)
//							/ waiting_times.size();
//	cout << "- 평균 대기 시간: " << ave_waiting_times;
//	cout << endl;
//}