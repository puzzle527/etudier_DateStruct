#include "stdafx.h"

int main(void)
{
	LinkedList List;

	List.AddNode(3);
	List.AddNode(1);
	List.AddNode(5);
	List.AddNode(4);
	List.AddNode(2);

	List.PrintListValue();

	//List.DeleteNode(5);
	//List.PrintListValue();

	List.Deletetail();
	List.PrintListValue();

	List.Deletehead();
	List.PrintListValue();

	return 0;
}