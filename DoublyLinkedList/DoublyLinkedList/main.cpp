#include <iostream>
#include "DoublelinkedList.h"

using namespace std;

int main(void)
{
	DoubleLinkedList List;

	List.Addtail(5);
	List.Addtail(4);
	List.Addtail(3);
	List.Addtail(2);

	List.PrintList();

	return 0;
}