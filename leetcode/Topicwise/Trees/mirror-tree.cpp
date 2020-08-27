void mirror(Node *node)
{
    // Your Code Here
    if (node == NULL)
        return;

    mirror(node->right);
    mirror(node->left);

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}