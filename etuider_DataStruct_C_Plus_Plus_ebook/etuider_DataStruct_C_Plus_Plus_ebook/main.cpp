#include "stdafx.h"

int main(void)
{
	//srand(time(NULL));
	//dynamic_array main
	/*{
		int nStudents;
		cout << "1�� �л� ���� �Է��ϼ���: ";
		cin >> nStudents;
	
		dynamic_array<student> class1(nStudents);
		for (int i = 0; i < nStudents; i++)
		{
			string name;
			int standard;
			cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���: ";
			cin >> name >> standard;
			class1[i] = student{ name, standard };
		}
	
		//�迭 ũ�⺸�� ū �ε����� �л��� ����
		try
		{
			//�Ʒ� �ּ��� �����ϸ� ���α׷��� ������ �����մϴ�.
			//class1[nStudents] = student {"John", 8} //������ �� ���� ����
			class1.at(nStudents) = student{ "John", 8 }; //���� �߻�
		}
		catch (...)
		{
			cout << "���� �߻�!" << endl;
		}
	
		//���� ����
		auto class2 = class1;
		cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << endl;
	
		//�� �б��� ���ļ� ���ο� ū �б��� ����
		auto class3 = class1 + class2;
		cout << "1�ݰ� 2���� ���� 3�� ����: " << class3.to_string() << endl;
	}*/

	//forword_List
	/*{
		//fwd_list.push_front(0); // �Ǿտ� ���� ����
		//
		//auto it = fwd_list.begin();
		//
		//fwd_list.insert_after(it, 5); //ù��° ���� ������ ���� ����
		//fwd_list.insert_after(it, 6);
		//fwd_list.pop_front(); //�Ǿ� ���� ����
		//fwd_list.erase_after(it); //�Ǿ� ���� ���� ����
		//fwd_list.erase_after(it, fwd_list.end()); //�Ǿ� ���� ���Һ��� ������ ���ұ��� ����

		//fwd_list remove(), remove_if() ��� O(n) �ð����⵵
		forward_list<citizen> citizens = { {"Kim",22}, {"Lee", 25}, {"Park", 18} };

		auto citizen_copy = citizens; //���� ����

		cout << "��ü�ùε�: ";
		for (const auto &c : citizens)
			cout << c << " ";
		cout << endl;

		citizens.remove_if([](const citizen &c)
		{
			//���̰� 19������ ������ ����Ʈ���� ����
			return (c.age < 19);
		});

		cout << "��ǥ���� �ִ� �ùε�: ";
		for (const auto &c : citizens)
			cout << c << " ";
		cout << endl;

		forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };

		//fwd_list sort() �ð����⵵ O(nlogn)
		list1.sort();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//ū������ ����
		list1.sort(greater<int>());
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//reverse() �ð����⵵ O(n)
		list1 = { 2, 53, 1, 0, 4, 10 };
		list1.reverse();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
		//unique ���������� ���Ұ� ���� ������ �ϳ��� ����, ���� �� ����ؾ� ������ ���Ұ� ���Ե�.
		list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
		list1.sort();
		list1.unique();
		for (const auto &c : list1)
			cout << c << " ";
		cout << endl;
	}*/

	//STL iterator(�ݺ���) �̿� vector / forward_list ��
	/*{
		vector<string> vec = { "Lewis Hamilton", "Lewis Hamilton", "Nico Rose berg", "Sebastian Vettel", "Lewis Hamilton",
							 "Sebastian Vettel",  "Sebastian Vettel",  "Sebastian Vettel", "Fernando Alonso" };

		auto it = vec.begin(); //����ð�
		cout << "���� �ֱ� �����: " << *it << endl;

		it += 8; //����ð�

		cout << "8�� �� �����: " << *it << endl;

		advance(it, -3);
		cout << "���� 3�� �� �����: " << *it << endl;

		forward_list<string> fwd(vec.begin(), vec.end());

		auto it1 = fwd.begin();
		cout << "���� �ֱ� �����: " << *it1 << endl;

		advance(it1, 5); //�����ð�
		cout << "5�� �� �����: " << *it1 << endl;

		//forward_list�� ������ �̵��� ����
		//���� �ڵ� -> advance(it1, -2);
	}*/

	//�������Ḯ��Ʈ�� ���� �÷��̸���Ʈ;
	/*playlist pl;

	pl.insert(1);
	pl.insert(2);
	cout << "��� ��� : ";
	pl.loopOnce();

	playlist pl2 = pl;
	pl2.erase(2);
	pl2.insert(3);
	cout << "�ι�° ��� ��� : ";
	pl2.loopOnce();*/
	
	//STL ����� ���Ḯ��Ʈ �̿�
	/*list<int> list1 = { 1,2,3,4,5 };
	list1.push_back(6); //1,2,3,4,5,6 //�ǵڿ� �߰�
	list1.insert(next(list1.begin()), 0); //1,0,2,3,4,5,6 //ù��° ������ 0�߰�
	list1.insert(list1.end(), 7); //1,0,2,3,4,5,6,7 //�������� 7�߰�
	list1.pop_back(); //1,0,2,3,4,5,6 //����������

	cout << "���� & ���� �� ����Ʈ: ";
	for (auto i : list1)
		cout << i << " ";
	cout << endl;

	list<int>::reverse_iterator iter; //������ �ݺ���

	list<int> lst = { 1,2,3,4,5 };

	//list�� �ݺ��ڴ� ����, ���� ���ۿ��� �ݺ��ڰ� ��ȿȭ ���� �ʴ´�.
	//vector�� ��ȿȭ��
	auto l_it4 = next(lst.begin(), 4);
	cout << *l_it4 << endl;

	lst.insert(next(lst.begin(), 2), 0);
	for (auto i : lst)
		cout << i << " ";
	cout << endl;
	cout << *l_it4 << endl;*/

	//�ǽ�����2 : ī����� �ùķ��̼�
	/*game Cg;
	Cg.buildDeck();
	Cg.dealCards();
	Cg.playGame();
	auto winner = Cg.getWinner();
	cout << winner << "�� �÷��̾ �̰���ϴ�!" << endl;*/

	//deque
	/*deque<int> deq = { 1,2,3,4,5 };

	deq.push_front(0);//�� �տ� 0�߰�;
	deq.push_back(6);//�� �ڿ� 6�߰�;
	deq.insert(deq.begin() + 2, 10);//�� �տ��� 2ĭ �ڿ� 10�߰�
	deq.pop_back();
	deq.pop_front();
	deq.erase(deq.begin() + 1); //�� �տ��� 1ĭ �� ����
	deq.erase(deq.begin() + 3, deq.end()); //�� �տ��� 3ĭ �ں��� ���������� ����*/

	//stack -> ��� ������ �ð����⵵ O(1), LIFO Last In First Out
	//�����̳� ��� stack, queue, priority_queue -> deque�� ������� �����Ǿ� ����.
	//deque�� �ƴ� list, vector�� �⺻ �����ڷ� ������� �Ѵٸ�
	//stack<int, vector<int>> stk; stack<int, list<int>> skt; ������ �����ϸ� ��.
	
	//queue FIFO First In First Out �Ʒ� �Լ����� �ð����⵵ O(1)
	/*queue<int> q;
	q.push(1); //�� �ڿ� 1 �߰�
	q.push(2); //�� �ڿ� 2 �߰�
	q.push(3); //�� �ڿ� 3 �߰� {1, 2, 3};
	q.pop(); //�� �� ���� ���� {2, 3};
	q.push(4); //�� �ڿ� 4�� �߰�{2, 3, 4};*/

	//priority_queue heap�̶�� �θ��� ����;
	//heap�� �����̳ʿ��� ���� ����(�Ǵ� ���� ū) ���ҿ� ������ ������ �� �ִ� �ڷ� ����
	//�ּ�/�ִ� ���ҿ� �����ϴ� ������ O(1)�� �ð����⵵�� ����;
	//���� ������ O(log n)�� �ð����⵵�� ����
	//�������Ŵ� �ּ�/�ִ� ���ҿ� ���ؼ��� ����
	//stack, queue�� �޸� �⺻���� ����� �����̳ʰ� vector
	//�⺻������ �ִ� ������ ���� ���� std::less

	//stack, queue, priority_queue -> ��� ���Ҹ� ��ȸ�ϴ� �۾��� �ʿ�����Ƿ� STL �ݺ��� ���� X

	//Lesson3
	/*Printer<5> printer;

	Job j1("����", 10);
	Job j2("����", 4);
	Job j3("����", 5);
	Job j4("����", 7);
	Job j5("ä��", 8);
	Job j6("�ÿ�", 10);
	
	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6); //�����⿭�� ���� ���־ �߰��� �� ����
	printer.startPrinting();

	printer.addNewJob(j6); //���� ��⿭�� ������Ƿ� �߰� ����
	printer.startPrinting();*/

	//���� ����
	//tree(Ʈ��):���� ������ ����
	//node : �����Ͱ� ����� �κ�, edge : ���� ��� ���̸� �մ� ��
	//Ʈ���� �߽��� �Ǵ� ��� : root node (���� �� ��)
	//auto tree = org_tree::create_org_structure("CEO");
	//
	//tree.addSubordinate("CEO", "�λ���");
	//tree.addSubordinate("�λ���", "����Ƽ����");
	//tree.addSubordinate("�λ���", "�����ú���");
	//tree.addSubordinate("����Ƽ����", "��������");
	//tree.addSubordinate("����Ƽ����", "�۰�������");
	//tree.addSubordinate("�����ú���", "��������");
	//tree.addSubordinate("�����ú���", "ȫ������");
	//tree.addSubordinate("�λ���", "�繫����");
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

	//cout << "���� ��ȸ: ";
	//tree.inorder(); //BST�� ��� ���Ҹ� ������������ ����մϴ�.
	//cout << endl;
	//tree.deleteValue(12);
	//cout << "12�� ������ �� ���� ��ȸ: ";
	//tree.inorder(); //BST�� ��� ���Ҹ� ������������ ����մϴ�.
	//cout << endl;

	//if (tree.find(12))
	//	cout << "���� 12�� Ʈ���� �ֽ��ϴ�." << endl;
	//else
	//{
	//	cout << "���� 12�� Ʈ���� �����ϴ�." << endl;
	//}

	//���Ͻý��۸����
	//file_system fs;

	//���� �̿��� ������ ����Ʈ ���� activity 05
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

	//�׷��� �����
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
	//		cout << "�ؽÿ��� " << value << " ã��";
	//	else
	//		cout << "�ؽÿ��� " << value << " ��ã��";
	//	cout << endl;
	//};
	//
	//map.insert(2);
	//map.insert(25);
	//map.insert(10);
	//print(25);
	//
	//map.insert(100);
	//2�� ����� �浹
	//print(100);
	//2 ã�� �� ����
	//print(2);
	//
	//map.erase(25);
	 
	//Exercise14
	//hash_map map(7);
	//
	//auto print = [&](int value) {
	//	if (map.find(value))
	//		std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�ҽ��ϴ�.";
	//	else
	//		std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�� ���߽��ϴ�.";
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
	//map.insert(14); // ����Ŭ �߻�!

	//Activity06
	/*URLService service;

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang"))
	{
		std::cout << "https://py_dojang ���" << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang ��� ����" << std::endl;
	}

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN001484", "https://c_dojang"))
	{
		std::cout << "https://c_dojang ���" << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang ��� ����" << std::endl;
	}

	if (service.registerURL("https://www.gilbut.co.kr/book/view?bookcode=BN002402", "https://opencv4"))
	{
		std::cout << "https://opencv4 ���" << std::endl;
	}
	else
	{
		std::cout << "https://opencv4 ��� ����" << std::endl;
	}

	auto pythonBook = service.lookup("https://py_dojang");
	if (pythonBook.first)
	{
		std::cout << "https://py_dojang ���� URL: " << pythonBook.second << std::endl;
	}
	else
	{
		std::cout << "https://py_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
	}

	auto cppBook = service.lookup("https://cpp_dojang");
	if (cppBook.first)
	{
		std::cout << "https://cpp_dojang ���� URL: " << cppBook.second << std::endl;
	}
	else
	{
		std::cout << "https://cpp_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
	}

	if (service.deregisterURL("https://c_dojang"))
	{
		std::cout << "c_dojang å URL ��� ����" << std::endl;
	}
	else
	{
		std::cout << "c_dojang å URL ��� ���� ����" << std::endl;
	}

	auto findQtBook = service.lookup("https://c_dojang");
	if (findQtBook.first)
	{
		std::cout << "https://c_dojang ���� URL: " << findQtBook.second << std::endl;
	}
	else
	{
		std::cout << "https://c_dojang ���� URL�� ã�� �� �����ϴ�." << std::endl;
	}

	std::cout << "��ϵ� URL ����Ʈ:" << std::endl;
	service.printURLs();*/

	//Activity 8
	// ������ �л� ���� ����
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
	//std::cout << "[ó�� �� ó�� �ð� & ��� �ð�]" << std::endl;
	//compute_and_print_waiting_times<int>(service_times);
	//
	//// �� ó�� �ð��� ������������ ����
	//std::sort(service_times.begin(), service_times.end());
	//
	//std::cout << std::endl;
	//std::cout << "[���� �� �� ó�� �ð� & ��� �ð�]" << std::endl;
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
	//// ����� �� �ִ� ���� ���� ���
	//std::cout << "[����� �� �ִ� ���� ����]" << std::endl;
	//for (auto& o : objects)
	//std::cout << o << std::endl;
	//std::cout << std::endl;
	//
	//// ���Ұ��� �賶 ���� �˰��� ����, �賶�� �ִ� ��� ���Դ� 7�� ����.
	//int knapsack_capacity = 7;
	//auto solution = fill_knapsack(objects, knapsack_capacity);
	//
	//// �賶�� ���� ���� ���� ���
	//std::cout << "[�賶�� ���� ���ǵ� (�ִ� �뷮 = " << knapsack_capacity << ")]" << std::endl;
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

	// �׷��� ��ü ����
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
	//cout << "[�Է� �׷���]" << endl;
	//cout << G << endl;
	//
	//Graph<T> MST = minimum_spanning_tree(G);
	//cout << "[�ּ� ���� Ʈ��]" << endl;
	//cout << MST;

	return 0;
}