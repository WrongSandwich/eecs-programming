#include "Node.h"

Node::Node(const int& valueIn) : value(valueIn)
{}

void Node::setValue(const int& valueIn)
{
    value = valueIn;
}

void Node::setParent(Node* parentIn)
{
    parent = parentIn;
}

int Node::getValue()
{
    return value;
}

Node* Node::getParent()
{
    return parent;
}