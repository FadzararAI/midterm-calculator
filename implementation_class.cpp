#include <iostream>

using namespace std;
struct node{
	int x;
	node *next;
};
class linkedlist{
public:
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	void add_node(int n);
private:
	node *head, *tail;
};
void linkedlist::add_node(int n){
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	if(head == NULL){
		head = tmp;
		tail = tmp;
	}else{
		tail->next = tmp;
		tail = tail->next;
	}
}
void display(){
	if(head == NULL){
		cout << "Empty" << endl;
	}else{
		while(head != NULL){
			cout << tmp << " ";
			tmp = tmp->next;
		}
	}
}
int main(){
	linkedlist a;
	a.add_node(5);
	a.add_node(10);
	a.display()
	return 0;
}
// [5] -> [10]