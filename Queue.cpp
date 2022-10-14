#include"Queue.h"
#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

//Making the new queue
Queue::Queue(int size) {
    this->front = 0;
    this->rear = 0;
    this->size = size;
    this->array = new double[size];
    
    if (array == NULL){
    	cout << "Error" << endl;
    	exit(EXIT_FAILURE);
	}
}

//delete the queue
Queue::~Queue() {
    delete[] this->array;
}

//checking if is full
bool Queue::IsFull() {
	//full if size equal to rear
    return (this->size == this->rear);
}

//checking if is empty
bool Queue::IsEmpty(){
	//empty if the front equal to rear
    return (this->front == this->rear);
}

//push the num values
void Queue::Enqueue(double K) {
	
	//check if full
    if (IsFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = K; //put inside the array
        this->rear = this->rear + 1; //increase the rear
    }
    return;
}

//push the char values
void Queue::characterEnqueue(char C) {
	
	//check if full
    if (IsFull()) {
        cout << "\n\tOverflow" << endl;
        return;
    }
    else {
        this->array[this->rear] = C; //put inside the array
        this->rear = this->rear + 1; //increase the rear
    }
    return;
}

//Queue is First in First out
//But for the purpose of the calculator
//We make the queue to Last in First out
void Queue::Dequeue(){
	
	//check if empty
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
        return;
    }
    
    //dequeue with rear-1
    else {
        this->rear = this->rear - 1;
    }
    return;
}

//getting the front
//never used it
double Queue::getFront(){
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->front];
}

//getting the rear
double Queue::getRear(){
    if (IsEmpty()){
        cout << "\n\tUnderflow" << endl;
    }
	return this->array[this->rear - 1];
}

