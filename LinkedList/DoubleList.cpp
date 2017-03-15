#include <iostream>
#include"DoubleList.h"

//constructor who construct doubly linked list with one head and tail
DoubleList::DoubleList()
{
	head = new DoubleNode(0);
	tail = new DoubleNode(0);
	head->next = tail;
	tail->prev = head;
}

//destructor
DoubleList::~DoubleList()
{
	
}
/* Function to delete the entire linked list */
void DoubleList::deleteList(DoubleNode* head)
{
	/* pass head to get the current node */
	DoubleNode* current = head;
	DoubleNode* next;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}
	
	head= NULL;
}

//reverse the doubly linked list
void DoubleList::reverse(DoubleList& list)
{
	DoubleNode *previous = list.tail;
	DoubleNode *current = list.head->next;
	//if there is no node in the list, we are not doing anything.
	if (current->next == NULL)
	{
		return;
	}

	//changing all the pointer of the node while iterating it.
	DoubleNode *nextt = current->next;
	while (nextt->next != NULL)
	{
		current->next = previous;
		current->prev = nextt;
		previous = current;
		current = nextt;
		nextt = nextt->next;
	}

	// to set a pointer of last node which is before tail.
	current->next = previous;
	current->prev = list.head;
	list.tail->prev = list.head->next;
	list.head->next = current;
}

//shuffle the doubly linked list
void DoubleList::shuffle(DoubleList& list)
{
	int i = 0;
	DoubleNode *node = list.head->next;
	while (node->next != NULL)
	{
		i++;
		node = node->next;
	}
	int k1, k2;
	if (i % 2 == 0)
	{
		k1 = k2 = i / 2;
	}
	else
	{
		k2 = i / 2;
		k1 = k2 + 1;
	}
	DoubleNode* firsthalf = list.head->next;
	DoubleNode* secondhalf = firsthalf;

	//iterating through the linked list to get start point of second half
	for (int i = 0; i < k1; i++)
	{
		secondhalf = secondhalf->next;
	}

	//printing both halfs.
	std::cout << "\n** first half **\n";
	displayCountedNode(firsthalf, k1);
	std::cout << "\n** second half **\n";
	displayCountedNode(secondhalf, k2);

	while (k2 != 0)
	{
		DoubleNode *Temp = secondhalf->next;
		firsthalf->insert_next(secondhalf);

		//setting pointer of last node to get proper shuffled linkedlist.
		if (Temp->next == NULL)
		{
			if (i % 2 == 0)
			{
				firsthalf->next->next = Temp;
			}
			else
			{
				firsthalf->next->next->next = Temp;
			}
			break;
		}
		else
		{
			firsthalf = secondhalf->next;
		}
		secondhalf = Temp;
		k2--;
	}
	
}

//display only numbers of node from doubly linked list mentioned in the nodeCount
void DoubleList::displayCountedNode(DoubleNode* node, int nodeCount)
{
	int i = 0;
	while (nodeCount != 0)
	{
		std::cout << node->data;
		std::cout << ", ";
		node = node->next;
		i++;
		if (i % 4 == 0)
			std::cout << "\n";
		nodeCount--;
	}
}

//sort linked list in team of four(bubble sort)
void DoubleList::SortAscend(DoubleList& list)
{
	DoubleNode* node1 = list.head;
	node1 = node1->next;
	//variable to reflect instance when four node(Team of four) is sorted.
	int j = 0;
	while (node1->next != NULL)
	{
		//variable to reflect count of nodes with which we are go compare a single node
		int i = 3 - j;
		DoubleNode* node2 = node1->next;
		while (node2->next != NULL)
		{
			if (node1->data > node2->data)
			{
				swap(node1, node2);
				DoubleNode *Temp2 = node2;
				DoubleNode *Temp1 = node1;
				node1 = Temp2;
				node2 = Temp1;
			}
			i--;
			if (i == 0)
			{
				break;
			}
			node2 = node2->next;
		}
		j++;
		if (j == 3)
		{
			//when one team is sorted(four node), its time to move on next team.
			j = 0;
			if (node2->next != NULL)
			{
				node1 = node2->next;
			}
		}
		else
		{
			node1 = node1->next;
		}
	}
}

//display whole doubly linked list
void DoubleList::display(DoubleNode* node)
{
	//skipping a head
	node = node->next;
	int i = 0;
	while (node->next != NULL)
	{
		std::cout << node->data;
		std::cout << ", ";
		node = node->next;
		i++;
		if (i % 4 == 0)
			std::cout << "\n";
	}
	if (i == 0)
	{
		std::cout << "\nList is empty.\n";
	}
	
}

