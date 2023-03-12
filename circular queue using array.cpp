#include<iostream>
using namespace std;
#define n 10
//back==rear

class queue{
    private :
    int *arr;
    int front, back;

    public:
    queue(){
        arr=new int[n];
        front=back=-1;
    }
    
    bool isFull(){
        if(front==0 && back==n-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"queue is full"<<endl;
        }
        else{
            
            if(front==-1) front++; //first element

            back= (back+1)%n;
            arr[back]=x;

            cout<<"Inserted element: "<<x<<endl;


        }
    }

int dequeue(){
        int element;

        if(isEmpty()){
            return -1;
        }
        else{
            element=arr[front];
           if(front==back){//last element
            front=back=-1;
           }
           else{
            front=(front+1)%n;

           }
           return( element);

        }

    }

    void display(){
        if(isEmpty()){
            cout<<"empty queue"<<endl;
        }
        else{
            int i;
            for(i=front;i!=back;i=(i+1)%n){
                cout<<arr[i]<<" ";
            }
            cout<<arr[i]<<endl;
        }
    }



};


int main(){

    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
   q.display();
   cout<<q.dequeue()<<endl;
   cout<<q.isEmpty()<<endl;



    return 0;
}