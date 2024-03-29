#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>

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

//level order in zigzag
//using two stacks
void zigzagTraversal(Node* root){

    if(root==NULL){
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight=true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp=currLevel.top();
        currLevel.pop();

        if(temp){
        cout<<temp->data<<" ";

        if(leftToRight){
            if(temp->left)
            nextLevel.push(temp->left);
            if(temp->right)
            nextLevel.push(temp->right);
        }
        else{//right to left
        if(temp->right)
        nextLevel.push(temp->right);
        if(temp->left)
            nextLevel.push(temp->left);

        }
        }

        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }


    }



}//O(n)

int main(){
     
     Node* root=new Node(12);
    
    root->left=new Node(9);
    root->right=new Node(15);

    root->left->left=new Node(5);
    root->left->right=new Node(10);
    zigzagTraversal(root);
    cout<<endl;
    

}

