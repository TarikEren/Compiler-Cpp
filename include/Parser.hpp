#pragma once

#include <optional>
#include <string>

//Might change this into a binary tree. A generic tree seems rather too complex for this.

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
    std::optional<string> name{};
    Node_Type type;
public:
    Node();
    ~Node();
    Node* get_child();
    Node* get_sibling();
    int get_value();
    string get_type();
    string get_name();
    void set_child(Node* new_node);
    void set_sibling(Node* new_node);
    void set_value(std::optional<int> value);
    void set_type(Node_Type new_type);
    void set_name(string new_name);
};

class Expr_Node : public Node {
public:
    Expr_Node() {
        set_type(EXPR);
    }
};

class Num_Node : public Node {
public:
    Num_Node() {
        set_type(NUM);
    }
};

class Var_Node : public Node {
public:
    Var_Node() {
        set_type(VAR);
    }
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