
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
    int SubTreeSum (TreeNode*& T, std::unordered_map<int, int>& Hash) {
        // 求解子树的和即访问该树的所有节点，采取先序搜索
        if (T == nullptr)
            return 0;
        int TempSum = T->val + SubTreeSum(T->left, Hash) + SubTreeSum(T->right, Hash);
        ++Hash[TempSum];
        return TempSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // 0、为空则返回0
        std::vector<int> ans;
        if (root == nullptr)
            return ans;
        // 1、求解子树的节点和: Hash: Sum -> Nums
        std::unordered_map<int, int> Hash;
        SubTreeSum(root, Hash);
        // 2、遍历Hash表找出出现次数最多的子树和
        int MaxNums = -1;
        for (std::unordered_map<int,int>::iterator Pos = Hash.begin(); Pos != Hash.end(); ++Pos) {
            if (Pos->second > MaxNums) {
                MaxNums = Pos->second; 
                ans.clear();
                ans.push_back(Pos->first);
            }   
            else if (Pos->second == MaxNums)
                ans.push_back(Pos->first);
        }
        return ans;
    }
};