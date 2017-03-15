class DoubleNode
{
public:
	int data;
	DoubleNode* next;
	DoubleNode* prev;
	DoubleNode();
	~DoubleNode();
	DoubleNode(int);
	void insert_next(DoubleNode*);
	void remove_next();
	static void swap(DoubleNode*, DoubleNode*);
};
