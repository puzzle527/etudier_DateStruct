#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T value;
	struct Node<T> *next = nullptr;
};

#include "LinkedList.h"