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

//preorder-> root,left subtree and right subtree
//inorder-> left subtree,root and right subtree
//postorder-> left subtree,right subtree and root
//as in postorder, root comes at last, we have to traverse from the n-1


int search(int inorder[],int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val)
        return i;
    }
    return -1;
}
Node* buildTree(int postorder[],int inorder[],int start,int end){
    static int idx=4;

    if(start>end)
    return NULL;


    int val=postorder[idx];
    idx--;
    Node* curr=new Node(val);
    if(start==end) return curr;
    int pos=search(inorder,start,end,val);
    curr->right=buildTree(postorder,inorder,pos+1,end);
    curr->left=buildTree(postorder,inorder,start,pos-1);

    return curr;


}

void inorderPrint(Node* root){
    if(root==NULL) return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}


int main(){

    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    Node* root=buildTree(postorder,inorder,0,4);
    inorderPrint(root);
    cout<<endl;





    return 0;
}

//we can not build trees from postorder and preorder(if it is not a full binary tree)

