#include "Node.h"

Node::Node(const int& valueIn) : value(valueIn), rank(0), parent(nullptr)
{}

void Node::setValue(const int& valueIn)
{
    value = valueIn;
}

void Node::setParent(Node* parentIn)
{
    parent = parentIn;
}

void Node::setRank(const int& rankIn)
{
    rank = rankIn;
}

int Node::getValue()
{
    return value;
}

Node* Node::getParent()
{
    return parent;
}

int Node::getRank()
{
    return rank;
}