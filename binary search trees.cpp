//build a bst
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
       this-> data=val;
        this->left=NULL;
        this->right=NULL;

    }

};
Node* insertBST(Node* root,int val){

    if(root==NULL){ //empty node
        return new Node(val);
    }

    if(val< root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inorderPrint(Node* root){

    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,1);
     insertBST(root,3);
      insertBST(root,4);
       insertBST(root,2);
        insertBST(root,7);
       

       //print inorder
       inorderPrint(root);
//binary search tree,inorder traversal always give a sorted order




    return 0;
}