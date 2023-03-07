#include <map>
#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int d){
		this->data = d;
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

void insertLast(Node* &tail, int val){
  Node* newNode = new Node(val);
  tail->next = newNode;
  tail = newNode;
}

void reverse1(Node* &head, Node* prev, Node* curr){
	if(curr==NULL){
		head = prev	;
		return;
	}
	Node* forward = curr->next;
	reverse1(head, curr, forward);
	curr->next = prev;
}

Node* reverse2(Node* &head)	{
	if(head==NULL || head->next == NULL){
		return head;
	}
	
	Node* chotaHead = reverse2(head->next);
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}

Node* reverseList(Node* head){
  //~ Node* prev = NULL;
  //~ Node* curr = head;
 
  
  //~ reverse1(head, prev, curr);
  return reverse2(head);
}

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
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

bool checkLoop(Node* head){
	if(head==NULL) return false;
	Node* temp = head;
	map<Node*, bool> visited;
	
	
	while(temp!=NULL){	
		if(visited[temp]==true) {
			cout<<"Loop present on elem "<<temp->data<<endl;
			return true;
		}
		visited[temp] = true;
		temp = temp->next;
	}
return false;
}

Node* checkLoop2(Node* head){
	//~ using floyd algo
	if(head==NULL) return NULL;
	
	Node* slow = head;
	Node* fast = head;
	
	while(slow!=NULL && fast!=NULL){
		slow = slow->next;
		if(fast!=NULL && fast->next!=NULL){
			fast = fast->next->next;
		}
		if(slow==fast){
			return slow;
		}
	}
	return NULL;
}


Node* getStarting(Node* head){
	if(head==NULL){
		return NULL;
	};
		
	Node* intersection = checkLoop2(head);
	Node* slow = head;
	
	while(intersection!=slow){
		intersection = intersection	->next;
		slow = slow->next;
	}
	
	return slow;
}

void removeLoops(Node* head){
	if(head == NULL){
	return;
	
	Node* startOfLoop = getStarting(head);
	Node* temp = startOfLoop;
	
	while(temp->next != startOfLoop){
		temp = temp->next;
	}
	
	temp= temp->NULL;
}

int main(){
	Node* node = new Node(10);
	Node* tail = node;
	Node* head = node;
	insertLast(tail, 5);
	insertLast(tail, 17);
	insertLast(tail, 8);
	tail->next = head->next;
	//~ cout<<"head is "<<head->data<<endl;
	//~ cout<<"tail is "<<tail->data<<endl;
	
	if(checkLoop2(head)){ 
		cout<<"Yeahs loop exists at point"<<endl;	
		cout<<getStarting(head)->data;
	}else{
		cout<<"loop doesnt' exists"<<endl;
		//~ print(head);
	}
	return 0;
}
