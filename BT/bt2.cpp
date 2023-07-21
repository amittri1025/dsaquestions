#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *right;
  Node *left;

  Node(int data)
  {
    this->data = data;
    this->right = NULL;
    this->left = NULL;
  }
};

Node *buildtree(Node *&root)
{
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1)
    return NULL;

  cout << "Enter the data LEFT ";
  root->left = buildtree(root->left);
  cout << "Enter the data RIGHT ";
  root->right = buildtree(root->right);

  return root;
};

int levelOrderTraversal(Node *&root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  int height = 0;
  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      height = height + 1;
      cout<<endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
  return height;
}

void buildFromLevelOrder(Node* &root)
{
  /*
  build from level order traversal 
  just get input at each point 
  (make sure it's not -1, if it is do nothing)
  and push it to the Queue
  and do this until queue is empty
  (this condition will be true ,when elem are -1 
  bcoz in that case you are not pusshign anything inside)
  */
  queue<Node*> q;
  cout<<"Enter the root data: ";
  int data;
  cin>>data;
  root = new Node(data);

  q.push(root); 

  while(!q.empty()){
    Node* temp = q.front();
    q.pop();

    cout<<"Enter the left of  :"<<temp->data<<endl;
    int leftData;
    cin>>leftData;

    if(leftData!=-1){
      root->left = new Node(leftData);
      q.push(temp->left);
    }

    cout<<"Enter the right of  :"<<temp->data<<endl;
    int rightData;
    cin>>rightData;

    if(rightData!=-1){
      temp->right = new Node(rightData);
      q.push(temp->right);
    }

  }

}

int maxDepth(Node* node){
  if(node == NULL)
    return 0;

    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    // use the larger one 

    int ans = max(maxDepth(node->left), maxDepth(node->right)) + 1;
    return ans;
}

void solve(Node* root, vector<int> &v){
  if(root==NULL) return;
  solve(root->left, v);
  v.push_back(root->data);
  solve(root->right, v);
}

vector<int> inorder(Node* root){
  vector<int> v;
  solve(root, v);

  return v;
}


int main(){
  // building a tree
  // Node *root = new Node(1);
  // root->left = new Node(2);
  // root->right = new Node(3);
  // root->left->left = new Node(4);
  // root->left->right = new Node(5);

  Node *root = NULL;


  // // root = buildtree(root);
  buildFromLevelOrder(root);

  int height = levelOrderTraversal(root);
  cout<<"Heigh of Tree: "<<height;

  // vector<int> ans = inorder(root);
  // cout<<endl;
  // for(auto i: ans){
  //   cout<<i<<" ";
  // }

  return 0;
}