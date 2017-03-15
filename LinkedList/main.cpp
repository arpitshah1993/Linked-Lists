#include "SingleList.h"
#include"DoubleList.h"
#include<iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//Creating all test case and its combination with singly and doubly linked list
void create(SingleList &S1single, SingleList &S2single, DoubleList &S1double, DoubleList &S2double)
{
	//creating test case S1 for singly linked list
	S1single = SingleList();
	Singlenode *temp = S1single.head;
	for (int i = 1; i < 101; i++)
	{
		Singlenode* newNode = new Singlenode(i);
		temp->insert_next(newNode);
		temp = temp->next;
	}

	//creating test case S2 for singly linked list
	S2single = SingleList();
	/* initialize random seed */
	srand(time(NULL));
	Singlenode* temp1 = S2single.head;
	for (int i = 1; i < 101; i++)
	{
		Singlenode* newNode = new Singlenode(rand());
		temp1->insert_next(newNode);
		temp1 = temp1->next;
	}

	//creating test case S1 for doubly linked list
	S1double = DoubleList();
	DoubleNode *temp2 = S1double.head;
	for (int i = 1; i < 101; i++)
	{
		DoubleNode* newNode = new DoubleNode(i);
		temp2->insert_next(newNode);
		temp2 = temp2->next;
	}

	//creating test case S2 for doubly linked list
	S2double = DoubleList();
	DoubleNode* temp3 = S2double.head;
	for (int i = 1; i < 101; i++)
	{
		DoubleNode* newNode = new DoubleNode(rand());
		temp3->insert_next(newNode);
		temp3 = temp3->next;
	}
}

int main()
{
	SingleList S1single;
	SingleList S2single;
	DoubleList S1double;
	DoubleList S2double;

	create(S1single, S2single, S1double, S2double);

	//team of four operation
	std::cout << "\n*****Team of four operation*****\n";
	std::cout << "**********************************************\n";
	std::cout << "*****For Input Sequence S1*****\n";
	std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "**** Before the operation *****\n";
	SingleList::display(S1single.head);
	std::cout << "\n***** After the team of four operation *****\n";
	SingleList::SortAscend(S1single);
	SingleList::display(S1single.head);
	SingleList::deleteList(S1single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S1double.head);
	std::cout << "\n***** After the team of four operation *****\n";
	DoubleList::SortAscend(S1double);
	DoubleList::display(S1double.head);
	DoubleList::deleteList(S1double.head);

	std::cout << "\n\n*****For Input Sequence S2*****\n";
	std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	SingleList::display(S2single.head);
	std::cout << "\n***** After the team of four operation *****\n";
	SingleList::SortAscend(S2single);
	SingleList::display(S2single.head);
	SingleList::deleteList(S2single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S2double.head);
	std::cout << "\n***** After the team of four operation *****\n";
	DoubleList::SortAscend(S2double);
	DoubleList::display(S2double.head);
	DoubleList::deleteList(S2double.head);
	std::cout << "\n\n**********************************************\n\n";

	create(S1single, S2single, S1double, S2double);

	//Reverse operation
	std::cout << "\n*****Reverse operation*****\n";
	std::cout << "**********************************************\n";
	std::cout << "*****For Input Sequence S1*****\n";
	std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	SingleList::display(S1single.head);
	std::cout << "\n***** After the Reverse operation *****\n";
	SingleList::reverse(S1single);
	SingleList::display(S1single.head);
	SingleList::deleteList(S1single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S1double.head);
	std::cout << "\n***** After the Reverse operation *****\n";
	DoubleList::reverse(S1double);
	DoubleList::display(S1double.head);
	DoubleList::deleteList(S1double.head);

	std::cout << "\n\n*****For Input Sequence S2*****\n";
std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	SingleList::display(S2single.head);
	std::cout << "\n***** After the Reverse operation *****\n";
	SingleList::reverse(S2single);
	SingleList::display(S2single.head);
	SingleList::deleteList(S2single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S2double.head);
	std::cout << "\n***** After the Reverse operation *****\n";
	DoubleList::reverse(S2double);
	DoubleList::display(S2double.head);
	DoubleList::deleteList(S2double.head);
	std::cout << "\n\n**********************************************\n\n";


	create(S1single, S2single, S1double, S2double);

	//shuffle opertaion
	std::cout << "\n*****Shuffle opertaion*****\n";
	std::cout << "**********************************************\n";
	std::cout << "*****For Input Sequence S1*****\n";
	std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	SingleList::display(S1single.head);
	SingleList::shuffle(S1single);
	std::cout << "\n\n***** After the Shuffle operation *****\n";
	SingleList::display(S1single.head);
	SingleList::deleteList(S1single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S1double.head);
	DoubleList::shuffle(S1double);
	std::cout << "\n\n***** After the Shuffle operation *****\n";
	DoubleList::display(S1double.head);
	DoubleList::deleteList(S1double.head);


	std::cout << "\n\n*****For Input Sequence S2*****\n";
	std::cout << "**********************************************\n";
	std::cout << "\n*****Singly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	SingleList::display(S2single.head);
	SingleList::shuffle(S2single);
	std::cout << "\n\n***** After the Shuffle operation *****\n";
	SingleList::display(S2single.head);
	SingleList::deleteList(S2single.head);
	std::cout << "\n\n*****Doubly Linked List*****\n";
	std::cout << "***** Before the operation *****\n";
	DoubleList::display(S2double.head);
	DoubleList::shuffle(S2double);
	std::cout << "\n\n***** After the Shuffle operation *****\n";
	DoubleList::display(S2double.head);
	DoubleList::deleteList(S2double.head);
	std::cout << "\n\n**********************************************\n\n";

	return 0;
}
