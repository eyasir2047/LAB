//1 1 2 5 14->Catalan sequence
//Cn=1/n+1
//2nCn=sum(Ci*Cn-i),i=0 to n-1
//C0=1
//C1=1
//C2=C0C1+C1C0=1+1=2
//C3=C0C2+C1C1+C2C0=5

//nth catalan find
#include<iostream>
#include<vector>

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
void preorder(Node* root){

    if(root==NULL){
       return; 
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

int catalan(int n){
    if(n<=1) return 1;//base case

    int res=0;
    for(int i=0;i<=(n-1);i++){
            res+=catalan(i)*catalan(n-i-1);
    }

    return res;
}//O(n)

//application of catalan numbers
/*
possible BSTS
parenthesis combinations
possible forests
ways of trangulations
possible paths in matrix
*/

//possible BST->number of nodes given(n)
//n=1 BST=1
//n=2 BST=2
//n=3 BST=5
/*
C3=C0C2+C1C1+C2C0=2+1+2=5

*/

vector<Node*>constructTrees(int start,int end){

   vector<Node*>trees;
if(start>end){
        trees.push_back(NULL);
        return trees;
    }

for(int i=start;i<=end;i++){
    vector<Node*>leftSubtrees=constructTrees(start,i-1);
    vector<Node*>rightSubtrees=constructTrees(i+1,end);

    for(int j=0;j<leftSubtrees.size();j++){
        Node* left=leftSubtrees[j];
        for(int k=0;k<rightSubtrees.size();k++){
            Node* right=rightSubtrees[k];
            Node* node=new Node(i);
            node->left=left;
            node->right=right;
            trees.push_back(node);
        }

    }
    

}

return trees;


}



int main(){
   /* for(int i=0;i<10;i++)
    cout<<catalan(i)<<" ";
    cout<<endl;*/
    vector<Node*>totalTrees=constructTrees(1,4);

    for(int i=0;i<totalTrees.size();i++){
        cout<<i+1 <<":"<<" ";
       preorder(totalTrees[i]);
       cout<<endl;
    }

    return 0;


}
