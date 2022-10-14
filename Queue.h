#ifndef QUEUEH
#define QUEUEH

#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

class Queue {
private:
	int front, rear, size;
	double* array;
public :
    Queue(int size);
    ~Queue();
    bool IsFull();
    bool IsEmpty();
    void Enqueue(double K);
    void characterEnqueue(char C);
    void Dequeue();
    double getFront();
    double getRear();
};

#endif