#pragma once
#include <iostream>

using namespace std;

struct Node
{
public:
	int value;
	struct Node *next = nullptr;
};

#include "LinkedList.h"