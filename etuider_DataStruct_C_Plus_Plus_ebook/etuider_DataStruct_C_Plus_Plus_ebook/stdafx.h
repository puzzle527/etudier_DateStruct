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
#include <unordered_map>
#include <unordered_set>

#include <type_traits>

#include <time.h>

using namespace std;

#include "Lesson1/array.h"
#include "Lesson1/CardGame.h"
#include "Lesson1/cir_list.h" //activity 1
#include "Lesson1/Printer.h" //activity 2
#include "Lesson1/singly_ll.h"
//#include "org_tree.h" //트리구조로 회사 구조만들기
#include "Lesson2/BST_Binary_Search_Tree.h"
#include "Lesson2/DataListMergeUsingHeap.h" //파일시스템 만들기 activity 4
#include "Lesson2/Graph.h"
#include "Lesson2/AdjacencyList.h"

#include "Lesson3/Hash_int.h"
#include "Lesson3/ChainingHash.h"
#include "Lesson3/CukooHash.h"
#include "Lesson3/URLMapping.h"
#include "Lesson3/Bloom_Filter.h"
#include "Lesson3/DuplicateCheckEmail.h"

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