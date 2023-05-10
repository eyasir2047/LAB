
#include<iostream>
using namespace std;
class Node{
    public:
    int data, height;
    Node* left;
    Node* right;
    Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}


};

int height(Node *N)
{
    if (N == NULL)
        return 0;

    return N->height;
}


Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
   
    return x;
}
 

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}
 

int balanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}


Node* minimumValue(Node* node){

    Node* current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    
    return current;
}

Node* deleteNode(Node* root, int data)
{
    
    if(root==NULL)return root;

    else if(root->data>data){
       root->left= deleteNode(root->left,data);
    }
    else if(root->data<data){
        root->right=deleteNode(root->right,data);
    }
    else{
        
        if(root->left==NULL || root->right==NULL){ 
            
            Node* temp;
            
            temp=root->left?root->left:root->right;
            
            if(temp==NULL){ 
               temp=root;
                root=NULL;
            }
            else{ 
               
                *root=*temp;
                
            }
            free(temp);
        }
        else{
            
            Node* temp=minimumValue(root->right);// inorder successor
             root->data=temp->data;
             
            root->right= deleteNode(root->right,temp->data);
            
        }
        
        
        
        }
        
        if(root==NULL) return root;
        
        int bf=balanceFactor(root);
        root->height=max(height(root->left),height(root->right))+1;
        
        if(bf>1){
            if(balanceFactor(root->left)>=0){
                return rotateRight(root);//LL
            }
            else if(balanceFactor(root->left)<0){
                root->left=rotateLeft(root->left);
                return rotateRight(root);//LR
            }
        }
        
        else if(bf<-1){
            if(balanceFactor(root->right)<=0){
                return rotateLeft(root);//RR
            }
            else if(balanceFactor(root->right)>0){//RL
            root->right=rotateRight(root->right);
            return rotateLeft(root);
                
            }
        }
        
    
    
    return root;
}
Node* newNode(int key)
{
    Node* node = new Node(key);
    return(node);
}

Node* insertToAVL(Node* node, int key)
{
       if (node == NULL)
        return(new Node(key));
 
    if (key < node->data)
        node->left = insertToAVL(node->left, key);
    else if (key > node->data)
        node->right = insertToAVL(node->right, key);
    else 
        return node;
 
   
    node->height = 1 + max(height(node->left), height(node->right));
 
    
    int balance = balanceFactor(node);
    
    
    if(balance>1){
         if(key < node->left->data)
        return rotateRight(node);
        
         else if (key > node->left->data)
        {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
             }
        
    }
 
    
    else if(balance<-1){
        if ( key > node->right->data)
        return rotateLeft(node);
       else  if (key < node->right->data)
        {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
        }
        
    }
 
    return node;
    }
void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main()
{
    Node *root = NULL;
     
    
    root = insertToAVL(root, 10);
    root = insertToAVL(root, 20);
    root = insertToAVL(root, 30);
    root = insertToAVL(root, 40);
    root = insertToAVL(root, 50);
    root = insertToAVL(root, 25);
     
    /* The constructed AVL Tree would be
            30
            / \
            20 40
            / \ \
          10   25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    cout<<endl;

    deleteNode(root,30);

     cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
   
    preOrder(root);

     
    return 0;
}

