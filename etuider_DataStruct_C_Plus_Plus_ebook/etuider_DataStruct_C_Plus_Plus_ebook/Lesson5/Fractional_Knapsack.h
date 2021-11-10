//#pragma once
////Exercise25
////���� ���� �賶 ����
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
//	//std::sort()���� ���
//	inline bool operator< (const Object& obj) const
//	{
//		return this->value_per_unit_weight < obj.value_per_unit_weight;
//	}
//
//	//�ܼ� ��� ����. cout << obj << endl; �ڵ� ��� ����
//	friend ostream& operator<< (ostream& os, const Object& obj);
//};
//
//ostream& operator<< (ostream& os, const Object& obj)
//{
//	os << "[" << obj.id << "] ����: " << obj.value
//		<< "\t����: " << obj.weight
//		<< "kg\t���� ���� �� ����: " << obj.value_per_unit_weight;
//	return os;
//}
//
////���� ���� �賶 ���� �˰��� ���� �Լ�
//auto fill_knapsack(vector<Object>& objects, int knapsack_capacity)
//{
//	vector<Object> knapsack_contents;
//	knapsack_contents.reserve(objects.size());
//
//	//���ǵ��� ������������ ����(���� ���� �� ���� ����)
//	sort(objects.begin(), objects.end());
//	reverse(objects.begin(), objects.end());
//
//	//'���� ��ġ �ִ�' ���ǵ� ���� �賶�� �߰�
//	auto current_object = objects.begin();
//	int current_total_weight = 0;
//	while (current_total_weight < knapsack_capacity && current_object != objects.end())
//	{
//		knapsack_contents.push_back(*current_object);
//		current_total_weight += current_object->weight;
//		current_object++;
//	}
//
//	//������ �߰��� ���ǿ� ���� �賶 �ִ� ��� ���԰� �ʰ��� ���
//	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
//	Object& last_object = knapsack_contents.back();
//	if (weight_of_last_obj_to_remove > 0)
//	{
//		last_object.weight -= weight_of_last_obj_to_remove;
//		last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
//	}
//	return knapsack_contents;
//}