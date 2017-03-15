#include"SingleNode.h"

class SingleList : Singlenode
{
public:
	Singlenode *head;
	Singlenode *tail;
	SingleList();
	~SingleList();
	static void deleteList(Singlenode * head);
	static void SortAscend(SingleList&);
	static void reverse(SingleList&);
	static void shuffle(SingleList&);
	static void displayCountedNode(Singlenode*, int);
	static void display(Singlenode*);
};

