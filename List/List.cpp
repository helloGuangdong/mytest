#include <iostream>
#include "List.h"
using namespace std;


List::List(ListNodePosi p, int n)
{
	cout<<"List(ListNodePosi p, int n)....."<<endl;
}

void List::init()
{
	header = new ListNode;
	trailer = new ListNode;

	header->pred = NULL;
	header->succ = trailer;
	trailer->pred = header;
	trailer->succ = NULL;

	_size = 0;
}

List::~List()
{
	cout<<"delete"<<endl;
}

void List::tranverse_print()
{
	ListNodePosi p = header->succ;
	while (p != trailer)
	{
		cout<<"Node: "<<p->data<<endl;
		p = p->succ;
	}
	cout<<"The size is "<<get_size()<<endl;
}

int List::get_size()
{
	return _size;
}

ListNodePosi List::insertafter(ListNodePosi p, int e)
{
	while (p!=NULL && p!=trailer)
	{
		ListNodePosi tamp = new ListNode;
		tamp->data = e;
		
		tamp->pred = p;
		tamp->succ = p->succ;
		p->succ->pred = tamp;
		p->succ = tamp;
		
		_size++;
		return tamp;
	}
	return NULL;
}

ListNodePosi List::insertbefore(ListNodePosi p, int e)
{
	while (p!=NULL && p!=header)
	{
		ListNodePosi tamp = new ListNode;
		tamp->data = e;
		
		tamp->pred = p->pred;
		tamp->succ = p;
		p->pred->succ = tamp;
		p->pred = tamp;
		
		_size++;
		return tamp;
	}
	return NULL;
}

ListNodePosi List::get_header()
{
	return header;
}

ListNodePosi List::get_trailer()
{
	return trailer;
}

ListNodePosi List::get_anyposi(int n)
{
	if (n>_size)
	{
		cout<<"error: n>_size"<<endl;
		return NULL;
	}
	ListNodePosi p = header;
	for ( ; n>0; n--)
	{
		p = p->succ;
	}
	return p;
}

void List::remove(ListNodePosi p)
{
	if (p!=header && p!=trailer)
	{
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		delete p;
		_size--;
	}	
}

void List::remove(int n)
{
	if (n>_size)
	{
		return ;
	}
	remove(get_anyposi(n));
}