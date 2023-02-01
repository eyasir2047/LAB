#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void frequency_of_values(int n, int numbers[]) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        if (freq.count(numbers[i]) == 0) {
            freq[numbers[i]] = 1;
        }
        else {
            freq[numbers[i]]++;
        }
    }

    vector<pair<int, int>> freq_list;
    for (auto x : freq) {
        freq_list.push_back(x);
    }

    sort(freq_list.begin(), freq_list.end(), [](const auto &left, const auto &right) {
        return left.first < right.first;
    });

    for (auto x : freq_list) {
        cout << x.first << " " << x.second << endl;
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