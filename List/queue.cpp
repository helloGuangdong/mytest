#include <iostream>
#include "queue.h"
using namespace std;

queue::~queue()
{
	cout<<"delete queue"<<endl;
}

void queue::enqueue(int e)
{
	insertbefore(get_trailer(), e);
}

void queue::dequeue()
{
	remove(1);
}

int queue::front()
{
	return get_header()->succ->data;
}

int queue::back()
{
	return get_trailer()->pred->data;
}

int queue::queue_size()
{
	return get_size();
}

bool queue::empty()
{
	if (get_size()==0)
	{
		return true;
	}
	else
		return false;
}