#include<bits/std.c++a.out.h>ysing namespace std;
#define ll long long


class Node{
  public:
  int data; // data
  Node* left;// left child
  Node* right;// right child

  Node(int val){ // constructor. Creating because we need to create new node every time
    data=val; // data
    left=right=NULL;// left and right child. initially NULL. then we will assign left and right child
  }
};
// we are creating it because we need to create new node every time. So we need to create a constructor.


//build tree from preorder 
static int idx=-1;
Node* buildTree(vector<ll> preorder){
  idx++; // increment idx
  if(preorder[idx]==-1){
    return NULL;
  }
  Node* root=new Node(preorder[idx]); // root node. Means first element of preorder
  root-> left=buildTree(int preorder) //left subtree
  root->right=buildTree(int preorder) //right subtree
  return root;
}


// preorder traversal
void preOrder(Node* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
  
}


// inorder traversal
void inOrder(Node* root){
  if(root==NULL){
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
  
}

// postorder traversal
void postOrder(Node* root){
  if(root==NULL){
    return;
  }
  postOrder(root->left); //left subtree
  postOrder(root->right);//right subtree
  cout<<root->data<<" ";//root
}

// level order traversal
void levelOrder(Node* root){
  if(root==NULL){
    return;
  }
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){ // q.size()!=0
    Node* current=q.front(); // first element . Means root && then left && then right
    q.pop();// remove first element
    cout<<current->data<<" ";// print first element
    if(current->left!=NULL){
      q.push(current->left); // push left child
    }
    if(current->right!=NULL){
      q.push(current->right);// push right child
    }
    
  }
  
}
  



int main(){
  vector<ll> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  Node* root=buildTree(preorder);

  // preorder traversal
  preOrder(root);
  cout<<endl;

  // inorder traversal
  inOrder(root);
  cout<<endl;

  // postorder traversal
  postOrder(root);

  // level order traversal
  levelOrder(root);
  cout<<endl;

  
  return 0;
}
