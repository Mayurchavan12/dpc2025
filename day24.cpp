#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class Tree{
public:
    TreeNode* root;

    Tree() : root(NULL) {}

    void insert(int val) {
        root = insertRec(root, val);
    }

    
    TreeNode* insertRec(TreeNode* node, int val) {
        if (node == NULL) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    
    TreeNode* findLCA(int n1, int n2) {
        return findLCARec(root, n1, n2);
    }

    
    TreeNode* findLCARec(TreeNode* node, int n1, int n2) {
        if (node == NULL) {
            return NULL;
        }

        
        if (node->data == n1 || node->data == n2) {
            return node;
        }

        
        TreeNode* left_lca = findLCARec(node->left, n1, n2);
        TreeNode* right_lca = findLCARec(node->right, n1, n2);

        
        if (left_lca && right_lca) {
            return node;
        }

        return (left_lca != NULL) ? left_lca : right_lca;
    }

    TreeNode* getRoot() {
        return root;
    }
};

int main() {
    Tree tree;
    cout << "Enter number of nodes: ";
    int n;
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }

    int n1, n2;
    cout << "Enter two nodes to find LCA: ";
    cin >> n1 >> n2;

    
    if (tree.getRoot() == NULL) {
        cout << "Tree is empty!" << endl;
        return 0;
    }

    
    TreeNode* lca = tree.findLCA(n1, n2);
    if (lca != NULL) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found (one or both nodes may not exist in the tree)." << endl;
    }

    return 0;
}
