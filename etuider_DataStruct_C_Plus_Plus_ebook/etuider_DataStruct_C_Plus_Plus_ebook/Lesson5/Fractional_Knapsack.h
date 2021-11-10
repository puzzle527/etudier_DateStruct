//#pragma once
////Exercise25
////분할 가능 배낭 문제
//
//struct Object
//{
//	int id;
//	int weight;
//	double value;
//	double value_per_unit_weight;
//
//	Object(int i, int w, double v)
//		: id(i), weight(w), value(v), value_per_unit_weight(v / w) {}
//
//	//std::sort()에서 사용
//	inline bool operator< (const Object& obj) const
//	{
//		return this->value_per_unit_weight < obj.value_per_unit_weight;
//	}
//
//	//콘솔 출력 지원. cout << obj << endl; 코드 사용 가능
//	friend ostream& operator<< (ostream& os, const Object& obj);
//};
//
//ostream& operator<< (ostream& os, const Object& obj)
//{
//	os << "[" << obj.id << "] 가격: " << obj.value
//		<< "\t무게: " << obj.weight
//		<< "kg\t단위 무게 당 가격: " << obj.value_per_unit_weight;
//	return os;
//}
//
////분할 가능 배낭 문제 알고리즘 구현 함수
//auto fill_knapsack(vector<Object>& objects, int knapsack_capacity)
//{
//	vector<Object> knapsack_contents;
//	knapsack_contents.reserve(objects.size());
//
//	//물건들을 내림차순으로 정렬(단위 무게 당 가격 기준)
//	sort(objects.begin(), objects.end());
//	reverse(objects.begin(), objects.end());
//
//	//'가장 가치 있는' 물건들 먼저 배낭에 추가
//	auto current_object = objects.begin();
//	int current_total_weight = 0;
//	while (current_total_weight < knapsack_capacity && current_object != objects.end())
//	{
//		knapsack_contents.push_back(*current_object);
//		current_total_weight += current_object->weight;
//		current_object++;
//	}
//
//	//마지막 추가한 물건에 의해 배낭 최대 허용 무게가 초과된 경우
//	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
//	Object& last_object = knapsack_contents.back();
//	if (weight_of_last_obj_to_remove > 0)
//	{
//		last_object.weight -= weight_of_last_obj_to_remove;
//		last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
//	}
//	return knapsack_contents;
//}