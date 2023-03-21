//height=max(left height, right height)+1
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

int calcDiameter2(Node* root){
    if(root==NULL)
    return 0;

    int lHeight= calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currDiameter=lHeight+rHeight+1;//1 for current node

    int lDiameter=calcDiameter2(root->left);
    int rDiameter=calcDiameter2(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));

}//O(n*n)
//better approach
int calcDiameter(Node* root, int* height){

    if(root==NULL){
        *height=0;
        return 0;
    }
    
    int lh=0,rh=0;
    int lDiameter= calcDiameter(root->left,&lh);
    int rDiameter=calcDiameter(root->right,&rh);

    int currDiameter= lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}//O(n)



int32_t main(){
    Node* root=new Node(1);
    
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<calcHeight(root)<<endl;//O(n)

//diameter->number of nodes in the longest part between any 2 leaves
cout<<calcDiameter2(root)<<endl;//O(n*N)

int height=0;
cout<<calcDiameter(root,&height)<<endl;


    

}
