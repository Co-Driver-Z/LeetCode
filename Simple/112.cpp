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
    // 先序搜索
    bool DfsSumNum(TreeNode* root, int targetSum, int CurNum) {
        if (root == nullptr) return false;
        if (root->left==nullptr && root->right==nullptr && CurNum+root->val == targetSum)  //  || CurNum==-1
            return true;
        else 
            return DfsSumNum(root->left,  targetSum, CurNum+root->val) || DfsSumNum(root->right, targetSum, CurNum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 0、分析：适合采用深度优先搜索（DFS）
        // 1、若树为空则返回false
        if (root == nullptr)
            return false;
        // 2、DFS搜索
        int CurNum = 0;
        return (DfsSumNum(root, targetSum, CurNum));

    }
};