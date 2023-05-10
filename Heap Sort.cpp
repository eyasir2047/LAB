#include<iostream>
#include<stdio.h>
using namespace std;

int left(int v){
    return 2*v+1;
}
int right(int v){
    return 2*v+2;
}

void heapify(int arr[],int n,int v){//maxHeap
    int largest=v;
    int l=left(v);//0-base indexing 
    int r=right(v);

    if(l<n && arr[l]>arr[largest])
    largest=l;

    if(r<n && arr[r]>arr[largest])
    largest=r;

    if(largest!=v){
        swap(arr[v],arr[largest]);
        heapify(arr,n,largest);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    cout<<endl;
}

void heapSort(int arr[],int n){

    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        n--;
        heapify(arr,i,0);
    }
}

int main(){

    int arr[]={60,20,40,70,30,10};
    int n=sizeof(arr)/sizeof(arr[0]);


    for(int i=n/2-1;i>=0;i--)//does  not need to heapify leaf node to built maxheap
    heapify(arr,n,i);   

     printArray(arr,n);
    cout<<endl;

    heapSort(arr,n);

    printArray(arr,n);
    cout<<endl;



return 0;

}
