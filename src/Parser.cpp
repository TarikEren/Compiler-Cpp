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

string Node::get_type() {
    switch (this->type) {
        case EXPR:
            return "EXPR";
        case NUM:
            return "NUM";
        case VAR:
            return "VAR";
        default:
            return "UNDEFINED";
    }
}

void Node::set_type(Node_Type new_type) {
    this->type = new_type;
}

void Node::set_name(string new_name) {
    this->name = new_name;
}

string Node::get_name() {
    return this->name.value();
}

Node *Tree::get_root() {
    return this->root;
}

void Tree::set_root(Node* new_node) {
    this->root = new_node;
}
