//infix, prefix and postfix expression

//infix ->normally ->BODMAS
//operand, operator, operand
//precedence -> (),^,*,/,+,- 
//associativity-> left to right (most of the time)
//^ ->right to left


/* prefix expression-> polish notation(for computer)
 operator, operand, operand
 ((4*2)+3)-> +*4 2 3
 5-6/3 =(5-(6/3)) -> -5 /6 3

*/

/*
postfix operation->reverse polish expression->computer
operand, operand, operator
4*2+3=((4*2)+3)-> 4 2*3+
5-6/3= (5-(6/3))-> 5 6 3 / -

*/
//infix to postfix 

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

//(a-b/c)*(a/k-l) -> abc/-ak/l-*
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
    stack<char>st;
    string result;

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){

           while(!st.empty() && st.top()!='('){
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

    return result;


}

int main(){
    string s="(a-b/c)*(a/k-l)";
    cout<<infixtoPostfix(s)<<endl;
    return 0;
}




