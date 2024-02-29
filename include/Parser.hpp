#pragma once

#include <optional>

class Node {
private:
    Node* child = nullptr;
    Node* sibling = nullptr;
    std::optional<int> value{};
public:
    Node();
    ~Node();
    Node* get_child();
    Node* get_sibling();
    int get_value();
    void set_child(Node* new_node);
    void set_sibling(Node* new_node);
    void set_value(std::optional<int> value);
};

class Tree {
private:
    Node* root;
public:
    Tree();
    ~Tree();
    Node* get_root();
    void set_root(Node* new_node);
};