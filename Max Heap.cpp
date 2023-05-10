#include<iostream>
#include<climits>
#include<stdio.h>

using namespace std;

class MaxHeap{

    int *arr;
    int capacity;
    int size;
    
    public:
    MaxHeap(int capacity){
        this->capacity=capacity;
        this->size=0;
        arr=new int[capacity];
    }

    int parent(int v){
        return (v-1)/2;
    }

    int left(int v){
        return 2*v+1;
    }

    int right(int v){
        return 2*v+2;
    }

    void insertKey(int k){
         if(size==capacity){
            cout<<"Overflow"<<endl;
            return;
        }

        size++;
        int v=size-1;
        arr[v]=k;

        while(v!=0 && arr[parent(v)]<arr[v]){
            swap(&arr[v],&arr[parent(v)]);
            v=parent(v);
        }

    }

    void increaseKey(int v,int newVal){
        
        arr[v]=newVal;
         while(v!=0 && arr[parent(v)]<arr[v]){
            swap(&arr[v],&arr[parent(v)]);
            v=parent(v);
        }

        
    }

    int getMax(){
        return arr[0];
    }

    int removeMax(){
        if(size<=0)
        return INT_MIN;

        if(size==1){
            size--;
            return arr[0];
        }

        int root=arr[0];
        arr[0]=arr[size-1];
        size--;
        MaxHeapify(0);

        return root;
    }

    void deleteKey(int v){
        increaseKey(v,INT_MAX);
        removeMax();
    }

    void MaxHeapify(int v){
        int l=left(v);
        int r=right(v);

        int largest=v;

        if(l<size && arr[l]>arr[v])
        largest=l;

        if(r<size && arr[r]>arr[largest])
        largest=r;

        if(largest!=v){
            swap(&arr[v],&arr[largest]);
            MaxHeapify(largest);
        }
    }

    int curSize(){
        return size;
    }


 void swap(int *x,int *y){

    int temp=*x;
    *x=*y;
    *y=temp;
}




};

int main(){

     MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);//  3 is deleted
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.removeMax() << " ";
    cout << h.getMax() << " ";
    h.increaseKey(2, 100);
    cout << h.getMax();

}
