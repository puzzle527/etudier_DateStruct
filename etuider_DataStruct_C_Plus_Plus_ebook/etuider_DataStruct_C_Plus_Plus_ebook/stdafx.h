#pragma once

#include <iostream>
#include <sstream>
#include <array>
#include <list>
#include <forward_list>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>

#include <algorithm>
#include <numeric>
#include <cmath>
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

#include "Lesson4/BinarySearch.h"
#include "Lesson4/Vaccine.h"
#include "Lesson4/MergeSort.h"
#include "Lesson4/QuickSort.h"
#include "Lesson4/Partial_QuickSort.h"
#include "Lesson4/Linear_Time_Select.h"
#include "Lesson4/Transform_Accumulate.h"
#include "Lesson4/Mapreduce_Primecheck.h"

#include "Lesson5/Shortest_Job_First.h"
#include "Lesson5/Fractional_Knapsack.h"
#include "Lesson5/Interval_Scheduling_Solution.cpp.h"
#include "Lesson5/Kruskal_Mst.cpp.h"


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