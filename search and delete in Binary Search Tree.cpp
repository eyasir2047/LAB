//search in a BST
//binary tree-> O(N)
//bst-> O(logN)
//Delete and search in bst
//delete ->leaf/node has one child/node has two children(inorder successor)



#include<iostream>
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



Node* searchInBST(Node* root,int key){
    if(root==NULL)
    return NULL;

     if(root->data==key)
    return root;

    if(key< root->data)
    return searchInBST(root->left,key);

    return searchInBST(root->right,key);

}
//deleting two children->inorder successor
//in bst , inorder sequence is sorted
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int key){

    if(root==NULL) return root;


    if(key< root->data)
        root->left= deleteInBST(root->left,key);

    

   else  if(key> root->data)
    root->right=deleteInBST(root->right,key);

    else{
        if(root->left==NULL){
            Node* temp=root->right;//single child/leaf,leaf is when root->right==NULL
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;//single child/leaf , leaf is when root->left==NULL
            free(root);
            return temp;

        }

        //two child-> inorder successor
        Node* temp=inorderSucc(root->right);
        root->data= temp->data;
        root->right=deleteInBST(root->right,temp->data);


        
    }

    return root;

    


}

void inorder(Node* root){
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){

    
         Node* root=new Node(4);
        root->left=new Node(2);
        root->right=new Node(5);

        root->left->left=new Node(1);
        root->left->right=new Node(3);
        root->right->right=new Node(6);
        

      
    /*if(searchInBST(root,5)==NULL)
    cout<<"key does not exist"<<endl;
    else
    cout<<"key exists"<<endl;*/

    inorder(root);
    cout<<endl;

    root=deleteInBST(root,5);
    inorder(root);
    cout<<endl;





    return 0;
}