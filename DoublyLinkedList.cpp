#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	
	Node(int d){
		this->data = d;
		this->prev = NULL;
		this->next = NULL;
	};
	// it is called when we delete object
	~Node(){
		int val = this->data;
		if(next!=NULL){
			delete next;
			next = NULL;
		}
		cout<<"Memory free for Node with data "<<val<<endl;
	}
};

void insertFirst(Node* &head,Node* &tail, int val){
	if(head==NULL){
		Node* newNode =new Node(val);
		head = newNode;
		tail = newNode;
	}else{
		Node* newNode =new Node(val);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

}

void insertLast(Node* &head ,Node* &tail, int val){
	if(tail==NULL){
		Node* newNode =new Node(val);
		head = newNode;
		tail = newNode;
		return;
	}
	Node* newNode =new Node(val);
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

void insertMiddle(Node* &head, Node* &tail, int pos, int data){
	
	if(head==NULL || tail==NULL){
		Node* newNode =new Node(data);
		head = newNode;
		tail = newNode;
		return;
	}
	
	Node* newNode = new Node(data);
	Node* temp = head;
	
	pos = pos-1;
	//~ first pos
	if(pos==0){
		insertFirst(head,tail, data);
		return;
	}

	
	while(pos-1!=0 && temp->next!=NULL){
		temp = temp->next;
		pos = pos-1;
	}
	
	//~ last pos
	if(temp->next==NULL){
	 insertLast(head,tail, data);
	 return;
	}
	
	
	newNode->next = temp->next;
	temp->next->prev = newNode;
	
	temp->next = newNode;
	newNode->prev = temp;
}

void deleteNode(Node* &head,Node* &tail, int pos){
	//~ First Node
	pos = pos-1;
	if(pos==0){
		Node* temp = head;
		temp->next->prev = NULL;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}else{
		//~ for second and last
		Node* curr = head;
		Node* prev = NULL;
			
		// handles code for taking the curr to the element
		// to be removed, here , if pos > size, then it will
		// remove the last element
			while(pos!=0 && curr->next!=NULL){
				prev = curr;
				curr = curr->next;
				pos=pos-1;
			}
	
			if(curr->next==NULL){
				// if deleting end node
				tail =  prev;
				curr->prev = NULL;		
				prev->next = curr->next;
				curr->next = NULL;
				delete curr;
			}else{
				// if deleting middle node
				curr->prev = NULL;		
				prev->next = curr->next;
				//it is connecting the nodes both side, when we delete a node in between
				curr->next->prev = prev ;
				curr->next = NULL;
				delete curr;
			}

		}
}
void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

void printRev(Node* tail){
	Node* temp = tail;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->prev;
	}
	cout<<"NULL"<<endl;
}
int length(Node* head){
	int len = 0;
	Node* temp = head;
	while(temp!=NULL){
		len = len+1;
		temp = temp->next;
	};
	return len;
};

int main(){
	Node* head = NULL;
	Node* tail = NULL;
	insertLast(head, tail, 10);
	insertLast(head, tail, 20);
	insertLast(head, tail, 30);
	insertLast(head, tail, 40);
	insertLast(head, tail, 50);
	insertLast(head, tail, 60);
	insertLast(head, tail, 70);
	
	
	print(head);
	cout<<"head: "<<head->data<<endl;
	cout<<"tail: "<<tail->data<<endl;
	
	
	deleteNode(head,tail,1);
	print(head);
	cout<<"head: "<<head->data<<endl;
	cout<<"tail: "<<tail->data<<endl;
	
	deleteNode(head,tail,4);
	print(head);
	cout<<"head: "<<head->data<<endl;
	cout<<"tail: "<<tail->data<<endl;
	
	deleteNode(head,tail,10);
	print(head);
	cout<<"head: "<<head->data<<endl;
	cout<<"tail: "<<tail->data<<endl;

	cout<<length(head);
	return 0;
}
