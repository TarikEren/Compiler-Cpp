#include "../include/Parser.hpp"

Node* Node::get_child() {
    return this->child;
}
Node* Node::get_sibling() {
    return this->sibling;
}

void Node::set_child(Node *new_node) {
    this->child = new_node;
}

void Node::set_sibling(Node *new_node) {
    this->sibling = new_node;
}

int Node::get_value() {
    if (this->value.has_value())
        return this->value.value();
    else {
        return (int)NULL;
    }
}

void Node::set_value(std::optional<int> value) {
    this->value = value;
}

Node *Tree::get_root() {
    return this->root;
}

void Tree::set_root(Node* new_node) {
    this->root = new_node;
}
