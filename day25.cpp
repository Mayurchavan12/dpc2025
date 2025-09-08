#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& data) {
    if (data.empty() || data == "[]") return nullptr;

    string trimmed = data.substr(1, data.size() - 2);
    stringstream ss(trimmed);
    string item;
    vector<TreeNode*> nodes;

    while (getline(ss, item, ',')) {
        if (item == "null") {
            nodes.push_back(nullptr);
        } else {
            nodes.push_back(new TreeNode(stoi(item)));
        }
    }

    int n = nodes.size();
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != nullptr) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

bool isValid(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;

    if (node->val <= minVal || node->val >= maxVal)
        return false;

    return isValid(node->left, minVal, node->val) &&
           isValid(node->right, node->val, maxVal);
}


bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    cout << "Enter tree as array : ";
    string input;
    getline(cin, input);

    TreeNode* root = buildTree(input);
    bool result = isValidBST(root);

    cout << (result ? "Output: true" : "Output: false") << endl;

    return 0;
}
