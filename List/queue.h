#include <iostream>
#include "List.h"
using namespace std;

class queue : public List
{
public:
	queue(){List();}
	queue(ListNodePosi p, int n){List(p, n);}
	~queue();
	void enqueue(int e);
	void dequeue();
	int front();
	int back();
	int queue_size();
	bool empty();
};