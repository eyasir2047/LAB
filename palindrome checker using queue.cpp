#include<iostream>
using namespace std;
class node{

    public:
    char v;
   node* next;
   node* prev;
  

   node(char v){
    this->v=v;
    next=NULL;
    prev=NULL;
   
   }

};

class queue{

        node* front;
        node* back;
        int len;
        
        public:
        queue(){
           front=back=NULL; 
           len=0;
        }

        void enqueue(char a){
            node* temp=new node(a);

            if(front==NULL){//first element
                front=back=temp;
                back->next= front;
                front->prev=back;
                len++;
                return;

            }

            back->next=temp;
            temp->prev=back;
            back=temp;
            back->next=front;
            front->prev=back;

            len++;

            

        }

       

       
    bool isPalindrome(){

    
    node *temp=back;
    node* temp1=front;

  
    int i, mid=len/2;

    //if(len%2!=0){//not taking the middle element

    for(i=0;i<mid;i++){
      if(temp1->v!= temp->v){
        return false;
      }
      //cout<<temp1->v<<" "<<temp->v<<endl;
      temp=temp->prev;
      temp1=temp1->next;
    }

    //cout<<i<<endl;

   // }




    return true;


}
};

int main(){

queue q;
q.enqueue('a');
q.enqueue('b');
//q.enqueue('e');
q.enqueue('b');
q.enqueue('a');

cout<<q.isPalindrome()<<endl;



    return 0;
}