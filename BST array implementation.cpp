
#include <iostream>
#include<math.h>
using namespace std;


const int MAX_SIZE = 100; // maximum size of the array

class BinarySearchTree {
public:

    BinarySearchTree() {//constructor
        for (int i = 0; i < MAX_SIZE; i++) {
            arr[i] = -1; // initialize array to -1
        }
    }

    // insert a value into the tree
    void insert(int value) {
        insertHelper(0, value);
    }

    // delete a value from the tree
    void remove(int value) {
        removeHelper(0, value);
    }

    // perform an inorder traversal of the tree
    void inorderTraversal() {
        inorderTraversalHelper(0);
        cout <<endl;
    }

    void preorderTraversal(){
        preorderTraversalHelper(0);
        cout<<endl;
    }

    bool searchInBST(int data){
        if(search(data,0)) return true;
        else
        return false;
       
    }
    void deleteKey(int key) {
        
        deleteHelper(0, key);
    }

private:
    int arr[MAX_SIZE];

    // recursive helper function to insert a value into the tree
    void insertHelper(int idx, int value) {
        if (arr[idx] == -1) { //index in empty , so insert the value
            arr[idx] = value;
        }
        else if (value < arr[idx]) {
            insertHelper(2*idx+1, value);
        }
        else {
            insertHelper(2*idx+2, value);
        }
    }

    // recursive helper function to delete a value from the tree
    int removeHelper(int idx, int value) {
        if (arr[idx] == -1) {
            return -1;
        }
        else if (value < arr[idx]) {
            return removeHelper(2*idx+1, value);
        }
        else if (value > arr[idx]) {
            return removeHelper(2*idx+2, value);
        }
        
        else {///value==arr[idx]

            //three cases
            //leaf node-> no children
            //node has only one children
            //node->two children
            

            if (arr[2*idx+1] == -1 && arr[2*idx+2] == -1) {//the node has no children
                arr[idx] = -1;
            }
            else if (arr[2*idx+1] == -1) { //one children.->cinfusion We know that one children will be at left , so arr[right]=-1(right=2*idx+2)
                arr[idx] = arr[2*idx+2];
                removeHelper(2*idx+2, arr[2*idx+2]);
            }
            else {//arr[2*idx+2]==-1
                int maxLeftSubtree = findMax(2*idx+1);
                arr[idx] = maxLeftSubtree;
                removeHelper(2*idx+1, maxLeftSubtree);
            }
            return idx;
        }
        
    }

    // recursive helper function to find the maximum value in a subtree
    int findMax(int idx) {
        if (arr[2*idx+2] == -1) {
            return arr[idx];
        }
        else {
            return findMax(2*idx+2);
        }
    }

    // recursive helper function to perform an inorder traversal of the tree
    void inorderTraversalHelper(int idx) {
        if (arr[idx] == -1) {
            return;
        }
        inorderTraversalHelper(2*idx+1);
        cout << arr[idx] << " ";
        inorderTraversalHelper(2*idx+2);
    }


    void  preorderTraversalHelper(int idx){

        if(arr[idx]==-1){
            return;
        }
        
        cout<<arr[idx]<<" ";
        preorderTraversalHelper(2*idx+1);
        preorderTraversalHelper(2*idx+2);
    }


    bool search(int data,int index){
    if(arr[index]==0) return false;

    if(arr[index]==data) return true;

    if(data<arr[index])
    return search(data,index*2);

    else
     return search(data,index*2+1);
}

void deleteHelper(int i, int key) {
        if (arr[i] == -1) {
            return;
        }
        if (key < arr[i]) {
            deleteHelper(2*i+1, key);
        }
        else if (key > arr[i]) {
            deleteHelper(2*i+2, key);
        }
        else {
            //key==arr[i]
            if (2*i+1 >= MAX_SIZE || 2*i+2 >= MAX_SIZE) {
                arr[i] = -1;
                return;
            }
            int minRight = min(2*i+2, MAX_SIZE - 1);
           // int maxLeft = max(2*i+1, 0);
            int successor = arr[minRight];
            arr[i] = successor;
            deleteHelper(minRight, successor);
        }
    }

};

int main() {
    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    

   cout<<tree.searchInBST(6)<<endl;
   cout<<tree.searchInBST(23)<<endl;


    cout<<"Preorder Traversal"<<" ";
    tree.preorderTraversal();

    cout << "Inorder traversal: ";
    tree.inorderTraversal(); 

    

    tree.remove(3);
    tree.remove(8);
   
     cout << "Inorder traversal: ";
    tree.inorderTraversal();

    tree.deleteKey(2);
    tree.deleteKey(6);
    cout << "Inorder traversal: ";
    tree.inorderTraversal();


    return 0;

}

    