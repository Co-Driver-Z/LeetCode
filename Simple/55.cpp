/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // -- 深度优先搜索
        // 1、如果二叉树为空，则返回0
        if (root == NULL)
            return 0;
        // 2、如果二叉树不为空，开始递归
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
        // // -- 广度优先搜索
        // // 0、如果二叉树为空，则返回0
        // if (root == NULL)
        //     return 0;
        // // 1、创建一个队列用于存储当前深度的节点
        // int Result = 0;
        // std::queue<TreeNode*> Q;
        // Q.push(root);
        // // 2、开始广度优先搜索
        // while (!Q.empty()) {
        //     int Size = Q.size();
        //     while (Size > 0) {
        //         TreeNode* Cur = Q.front(); Q.pop();
        //         if (Cur->left != NULL) Q.push(Cur->left);
        //         if (Cur->right != NULL) Q.push(Cur->right);
        //         --Size;
        //     }
        //     ++Result;
        // }
        // return Result;
    }
};