#include <iostream>
using namespace std;
struct nodes{
	int number;
	char oprt;
	nodes *next;
}*head=NULL,*tail,*temp;
void add(int n){
	temp = new nodes;
	temp->number = n;
	temp->next = NULL;
	if(head == NULL){
		head = tail = temp;
	}
	else{
			tail->next=temp;
			tail=temp;
	}
}
void history(){
	if(head==NULL){
		cout << "List Empty" << endl;
	}
	else{
		temp=head;
		while(temp != NULL){
			cout << temp->number << " ";
			temp = temp->next;
		}
	}
}
int main(){
	int checker;
	while(true){
	    cout << "Enter number: ";
		cin >> checker;
	    if(checker != 00){
		add(checker);
	    }else{
	        break;
	    }
	}
	history();
	return 0;
}