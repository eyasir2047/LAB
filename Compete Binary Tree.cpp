#include<iostream>
#include<algorithm>

//postorder, inorder and preorder traversal


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



//counting the number of nodes
int countNumNodes(Node* root){

    if(root==NULL){
        return 0;
    }
    
    return 1+countNumNodes(root->left)+countNumNodes(root->right);
}

bool checkComplete(Node* root,int index,int numberOfNodes){

    if(root==NULL) return true;

    if(index>=numberOfNodes){
        //as index starting from 0
        return false;
    }

    return checkComplete(root->left,2*index+1,numberOfNodes) && checkComplete(root->right,2*index+2,numberOfNodes);
}



int main(){

        Node* root=new Node(1);
        root->left=new Node(2);
        root->right=new Node(3);

        root->left->left=new Node(6);
        root->left->right=new Node(4);
        root->right->left=new Node(5);

        int node_count=countNumNodes(root);
        //cout<<node_count<<endl;
        int index=0;

        if(checkComplete(root,index,node_count))
        cout<<"Complete Binary tree"<<endl;

        else
        cout<<"Not Complete Binary tree"<<endl;


        


       






        return 0;

}