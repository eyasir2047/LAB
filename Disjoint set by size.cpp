#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
//make,find and union 
const int N=1e5+10;
int size2[N];
int parent[N];



 void make(int v){
    parent[v]=v;
    size2[v]=1;
}

 int find(int v){
    if(parent[v]==v)return v;
    return parent[v]=find(parent[v]);//path compression
 }

 //union by size
 void Union(int a,int b){

    a=find(a);
    b=find(b);

    if(a!=b){
        if(size2[a]<size2[b]){
            swap(a,b);
        }//a>b

        parent[b]=a;
        size2[a]+=size2[b];
    }
 }

 

int main(){

    int n,k;
   // cin>>n>>k;
   n=5,k=3;

    



    for(int i=1;i<=n;i++)make(i);

    while(k--){
        int u,v;
       // cin>>u>>v;
     //  Union(u,v);
     Union(0,2);
     Union(4,2);
     Union(3,1);
     
}

    if(find(4)==find(0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }

    if(find(1)==find(0)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }



    return 0;
}
