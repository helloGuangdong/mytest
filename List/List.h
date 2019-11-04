#include <iostream>
using namespace std;
#define ListNodePosi ListNode*

struct ListNode 
{
	int data;
	ListNodePosi pred;
	ListNodePosi succ;
};

class List
{
public:
	List()
	{
		init();
	}
	List(ListNodePosi p, int n);
	~List();
	void init();
	void tranverse_print();
	int get_size();
	ListNodePosi get_header();
	ListNodePosi get_trailer();
	ListNodePosi get_anyposi(int n);
	ListNodePosi insertbefore(ListNodePosi p, int e);
	ListNodePosi insertafter(ListNodePosi p, int e);
	void remove(ListNodePosi p);
	void remove(int n);

private:
	int _size;
	ListNodePosi header;
	ListNodePosi trailer;
};
