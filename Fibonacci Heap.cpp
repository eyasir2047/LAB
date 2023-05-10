//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define PI (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10, mod = 1e9+7;

using namespace std;

// Node class to represent a single node in the heap
class Node {
public:
    int key; // the key value of the node
    int degree; // the degree of the node
    bool mark; // whether the node has lost a child since it became a child of another node
    Node* parent; // a pointer to the parent node
    Node* child; // a pointer to one of the children nodes
    Node* left; // a pointer to the node to the left in the list of siblings
    Node* right; // a pointer to the node to the right in the list of siblings
    
    Node(int key) {
        this->key = key;
        degree = 0;
        mark = false;
        parent = nullptr;
        child = nullptr;
        left = this;
        right = this;
    }
};

// Fibonacci Heap class
class FibonacciHeap {
private:
    Node* minNode; // a pointer to the node with the minimum key value in the heap
    int n; // the number of nodes in the heap
    
    // Helper function to add a node to the list of nodes
    void addNodeToList(Node* node, Node* list) {
        node->left = list->left;
        node->right = list;
        list->left->right = node;
        list->left = node;
    }
    
    // Helper function to remove a node from the list of nodes
    void removeNodeFromList(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        node->left = node;
        node->right = node;
    }
    
    // Helper function to consolidate the heap after a node has been removed
    void consolidate() {
        int maxDegree = log2(n) + 1; // the maximum degree that any node can have in the heap
        vector<Node*> degreeList(maxDegree, nullptr); // an array to keep track of nodes with the same degree
        
        // Loop through all the nodes in the list and merge nodes with the same degree
        Node* currentNode = minNode;
        do {
            Node* nextNode = currentNode->right;
            int degree = currentNode->degree;
            
            // Merge nodes with the same degree until no more nodes with the same degree are left
            while (degreeList[degree] != nullptr) {
                Node* otherNode = degreeList[degree];
                if (currentNode->key > otherNode->key) {
                    swap(currentNode, otherNode);
                }
                link(otherNode, currentNode);
                degreeList[degree] = nullptr;
                degree++;
            }
            
            degreeList[degree] = currentNode;
            currentNode = nextNode;
        } while (currentNode != minNode);
        
        // Find the new minimum node
        minNode = nullptr;
        for (int i = 0; i < maxDegree; i++) {
            if (degreeList[i] != nullptr) {
                if (minNode == nullptr || degreeList[i]->key < minNode->key) {
                    minNode = degreeList[i];
                }
            }
        }
    }
    
    // Helper function to link two nodes together
    void link(Node* child, Node* parent) {
        removeNodeFromList(child);
        child->parent = parent;
        child->mark = false;
        
        if (parent->child == nullptr) {
            parent->child = child;
            child->left         = child;
        child->right = child;
    } else {
        addNodeToList(child, parent->child);
    }
    
    parent->degree++;
    }

    // Helper function to cut a node from its parent
    void cut(Node* node) {
        Node* parent = node->parent;
        removeNodeFromList(node);
        
        if (node == parent->child) {
            parent->child = node->right;
            if (parent->child == node) {
                parent->child = nullptr;
            }
        }
        
        parent->degree--;
        addNodeToList(node, minNode);
        node->parent = nullptr;
        node->mark = false;
    }

    // Helper function to cascade-cut a node
    void cascadeCut(Node* node) {
        Node* parent = node->parent;
        if (parent != nullptr) {
            if (node->mark == false) {
                node->mark = true;
            } else {
                cut(node);
                cascadeCut(parent);
            }
        }
    }
public:
    FibonacciHeap() {
        minNode = nullptr;
        n = 0;
    }

    // Function to check if the heap is empty
    bool isEmpty() {
        return minNode == nullptr;
    }

    // Function to insert a node into the heap
    void insert(int key) {
        Node* newNode = new Node(key);
        if (minNode == nullptr) {
            minNode = newNode;
        } else {
            addNodeToList(newNode, minNode);
            if (newNode->key < minNode->key) {
                minNode = newNode;
            }
        }
        n++;
    }

    // Function to get the minimum node from the heap
    int getMin() {
        return minNode->key;
    }

    // Function to delete the minimum node from the heap
    void deleteMin() {
        if (minNode != nullptr) {
            Node* oldMin = minNode;
            
            // Add the children of the minimum node to the list of nodes
            if (minNode->child != nullptr) {
                Node* child = minNode->child;
                do {
                    Node* nextChild = child->right;
                    addNodeToList(child, minNode);
                    child->parent = nullptr;
                    child = nextChild;
                } while (child != minNode->child);
            }
            
            // Remove the minimum node from the list of nodes
            removeNodeFromList(minNode);
            n--;
            if (n == 0) {
                minNode = nullptr;
            } else {
                minNode = oldMin->right;
                consolidate();
            }
            delete oldMin;
        }
    }

    // Function to decrease the key of a node in the heap
    void decreaseKey(Node* node, int newKey) {
        if (newKey > node->key) {
            return;
        }
        node->key = newKey;
        Node* parent = node->parent;
        if (parent != nullptr && node->key < parent->key) {
            cut(node);
            cascadeCut(parent);
        }
        if (node->key < minNode->key) {
            minNode = node;
        }
    }

    // Function to delete a node from the heap
    void deleteNode(Node* node) {
        decreaseKey(node, INT_MIN);
        deleteMin();
    }

};

int main(){

    fastio
    
    FibonacciHeap* a=new FibonacciHeap();
    a->insert(7);
     a->insert(10);
      a->insert(2);
       a->insert(4);
        a->insert(3);

        cout<<a->getMin()<<endl;


    

    return 0;
}