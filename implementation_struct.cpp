#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
	int number;
	char opert;
	Node *next;
}*front=NULL,*rear,*temp;
void add(int x){
	temp = new Node;
	temp->number = x;
	temp->next = NULL;
	if(front == NULL){
		front = rear = temp;
	}else{
		rear->next=temp;
		rear=temp;
	}
}
void history(){
	if(front==NULL){
		cout << "List Empty" << endl;
	}
	else{
		temp=front;
		while(temp != NULL){
			cout << temp->number << " ";
			temp = temp->next;
		}
	}
}
int main(){
	
	return 0;
}