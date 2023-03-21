#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }

};
//bst -> condition
//node>left child and node<right child(error)
//approch-2
//maxLeft and minRight
//node>maxL and node<minR
//approach-3
//min allowed<node
//max allowed>node
//node(min,max)-> left(min,node) and right(node,max)


bool isBST(Node* root,Node* min=NULL,Node* max=NULL){

    if(root==NULL){//base case
        return true;//the tree is empty,so it is BST
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }

    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    return leftValid and rightValid;

}//O(n)-> we are traversing each node only once 


int main(){

    Node* root= new Node(5);
    root->left=new Node(2);
    root->right=new Node(8);

    if(isBST(root,NULL,NULL))
    cout<<"Valid BST"<<endl;
    else
    cout<<"Not Valid BST"<<endl;

    



}