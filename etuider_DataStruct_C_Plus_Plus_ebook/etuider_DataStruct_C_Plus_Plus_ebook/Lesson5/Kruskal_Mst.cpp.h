//#pragma once
////Exercise26
//
//class SimpleDisjointSet
//{
//private:
//	struct Node
//	{
//		unsigned id;
//		unsigned rank;
//		unsigned parent;
//
//		Node(unsigned _id) : id(_id), rank(0), parent(_id) {}
//
//		bool operator!=(const Node& n) const
//		{
//			return this->id != n.id;
//		}
//	};
//
//	//������Ʈ-�� ������Ʈ
//	vector<Node> nodes;
//public:
//	SimpleDisjointSet(unsigned N)
//	{
//		nodes.reserve(N);
//	}
//	void make_set(const unsigned& x)
//	{
//		nodes.emplace_back(x);
//	}
//	unsigned find(unsigned x)
//	{
//		auto node_it = find_if(nodes.begin(), nodes.end(), [x](auto n) {return n.id == x; });
//		unsigned node_id = (*node_it).id;
//
//		while (node_id != nodes[node_id].parent)
//		{
//			node_id = nodes[node_id].parent;
//		}
//		return node_id;
//	}
//	void union_sets(unsigned x, unsigned y)
//	{
//		auto root_x = find(x);
//		auto root_y = find(y);
//
//		//���� X�� Y�� ���� Ʈ���� �ִٸ� �״�� ����
//		if (root_x == root_y)
//			return;
//		//���� ��ũ�� Ʈ���� ū ��ũ�� Ʈ�� ������ ����
//		if (nodes[root_x].rank > nodes[root_y].rank)
//			swap(root_x, root_y);
//
//		nodes[root_x].parent = nodes[root_y].parent;
//		nodes[root_y].rank++;
//	}
//};
//
//template<typename T>
//struct Edge
//{
//	unsigned src;
//	unsigned dest;
//	T weight;
//
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
//	unsigned V; //��������
//	vector<Edge<T>> edge_list;
//public:
//	//N���� �������� ������ �׷���
//	Graph(unsigned N) : V(N) {}
//	//�׷����� ���� ���� ��ȯ
//	auto vertices() const { return V; }
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
//	void add_edge(Edge<T>&& e)
//	{
//		//���� �� �� ���� ID�� ��ȿ���� �˻�
//		if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V)
//			edge_list.emplace_back(e);
//		else
//			cout << "���� : ��ȿ������ ��� ����!" << endl;
//	}
//
//	//ǥ�� ��� ��Ʈ�� ����
//	template<typename U>
//	friend ostream& operator<< (ostream& os, const Graph<U>& G);
//};
//
//template<typename U>
//ostream& operator<< (ostream& os, const Graph<U>& G)
//{
//	for (unsigned i = 1; i < G.vertices(); i++)
//	{
//		os << i << ":\t";
//		auto edges = G.edges(i);
//		for (auto& e : edges)
//			os << "{" << e.dest << ": " << e.weight << "}, ";
//		os << endl;
//	}
//	return os;
//}
//
////ũ�罺Į �ּ� ���� Ʈ�� �˰��� ����
//template<typename T>
//Graph<T> minimum_spanning_tree(const Graph<T>& G)
//{
//	//���� ����ġ�� �̿��� �ּ� �� ����
//	priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;
//
//	//��� ������ �ּ� ���� �߰�
//	for (auto& e : G.edges())
//		edge_min_heap.push(e);
//
//	//���� ������ �ش��ϴ� ũ���� ������Ʈ-�� �ڷ� ���� ���� �� �ʱ�ȭ
//	auto N = G.vertices();
//	SimpleDisjointSet dset(N);
//	for (unsigned i = 0; i < N; i++)
//		dset.make_set(i);
//
//	//������Ʈ-�� �ڷᱸ���� �̿��Ͽ� �ּ� ���� Ʈ�� ���ϱ�
//	Graph<T> MST(N);
//	while (!edge_min_heap.empty())
//	{
//		//�ּ� ������ �ּ� ����ġ ������ ����
//		auto e = edge_min_heap.top();
//		edge_min_heap.pop();
//		//������ ������ ����Ŭ�� �������� ������ �ش� ������ MST�� �߰�
//		if (dset.find(e.src) != dset.find(e.dest))
//		{
//			MST.add_edge(Edge<T>{e.src, e.dest, e.weight});
//			dset.union_sets(e.src, e.dest);
//		}
//	}
//	return MST;
//}