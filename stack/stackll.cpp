#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* tail;
	
	Node(int data){
		this->data = data;
		next = NULL;
	}
	
	
};

class Stack{
	public:
	Node* node;
	Node* tail;
	Node* head;
	
	int size;
	Stack(int size){
		this->size = size;
	}
	
	int top = 0;
	
	void push(int data){
		
		if(top==0){
			node  = new Node(data);
			tail = node;
			head = node;	
			top++;
			return;
		}
		
		if(top>=1 && size>top){
			//~ Add elem
			Node* newNode = new Node(data);
			tail->next = newNode;
			tail = newNode;
			top++;
		}else{
			cout<<"Stack Overflow"<<endl;
		}
		
	}
	
	void pop(){
		if(top>=1){
			
			Node* temp = head;

			while(temp->next!=NULL&&temp->next->next){	
				temp = temp->next;
			}
			
			top--;
			// if only one element is left
			if(temp->next==NULL){
					node = NULL;
					temp = NULL;
					cout<<"Stack is already empty"<<endl;
					return;
			}
			temp->next = temp->next->next;
			tail = temp;
			
		}else{
			cout<<"Stack is already empty"<<endl;
		}
	}
	
	
	void peek(){
		Node* temp = head;
		while(temp->next){
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
	
void print(){
		Node* temp = node;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
	
};


int main(){
	
	Stack st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	
	st.peek();
	st.pop();
	st.peek();
	
	return 0;
}
