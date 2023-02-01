#include <bits/stdc++.h>
void selectionSort(vector<int>& arr, int n)
{  
    // Write your code here.
    for(int i=0;i<=(n-2);i++){
        int minIndex= i;
        for(int j=i+1;j<=(n-1);j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
