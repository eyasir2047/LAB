#include<iostream>
#include<stack>
using namespace std;
bool isPalindrome(string s){
    int len=s.size();

    stack<char>st;
    int i, mid=len/2;

    for(i=0;i<mid;i++){
        st.push(s[i]);
    }

    if(len%2!=0) i++;//not taking the middle point

    char ele;

    while(s[i]!='\0'){
        ele=st.top();
        st.pop();
        if(ele!=s[i]){
            return false;
        }
        i++;
    }

    return true;


}
int main(){
    string s="tabctkkcba";
    cout<<isPalindrome(s)<<endl;
}
