#include "stdafx.h"

int main(void)
{
	//srand(time(NULL));
	//dynamic_array main
	/*{
		int nStudents;
		cout << "1반 학생 수를 입력하세요: ";
		cin >> nStudents;
	
		dynamic_array<student> class1(nStudents);
		for (int i = 0; i < nStudents; i++)
		{
			string name;
			int standard;
			cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
			cin >> name >> standard;
			class1[i] = student{ name, standard };
		}
	
		//배열 크기보다 큰 인덱스의 학생에 접근
		try
		{
			//아래 주석을 해제하면 프로그램이 비정상 종료합니다.
			//class1[nStudents] = student {"John", 8} //예상할 수 없는 동작
			class1.at(nStudents) = student{ "John", 8 }; //예외 발생
		}
		catch (...)
		{
			cout << "예외 발생!" << endl;
		}
	
		//깊은 복사
		auto class2 = class1;
		cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;
	
		//두 학급을 합쳐서 새로운 큰 학급을 생성
		auto class3 = class1 + class2;
		cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << endl;
	}*/

	//forword_List
	/*{
		//fwd_list.push_front(0); // 맨앞에 원소 삽입
		//
		//auto it = fwd_list.begin();
		//
		//fwd_list.insert_after(it, 5); //첫번째 원소 다음에 원소 삽입
		//fwd_list.insert_after(it, 6);
		//fwd_list.pop_front(); //맨앞 원소 삭제
		//fwd_list.erase_after(it); //맨앞 다음 원소 삭제
		//fwd_list.erase_after(it, fwd_list.end()); //맨앞 다음 원소부터 마지막 원소까지 삭제

		//fwd_list remove(), remove_if() 사용 O(n) 시간복잡도
		forward_list<citizen> citizens = { {"Kim",22}, {"Lee", 25}, {"Park", 18} };

		auto citizen_copy = citizens; //깊은 복사

		cout << "전체시민들: ";
		for (const auto &c : citizens)
			cout << c << " ";
		cout << endl;

		citizens.remove_if([](const citizen &c)
		{
			//나이가 19세보다 작으면 리스트에서 제거
			return (c.age < 19);
		});

		cout << "투표권이 있는 시민들: ";
		for (const auto &c : citizens)
			cout << c << " ";
		cout << endl;

		forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };

		//fwd_list sort() 시간복잡도 O(nlogn)
		list1.sort();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//큰수부터 정렬
		list1.sort(greater<int>());
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//reverse() 시간복잡도 O(n)
		list1 = { 2, 53, 1, 0, 4, 10 };
		list1.reverse();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//unique 서로인접한 원소값 비교후 같으면 하나만 남김, 정렬 후 사용해야 유일한 원소가 남게됨.
		list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
		list1.sort();
		list1.unique();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
	}*/

	//STL iterator(반복자) 이용 vector / forward_list 비교
	/*{
		vector<string> vec = { "Lewis Hamilton", "Lewis Hamilton", "Nico Rose berg", "Sebastian Vettel", "Lewis Hamilton",
							 "Sebastian Vettel",  "Sebastian Vettel",  "Sebastian Vettel", "Fernando Alonso" };

		auto it = vec.begin(); //상수시간
		cout << "가장 최근 우승자: " << *it << endl;

		it += 8; //상수시간

		cout << "8년 전 우승자: " << *it << endl;

		advance(it, -3);
		cout << "그후 3년 뒤 우승자: " << *it << endl;

		forward_list<string> fwd(vec.begin(), vec.end());

		auto it1 = fwd.begin();
		cout << "가장 최근 우승자: " << *it1 << endl;

		advance(it1, 5); //선형시간
		cout << "5년 전 우승자: " << *it1 << endl;

		//forward_list는 순방향 이동만 가능
		//에러 코드 -> advance(it1, -2);
	}*/

	//원형연결리스트로 만든 플레이리스트;
	/*playlist pl;

	pl.insert(1);
	pl.insert(2);
	cout << "재생 목록 : ";
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(2);
	pl2.insert(3);
	cout << "두번째 재생 목록 : ";
	pl2.loopOnce();*/
	
	//STL 양방향 연결리스트 이용
	/*list<int> list1 = { 1,2,3,4,5 };
	list1.push_back(6); //1,2,3,4,5,6 //맨뒤에 추가
	list1.insert(next(list1.begin()), 0); //1,0,2,3,4,5,6 //첫번째 다음에 0추가
	list1.insert(list1.end(), 7); //1,0,2,3,4,5,6,7 //마지막에 7추가
	list1.pop_back(); //1,0,2,3,4,5,6 //마지막빼기

	cout << "삽입 & 삭제 후 리스트: ";
	for (auto i : list1)
		cout << i << " ";
	cout << endl;

	list<int>::reverse_iterator iter; //역방향 반복자

	list<int> lst = { 1,2,3,4,5 };

	//list의 반복자는 삽입, 삭제 동작에서 반복자가 무효화 되지 않는다.
	//vector는 무효화됨
	auto l_it4 = next(lst.begin(), 4);
	cout << *l_it4 << endl;

	lst.insert(next(lst.begin(), 2), 0);
	for (auto i : lst)
		cout << i << " ";
	cout << endl;
	cout << *l_it4 << endl;*/

	//실습문제2 : 카드게임 시뮬레이션
	/*game Cg;
	Cg.buildDeck();
	Cg.dealCards();
	Cg.playGame();
	auto winner = Cg.getWinner();
	cout << winner << "번 플레이어가 이겼습니다!" << endl;*/

	//deque
	/*deque<int> deq = { 1,2,3,4,5 };

	deq.push_front(0);//맨 앞에 0추가;
	deq.push_back(6);//맨 뒤에 6추가;
	deq.insert(deq.begin() + 2, 10);//맨 앞에서 2칸 뒤에 10추가
	deq.pop_back();
	deq.pop_front();
	deq.erase(deq.begin() + 1); //맨 앞에서 1칸 뒤 삭제
	deq.erase(deq.begin() + 3, deq.end()); //맨 앞에서 3칸 뒤부터 마지막까지 삭제*/

	//stack -> 모든 연산의 시간복잡도 O(1), LIFO Last In First Out
	//컨테이너 어뎁터 stack, queue, priority_queue -> deque의 기반으로 구현되어 있음.
	//deque이 아닌 list, vector를 기본 생성자로 만들고자 한다면
	//stack<int, vector<int>> stk; stack<int, list<int>> skt; 등으로 선언하면 됨.
	
	//queue FIFO First In First Out 아래 함수들의 시간복잡도 O(1)
	/*queue<int> q;
	q.push(1); //맨 뒤에 1 추가
	q.push(2); //맨 뒤에 2 추가
	q.push(3); //맨 뒤에 3 추가 {1, 2, 3};
	q.pop(); //맨 앞 원소 제거 {2, 3};
	q.push(4); //맨 뒤에 4를 추가{2, 3, 4};*/

	//priority_queue heap이라고 부르는 구조;
	//heap은 컨테이너에서 가장 작은(또는 가장 큰) 원소에 빠르게 접근할 수 있는 자료 구조
	//최소/최대 원소에 접근하는 동작은 O(1)의 시간복잡도를 가짐;
	//원소 삽입은 O(log n)의 시간복잡도로 동작
	//원소제거는 최소/최대 원소에 대해서만 가능
	//stack, queue와 달리 기본적인 어댑터 컨테이너가 vector
	//기본적으로 최대 힙으로 생성 비교자 std::less

	//stack, queue, priority_queue -> 모든 원소를 순회하는 작업이 필요없으므로 STL 반복자 지원 X

	//Lesson3
	/*Printer<5> printer;

	Job j1("광희", 10);
	Job j2("정다", 4);
	Job j3("현수", 5);
	Job j4("유미", 7);
	Job j5("채원", 8);
	Job j6("시원", 10);
	
	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6); //현재대기열이 가득 차있어서 추가할 수 없음
	printer.startPrinting();

	printer.addNewJob(j6); //현재 대기열이 비었으므로 추가 가능
	printer.startPrinting();*/

	//비선형 구조
	//tree(트리):상하 반전된 형태
	//node : 데이터가 저장된 부분, edge : 노드와 노드 사이를 잇는 선
	//트리의 중심이 되는 노드 : root node (가장 맨 위)
	//auto tree = org_tree::create_org_structure("CEO");
	//
	//tree.addSubordinate("CEO", "부사장");
	//tree.addSubordinate("부사장", "아이티부장");
	//tree.addSubordinate("부사장", "마케팅부장");
	//tree.addSubordinate("아이티부장", "보안팀장");
	//tree.addSubordinate("아이티부장", "앱개발팀장");
	//tree.addSubordinate("마케팅부장", "물류팀장");
	//tree.addSubordinate("마케팅부장", "홍보팀장");
	//tree.addSubordinate("부사장", "재무부장");
	//
	//cout << endl;
	//
	//tree.preOrder(tree.root);
	//tree.inOrder(tree.root);
	//tree.postOrder(tree.root);
	//tree.levelOrder(tree.root);
	
	//BST
	//bst tree;
	//tree.insert(12);
	//tree.insert(10);
	//tree.insert(20);
	//tree.insert(8);
	//tree.insert(11);
	//tree.insert(15);
	//tree.insert(28);
	//tree.insert(4);
	//tree.insert(2);

	//cout << "중위 순회: ";
	//tree.inorder(); //BST의 모든 원소를 오름차순으로 출력합니다.
	//cout << endl;
	//tree.deleteValue(12);
	//cout << "12를 삭제한 후 중위 순회: ";
	//tree.inorder(); //BST의 모든 원소를 오름차순으로 출력합니다.
	//cout << endl;

	//if (tree.find(12))
	//	cout << "원소 12는 트리에 있습니다." << endl;
	//else
	//{
	//	cout << "원소 12는 트리에 없습니다." << endl;
	//}

	//파일시스템만들기
	//file_system fs;

	//힙을 이용한 데이터 리스트 병합 activity 05
	//vector<int> v1 = { 1, 3, 8, 15, 105 };
	//vector<int> v2 = { 2, 3, 10, 11, 16, 20, 25 };
	//vector<int> v3 = { -2, 100, 1000 };
	//vector<int> v4 = { -1, 0, 14, 18 };
	//
	//auto result = merge({ v1, v2, v3, v4 });
	//
	//for (auto i : result)
	//cout << i << ' ';
	//cout << endl;

	//그래프 만들기
	//graph g(6);
	//g.addEdge(city::LONDON, city::MOSCOW, 2500);
	//g.addEdge(city::LONDON, city::SEOUL, 9000);
	//g.addEdge(city::LONDON, city::DUBAI, 5500);
	//g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	//g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	//g.addEdge(city::SEOUL, city::DUBAI, 7000);
	//g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	//g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	//g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	//g.addEdge(city::DUBAI, city::SYDNEY, 1200);
	//
	//g.addEdge(city::SEATTLE, city::LONDON, 8000);
	//g.removeEdge(city::SEATTLE, city::LONDON);
	
	//activity 12
	//graph g(6);
	//g.addEdge(city::LONDON, city::MOSCOW, 2500);
	//g.addEdge(city::LONDON, city::SEOUL, 9000);
	//g.addEdge(city::LONDON, city::DUBAI, 5500);
	//g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	//g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	//g.addEdge(city::SEOUL, city::DUBAI, 7000);
	//g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	//g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	//g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	//g.addEdge(city::DUBAI, city::SYDNEY, 1200);
	//
	//g.addEdge(city::SEATTLE, city::LONDON, 8000);
	//g.removeEdge(city::SEATTLE, city::LONDON);

	//Exercise13
	//hash_map map(7);
	//auto print = [&](int value)
	//{
	//	if (map.find(value))
	//		cout << "해시에서 " << value << " 찾음";
	//	else
	//		cout << "해시에서 " << value << " 못찾음";
	//	cout << endl;
	//};
	//
	//map.insert(2);
	//map.insert(25);
	//map.insert(10);
	//print(25);
	//
	//map.insert(100);
	//2가 사라짐 충돌
	//print(100);
	//2 찾을 수 없음
	//print(2);
	//
	//map.erase(25);
	 
	//Exercise14
	//hash_map map(7);
	//
	//auto print = [&](int value) {
	//	if (map.find(value))
	//		std::cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
	//	else
	//		std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
	//	std::cout << std::endl;
	//};
	//
	//map.insert(2);
	//map.insert(25);
	//map.insert(10);
	//
	//map.insert(100);
	//map.insert(55);
	//
	//print(100);
	//print(2);
	//
	//map.erase(2);

	//Exercise15
	//hash_map map(7);
	//map.print();
	//std::cout << std::endl;
	//
	//map.insert(10);
	//map.insert(20);
	//map.insert(30);
	//std::cout << std::endl;
	//
	//map.insert(104);
	//map.insert(2);
	//map.insert(70);
	//map.insert(9);
	//map.insert(90);
	//map.insert(2);
	//map.insert(7);
	//std::cout << std::endl;
	//
	//map.print();
	//std::cout << std::endl;
	//
	//map.insert(14); // 사이클 발생!

	//Activity06
	/*URLService service;

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang"))
	{
		std::cout << "https://py_dojang 등록" << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang 등록 실패" << std::endl;
	}

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN001484", "https://c_dojang"))
	{
		std::cout << "https://c_dojang 등록" << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang 등록 실패" << std::endl;
	}

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002402", "https://opencv4"))
	{
		std::cout << "https://opencv4 등록" << std::endl;
	}
	else
	{
		std::cout << "https://opencv4 등록 실패" << std::endl;
	}

	auto pythonBook = service.lookup("https://py_dojang");
	if (pythonBook.first)
	{
		std::cout << "https://py_dojang 원본 URL: " << pythonBook.second << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	auto cppBook = service.lookup("https://cpp_dojang");
	if (cppBook.first)
	{
		std::cout << "https://cpp_dojang 원본 URL: " << cppBook.second << std::endl;
	}
	else
	{
		std::cout << "https://cpp_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	if (service.deregisterURL("https://c_dojang"))
	{
		std::cout << "c_dojang 책 URL 등록 해제" << std::endl;
	}
	else
	{
		std::cout << "c_dojang 책 URL 등록 해제 실패" << std::endl;
	}

	auto findQtBook = service.lookup("https://c_dojang");
	if (findQtBook.first)
	{
		std::cout << "https://c_dojang 원본 URL: " << findQtBook.second << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
	}

	std::cout << "등록된 URL 리스트:" << std::endl;
	service.printURLs();*/

	//Activity 8
	// 임의의 학생 정보 생성
	//auto p = generate_random_Student(1000);
	//
	//search_test(1000, p);
	//search_test(10000, p);
	//search_test(100000, p);

	//Exercise17
	//bloom_filter bf(7);
	//bf.insert(100);
	//bf.insert(54);
	//bf.insert(82);
	//
	//bf.lookup(5);
	//bf.lookup(50);
	//bf.lookup(20);
	//bf.lookup(54);

	//Activity07
	//BloomFilter bloom(128, 5);
	//
	//bloom.add("abc@gilbut.com");
	//bloom.add("xyz@gilbut.com");
	//
	//bloom.mayContain("abc");
	//bloom.mayContain("xyz@gilbut.com");
	//bloom.mayContain("xyz");
	//
	//bloom.add("abcd@gilbut.com");
	//bloom.add("ab@gilbut.com");
	//
	//bloom.mayContain("abcd");
	//bloom.mayContain("ab@gilbut.com");

	//run_small_search_test();
	//
	//run_large_search_test(100000, 36543);
	//run_large_search_test(1000000, 36543);
	//run_large_search_test(10000000, 36543);

	//Exercise19
	//run_merge_sort_test();

	//Exercise20
	//run_quick_sort_test();

	//Activity09
	//test_partial_quicksort<unsigned>(100, 10);

	//Exercise21
	//run_linear_select_test();

	//binary_search()
	//vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	//reduce()

	//Exercise22
	//vector<int> S{ 1,10,4,7,3,5,6,9,8,2 };
	//
	//transform_test(S);
	//reduce_test(S);
	 
	//Exercise25
	//std::vector<int> service_times{ 8, 1, 2, 4, 9, 2, 3, 5 };
	//
	//std::cout << "[처음 일 처리 시간 & 대기 시간]" << std::endl;
	//compute_and_print_waiting_times<int>(service_times);
	//
	//// 일 처리 시간을 오름차순으로 정렬
	//std::sort(service_times.begin(), service_times.end());
	//
	//std::cout << std::endl;
	//std::cout << "[정렬 후 일 처리 시간 & 대기 시간]" << std::endl;
	//compute_and_print_waiting_times<int>(service_times);
	// 
	//Exercise26
	//std::vector<Object> objects;
	//objects.reserve(7);
	//
	//std::vector<int> weights{ 1, 2, 5, 9, 2, 3, 4 };
	//std::vector<double> values{ 10, 7, 15, 10, 12, 11, 5 };
	//for (auto i = 0; i < 7; i++)
	//{
	//	objects.push_back(Object(i + 1, weights[i], values[i]));
	//}
	//
	//// 사용할 수 있는 물건 정보 출력
	//std::cout << "[사용할 수 있는 물건 정보]" << std::endl;
	//for (auto& o : objects)
	//std::cout << o << std::endl;
	//std::cout << std::endl;
	//
	//// 분할가능 배낭 문제 알고리즘 실행, 배낭의 최대 허용 무게는 7로 지정.
	//int knapsack_capacity = 7;
	//auto solution = fill_knapsack(objects, knapsack_capacity);
	//
	//// 배낭에 넣을 물건 정보 출력
	//std::cout << "[배낭에 넣을 물건들 (최대 용량 = " << knapsack_capacity << ")]" << std::endl;
	//for (auto& o : solution)
	//std::cout << o << std::endl;
	//std::cout << std::endl;

	//activity 11
	//list<Work> list;
	//list.push_back(Work(1, 5, 9));
	//list.push_back(Work(2, 6, 20));
	//list.push_back(Work(3, 16, 19));
	//list.push_back(Work(4, 7, 10));
	//list.push_back(Work(5, 9, 19));
	//list.push_back(Work(6, 10, 19));
	//list.push_back(Work(7, 6, 12));
	//list.push_back(Work(8, 2, 17));
	//list.push_back(Work(9, 10, 13));
	//list.push_back(Work(10, 4, 7));
	//for (auto& i : list)
	//	cout << i << endl;
	////cout << *list.begin() << endl;
	////list.remove(Work(1, 5, 9));
	////cout << *list.begin() << endl;
	//
	//vector<Work> vlist;
	//scheduling(vlist, list);
	//for (auto& i : vlist)
	//	cout << i << endl;

	//Exercise26
	using T = unsigned;

	// 그래프 객체 생성
	//Graph<T> G(9);
	//
	//map<unsigned, vector<pair<unsigned, T>>> edge_map;
	//edge_map[1] = { {2, 2}, {5, 3} };
	//edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
	//edge_map[3] = { {4, 2}, {7, 3} };
	//edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
	//edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
	//edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
	//edge_map[7] = { {3, 3}, {6, 4} };
	//edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };
	//
	//for (auto& i : edge_map)
	//for (auto& j : i.second)
	//G.add_edge(Edge<T>{ i.first, j.first, j.second });
	//
	//cout << "[입력 그래프]" << endl;
	//cout << G << endl;
	//
	//Graph<T> MST = minimum_spanning_tree(G);
	//cout << "[최소 신장 트리]" << endl;
	//cout << MST;

	return 0;
}