#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[] , int n) {
    for (int i = 1; i < n ; i++) {
        int j = i - 1;
        while (j>=0 && arr[j+1] < arr[j]) {
            swap (arr[j], arr[j+1]);
            j-=1;
        }
    }
}

int main() {
    int arr[] = {4,5,5,3,2,3,6,8,9,10};
    int n = size(arr);
    insertion_sort(arr, n);
    for (int i = 1; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}