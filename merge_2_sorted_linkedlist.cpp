#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
   
    Node* next;

    //constructor
    Node(int d){
        this->data=d;
        
        this->next=NULL;
    }

    ~Node(){
        int val= this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }

};

void print(Node* &head,Node* &tail){
    Node* temp=head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;

   // cout<<"head "<<head->data<<endl;
   // cout<<"tail "<<tail->data<<endl;
    
}

int length(Node* head){
    Node* temp=head;
    int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

void insertionAtHead(Node* &tail,Node* &head,int d){

    if(head== NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=head;
    head= temp;
    }
    
}

void insertionAtTail(Node* &tail,Node* &head,int d){

    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node* temp= new Node(d);
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertionAtHead(tail,head,d);
        return;
    }
    else{

        Node* temp= head;
        int cnt=1;

        while(cnt<position-1){
            temp=temp->next;
            cnt++;
        }
        //temp is in the current position

        if(temp->next==NULL){
            insertionAtTail(tail,head,d);
            return;
        }

        Node* nodeToInsert= new Node(d);

        nodeToInsert->next=temp->next;
       

      
        temp->next=nodeToInsert;





       
    }
}

void deleteNode(int position,Node* &tail,Node* &head){
    if(position==1){
        Node* temp= head;
      
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{

        Node* curr=head;
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        if(curr->next==NULL){
            Node* temp2= tail;
            
            prev->next=NULL;
            tail= prev;
            temp2->next=NULL;
            delete temp2;

            return;
        }

       
        prev->next=curr->next;
        curr->next=NULL;

        delete curr;


    }
}

Node* merge(Node* &head1,Node* &head2){
    Node* p1=head1;
    Node* p2=head2;

    Node* dummyNode=new Node(-1);
    Node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){

        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;

    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
         p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
         p3=p3->next;
    }

    return dummyNode->next;//returning the head



}

//recurssive method

Node* mergeRecursive(Node* &head1,Node* &head2){
    Node* result;

    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;

}

int main(){

    //Node* node1= new Node(10);
   // Node* head= node1;
   // Node* tail= node1;
   Node* head= NULL;
   Node* tail=NULL;

   Node* head1=NULL;
   Node* head2=NULL;
   Node* tail1=NULL;
   Node* tail2=NULL;

   //print(head);
    //cout<<getLength(head)<<endl;
    
    int arr1[]={1,1,5,7};
    int arr2[]={2,3,6};

    for(int i=0;i<4;i++){
        insertionAtTail(tail1,head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertionAtTail(tail2,head2,arr2[i]);
    }

    print(head1,tail1);
    print(head2,tail2);

    Node* newHead=merge(head1,head2);
  // Node* newHead2=mergeRecursive(head1,head2);

    print(newHead,tail1);
   // print(newHead2,tail2);


    

   








    return 0;
}

