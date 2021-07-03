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
void deletehead(list& l);
void deletetail(list& l);
void deleteat(list& l, int pos);
void deleteheadlist(list& l);
node* addat(node* p, int pos, int x);

#endif
