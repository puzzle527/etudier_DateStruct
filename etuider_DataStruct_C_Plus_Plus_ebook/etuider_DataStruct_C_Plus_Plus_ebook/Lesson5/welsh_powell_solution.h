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
//	//Edge 객체 비교는 가중치를 이용
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
//	//N개의 정점으로 구성된 그래프
//	Graph(unsigned N) : V(N) {}
//	//그래프의 정점 개수 반환
//	auto vertices() const { return V; }
//	//전체 에지 리스트 반환
//	auto& edges() { return edge_list; }
//	//정점 v에서 나가는 모든 에지를 반환
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
//		//에지 양 끝 정점 ID가 유효한지 검사
//		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
//			edge_list.emplace_back(e);
//		else
//			cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
//	}
//
//	//표준 출력 스트림 지원
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
//// 그래프 컬러링에 사용할 색상 번호
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
//	//각 정점의 차수를 <정점 ID, 차수>의 쌍으로 취합
//	for (unsigned i = 1; i < size; i++)
//		degrees.push_back(make_pair(i, G.edges(i).size()));
//
//	//정점의 차수 기준으로 내림차순 정렬
//	sort(degrees.begin(), degrees.end(), [](auto& a, auto& b) {return a.second > b.second; });
//
//	cout << "[색상 지정 순서 (괄호는 차수)]" << endl;
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
//			//이미 색칠이 칠해져 있으면 다음 정점을 검사
//			if (assigned_color[i.first] != 0)
//				continue;
//
//			auto outgoing_edges = G.edges(i.first);
//
//			//i번째 정점과 인접해있는 정점들의 현재 색상
//			set<unsigned> neighbours;
//
//			for (auto& e : outgoing_edges)
//			{
//				neighbours.insert(assigned_color[e.dst]);
//			}
//			//i번째 정점과 인접한 정점이 color_to_be_assigned 색상을 가지고 있지 않다면
//			//i번째 정점에 color_to_be_assigned 색상을 지정
//			if (neighbours.find(color_to_be_assigned) == neighbours.end())
//				assigned_color[i.first] = color_to_be_assigned;
//		}
//
//		color_to_be_assigned++;
//
//		//모든 정점에 색칠이 칠해졌으면 종료
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