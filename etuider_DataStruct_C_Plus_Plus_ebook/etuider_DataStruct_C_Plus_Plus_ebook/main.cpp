#include "stdafx.h"

int main(void)
{
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

	return 0;
}