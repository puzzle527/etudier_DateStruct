#include "stdafx.h"

int main(void)
{
	srand(time(NULL));
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
	game Cg;
	Cg.buildDeck();
	Cg.dealCards();
	Cg.playGame();
	auto winner = Cg.getWinner();
	cout << winner << "번 플레이어가 이겼습니다!" << endl;

	return 0;
}