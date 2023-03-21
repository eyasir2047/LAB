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
//inorder->sorted order
//preorder-> root,left->root, right->root
//n->number of nodes

Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    //base case
    if(*preorderIdx>=n)
    return NULL;
//preorderIdx representing the key
        Node* root=NULL;
        if(key>min && key<max){
            root=new Node(key);
    //now we have to update the preorderIdx
    *preorderIdx=*preorderIdx+1;

    if(*preorderIdx <n){
        root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
    }

    if(*preorderIdx<n){
        root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);

    }

}

     return root;

}//O(n)

void PrintPreorder(Node * root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

int main(){

    int preorder[]={10,2,1,13,11};
    int n=5;
    int preorderIdx=0;

   Node* root= constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
   PrintPreorder(root);





}