#include"DoubleNode.h"

class DoubleList : DoubleNode
{
public:
	DoubleNode *head;
	DoubleNode *tail;
	DoubleList();
	~DoubleList();
	static void deleteList(DoubleNode * head);
	static void reverse(DoubleList&);
	static void shuffle(DoubleList&);
	static void displayCountedNode(DoubleNode*, int);
	static void SortAscend(DoubleList&);
	static void display(DoubleNode*);
};
