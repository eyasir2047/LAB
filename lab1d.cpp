#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int roll;
    double cgpa;
    int marks;
};

bool compare(Student s1, Student s2) {
    if (s1.cgpa != s2.cgpa) {
        return s1.cgpa > s2.cgpa;
    } else if (s1.marks != s2.marks) {
        return s1.marks > s2.marks;
    } else {
        return s1.roll < s2.roll;
    }
}

void prepare_result(int n, Student students[]) {
    sort(students, students + n, compare);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << students[i].name << " " << students[i].roll
             << " " << students[i].cgpa << " " << students[i].marks << endl;
    }
}


int main(){
    int n;
    cin>>n;
    Student students[n];
    for(int i=0;i<n;i++){
        cin>>students[i].name>>students[i].roll>>students[i].cgpa>>students[i].marks;
    }
    prepare_result(n, students);
    return 0;
}