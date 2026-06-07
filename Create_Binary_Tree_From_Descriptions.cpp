#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode* > mp;
        unordered_set<int> child;

        for(auto &d : descriptions){
            int p = d[0];
            int c = d[1];
            int l = d[2];

            if( !mp.count(p) ) mp[p] = new TreeNode(p);
            if( !mp.count(c) ) mp[c] = new TreeNode(c);

            if(l) mp[p]->left = mp[c];
            else mp[p]->right = mp[c];

            child.insert(c);
        }

        for(auto &[v, node]: mp){
            if(!child.count(v)) return node;
        }
        return NULL;
        
    }
};


void preorder(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };

    Solution obj;
    TreeNode* root = obj.createBinaryTree(descriptions);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}