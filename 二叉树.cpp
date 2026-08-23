#include <iostream>
#include <queue>
#include <cstdlib> 
// 二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 插入节点（二叉搜索树方式）
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// 前序遍历（根 -> 左 -> 右）
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历（左 -> 根 -> 右）—— 二叉搜索树中序结果是有序的
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

// 后序遍历（左 -> 右 -> 根）
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

// 层序遍历（按层输出）
void levelorder(TreeNode* root) {
    if (root == nullptr) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        std::cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// 查找节点
bool search(TreeNode* root, int val) {
    if (root == nullptr) return false;
    if (root->val == val) return true;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

// 释放内存
void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;
    system("chcp 65001"); 


    // 自动插入一些节点
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    std::cout << "插入节点: ";
    for (int val : values) {
        std::cout << val << " ";
        root = insert(root, val);
    }
    std::cout << "\n\n";

    std::cout << "前序遍历: ";
    preorder(root);
    std::cout << "\n";

    std::cout << "中序遍历: ";
    inorder(root);
    std::cout << "  （二叉搜索树的中序遍历结果是有序的）\n";

    std::cout << "后序遍历: ";
    postorder(root);
    std::cout << "\n";

    std::cout << "层序遍历: ";
    levelorder(root);
    std::cout << "\n\n";

    // 查找测试
    int target = 40;
    std::cout << "查找 " << target << ": " << (search(root, target) ? "找到" : "未找到") << "\n";

    target = 100;
    std::cout << "查找 " << target << ": " << (search(root, target) ? "找到" : "未找到") << "\n";

    destroy(root);
    return 0;
}