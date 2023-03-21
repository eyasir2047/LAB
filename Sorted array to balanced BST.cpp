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
//balanced bst -> height balanced
//abs(left heigth- right height)<=1

//approach like binary search

Node* sortedArrayToBST(int arr[],int start,int end){

    if(start>end) return NULL;

    int mid=(start+end)/2;

    Node* root=new Node(arr[mid]);
    root->left=sortedArrayToBST(arr,start,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,end);

    return root;



}
void preorder(Node* root){

    if(root==NULL){
       return; 
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

int main(){

    int arr[]={10,20,30,40,50};
    Node* root=sortedArrayToBST(arr,0,4);
    preorder(root);
    cout<<endl;
    return 0;
}

