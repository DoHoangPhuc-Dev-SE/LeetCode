/*
LC 543 - Diameter of Binary Tree
Link: https://leetcode.com/problems/diameter-of-binary-tree/
Hours Effort: 00:22:59
Solution: DFS (Post-order Traversal with Height & Max-Diameter Tracking via Pointer)
Time: O(n), Space: O(h)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int maxDiameter = 0;
 int height(struct TreeNode* root, int* maxDiameter){
    if(root == NULL) return 0;
    int left = height(root->left,maxDiameter);
    int right = height(root->right,maxDiameter);
    if(left + right > *maxDiameter) *maxDiameter = left + right;
    return (left > right ? left : right) + 1;
 }
int diameterOfBinaryTree(struct TreeNode* root) {
    int maxDiameter = 0;
    height(root,&maxDiameter);
    return maxDiameter;
}