//#pragma once
//
//Activity12
//template<typename T>
//struct Edge
//{
//	unsigned src;
//	unsigned dst;
//	T weight;
//
//	//Edge ��ü �񱳴� ����ġ�� �̿�
//	inline bool operator< (const Edge<T>& e) const
//	{
//		return this->weight < e.weight;
//	}
//	inline bool operator> (const Edge<T>& e) const
//	{
//		return this->weight > e.weight;
//	}
//};
//
//template<typename T>
//class Graph
//{
//private:
//	unsigned V;
//	vector<Edge<T>> edge_list;
//public:
//	//N���� �������� ������ �׷���
//	Graph(unsigned N) : V(N) {}
//	//�׷����� ���� ���� ��ȯ
//	auto vertices() const { return V; }
//	//��ü ���� ����Ʈ ��ȯ
//	auto& edges() { return edge_list; }
//	//���� v���� ������ ��� ������ ��ȯ
//	auto edges(unsigned v) const
//	{
//		vector<Edge<T>> edges_from_v;
//		for (auto& e : edge_list)
//		{
//			if (e.src == v)
//				edges_from_v.emplace_back(e);
//		}
//
//		return edges_from_v;
//	}
//	void add_edge(Edge<T>&& e)
//	{
//		//���� �� �� ���� ID�� ��ȿ���� �˻�
//		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
//			edge_list.emplace_back(e);
//		else
//			cerr << "����: ��ȿ ������ ��� ����!" << endl;
//	}
//
//	//ǥ�� ��� ��Ʈ�� ����
//	template<typename U>
//	friend ostream& operator<< (ostream& os, Graph<U>& G);
//};
//
//template <typename U>
//ostream& operator<< (ostream& os, Graph<U>& G)
//{
//	for (unsigned i = 1; i < G.vertices(); i++)
//	{
//		os << i << ":\t";
//
//		auto edges = G.edges(i);
//		for (auto& e : edges)
//			os << "{" << e.dst << ": " << e.weight << "}, ";
//
//		os << endl;
//	}
//	return os;
//}
//
//// �׷��� �÷����� ����� ���� ��ȣ
//unordered_map<unsigned, string> color_map = {
//	{1, "Red"},
//	{2, "Blue"},
//	{3, "Green"},
//	{4, "Yellow"},
//	{5, "Black"},
//	{6, "White"}
//};
//
//template<typename T>
//auto welsh_powell_coloring(Graph<T>& G)
//{
//	auto size = G.vertices();
//	vector<pair<unsigned, size_t>> degrees;
//
//	//�� ������ ������ <���� ID, ����>�� ������ ����
//	for (unsigned i = 1; i < size; i++)
//		degrees.push_back(make_pair(i, G.edges(i).size()));
//
//	//������ ���� �������� �������� ����
//	sort(degrees.begin(), degrees.end(), [](auto& a, auto& b) {return a.second > b.second; });
//
//	cout << "[���� ���� ���� (��ȣ�� ����)]" << endl;
//	for (auto i : degrees)
//		cout << "" << i.first << " (" << i.second << ")" << endl;
//
//	vector<unsigned> assigned_color(size);
//	auto color_to_be_assigned = 1;
//
//	while (1)
//	{
//		for (auto i : degrees)
//		{
//			//�̹� ��ĥ�� ĥ���� ������ ���� ������ �˻�
//			if (assigned_color[i.first] != 0)
//				continue;
//
//			auto outgoing_edges = G.edges(i.first);
//
//			//i��° ������ �������ִ� �������� ���� ����
//			set<unsigned> neighbours;
//
//			for (auto& e : outgoing_edges)
//			{
//				neighbours.insert(assigned_color[e.dst]);
//			}
//			//i��° ������ ������ ������ color_to_be_assigned ������ ������ ���� �ʴٸ�
//			//i��° ������ color_to_be_assigned ������ ����
//			if (neighbours.find(color_to_be_assigned) == neighbours.end())
//				assigned_color[i.first] = color_to_be_assigned;
//		}
//
//		color_to_be_assigned++;
//
//		//��� ������ ��ĥ�� ĥ�������� ����
//		if (find(assigned_color.begin() + 1, assigned_color.end(), 0) ==
//			assigned_color.end())
//			break;
//	}
//
//	return assigned_color;
//}
//
//template <typename T>
//void print_colors(vector<T>& colors)
//{
//	for (auto i = 1; i < colors.size(); i++)
//	{
//		cout << i << ": " << color_map[colors[i]] << endl;
//	}
//}