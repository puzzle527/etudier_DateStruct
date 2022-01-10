//#pragma once
//Exercise30
//
//template<typename T>
//struct Edge
//{
//	unsigned src;
//	unsigned dst;
//	T weight;
//};
//
//template<typename T>
//class Graph
//{
//private:
//	unsigned V;
//	vector<Edge<T>> edge_list;
//public:
//	Graph(unsigned N) : V(N) {}
//
//	 표준 출력 스트림 지원
//	template <typename U>
//	friend ostream& operator<< (ostream& os, const Graph<U>& G);
//
//	auto vertices() const { return V; }
//	auto& edges() const { return edge_list; }
//	정점 v에서 나가는 모든 에지를 반환
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
//		 에지 양 끝 정점 ID가 유효한지 검사
//		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
//			edge_list.emplace_back(e);
//		else
//			cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
//	}
//};
//
//template <typename U>
//ostream& operator<< (ostream& os, const Graph<U>& G)
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
//
//	return os;
//}
//
//template <typename T>
//auto create_reference_graph()
//{
//	Graph<T> G(9);
//
//	map<unsigned, vector<pair<unsigned, T>>> edge_map;
//	edge_map[1] = { {2, 2}, {5, 3} };
//	edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
//	edge_map[3] = { {4, 2}, {7, 3} };
//	edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
//	edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
//	edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
//	edge_map[7] = { {3, 3}, {6, 4} };
//	edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };
//
//	for (auto& i : edge_map)
//		for (auto& j : i.second)
//			G.add_edge(Edge<T>{ i.first, j.first, j.second });
//
//	return G;
//}
//
//template<typename T>
//struct Label
//{
//	unsigned ID;
//	T distance;
//	Label 객체 비교는 거리 distance 값을 이용
//	inline bool operator> (const Label<T>& l) const
//	{
//		return this->distance > l.distance;
//	}
//};
//
//template<typename T>
//auto prim_MST(Graph<T>& G, unsigned src)
//{
//	최소 힙
//	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
//
//	모든 정점에서 거리 값을 최대로 설정
//	vector<T> distance(G.vertices(), numeric_limits<T>::max());
//
//	set<unsigned> visited; //방문한 정점
//	vector<unsigned> MST;  //최소신장트리
//
//	heap.emplace(Label<T>{src, 0}); //heap에 삽입
//
//	while (!heap.empty())
//	{
//		auto current_vertex = heap.top();
//		heap.pop();
//
//		현재 정점을 이전에 방문하지 않았다면
//		if (visited.find(current_vertex.ID) == visited.end())
//		{
//			MST.push_back(current_vertex.ID);
//
//			for (auto& e : G.edges(current_vertex.ID))
//			{
//				auto neighbor = e.dst;
//				auto new_distance = e.weight;
//
//				인접한 정점의 거리 값이 새로운 경로에 의한 거리 값보다 크면
//				힙에 추가하고, 거리 값을 업데이트함
//				if (new_distance < distance[neighbor])
//				{
//					heap.emplace(Label<T>{neighbor, new_distance});
//					distance[neighbor] = new_distance;
//				}
//			}
//			visited.insert(current_vertex.ID);
//		}
//	}
//	return MST;
//}