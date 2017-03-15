class Singlenode
{
public:
	int data;
	Singlenode* next;
	Singlenode();
	~Singlenode();
	Singlenode(int);
	void insert_next(Singlenode*);
	void remove_next();
	static void swap(Singlenode*, Singlenode*, Singlenode*, Singlenode*);
};
