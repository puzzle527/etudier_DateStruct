#include "stdafx.h"

int main(void)
{
	srand(time(NULL));
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

	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);
	
	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);


	return 0;
}