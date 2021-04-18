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
#include "cir_list.h" //Lesson 1

#include "CardGame.h" //Lesson 2

#include "Lesson3/Printer.h"

#include "org_tree.h" //트리구조로 회사 구조만들기

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