#include<iostream>
using namespace std;

#define MAX_SIZE 1000

int tree[MAX_SIZE];


void insert(int data,int index){
    //if the current node is empty,then insert the data
    if(tree[index]==0){
        tree[index]=data;
        return;
    }

    if(data<tree[index]){
        insert(data,index*2);
    }
    else{
        insert(data,index*2+1);
    }
    
}

bool search(int data,int index){
    if(tree[index]==0) return false;
    if(tree[index]==data) return true;
    if(data<tree[index])
    return search(data,index*2);
    else
     return search(data,index*2+1);
}
/*

void preorder(int arr[],int n,int i){
    if(i>=n) return;
    cout<<arr[i]<<" ";
    preorder(arr,n,2*i+1);
    preorder(arr,n,2*i+2);

}
void inorder(int arr[], int n, int i) {
    if (i >= n) return;
    inorder(arr, n, 2 * i + 1);
    cout << arr[i] << " ";
    inorder(arr, n, 2 * i + 2);
}
void postorder(int arr[], int n, int i) {
    if (i >= n) return;
    postorder(arr, n, 2 * i + 1);
    postorder(arr, n, 2 * i + 2);
    cout << arr[i] << " ";
}*/
int main(){

    for(int i=0;i<MAX_SIZE;i++)
    tree[i]=0;

    insert(5, 1);
    insert(3, 2);
    insert(7, 1);
    insert(1, 1);
    insert(4, 1);
    insert(6, 1);
    insert(8, 1);

    cout << search(1, 1) << endl;
    cout << search(3, 2) << endl;
    cout << search(5, 1) << endl;





    return 0;
}