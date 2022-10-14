#ifndef QUEUE1H
#define QUEUE1H
#include<iostream>
#include<stdlib.h>
#include<cmath>
#define MAX_SIZE 101  
using namespace std;

class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear; 
public:
	bool IsEmpty();
	bool IsFull();
	void Enqueue(int x); 
	void Dequeue();
	int Front();
		Queue()
		{
		front = -1; 
		rear = -1;
		}

};
#endif

