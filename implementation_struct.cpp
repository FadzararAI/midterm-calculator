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
void sortll(){
    struct Node *current = front, *index = NULL;
    int temp;
    if(front == NULL){
        return;
    }
    else{
        while(current != NULL){
            index = current->next;
            while(index != NULL){
                if(current->number > index->number){
                    temp = current->number;
                    current->number = index->number;
                    index->number = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
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
	add(5);
	add(20);
	add(10);
	add(25);
	add(60);
	add(50);
	history();
	sortll();
	history();
	return 0;
}