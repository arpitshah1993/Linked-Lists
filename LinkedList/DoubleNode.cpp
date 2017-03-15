#include "DoubleNode.h"
#include <iostream>

//default constructor
DoubleNode::DoubleNode() 
{
data=0;
next=NULL;
prev=NULL;
}

//data constructor
DoubleNode::DoubleNode(int datai = 0)
{
data=datai;
next=NULL;
prev=NULL;
}

//destructor
DoubleNode::~DoubleNode() 
{
}

//inserting new node after the calling node
void DoubleNode::insert_next(DoubleNode* newNode)
{
	newNode->next = this->next;
	this->next = newNode;
	newNode->prev = this;
	newNode->next->prev = newNode;
}

//remove the node which is after the calling node
void DoubleNode::remove_next()
{
	if (next == NULL || next->next == NULL)
	{
		std::cout << "\nNo node exist which can be removed.\n";
		return;
	}
	DoubleNode* Temp = this->next;
	next = Temp->next;
	Temp->next->prev = this;
	Temp->next = NULL;
	Temp->prev = NULL;
	delete Temp;
}

//swap position of two double node using poiners
void DoubleNode::swap(DoubleNode* node1, DoubleNode* node2)
{
	DoubleNode Temp(node2->data);
	Temp.next = node2->next;
	Temp.prev = node2->prev;
	node2->next->prev = node1;

	if (node2->prev != node1)
	{
		node2->next = node1->next;
		node2->prev->next = node1;
	}
	else
	{
		node2->next = node1;
	}
	node2->prev = node1->prev;
	if (node1->next != node2)
	{
		node1->next->prev = node2;
	}
	node1->prev->next = node2;
	if (node1->next != node2)
	{
		node1->next->prev = node2;
		node1->prev = Temp.prev;
	}
	else
	{
		node1->prev = node2;
	}
	node1->next = Temp.next;
}



