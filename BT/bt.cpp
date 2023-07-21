#include <iostream>
#include <queue>
using namespace std;

class Node{
	public:
	int data;
	Node* right;
	Node* left;
	
	Node(int d){
		this -> data = d;
		this -> left = nullptr;
		this -> right = nullptr;	
	}
};

Node* buildTree(Node* &root){
	cout<<"Enter the data: "<< endl;
	int data;
	cin>> data;
	root = new Node(data);
	
	if(data == -1){
		return  NULL;
	}
	
	cout<<"Enter the left of node: "<<data<<endl;
	root->left = buildTree(root->left);
	cout<<"Enter right of node: "<<data<<endl;
	root->right = buildTree(root->right);
	return root;
}	

void levelOrderTraversal(Node* root){
	queue<Node*> q;
	//~ pushing only one element
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		//~ printing that one element and go on to check and add 
		//~ them one by one
		Node* temp = q.front();
		q.pop();		

		if(temp == NULL){// purana level compleete traverse hogaya
			cout<<endl;
			if(!q.empty()) q.push(NULL);
		}else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
	
			if(temp->right){
				q.push(temp->right);
			}
		}
		
	}


}

void inorder(Node* root){
	// l n r;
	// base case

	if(root==NULL) return; 
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(Node* root){
	// n l r;
	// base case

	if(root==NULL) return; 
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}

void postorder(Node* root){
	// l r n;
	// base case

	if(root==NULL) return; 
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";

}

int main(){
		Node* root = NULL;
		//~ creating a tree
		root = buildTree(root);
		levelOrderTraversal(root);
		cout<<"InOrder Traversal : "<<endl;
		inorder(root);
		cout<<"\nPreOrder Traversal : "<<endl;
		preorder(root);
		cout<<"\nPostOrder Traversal : "<<endl;
		postorder(root);
}
