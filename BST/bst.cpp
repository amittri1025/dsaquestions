#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    this->data = d;
    left = NULL;
    right = NULL;
  }
};

Node *createBST(Node *root, int d)
{
  // base case;
  if (root == NULL)
  {
    root = new Node(d);
    return root;
  }

  if (d > root->data)
  {
    // right part me insert karna hai
    root->right = createBST(root->right, d);
  }
  else
  {
    root->left = createBST(root->left, d);
  }

  return root;
};

void levelOrderTraversal(Node *root)
{
  if(root==nullptr) return;
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    //~ printing that one element and go on to check and add
    //~ them one by one
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    { // purana level compleete traverse hogaya

      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      if(temp!=NULL){
      cout << temp->data << " ";
      }


      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void inorderPd(Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;

  inorderPd(root->left, ans);
  ans.push_back(root->data);
  inorderPd(root->right, ans);
}

void preorder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

Node* minValue(Node *root)
{
  Node* temp = root;

  while(temp->left != NULL){
    temp = temp -> left;
  }

  return temp;
}

int maxValue(Node *root)
{
  if (root->right == NULL)
    return root->data;

  return maxValue(root->right);
}

Node *deleteFromBST(Node *root, int val)
{
  if(root==NULL) return root;

  if(root->data==val){
    // asli khel start
    // sirf 1 node ho no bacccha i..e LEAF
    if(root->left==NULL && root->right==NULL){
      delete root;
      return NULL;
    }

    // case 2
    // ek node ho ya toh LEFT mein ya toh RIGHT me
    if(root->right==NULL && root->left!=NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }

    if(root->left==NULL && root->right!=NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }
 
    // case no. 3
// the most special case, kyounki esi tika hai pura alog
// esme root ke dono child zinda honge ar kya pata unke bhi child ho, BUTTT hame root
// ko hee delete karana hi, SOLUTIOON : root ko delete karke , uska INORDER successor daldo 
    if(root->left!=NULL && root->right!=NULL){
      // Node* temp = root->right->left->data;
      // root->data = temp->data;
      // root->left->right = deleteFromBST(temp, temp->data);

      int mini = minValue(root->right)->data;
      root->data = mini;
      root->right = deleteFromBST(root->right, mini);
      return root;  
    }
  }else if( root->data > val ){
    root->left = deleteFromBST(root->left, val);
    return root;
  }
}

int main()
{
  // building the BST
  Node *root = NULL;
  int data;
  cout << "enter data to create   BST ";
  cin >> data;
  while (data != -1)
  {
    root = createBST(root, data);
    cin >> data;
  }

  // printing the elems of bst
  levelOrderTraversal(root);

  // 10 8 17 7 6 15 18 12 -1
  // 15 12 20 5 14 16 22 13 18 19 -1

  int target = 20;

  Node* ans = deleteFromBST(root, target);
  levelOrderTraversal(ans);

  cout<<endl<<"MIN VALUE: "<<minValue(root);

  return 0;
}