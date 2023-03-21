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

    

//vertical order traversal
//storing->node,vertical and level
//vercial-> root->0, left->-1,-2,-3 ,right->1,2,3
//root(0,0)=means that vertical=0 and level=0

//multiset->as have values to print
//on every level->there are multiple nodes

//map<int,map<int,multiset<int>>mp;
//map<vertical,map<level,multinodes>>mp
//multiset or priority queue

//using the level order traversal





int main(){
     Node* root=new Node(5);
    
    root->left=new Node(3);
    root->right=new Node(6);

    root->left->left=new Node(2);
    root->left->right=new Node(4);
   
   return 0;
}



