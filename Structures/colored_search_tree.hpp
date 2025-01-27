#pragma once

class ColoredSearchTree {
public:
    ColoredSearchTree() = default;
    ~ColoredSearchTree() = default;
    void insert(int key);
    void remove(int key);
    bool search(int key);

private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        bool is_red;
    };
    Node* root = nullptr;
    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* find_min(Node* node);
    Node* find_max(Node* node);
    Node* search(Node* node, int key);
    Node* rotate_left(Node* node);
    Node* rotate_right(Node* node);
    Node* flip_colors(Node* node);
    Node* move_red_left(Node* node);
    Node* move_red_right(Node* node);
    Node* balance(Node* node);
    Node* fix_up(Node* node);
    Node* remove_min(Node* node);
    Node* remove_max(Node* node);
    Node* delete_node(Node* node, int key);
    bool is_red(Node* node);
    int size(Node* node);
    void clear(Node* node);
};
