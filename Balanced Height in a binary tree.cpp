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
int calcHeight(Node* root){
    if(root==NULL) return 0;
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    return max(lHeight,rHeight)+1;

}

bool isBalanced2(Node* root){

    if(root==NULL)  return true;

    if(isBalanced2(root->left)==false)
    return false;
    if(isBalanced2(root->right)==false)
    return false;

    int lh=calcHeight(root->left);
    int rh=calcHeight(root->right);

    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
}//O(n*n)

bool isBalanced(Node* root, int *height){
    //height->current root ar height

    if(root==NULL) return true;

    int lh=0,rh=0;
    if(isBalanced(root->left,&lh)==false) return false;
    if(isBalanced(root->right,&rh)==false)return false;
    
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1) return true;
    else   return false;

}


int main(){
     Node* root=new Node(1);
    
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    cout<<isBalanced2(root)<<endl;

    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->left->left=new Node(3);
    cout<<isBalanced2(root2)<<endl; 

    int height=0;

    cout<<isBalanced(root2,&height)<<endl;



    return 0;
}
