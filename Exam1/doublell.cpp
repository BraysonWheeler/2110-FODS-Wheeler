#include <iostream>

using namespace std;


struct node{
	node* next;
	node* prev;
	int data;
	
	node(){
		prev = NULL;
		next = NULL;
	}
	
};

class lists{
	private:
	
	public:
	
	node* head;
	node* tail;
	node* current;
	
	lists(){
		head = NULL;
		tail = NULL;
		current = NULL;
	}
	void insert(int x){
		node* temp = new node;
		temp->data = x;
		
		if(head == NULL){
			head = temp;
			current = temp;
		}
		else{
			current->next = temp;
			temp->prev = current;
			current = current->next;
		}
	}
	void print(){
		node* temp = head;
		while(temp){
			cout << temp->data;
			temp = temp->next;
		}
	}
	
	void printrev(){
		node* temp = current;
		while(temp){
			cout << temp->data;
			temp = temp->prev;
		}
	}
};






int main(){
	lists l;
	
	l.insert(3);
	l.insert(9);
	l.insert(4);
	l.insert(10);
	
	l.print();
	printf("\n");
	l.printrev();
	printf("\n");
	
}