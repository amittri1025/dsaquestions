#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int d){
		this->data = d;
		next = NULL;
	}
	
	~Node(){
		int value = this->data;
		if(this->next!=NULL){
			delete next;
			next = NULL;
		}
		cout<<"memory is free for node: "<<value<<endl;
}
};

void insertNode(Node* &tail, int elem, int newelem){
	// if list is empty
	// insert first element
	Node* newNode = new Node(newelem);
	if(tail==NULL){
		tail = newNode;
		newNode->next = newNode;
	}else{
		//basically we are searching for the elem
		//if found we stop and add newelem to next position
		Node* temp = tail;
		while(temp->data!=elem){
			temp = temp->next;
		}
		//elem found at temp
		newNode->next =temp->next;
		temp->next = newNode;
	}
};

void deleteNode(Node* &tail, int elem){
	if(tail==NULL){
		cout<<"List is Empty..";
		return;
	}else{
		Node* prev = NULL;
		Node* curr = tail;
		//assuming elem is present
		do{
			prev = curr;
			curr = curr->next;
		}while(curr->data!=elem);
		
		prev->next = curr->next;
		
		
		// 1node linked list
		if(curr==prev){
			tail = NULL;
		}
		
		//>=2 Node linked list
		if(tail==curr){
			tail=prev;
		}
		
		//~ tail = prev->next;
		curr->next = NULL;
		delete curr;
	}
}

void print(Node* tail){
	if(tail==NULL){
		cout<<"NULL";
		return;
	}
	Node* temp = tail;
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	while(temp!=tail);
	cout<<"HEAD";
	cout<<endl;
	
}

bool checkCircular(Node* head){
	
	if(head==NULL){
		return true;
	}
	
	Node* temp = head->next;
	
	while(temp!=NULL && temp!=head){
		temp = temp->next;
	}	

	if(temp==head) return true;
	
	return false;
}

int main(){
	Node* tail = NULL;
	insertNode(tail, 10, 1);

	
	if(checkCircular(tail)) cout<<"Circular";
	else cout<<"Not Circular";


	return 0;
}
