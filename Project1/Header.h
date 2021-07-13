#ifndef Header_h
#define Header_h

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct NODE
{
	int data;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void init(LIST& l);
void addTail(LIST& l, int x);
void readFile(LIST& l);
void output(LIST l);
int length(LIST l);
void deleteHead(LIST& l);
void deleteTail(LIST& l);
void deleteAt(LIST& l, int pos);
void addHead(LIST& l, int x);
void addAt(LIST& l, int pos, int x);
int printOutAt(LIST l, int pos);
void push(int stack[], int value, int& top);
void save(LIST l);
void releaseList(LIST& l);
void writeFile(LIST l);

#endif
