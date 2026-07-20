#include<bits/stdc++.h>
using namespace std;

void push(vector<int> &arr, int n){
    arr.push_back(n);
}

void pop(vector<int> &arr){
    arr.pop_back();
}

int peek(vector<int> &arr){
    return arr[arr.size() - 1];
}

int main(){
    
}