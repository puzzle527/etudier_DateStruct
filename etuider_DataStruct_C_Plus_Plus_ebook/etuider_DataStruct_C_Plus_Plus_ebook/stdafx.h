#pragma once

#include <iostream>
#include <array>
#include <list>
#include <forward_list>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

#include <type_traits>
#include <algorithm>

using namespace std;

#include "array.h"
#include "singly_ll.h"

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