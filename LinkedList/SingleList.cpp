#include <iostream>
#include "SingleList.h"

//constructor who constructs head and tail when list is initialized.
SingleList::SingleList()
{
	head = new Singlenode(0);
	tail = new Singlenode(0);
	head->next = tail;
}


//destructor
SingleList::~SingleList()
{

}

/* Function to delete the entire linked list */
void SingleList::deleteList(Singlenode* head)
{
	/* pass head to get the current node */
	Singlenode* current = head;
	Singlenode* next;

	while (current != NULL)
	{
		next = current->next;
		delete current;
		current = next;
	}

	head = NULL;
}

//sorts singly linked list in ascending order in team of four
void SingleList::SortAscend(SingleList& list)
{
	Singlenode* parentNode1 = list.head;
	Singlenode* node1 = list.head;
	node1 = node1->next;
	Singlenode* parentNode2 = node1;
	//varaible to count sorted node.
	int j = 0;
	while (node1->next != NULL)
	{
		//variable to restrict the comparison of node1 to the other nodes
		// which are not the part of the running team of four sorting
		int i = 3 - j;
		Singlenode* node2 = node1->next;
		while (node2->next != NULL)
		{
			if (node1->data > node2->data)
			{
				swap(parentNode1, node1, node2, parentNode2);
				Singlenode *Temp2 = node2;
				Singlenode *Temp1 = node1;
				node1 = Temp2;
				node2 = Temp1;
			}
			i--;
			if (i == 0)
			{
				break;
			}
			parentNode2 = node2;
			node2 = node2->next;
		}
		j++;
		if (j == 3)
		{	
			//when four node is sorted, its time to move on next team of four.
			j = 0;
			parentNode1 = node2;
			if (parentNode1->next != NULL)
				node1 = parentNode2 = parentNode1->next;
		}
		else
		{
			parentNode1 = node1;
			node1 = node1->next;
			parentNode2 = node1;
		}
	}
}

//reverse singly linked list
void SingleList::reverse(SingleList& list)
{
	Singlenode *previous = list.tail;
	Singlenode *current = list.head->next;
	if (current->next == NULL)
	{
		list.head->next = previous;
		return;
	}
	Singlenode *nextt = current->next;
	while (nextt->next != NULL)
	{
		current->next = previous;
		previous = current;
		current = nextt;
		nextt = nextt->next;
	} 
	current->next = previous;
	list.head->next = current;
}

//shuffle singly linked list
void SingleList::shuffle(SingleList& list)
{
	int i = 0;
	Singlenode *node = list.head->next;
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
	Singlenode* firsthalf = list.head->next;
	Singlenode* secondhalf = firsthalf;
	//iteraing through the linked list till we get the starting  node of second half.
	for (int i = 0; i < k1; i++)
	{
		secondhalf = secondhalf->next;
	}
	std::cout << "\n** first half **\n";
	displayCountedNode(firsthalf, k1);
	std::cout << "\n** second half **\n";
	displayCountedNode(secondhalf, k2);
	//shuffle operation started here which insert nodes from second half to first half
	while (k2 != 0)
	{
		Singlenode *Temp = secondhalf->next;
		firsthalf->insert_next(secondhalf);
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

//display only numbers of nodes from singly linked list mentioned in the nodeCount 
void SingleList::displayCountedNode(Singlenode* node, int nodeCount)
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


//display whole singly linked list
void SingleList::display(Singlenode* node)
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

