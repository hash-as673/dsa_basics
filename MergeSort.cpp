#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int s, int m, int e) {
    vector<int> L(a.begin() + s, a.begin() + m + 1);
    vector<int> R(a.begin() + m + 1, a.begin() + e + 1);

    int i = 0, j = 0, k = s;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
        k++;
    }

    while (i < L.size()) {
        a[k++] = L[i++];
    }
    while (j < R.size()) {
        a[k++] = R[j++];
    }
}

void merge_sort(vector<int> &a, int s, int e) {
    if (s >= e) return;

    int m = s + (e - s) / 2;
    merge_sort(a, s, m);
    merge_sort(a, m + 1, e);
    merge(a, s, m, e);
}

int main() {
    vector<int> a = {44, 5, 5, 43, 4, 3, 23, 4, 5, 56};

    merge_sort(a, 0, a.size() - 1);

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}