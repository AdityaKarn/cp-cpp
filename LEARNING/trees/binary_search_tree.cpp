#include <iostream>

using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
};

void parent_node(int value, node *parent)
{
    node *new_node = new node();
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
}

void append_BTnode(int value, node *parent)
{

    node *new_node = new node();
    new_node->data = value;

    if (value < parent->data)
    {
        parent->left = new_node;
        new_node->left = NULL;
        new_node->right = NULL;
        parent = new_node;
    }

    else
    {
        parent->right = new_node;
        new_node->left = NULL;
        new_node->right = NULL;
        parent = new_node;
    }
}

int main()
{

    node *parent = NULL;

    parent_node(4, parent);

    append_BTnode(5, parent);
    append_BTnode(6, parent);
    append_BTnode(2, parent);
    append_BTnode(3, parent);
    append_BTnode(7, parent);
    append_BTnode(1, parent);

    // print_Tree(parent);
}