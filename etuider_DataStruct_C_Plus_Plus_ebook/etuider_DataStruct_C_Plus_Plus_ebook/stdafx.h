#pragma once

#include <iostream>
#include <array>
#include <list>
#include <forward_list>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <random>
#include <chrono>

#include <type_traits>

#include <time.h>

using namespace std;

#include "Lesson1/array.h"
#include "Lesson1/CardGame.h"
#include "Lesson1/cir_list.h" //activity 1
#include "Lesson1/Printer.h" //activity 2
#include "Lesson1/singly_ll.h"
//#include "org_tree.h" //Ʈ�������� ȸ�� ���������
#include "Lesson2/BST_Binary_Search_Tree.h"
#include "Lesson2/DataListMergeUsingHeap.h" //���Ͻý��� ����� activity 4
#include "Lesson2/Graph.h"
#include "Lesson2/AdjacencyList.h"

struct student
{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& s)
{
	return (os << "[" << s.name << s.standard << "]");
}

struct citizen
{
	string name;
	int age;
};

ostream& operator<<(ostream& os, const citizen& c)
{
	return (os << "[" << c.name << c.age << "]");
}