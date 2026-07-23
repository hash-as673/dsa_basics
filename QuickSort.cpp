#include<bits/stdc++.h>
using namespace std;


void quick_sort(int a[], int s, int e) {
    if (s >= e) return;
    int pivot = a[e];
    int left = s;
    for (int i = s; i< e ;i++) {
        if (a[i]< pivot) {
            swap(a[left], a[i]);
            left++;
        }
    }

    a[e] = a[left];
    a[left] = pivot;

    quick_sort(a, s, left-1);
    quick_sort(a, left+1,e);
}

int main() {
 int arr[] = {5,7,65,4,3,5,67,89,20};
    quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        cout<<arr[i]<<" ";
    }
}