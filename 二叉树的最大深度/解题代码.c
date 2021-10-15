/*
题目描述：
	给定一个二叉树，找出其最大深度。
	二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

	说明: 叶子节点是指没有子节点的节点。

	示例：
	给定二叉树 [3,9,20,null,null,15,7]，

	    3
	   / \
	  9  20
	    /  \
	   15   7
	返回它的最大深度 3 。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    //当为空树时，深度为0
    if(root == NULL)
        return 0;

    //不为空树时，分治思想
    //先求左右子树，再将得到的左右子树深度进行保存防止树过大而导致运行时间过长
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    //树的深度为左右子树中最大深度的数的深度加 1 ；
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

