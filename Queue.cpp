#include<iostream>
#include "Queue.h"
using namespace std; 

Queue::Queue(int size) {
    this->rear = 0;
    this->size = size;
    this->array = new double[size];
    
    if (array == NULL){
    	cout << "Error" << endl;
    	exit(EXIT_FAILURE);
	}
}

	// To check wheter Queue is empty or not
bool Queue::IsEmpty()
{
	return (front == -1 && rear == -1); 
}

	// To check whether Queue is full or not
bool Queue::IsFull()
{
	return (rear+1)%MAX_SIZE == front ? true : false;
}

	// Inserts an element in queue at rear end
void Queue::Enqueue(int x)
{
	cout<<"Enqueuing "<<x<<" \n";
	if(IsFull())
	{
		cout<<"Error: Queue is Full\n";
		return;
	}
	if (IsEmpty())
	{ 
		front = rear = 0; 
	}
	else
	{
		rear = (rear+1)%MAX_SIZE;
	}
	A[rear] = x;
}

	// Removes an element in Queue from front end. 
void Queue::Dequeue()
{
	cout<<"Dequeuing \n";
	if(IsEmpty())
	{
		cout<<"Error: Queue is Empty\n";
		return;
	}
	else if(front == rear ) 
	{
		rear = front = -1;
	}
	else
	{
			front = (front+1)%MAX_SIZE;
	}
}
	// Returns element at front of queue. 
int Queue::Front()
{
	if(front == -1)
	{
		cout<<"Error: cannot return front from empty queue\n";
		return -1; 
	}
	return A[front];
}
//push the char values
void Queue::characterEnqueue(char C) {
    
    //check if full
    if (isFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = C; //put inside the array
        this->rear = this->rear + 1; //increase the rear
    }
    return;
}
	
