#include <iostream>
#include <string>


using namespace std;




struct node{
	node* next;
	int data;
	
	node(){
		next = NULL;
		data = 0;
	}
};

class lists {
	private:
	
	public:
	
	node*current;
	node*head;
	node*prev;
	
	lists(){
		current = NULL;
		head = NULL;
		prev = NULL;
	}
	
	void insert(int x){
		node* temp = new node;
		temp->data = x;
		
		if(head == NULL){
			head = temp;
			current = temp;
			prev = temp;
		}
		
		else{
			current->next = temp;
			prev = current;
			current = current->next;
		}
	}
	
	void print(){
		node* temp  = head;
		while(temp != NULL){
			cout << temp->data;
			temp = temp->next;
		}
		printf("\n");
	}
	
	//works both ascending descending
	void selectionsort(){
		node* temp = head;
		while(temp){
			node* min = temp;
			node* r = temp->next;
			
			while(r){
				if(min->data < r->data){
					min = r;
				}
				r = r->next;
			}
			int x = temp->data;
			temp->data = min->data;
			min->data = x;
			temp = temp->next;
		}
	}
	
	void swap (node *n1, node *n2){
		int temp = n1->data;
		n1->data = n2->data;
		n2->data = temp;
	}
	
	//swap > < for ascending descending
	void bubblesort(){
		int swapped;
		node* lptr;
		node* rptr= NULL;
		do{
			swapped = 0;
			lptr = head;
			while(lptr->next != rptr){
				if(lptr->data > lptr->next->data){
					swap(lptr,lptr->next);
					swapped = 1;
				}
				lptr = lptr->next;
					
			}
			rptr = lptr;
		}
	while(swapped);
	}
	
	void reverse(){
		node* current = head;
		node* prev = NULL;
		node* after = NULL;
		
		while(current!= NULL){
			after = current->next;
			current->next = prev;
			prev = current;
			current = after;
		}
		head = prev;
	}
};

int main(){
	lists l;
	int sentvalue;
	int value;
	int count=0;
	
	while(sentvalue != -1){
		cin >> sentvalue;
		if(sentvalue != -1){
			value = sentvalue;
			l.insert(value);
			count++;
		}
	}
	printf("\n");
	//l.print();
	//l.selectionsort();
	l.print();
	l.bubblesort();
	l.print();
	l.reverse();
	l.print();
}
