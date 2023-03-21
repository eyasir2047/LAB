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

bool isBalanced(Node* root){
    if(root==NULL) return true;
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);

    bool diff=abs(calcHeight(root->left)-calcHeight(root->right))<=1;

    if(left && right && diff)
    return true;

    else
    return false;

}//O(n*n)




int main(){

     Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    cout<<isBalanced(root)<<endl;
   
   return 0;
}

