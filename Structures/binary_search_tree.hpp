#pragma once

template <typename T>
class BinarySearchTree {
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
    };

public:
    BinarySearchTree() : root(nullptr) { }
    ~BinarySearchTree() { clear(root); }
    void insert(const T& value) {
        root = insert(root, value);
    }

    bool find(const T& value) const {
        return find(root, value);
    }

    void remove(const T& value) {
        root = remove(root, value);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, const T& value) {
        if (node == nullptr) {
            node = new TreeNode{value, nullptr, nullptr};
        } else if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool find(TreeNode* node, const T& value) const {
        if (node == nullptr) {
            return false;
        } else if (value < node->data) {
            return find(node->left, value);
        } else if (value > node->data) {
            return find(node->right, value);
        } else {
            return true;
        }
    }

    TreeNode* remove(TreeNode* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    void clear(TreeNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

};

