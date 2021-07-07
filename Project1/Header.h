#ifndef Header_H
#define Header_H
#include<iostream>
#include<fstream>
#include<string>
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
void deletehead(list& l);
void deletetail(list& l);
void deleteat(list& l, int pos);
void addhead(list& l, int x);
void addat(list& l, int pos, int x);
void Push(int stack[], int value, int& top);
int printoutat(list l, int pos);
#endif
