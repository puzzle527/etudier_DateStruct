//#pragma once
////Exercise22
//
//void transform_test(vector<int> S)
//{
//	vector<int> Tr;
//	cout << "[맵 테스트]" << endl;
//	cout << "입력 배열, S: ";
//	for (auto i : S)
//		cout << i << " ";
//	cout << endl;
//
//	//std::transform() 함수 사용
//	transform(S.begin(), S.end(), back_inserter(Tr), [](int x) {return pow(x, 2.0); });
//
//	cout << "std::transform(), Tr: ";
//	for (auto i : Tr)
//		cout << i << " ";
//	cout << endl;
//
//	//std::for_each() 함수 사용
//	for_each(S.begin(), S.end(), [](int& x) {x = pow(x, 2.0); });
//
//	cout << "std::for_each(), S: ";
//	for (auto i : S)
//		cout << i << " ";
//	cout << endl;
//}
//
//void reduce_test(vector<int> S)
//{
//	cout << endl;
//	cout << "[리듀스 테스트]" << endl;
//	cout << "입력 배열, S: ";
//	for (auto i : S)
//		cout << i << " ";
//	cout << endl;
//
//	//std::accumulate() 함수 사용
//	auto ans = accumulate(S.begin(), S.end(), 0, [](int acc, int x) { return acc + x; });
//	cout << "std::accumulate(), ans: " << ans << endl;
//}
