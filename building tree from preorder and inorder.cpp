#include<iostream>
using namespace std;
//building tree from preorder and inorder
//preorder 1 2 3
//inorder 2 1 3
//preorder -> first come root (1)

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

int search(int inorder[],int start,int end,int curr ){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

void inorderPrint(Node* root){

    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}



Node* buildTree(int preorder[],int inorder[],int start,int end ){
    static int idx=0;

    if(start>end) return NULL;

    int curr= preorder[idx];
    idx++;
    Node* node=new Node(curr);

    if(start==end)//one single node
    {
        return node;
    }

    int pos=search(inorder,start,end,curr);
    node->left=buildTree(preorder,inorder,start,pos-1);
    node->right=buildTree(preorder,inorder,pos+1,end);

    return node;



}


int main(){

    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

   Node*root= buildTree(preorder,inorder,0,4);

   inorderPrint(root);









    return 0;
}