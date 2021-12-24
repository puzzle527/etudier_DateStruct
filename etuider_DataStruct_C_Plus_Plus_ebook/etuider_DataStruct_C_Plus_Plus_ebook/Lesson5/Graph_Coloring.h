//#pragma once
////Exercise27
// �׷��� �÷��� �ٽ� �����ϱ�
//
//template<typename T>
//struct Edge
//{
//	unsigned src;
//	unsigned dst;
//	T weight;
//
//	//Egde ��ü �񱳴� ����ġ�� �̿�
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
//	auto vertices() { return V; }
//	//��ü ���� ����Ʈ ��ȯ
//	auto& edges() const { return edge_list; }
//	//���� v���� ������ ��� ������ ��ȯ
//	auto edges(unsigned v) const
//	{
//		vector<Edge<T>> edges_from_v;
//		for (auto& e : edge_list)
//		{
//			if (e.src == v)
//				edges_from_v.emplace_back(e);
//		}
//		return edges_from_v;
//	}
//
//	void add_edge(Edge<T>&& e)
//	{
//		//���� �� �� ���� ID�� ��ȿ���� �˻�
//		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
//			edge_list.emplace_back(e);
//		else
//			cerr << "����: ��ȿ ������ ��� ����!" << endl;
//	}
//	//ǥ�� ��� ��Ʈ�� ����
//	template<typename U>
//	friend ostream& operator<< (ostream& os, const Graph<U>& G);
// };
//
//template<typename U>
//ostream& operator<< (ostream& os, Graph<U>& G)
//{
//	for (unsigned i = 1; i < G.vertices(); i++)
//	{
//		os << i << ":\t";
//		
//		auto edges = G.edges(i);
//		for (auto& e : edges)
//			os << "{" << e.dst << ": " << e.weight << "}, ";
//		os << endl;
//	}
//	return os;
//}
//
////�׷��� �÷����� ����� ���� ��ȣ
//unordered_map<unsigned, string> color_map = {
//	{1, "Red"},
//	{2, "Blue"},
//	{3, "Green"},
//	{4, "Yellow"},
//	{5, "Black"},
//	{6, "White"},
//};
//
//template<typename T>
//auto greedy_coloring(Graph<T>& G)
//{
//	auto size = G.vertices();
//	vector<unsigned> assigned_colors(size);
//
//	//1�� �������� ���ʴ�� �˻��մϴ�.
//	for (unsigned i = 1; i < size; i++)
//	{
//		auto outgoing_edges = G.edges(i);
//
//		//i��° ������ ������ �ִ� �������� ���� ����
//		set<unsigned> neighbours;
//
//		for (auto& e : outgoing_edges)
//		{
//			neighbours.insert(assigned_colors[e.dst]);
//		}
//		
//		//������ ������ ĥ������ ���� ���� �߿��� ���� ���� ������ ������ ����
//		auto smallest = 1;
//		for (; smallest <= color_map.size(); smallest++)
//		{
//			if (neighbours.find(smallest) == neighbours.end())
//				break;
//		}
//
//		assigned_colors[i] = smallest;
//	}
//	
//	return assigned_colors;
//}
//
//template<typename T>
//void print_colors(vector<T>& colors)
//{
//	for (auto i = 1; i < colors.size(); i++)
//	{
//		cout << i << ": " << color_map[colors[i]] << endl;
//	}
//}