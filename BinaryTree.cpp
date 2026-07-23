#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int _val = 0;
    TreeNode(int val) {
        _val = val;
    }
};