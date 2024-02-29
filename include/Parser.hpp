#pragma once

#include <optional>
#include <string>

using string = std::string;

typedef enum Node_Type {
    EXPR,
    NUM,
    VAR,
}Node_Type;

class Node {
private:
    Node* child = nullptr;
    Node* sibling = nullptr;
    std::optional<int> value{};
    Node_Type type;
public:
    Node();
    ~Node();
    Node* get_child();
    Node* get_sibling();
    int get_value();
    string get_type();
    void set_child(Node* new_node);
    void set_sibling(Node* new_node);
    void set_value(std::optional<int> value);
    void set_type(Node_Type new_type);
};

class Expr_Node : public Node {

};

class Num_Node : public Node {

};

class Var_Node : public Node {

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