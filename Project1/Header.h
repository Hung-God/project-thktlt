#ifndef Header_H
#define Header_H
#include<iostream>
#include<fstream>
using namespace std;

struct node
{
	int data;
	node* next;
};

struct list
{
	node* head;
	node* tail;
};

void init(list& l);
void add_tail(list& l, int x);
void read_file(list& l);
void output(list l);
int length(list l);
node* createnode(int x);
void addheadlist(list& l, node* p);
node* addhead(node* p, int x);
node* addtail(node* p, int x);
node* deletehead(node* p);
node* deletetail(node* p);
node* deleteat(node* p, int pos);
void deleteheadlist(list& l);
node* addat(node* p, int pos, int x);

#endif
