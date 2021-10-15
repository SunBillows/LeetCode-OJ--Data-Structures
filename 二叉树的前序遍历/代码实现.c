/*
题目描述：

你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
 
提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


 //编写一个函数，求一棵树的结点
 int TreeSize(struct TreeNode* root)
 {
     //利用递归来求出一棵树的节点个数
     return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
 }


//编写一个前序遍历函数
void preorder(struct TreeNode* root,int* array,int* i)
{
    if(root == NULL)
        return;

    array[*i] = root->val;
    (*i)++;
    preorder(root->left,array,i);
    preorder(root->right,array,i);
}

//其中returnSize为数组大小
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int i = 0;
    int Size = TreeSize(root);
    
    //创建一个数组用于存储各个结点
    int* array = (int*)malloc(sizeof(int) * Size);

    //开始递归遍历
    preorder(root,array,&i);

    *returnSize = Size;

    return array;
}

