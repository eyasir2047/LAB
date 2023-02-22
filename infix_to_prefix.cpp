#include<iostream>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

//(a-b/c)*(a/k-l) = doing reverse  )l-k/a(*)c/b-a( = (l-k/a)*(c/b-a)-> *-a/bc-/akl-> doing reverse
//*-a/bc-/akl
int prec(char c){
    if(c=='^') return 3;

    else if(c=='*' || c=='/')
    return 2;

    else if(c=='+' || c=='-')
    return 1;

    else
    return -1;

}

string infixtoPostfix(string s){
    reverse(s.begin(),s.end());
    stack<char>st;
    string result;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){

           while(!st.empty() && st.top()!=')'){
            result+=st.top();
            st.pop();
           }

           if(!st.empty()){
            st.pop();
           } 
        }
        else{//+,-,* .... etc

            while(!st.empty() && prec(st.top())>prec(s[i])){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }


    reverse(result.begin(),result.end());

    return result;


}

int main(){
    string s="(a-b/c)*(a/k-l)";
    cout<<infixtoPostfix(s)<<endl;
    return 0;
}




