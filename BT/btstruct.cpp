#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

//~ New Node creatioon

struct node * newNode(int data){
	//~ struct node *node = (struct node *)malloc(sizeof(struct node));
	struct node* node = nullptr;
	
	node->data = data;
	
	node->left = NULL;
	node->right = NULL;
	return (node);
}

//~ traverse pre order N L R
void traversePreorder(struct node* temp){
	if(temp!=NULL){
		cout<<" "<<temp->data;
		traversePreorder(temp->left);
		traversePreorder(temp->right);		
	}
}

//~ traverse in order L N R
void traverseInorder(struct node* temp){
	if(temp!=NULL){
		traverseInorder(temp->left);
		cout<<" "<<temp->data;
		traverseInorder(temp->right);
	}
}

//~ traverse in order L R N
void traversePostorder(struct node* temp){
	if(temp!=NULL){
		traversePostorder(temp->left);
		traversePostorder(temp->right);
		cout<<" "<<temp->data;
	}
}

int main(){
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(10);
	root->right->right = newNode(11);
	
	cout<<"PreOrder Traversal "; traversePreorder(root); 
	cout<<"\nInorder Traversal "; traverseInorder(root); 
	cout<<"\nPostOrder TRaversal"; traversePostorder(root);
}

