#include "SingleNode.h"
#include <iostream>
using namespace std;
	//default constructor
	Singlenode::Singlenode()
	{
	}

	//destructor
	Singlenode::~Singlenode()
	{
	}

	// constructor to initialize node with data.
	Singlenode::Singlenode(int datai = 0)
	{
		data = datai;
		next = NULL;
	}

	//inserting new node after the calling node
	void Singlenode::insert_next(Singlenode* nNode)
	{ 
		nNode->next = next;
		next = nNode;
	}

	//remove the node which is after the calling node
	void Singlenode::remove_next()
	{
		if (next == NULL || next->next==NULL)
		{
			std::cout << "\nNo node exist which can be removed.\n";
			return;
		}
		Singlenode* Temp = next;
		next = (Singlenode*)next->next;
		Temp->next = NULL;
		delete Temp;
	}

	//swap position of two single node using poiners
	//here, node1 and node2 are the nodes which actually get swapped with the help of
	//parentnode2 and parentnode1
	 void Singlenode::swap(Singlenode* parentNode1, Singlenode* node1, Singlenode* node2, Singlenode* parentNode2)
	{
		parentNode1->next = node2;
		parentNode2->next = node1;
		Singlenode Temp(node2->data);
		Temp.next = node2->next;
		node2->next = node1->next;
		node1->next = Temp.next;
	}
