/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node *convertExpression(string str, int i)
{
    //add code here.
    if (i == str.size())
    {
        return NULL;
    }

    Node *root = new Node(str[i]);

    if (i < str.size() && str[i + 1] == '?')
    {
        root->left = convertExpression(str, i + 2);
    }
    if (i < str.size() && str[i + 1] == ':')
    {
        root->right = convertExpression(str, i + 2);
    }

    return root;
}