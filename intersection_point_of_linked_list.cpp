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

int intersection(Node* &head1, Node* &head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    Node* ptr1;
    Node* ptr2;
    //considering that ptr1 is bigger
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2= head1;
    }

    while(d){
        ptr1= ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return -1;





}

void intersect(Node* &head1, Node* &head2,int pos){
    //head1>head2
    Node* temp1=head1;
    Node* temp2=head2;

    pos--;
    while(pos--){
        temp1=temp1->next;
    }

    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next=temp1;
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
    
    insertionAtTail(tail1,head1,1);
    insertionAtTail(tail1,head1,2);
    insertionAtTail(tail1,head1,3);
    insertionAtTail(tail1,head1,4);
    insertionAtTail(tail1,head1,5);
    insertionAtTail(tail1,head1,6);
    
    insertionAtTail(tail2,head2,9);
    insertionAtTail(tail2,head2,10);
    insertionAtTail(tail2,head2,11);
  

    intersect(head1,head2,3);

    print(head1,tail1);
    print(head2,tail2);

    cout<<intersection(head1,head2)<<endl;








    return 0;
}