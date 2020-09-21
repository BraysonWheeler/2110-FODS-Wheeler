#include <iostream>

using namespace std;

struct node{
	node* next;
	int data;
	node(){
		next = NULL;
		data = 0;
	}
	
};

class lists{
	private:
	
	public:
	
	node* head;
	node* current;
	node* tail;
	
	lists(){
		head = NULL;
		current = NULL;
		tail = NULL;
	}
	
	void print(){
		node* temp = head;
		do{
			cout << temp->data << " ";
			temp = temp->next;
		}
		while(temp!= head);
	}
	
	void insert(int x){
		node* temp = new node;
		temp->data = x;
		if(head == NULL){
			head = temp;
			tail = temp;
			current = temp;
			head->next = head;
		}
		else{
			current->next = temp;
			temp->next = head;
			current = temp;
			tail = temp;
		}
	}
	
};

int main(){
	lists l;
	l.insert(1);
	l.insert(5);
	l.insert(2);
	l.print();
}