#include<iostream>
#include<queue>
#include<map>
#include<vector>
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
//take U forward 

// two type traversal -> recursive traversal and level order traversal
//line concept-> vertical order traversal

void topView(Node* root){
    if(root==NULL) return;
    map<int,int>mp;
   
    queue<pair<Node*, int> > q;
    q.push({root,0});//line concept
    //root->0
    //left-> -1,-2,-3
    //right-> 1,2,3

    while(!q.empty()){
        Node* temp=q.front().first;
        int hd=q.front().second;
        q.pop();

        if(mp.find(hd)==mp.end())
        mp[hd]=temp->data;

        if(temp->left!= NULL)
        q.push({temp->left,hd-1});

        if(temp->right!=NULL){
            q.push({temp->right,hd+1});
        }

    }

   /*for(auto it: mp){
        cout<<it.second<<" ";

    }*/
    /*
    for (auto it = mp.begin(); it != mp.end(); ++it) {
    cout << it->second << " ";
}*/
for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
    cout << it->second << " ";
}


    cout<<endl;

    
}






//level order traversal
int main(){
     Node* root=new Node(5);
    
    root->left=new Node(3);
    root->right=new Node(6);

    root->left->left=new Node(2);
    root->left->right=new Node(4);
    topView(root);
   
   return 0;
}



