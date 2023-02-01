#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100000

void frequency_of_values(int n, int numbers[]) {
    int freq[MAX_NUMBERS] = {0};
    int max_value = 0;
    for (int i = 0; i < n; i++) {
        freq[numbers[i]]++;
        if (numbers[i] > max_value) {
            max_value = numbers[i];
        }
    }

    for (int i = 0; i <= max_value; i++) {
        if (freq[i] != 0) {
            printf("%d %d\n", i, freq[i]);
        }
    }
}

int main(void) {
	// your code goes here
	int n;
	cin>>n;
	int numbers[n];
	for(int i=0;i<n;i++){
	    cin>>numbers[i];
	}
	
	frequency_of_values(n,numbers);
	return 0;
}