#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void sort_numbers(int n, int numbers[]) {
    
    for (int i = 0; i < n; i++) {
        bool swapped=false;
        for (int j = 0; j < n - i - 1; j++) {
            if ((numbers[j] % 2 == 0 && numbers[j + 1] % 2 != 0) ||
                (numbers[j] % 2 != 0 && numbers[j + 1] % 2 != 0 && numbers[j] > numbers[j + 1]) ||
                (numbers[j] % 2 == 0 && numbers[j + 1] % 2 == 0 && numbers[j] < numbers[j + 1])) {
                    // odd ta age thake, even ta pore thakbe ,that's why 1st condition
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
                swapped=true;
                
                // 1 -1 2 -2 
                //-1 1 2 -2
                
            }
        }
        if(swapped==false) break;
    }
   /* for(int i=0;i<n;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;*/
}

int main(){
    int n;
    cin>>n;
    int numbers[n];
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    sort_numbers(n,numbers);
    
    for(int i=0;i<n;i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    
   
}