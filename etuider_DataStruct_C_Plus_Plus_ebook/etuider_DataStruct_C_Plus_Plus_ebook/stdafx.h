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

#include "array.h"
#include "singly_ll.h"
#include "cir_list.h" //activity 1
#include "CardGame.h" //activity 2
#include "Lesson3/Printer.h"
//#include "org_tree.h" //트리구조로 회사 구조만들기
#include "BST_Binary_Search_Tree.h"
#include "N_arr_tree.h" //파일시스템 만들기 activity 4

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