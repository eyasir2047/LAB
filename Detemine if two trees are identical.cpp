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

bool isIdentical(Node* r1,Node* r2){
    if(r1==NULL && r2==NULL)
    return true;
     if(r1!=NULL && r2==NULL)
    return false;
     if(r1==NULL && r2!=NULL)
    return false;

    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);

    bool value= r1->data==r2->data;

    if(left && right && value)
    return true;
    else
    return false;


}//O(n)

int main(){
     Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

     Node* root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(30);
    root2->right->left = new Node(15);
    root2->right->right = new Node(20);

    cout<<isIdentical(root,root2)<<endl;


}